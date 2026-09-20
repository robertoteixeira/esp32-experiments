use esp_idf_svc::hal::adc::oneshot::AdcDriver;
use esp_idf_svc::hal::adc::{
    attenuation::DB_12,
    oneshot::{config::AdcChannelConfig, AdcChannelDriver},
    Resolution,
};
use esp_idf_svc::hal::ledc::LedcDriver;
use esp_idf_svc::hal::peripherals::Peripherals;
use esp_idf_svc::hal::{
    ledc::{config::TimerConfig, LedcTimerDriver, Resolution as PwmResolution},
    units::Hertz,
};
use std::{thread, time::Duration};

fn main() {
    esp_idf_svc::sys::link_patches();

    let peripherals = Peripherals::take().unwrap();
    let adc = AdcDriver::new(peripherals.adc1).unwrap();

    let adc_config = AdcChannelConfig {
        attenuation: DB_12,
        resolution: Resolution::Resolution12Bit,
        ..Default::default()
    };

    let mut potentiometer =
        AdcChannelDriver::new(&adc, peripherals.pins.gpio34, &adc_config).unwrap();

    let timer = LedcTimerDriver::new(
        peripherals.ledc.timer0,
        &TimerConfig::new()
            .frequency(Hertz(5_000))
            .resolution(PwmResolution::Bits8),
    )
    .unwrap();

    let mut led =
        LedcDriver::new(peripherals.ledc.channel0, timer, peripherals.pins.gpio23).unwrap();

    loop {
        let reading = potentiometer.read_raw().unwrap();
        let brightness = u32::from(reading) * 255 / 4095;
        led.set_duty(brightness).unwrap();

        thread::sleep(Duration::from_millis(10));
    }
}
