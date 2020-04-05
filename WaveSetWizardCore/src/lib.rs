extern crate rand;

use rand::Rng;
mod buffer;

#[no_mangle]
pub unsafe extern fn process( buffer : *mut f32, channels: u16, block_size : u16)
{
    let mut rng = rand::thread_rng();
    for i in 0..channels * block_size
    {
        *buffer.offset(i as isize) = rng.gen::<f32>() * 2.0 - 1.0;
    }
}
