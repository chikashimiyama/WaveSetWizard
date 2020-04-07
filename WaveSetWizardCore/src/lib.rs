mod buffer;
mod processor;

use buffer::audio_buffer::AudioBuffer;

#[no_mangle]
pub unsafe extern fn prepare_to_play( channels: usize, block_size : usize)
{
}


#[no_mangle]
pub unsafe extern fn process( buffer : *mut f32, channels: usize, block_size : usize)
{
    let audio_buffer = AudioBuffer::new_from_pointer(channels, block_size, buffer);
}
