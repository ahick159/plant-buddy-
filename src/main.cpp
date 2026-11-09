
#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include "plant_sprites.h"

// LCD setup
Arduino_DataBus *bus = new Arduino_ESP32SPI(
    27, 5, 18, 23, GFX_NOT_DEFINED
);

Arduino_GFX *gfx = new Arduino_GC9A01(
    bus, 26, 0, true
);

// Moisture senso
#define MOISTURE_THRESHOLD 3500
// Light sensor
#define LIGHT_SENSOR 34
// Light thresholds
#define DARK_THRESHOLD 700

// Track current character
int currentState = -1;

void setup() {
    Serial.begin(115200);
    analogReadResolution(12);
    analogSetPinAttenuation(35, ADC_11db);

    gfx->begin();
    gfx->fillScreen(0x0000);
}

void loop() {

    int moistureValue = analogRead(35);
    int lightValue = analogRead(LIGHT_SENSOR);

    Serial.print("Moisture: ");
    Serial.println(moistureValue);

    Serial.print("Light: ");
    Serial.println(lightValue);

    int newState;

    if (lightValue < DARK_THRESHOLD) {
        newState = 2; // Sleeping
    } else if (moistureValue>MOISTURE_THRESHOLD){
        newState = 1;//thirsty
        
    } else {
        newState = 0; // Happy
    }

    // Only redraw when the character changes
    if (newState != currentState) {
        gfx->fillScreen(0x0000);

        if (newState == 2) {
            gfx->draw16bitRGBBitmap(
                23, 17, plant_sleeping,
                SPRITE_WIDTH, SPRITE_HEIGHT
            );
        } 
        else if (newState == 1) {
            gfx->draw16bitRGBBitmap(
                10, 10, plant_thirsty,
                SPRITE_WIDTH, SPRITE_HEIGHT
            );
        }
        else {
            gfx->draw16bitRGBBitmap(
                10, 10, plant_happy,
                SPRITE_WIDTH, SPRITE_HEIGHT
            );
        }

        currentState = newState;
    }

    delay(500
    );
}
