mod processor;

use processor::engine::Engine;

#[no_mangle]
pub extern fn create( channels: usize, block_size : usize) -> *mut Engine
{
    Box::into_raw(Box::new(Engine::new(channels, block_size)))
}

#[no_mangle]
pub unsafe extern fn destroy( engine: *mut Engine) {
    assert!(!engine.is_null());
    Box::from_raw(engine);
}

#[no_mangle]
pub unsafe extern fn process( engine: &mut Engine, buffer : *mut f32, channels: usize, block_size : usize)
{
    engine.process(buffer, channels, block_size);
}

#[no_mangle]
pub extern fn set_distortion(engine: &mut Engine, value: f32) {
    engine.set_distortion(value)
}
