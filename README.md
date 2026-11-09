# Interactive Flower Pot

I'm building an interactive flower pot using an ESP32. The idea is to have a small LCD screen built into the side of the pot with a little character displayed on it.

The character will react to what's happening around it using different sensors. For example, when the room gets dark, the character goes to sleep. If the soil gets too dry, 
it becomes unhappy or thirsty. Once the plant gets watered, its expression changes again.

### Current Features
- Uses an LDR sensor to detect when the room gets dark.
- Uses a soil moisture sensor to detect when the soil is dry.
- Displays different character expressions depending on sensor readings.
- Uses a 1.28-inch round LCD screen.

### Hardware
- ESP32
- 1.28-inch GC9A01 TFT LCD
- LDR light sensor
- Soil moisture sensor

### Software
- C++
- Arduino Framework
- PlatformIO
- Arduino_GFX

I'm still working on it and plan to add more expressions and interactions as I go. Eventually, I want the character to feel more like a little digital companion 
that lives in the flower pot.
