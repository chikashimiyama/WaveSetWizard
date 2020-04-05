use ring_buffer::RingBuffer;
use std::vec::Vec;

struct AudioRingBuffer {
    data : Vec<RingBuffer::<f32>>,
    threshold : usize
}

impl AudioRingBuffer {
    fn new(channels : usize, capacity : usize, threshold : usize) -> Self {
        let mut data = Vec::new();
        for _i in 0..channels {
            let ring_buf = RingBuffer::<f32>::with_capacity(capacity as usize);
            data.push(ring_buf);
        }
        AudioRingBuffer{
            data,
            threshold
        }
    }
}
