use esp_idf_svc::hal::{
    delay::FreeRtos,
    gpio::PinDriver,
    peripherals::Peripherals,
};

fn main() {
    esp_idf_svc::sys::link_patches();

    let peripherals = Peripherals::take().unwrap();

    let mut led = PinDriver::output(peripherals.pins.gpio23).unwrap();

    loop {
        led.set_high().unwrap();
        FreeRtos::delay_ms(200);

        led.set_low().unwrap();
        FreeRtos::delay_ms(200);
    }
}