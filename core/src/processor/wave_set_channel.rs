use std::collections::VecDeque;
use crate::processor::wave_set_detector::WaveSetDetector;
use crate::processor::wave_set_buffer::WaveSetBuffer;

pub struct WaveSetChannel {
    processed: VecDeque<f32>,
    wave_set_detector: WaveSetDetector,
    current_buffer: WaveSetBuffer
}

impl WaveSetChannel{
    pub fn new(max_length : usize)->Self{
        let mut processed = VecDeque::with_capacity(max_length);
        for _ in 0..max_length { processed.push_back(0.0);}

        WaveSetChannel{
            processed,
            wave_set_detector: WaveSetDetector::new(max_length),
            current_buffer: WaveSetBuffer::new(max_length),
        }
    }

    pub fn push_pop(&mut self, sample: f32) -> f32 {
        if self.wave_set_detector.check(sample){
            let replacement = self.current_buffer.generate();
            for value in replacement {
                self.processed.push_back(value);
            }
        }
        self.current_buffer.add(sample);
        return self.processed.pop_front().unwrap();
    }
}
