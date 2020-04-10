use std::vec::Vec;
use crate::processor::audio_buffer::AudioBuffer;

struct WaveSetBuffer{
    buffer: Vec<f32>,
    peak_amp : f32,
    index: usize
}

impl WaveSetBuffer
{
    pub fn new(capacity: usize) -> Self
    {
        WaveSetBuffer{
            buffer: Vec::with_capacity(capacity),
            peak_amp: 0.0,
            index: 0
        }
    }

    pub fn add(&mut self, sample: f32)
    {
        self.peak_amp = sample.abs().max(self.peak_amp);
        self.buffer.push(sample);
    }

    pub fn generate(&self)->Vec<f32>
    {
        let length = self.buffer.len();
        let cycle = std::f32::consts::PI * 2.0;
        let step = cycle / length as f32;
        let mut phase = 0.0;

        let mut replacement = Vec::with_capacity(length);
        for _ in 0..length{
            replacement.push(f32::sin(phase) * self.peak_amp );
            phase += step;
        }
        return replacement;
    }
}

#[cfg(test)]
mod tests {
    use crate::processor::wave_set_buffer::WaveSetBuffer;

    #[test]
    fn generate() {
        let mut wave_set_buffer = WaveSetBuffer::new(1024);
    }
}