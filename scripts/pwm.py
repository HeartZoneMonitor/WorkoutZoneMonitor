import RPi.GPIO as GPIO
import time

# Define GPIO pin
GPIO_PIN = 12

# Setup GPIO
GPIO.setmode(GPIO.BCM)  # Use BCM numbering
GPIO.setup(GPIO_PIN, GPIO.OUT)

# Initialize PWM on GPIO 12 at 440 Hz
pwm = GPIO.PWM(GPIO_PIN, 440)  # 440 Hz for an A4 note
pwm.start(50)  # 50% duty cycle for a balanced square wave

try:
    while True:
        time.sleep(1)  # Keep running indefinitely
except KeyboardInterrupt:
    print("\nStopping PWM output.")
    pwm.stop()
    GPIO.cleanup()