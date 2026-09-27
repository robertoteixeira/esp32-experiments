use esp_idf_svc::hal::{
    delay::FreeRtos, gpio::{PinDriver, Pull}, peripherals::Peripherals,
};
use std::time::{Duration, Instant};

fn main() {
    esp_idf_svc::sys::link_patches();

    let peripherals = Peripherals::take().unwrap();

    let mut led = PinDriver::output(peripherals.pins.gpio23).unwrap();
    let button = PinDriver::input(peripherals.pins.gpio22, Pull::Up).unwrap();

    let debounce_delay = Duration::from_millis(50);

    let mut last_reading = false;
    let mut button_pressed = false;
    let mut last_change = Instant::now();

    loop {
        let reading = button.is_low();

        if reading != last_reading {
            last_change = Instant::now();
        }

        if last_change.elapsed() >= debounce_delay 
            && reading != button_pressed 
        {
            button_pressed = reading;

            if button_pressed {
                led.set_high().unwrap();
                println!("Button pressed");
            } else {
                led.set_low().unwrap();
                println!("Button released");
            }            
        }

        last_reading = reading;

        FreeRtos::delay_ms(10);
    }
}