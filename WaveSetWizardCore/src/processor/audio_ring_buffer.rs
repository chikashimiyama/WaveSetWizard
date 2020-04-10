use ring_buffer::RingBuffer;
use std::vec::Vec;
use super::audio_buffer::AudioBuffer;

pub struct AudioRingBuffer {
    data : Vec<RingBuffer::<f32>>
}

impl AudioRingBuffer {
    pub fn new(channels: usize, capacity: usize) -> Self {
        let mut data = Vec::new();
        for _i in 0..channels {
            let ring_buf = RingBuffer::<f32>::with_capacity(capacity as usize);
            data.push(ring_buf);
        }
        AudioRingBuffer {
            data
        }
    }

    pub unsafe fn push_from_pointer(&mut self, buffer: *const f32, channels: usize, block_size: usize )
    {
        let mut offset = 0;
        for i in 0..channels {
            self.data[i].push(*buffer.offset(offset));
            offset += 1;
        }
    }

    pub fn push(&mut self, mut audio_buffer: AudioBuffer)
    {
        let channels = std::cmp::min(audio_buffer.channel_count(), self.data.len());
        for i in 0..channels {
            let channel_buffer = audio_buffer.channel(i);
            for sample in channel_buffer {
                self.data[i].push(*sample);
            }
        }
    }

    pub fn sample_count(&self) -> usize
    {
        return self.data[0].len();
    }

    pub fn channels(&self) -> usize { return self.data.len(); }

    pub fn pop(&mut self, block_size: usize) -> Option<AudioBuffer> {
        if self.data[0].len() < block_size { return None; }

        let mut audio_buffer = AudioBuffer::new(self.data.len(), block_size);
        for i in 0..audio_buffer.channel_count() {
            let channel = audio_buffer.channel(i);
            for j in 0..block_size {
                let sample = self.data[i].pop().unwrap();
                channel[j] = sample;
            }
        }
        return Some(audio_buffer);
    }
}

#[cfg(test)]
mod tests {
    use crate::processor::audio_ring_buffer::AudioRingBuffer;
    use crate::processor::audio_buffer::AudioBuffer;

    #[test]
    fn pop_insufficient_samples_in_buffer(){
        let mut ring_buffer =  AudioRingBuffer::new(2, 64);
        let to_push = AudioBuffer::new(2, 4); // push four samples
        ring_buffer.push(to_push);
        let data = ring_buffer.pop(5); // try to pull five samples

        assert!(data.is_none());
    }

    #[test]
    fn push_pop(){
        let mut ring_buffer =  AudioRingBuffer::new(1, 64);
        let mut to_push = AudioBuffer::new(1, 3);
        to_push.channel(0)[0] = 0.1;
        to_push.channel(0)[1] = 0.2;
        to_push.channel(0)[2] = 0.3;

        ring_buffer.push(to_push);
        let mut popped = ring_buffer.pop(3).unwrap();

        assert_eq!(popped.channel(0)[0], 0.1);
        assert_eq!(popped.channel(0)[1], 0.2);
        assert_eq!(popped.channel(0)[2], 0.3);
    }

    #[test]
    fn len(){
        let mut ring_buffer =  AudioRingBuffer::new(1, 64);
        let to_push = AudioBuffer::new(1, 3);

        ring_buffer.push(to_push);

        assert_eq!(ring_buffer.sample_count(), 3);
        ring_buffer.pop(1);

        assert_eq!(ring_buffer.sample_count(), 2);
    }


}
