use std::vec::Vec;
use crate::processor::wave_set_channel::WaveSetChannel;

pub struct Engine{
    distortion: f32,
    wave_set_channels: Vec<WaveSetChannel>
}

impl Engine{

    pub fn new(channels: usize) -> Self {
        let mut wave_set_channels = Vec::new();
        for _ in 0..channels {
            wave_set_channels.push(WaveSetChannel::new(2048));
        }

        Engine {
            distortion: 1.0,
            wave_set_channels
        }
    }

    pub fn process(&mut self, buffer: *mut f32, channels:usize, block_size: usize) {

        for ch in 0..channels{
            for index in 0..block_size {
                unsafe {
                    let offset = (ch * block_size + index) as isize;
                    let popped = self.wave_set_channels[ch].push_pop(*buffer.offset(offset));
                    *buffer.offset(offset) = popped;
                }
            }
        }
    }

    pub fn set_distortion(&mut self, value: f32) {
        self.distortion = value;
    }
}