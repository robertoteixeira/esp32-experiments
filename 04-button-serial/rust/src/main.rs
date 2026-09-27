use esp_idf_svc::hal::{
    delay::FreeRtos, gpio::{PinDriver, Pull}, peripherals::Peripherals,
};

fn main() {
    esp_idf_svc::sys::link_patches();

    let peripherals = Peripherals::take().unwrap();

    let mut led = PinDriver::output(peripherals.pins.gpio23).unwrap();
    let button = PinDriver::input(peripherals.pins.gpio22, Pull::Up).unwrap();

    loop {
        if button.is_low() {
            led.set_high().unwrap();
            println!("Button pressed");
        } else {
            led.set_low().unwrap();
            println!("Button released");
        }

        FreeRtos::delay_ms(10);
    }
}