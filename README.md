# Environmental-quality-with-ARDUINO

Project Title: Environmental Quality Monitoring Smart Device


https://www.tinkercad.com/things/4KI5ZKc374K-epic-duup-vihelmo/editel?sharecode=YTe4pgajR7rVzaNfDzwNZV1Urb0Y04PxRt1usr0P_rw

Overview

This Arduino project creates a device that monitors several important environmental factors within a space:

Temperature: Measures ambient temperature using a temperature sensor.
Gas: Detects potentially harmful gases or air quality changes using a gas sensor.
Light: Measures the amount of light present using a photoresistor.
Features

LCD Display: Provides real-time readouts of temperature, gas levels, and light intensity. The display cycles through these readings.
NeoPixel LED Strip: Offers visual feedback with colors representing:
Temperature ranges (blue for cold, green for moderate, red for hot).
Gas sensor levels (green for safe, yellow for moderate, red for high, blinking red for dangerous)
Light levels (purple-ish for low light, white for bright light)
Buzzer Alarm: Triggers an audible alarm if gas levels exceed a dangerous threshold or if the temperature goes above a set limit.
Hardware Components

Arduino Board (specify the type you're using)
Temperature sensor (specify the type)
Gas sensor (specify the type)
Photoresistor
NeoPixel LED Strip (4 LEDs)
LCD (16x2)
Buzzer
Button
Resistors (as needed)
Breadboard and connecting wires
Code Explanation

The code includes necessary libraries for the NeoPixel strip, LCD, and any sensor-specific libraries.
Variables are defined for pins, sensor readings, display modes, and LED control.
The setup function initializes the LCD, buzzer, button, and NeoPixel strip.
The loop function continuously:
Reads sensor values.
Cycles through display modes on the LCD.
Controls the NeoPixel LEDs based on sensor readings.
Triggers the buzzer alarm if necessary.
How to Use

Gather the required hardware components.
Assemble the circuit according to a wiring diagram (you'll want to provide this).
Upload the code to your Arduino board.
Place the device in the desired monitoring location.
Additional Notes

Consider adding calibration routines for the sensors.
You could expand the project to include data logging or sending readings to a web interface.