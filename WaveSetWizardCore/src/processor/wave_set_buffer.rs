use std::vec::Vec;

pub struct WaveSetBuffer{
    buffer: Vec<f32>,
    peak_amp : f32,
}

impl WaveSetBuffer
{
    pub fn new(capacity: usize) -> Self {
        WaveSetBuffer{
            buffer: Vec::with_capacity(capacity),
            peak_amp: 0.0,
        }
    }

    pub fn add(&mut self, sample: f32) {
        self.peak_amp = sample.abs().max(self.peak_amp);
        self.buffer.push(sample);
    }

    pub fn generate(&mut self)->Vec<f32> {
        let length = self.buffer.len();
        let cycle = std::f32::consts::PI * 2.0;
        let step = cycle / length as f32;
        let mut phase = 0.0;

        let mut replacement = Vec::with_capacity(length);
        for _ in 0..length{
            // here we implement interpolation
            replacement.push(f32::sin(phase) * self.peak_amp );
            phase += step;
        }

        self.buffer.clear();
        return replacement;
    }
}
