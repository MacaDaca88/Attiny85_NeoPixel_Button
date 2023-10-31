
#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN 1

#define PIXEL_PIN 0

#define PIXEL_COUNT 8

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


bool oldState = HIGH;

int mode = 0;
int sensorPin = A1;

int sensorValue = 0;
int button = 500;
void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {
  bool newState = digitalRead(BUTTON_PIN);
  bool WhiteLight = digitalRead(BUTTON_PIN);

  sensorValue = analogRead(sensorPin);

  int brightness = map(sensorValue, 1024, 0, 0, 255);
  strip.setBrightness(brightness);

  if ((BUTTON_PIN == HIGH) && (BUTTON_PIN >= button)) {
    colorWipe(strip.Color(255, 255, 255), 50);  // Black
  }

  if ((newState == LOW) && (oldState == HIGH)) {
    delay(20);
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {
      if (++mode > 8) mode = 0;
      switch (mode) {
        case 0:
          colorWipe(strip.Color(0, 0, 0), 50);  // Black
          break;
        case 1:
          colorWipe(strip.Color(255, 0, 0), 50);  // Red
          break;
        case 2:
          colorWipe(strip.Color(0, 255, 0), 50);  // Green
          break;
        case 3:
          colorWipe(strip.Color(0, 0, 255), 50);  // Blue
          break;
        case 4:
          theaterChase(strip.Color(127, 127, 127), 50);  // White
          break;
        case 5:
          theaterChase(strip.Color(127, 0, 0), 50);  // Red
          break;
        case 6:
          theaterChase(strip.Color(0, 0, 127), 50);  // Blue
          break;
        case 7:
          rainbow(10);
          break;
        case 8:
          theaterChaseRainbow(50);
          break;
      }
    }
  }

  oldState = newState;
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
    }
  }
}

void rainbow(int wait) {

  for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {

      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;
  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        int hue = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue));
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
      firstPixelHue += 65536 / 90;
    }
  }
}
