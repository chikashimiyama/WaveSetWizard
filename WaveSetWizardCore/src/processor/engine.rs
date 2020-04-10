use crate::processor::audio_ring_buffer::AudioRingBuffer;

pub struct Engine{
    block_size : usize,
    ring_buffer : AudioRingBuffer,
    threshold : usize,
    distortion: f32
}

impl Engine{
    pub fn new(channels: usize, block_size: usize) -> Self {
        Engine {
            block_size,
            ring_buffer: AudioRingBuffer::new(channels, 4096),
            threshold: 2048,
            distortion: 1.0
        }
    }

    pub fn process(&mut self, buffer: *mut f32, channels:usize, block_size: usize)
    {
        unsafe {
            self.ring_buffer.push_from_pointer(buffer, channels, block_size);
        }
    }

    pub fn set_distortion(&mut self, value: f32)
    {
        self.distortion = value;
    }
}