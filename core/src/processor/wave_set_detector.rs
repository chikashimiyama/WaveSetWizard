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

        if self.count == self.max_length-1 {
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

        self.count += 1;
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
        let mut detector = WaveSetDetector::new(64);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true);
        assert_eq!(detector.check(0.002), false);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true)
    }

    #[test]
    fn reach_max_length() {
        let mut detector = WaveSetDetector::new(10);
        for _ in 0..9 {
            assert_eq!(detector.check(0.0), false);
        }
        assert_eq!(detector.check(0.0), true);
        assert_eq!(detector.check(0.0), false);
    }

    #[test]
    fn detection_reset_max_length_count() {
        let mut detector = WaveSetDetector::new(10);

        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.0), false);
        assert_eq!(detector.check(0.001), true);

        for _ in 0..9 {
            assert_eq!(detector.check(0.0), false);
        }
        assert_eq!(detector.check(0.0), true);
    }
}