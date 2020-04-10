pub struct WaveSetDetector {
    ready : bool
}

impl WaveSetDetector
{
    pub fn new() -> Self
    {
        WaveSetDetector{
            ready:true
        }
    }

    pub fn check(&mut self, value : f32) -> bool
    {
        if value > 0.0 && self.ready == true{
            self.ready = false;
            return true;
        }

        if value <= 0.0 {
            self.ready = true;
        }
        return false;
    }
}

#[cfg(test)]
mod tests {
    use crate::processor::wave_set_detector::WaveSetDetector;

    #[test]
    fn check() {
        let mut detector = WaveSetDetector::new();
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true);
        assert_eq!(detector.check(0.002), false);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true)
    }
}