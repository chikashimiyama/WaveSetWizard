use std::vec::Vec;
use std::ptr;

pub struct AudioBuffer {
    data : Vec<f32>,
    channels : usize,
    block_size : usize
}

impl AudioBuffer {

    pub fn new(channels: usize, block_size: usize) -> Self {
        AudioBuffer {
            data: vec![0.0; channels * block_size],
            channels,
            block_size
        }
    }

    pub fn new_from_pointer(channels: usize, block_size: usize, source: *const f32) -> Self {
        let mut audio_buffer = Self::new(channels, block_size);
        // Todo: copying is not optimal for performance. should be reference
        if source != ptr::null(){
            let length = audio_buffer.data.len();
            for i in 0..length{
                unsafe {  audio_buffer.data[i] = *source.offset(i as isize); }
            }
        }
        return audio_buffer;
    }

    pub fn channel(&mut self, ch : usize) -> &mut [f32] {
        let begin = ch * self.block_size;
        let end = begin + self.block_size;
        return &mut self.data[begin..end];
    }

    pub fn channel_count(&self) -> usize {
        return self.channels;
    }
}


#[cfg(test)]
mod tests {

    use std::mem;
    use crate::processor::audio_buffer::AudioBuffer;
    use libc;

    #[test]
    fn new() {
        let audio_buffer = AudioBuffer::new(2, 64);

        assert_eq!(audio_buffer.channels,  2);
        assert_eq!(audio_buffer.block_size, 64);
        assert_eq!(audio_buffer.data.capacity(), 128);

        for element in audio_buffer.data{
            assert_eq!(element, 0.0);
        }
    }

    #[test]
    fn new_from_pointer() {
        unsafe {
            let c_buffer: *mut f32 = libc::malloc(mem::size_of::<f32>() * 128) as *mut f32;
            for i in 0..128 {
                *c_buffer.offset(i) = 0.5;
            }

            let audio_buffer = AudioBuffer::new_from_pointer(2, 64, c_buffer);

            assert_eq!(audio_buffer.channels,  2);
            assert_eq!(audio_buffer.block_size, 64);
            assert_eq!(audio_buffer.data.capacity(), 128);

            for element in audio_buffer.data{
                assert_eq!(element, 0.5);
            }

            libc::free(c_buffer as *mut libc::c_void)
        };
    }

    #[test]
    fn channel() {
        let mut audio_buffer =  AudioBuffer::new(2, 64);
        let channel = audio_buffer.channel(1);
        assert_eq!(channel.len(), 64);
    }

    #[test]
    fn channel_count() {
        let audio_buffer =  AudioBuffer::new(4, 64);
        assert_eq!(audio_buffer.channel_count(), 4);
    }
}
