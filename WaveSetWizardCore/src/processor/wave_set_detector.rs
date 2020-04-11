pub struct WaveSetDetector {
    ready : bool,
    max_length : usize,
    count : usize
}

impl WaveSetDetector {

    pub fn new(max_length : usize) -> Self {
        WaveSetDetector{
            ready: true,
            max_length,
            count: 0
        }
    }

    pub fn check(&mut self, value : f32) -> bool {

        if self.count == self.max_length {
            self.reset();
            return true;
        }

        if value > 0.0 && self.ready == true{
            self.reset();
            return true;
        }

        if value <= 0.0 {
            self.ready = true;
        }
        return false;
    }

    fn reset(&mut self){
        self.ready = false;
        self.count = 0;
    }
}

#[cfg(test)]
mod tests {
    use crate::processor::wave_set_detector::WaveSetDetector;

    #[test]
    fn check() {
        let mut detector = WaveSetDetector::new(2048);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true);
        assert_eq!(detector.check(0.002), false);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true)
    }
}