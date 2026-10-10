/*
 * Experimental target for the RP2040-FPV flight controller.
 *
 * Pin assignments are taken from the RP2040-FPV schematic and Zephyr
 * bring-up application.  Gyro alignment and voltage scaling must be calibrated
 * on hardware before flight.
 */

#pragma once

#define FC_TARGET_MCU RP2040

#define BOARD_NAME RP2040FPV
#define MANUFACTURER_ID CSTM
#define TARGET_BOARD_IDENTIFIER "R2FP"
#define USBD_PRODUCT_STRING "Betaflight RP2040-FPV"

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270

// SX1280 integrated ExpressLRS receiver on SPI0.
#define USE_RX_SPI
#define USE_RX_EXPRESSLRS
#define USE_RX_SX1280
#define RX_SPI_DEFAULT_PROTOCOL RX_SPI_EXPRESSLRS
#define DEFAULT_RX_FEATURE FEATURE_RX_SPI
// SX1280 air-rate table index 3 is LoRa 250 Hz.
#define DEFAULT_RX_EXPRESSLRS_RATE_INDEX 3

#define SPI0_SDI_PIN PA0
#define SPI0_SCK_PIN PA2
#define SPI0_SDO_PIN PA3

#define RX_SPI_INSTANCE SPI0
#define RX_SPI_CS_PIN PA1
#define RX_SPI_EXTI_PIN PA18
#define RX_SPI_BIND_PIN PA4
// Blue LED: fast blink while binding, solid when valid ELRS packets arrive.
#define RX_SPI_LED_PIN PA21
#define RX_EXPRESSLRS_SPI_BUSY_PIN PA19
#define RX_EXPRESSLRS_SPI_RESET_PIN PA20
#define RX_SPI_EXPRESSLRS_BUSY_PIN PA19
#define RX_SPI_EXPRESSLRS_RESET_PIN PA20

// BMI270 on its dedicated SPI1 bus.  INT1 is GPIO5; INT2 remains available on
// GPIO7 if the driver later needs a configurable interrupt output.
#define SPI1_SDI_PIN PA8
#define SPI1_SCK_PIN PA10
#define SPI1_SDO_PIN PA11
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_CS_PIN PA9
#define GYRO_1_EXTI_PIN PA5
#define GYRO_1_ALIGN CW0_DEG

#define MOTOR1_PIN PA12
#define MOTOR2_PIN PA13
#define MOTOR3_PIN PA14
#define MOTOR4_PIN PA15

#define UART0_TX_PIN NONE
#define UART0_RX_PIN NONE
#define UART1_TX_PIN PA24
#define UART1_RX_PIN PA25

#define I2C0_SDA_PIN PA28
#define I2C0_SCL_PIN PA29
#define I2C1_SDA_PIN NONE
#define I2C1_SCL_PIN NONE

#define ADC_EXTERNAL1_PIN PA26
#define ADC_VBAT_PIN PA27
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

// Green is the general flight-controller status LED. Blue is owned by the
// integrated SPI receiver above; red remains available for later use.
#define LED0_PIN PA22
#define LED1_PIN NONE
#define LED2_PIN NONE

#define DEFAULT_DSHOT_BURST DSHOT_DMAR_AUTO
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_OFF
#define DEFAULT_MOTOR_PROTOCOL MOTOR_PROTOCOL_DSHOT300

// Conservative first-flight defaults for the M0+ performance envelope.
#define DEFAULT_GYRO_TO_USE GYRO_CONFIG_USE_GYRO_1
