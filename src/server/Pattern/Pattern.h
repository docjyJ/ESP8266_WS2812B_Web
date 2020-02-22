#ifndef ADAFRUIT_NEOPIXEL_H
#define ADAFRUIT_NEOPIXEL_H

#ifdef ARDUINO
  #if (ARDUINO >= 100)
  #include <Arduino.h>
  #else
  #include <WProgram.h>
  #include <pins_arduino.h>
  #endif
#endif

#ifdef TARGET_LPC1768
  #include <Arduino.h>
#endif

// RGB NeoPixel permutations; white and red offsets are always same
// Offset:         W        R        G        B
#define NEO_RGB  ((0<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B
#define NEO_RBG  ((0<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G
#define NEO_GRB  ((1<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B
#define NEO_GBR  ((2<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R
#define NEO_BRG  ((1<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G
#define NEO_BGR  ((2<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R

// RGBW NeoPixel permutations; all 4 offsets are distinct
// Offset:         W          R          G          B
#define NEO_WRGB ((0<<6) | (1<<4) | (2<<2) | (3)) ///< Transmit as W,R,G,B
#define NEO_WRBG ((0<<6) | (1<<4) | (3<<2) | (2)) ///< Transmit as W,R,B,G
#define NEO_WGRB ((0<<6) | (2<<4) | (1<<2) | (3)) ///< Transmit as W,G,R,B
#define NEO_WGBR ((0<<6) | (3<<4) | (1<<2) | (2)) ///< Transmit as W,G,B,R
#define NEO_WBRG ((0<<6) | (2<<4) | (3<<2) | (1)) ///< Transmit as W,B,R,G
#define NEO_WBGR ((0<<6) | (3<<4) | (2<<2) | (1)) ///< Transmit as W,B,G,R

#define NEO_RWGB ((1<<6) | (0<<4) | (2<<2) | (3)) ///< Transmit as R,W,G,B
#define NEO_RWBG ((1<<6) | (0<<4) | (3<<2) | (2)) ///< Transmit as R,W,B,G
#define NEO_RGWB ((2<<6) | (0<<4) | (1<<2) | (3)) ///< Transmit as R,G,W,B
#define NEO_RGBW ((3<<6) | (0<<4) | (1<<2) | (2)) ///< Transmit as R,G,B,W
#define NEO_RBWG ((2<<6) | (0<<4) | (3<<2) | (1)) ///< Transmit as R,B,W,G
#define NEO_RBGW ((3<<6) | (0<<4) | (2<<2) | (1)) ///< Transmit as R,B,G,W

#define NEO_GWRB ((1<<6) | (2<<4) | (0<<2) | (3)) ///< Transmit as G,W,R,B
#define NEO_GWBR ((1<<6) | (3<<4) | (0<<2) | (2)) ///< Transmit as G,W,B,R
#define NEO_GRWB ((2<<6) | (1<<4) | (0<<2) | (3)) ///< Transmit as G,R,W,B
#define NEO_GRBW ((3<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B,W
#define NEO_GBWR ((2<<6) | (3<<4) | (0<<2) | (1)) ///< Transmit as G,B,W,R
#define NEO_GBRW ((3<<6) | (2<<4) | (0<<2) | (1)) ///< Transmit as G,B,R,W

#define NEO_BWRG ((1<<6) | (2<<4) | (3<<2) | (0)) ///< Transmit as B,W,R,G
#define NEO_BWGR ((1<<6) | (3<<4) | (2<<2) | (0)) ///< Transmit as B,W,G,R
#define NEO_BRWG ((2<<6) | (1<<4) | (3<<2) | (0)) ///< Transmit as B,R,W,G
#define NEO_BRGW ((3<<6) | (1<<4) | (2<<2) | (0)) ///< Transmit as B,R,G,W
#define NEO_BGWR ((2<<6) | (3<<4) | (1<<2) | (0)) ///< Transmit as B,G,W,R
#define NEO_BGRW ((3<<6) | (2<<4) | (1<<2) | (0)) ///< Transmit as B,G,R,W


#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission
#ifndef __AVR_ATtiny85__
#define NEO_KHZ400 0x0100 ///< 400 KHz data transmission
#endif


#ifdef NEO_KHZ400
typedef uint16_t neoPixelType; ///< 3rd arg to Adafruit_NeoPixel constructor
#else
typedef uint8_t  neoPixelType; ///< 3rd arg to Adafruit_NeoPixel constructor
#endif

static const uint8_t PROGMEM _NeoPixelSineTable[256] = {
  128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,
  176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
  218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,
  245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
  255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,
  245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
  218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,
  176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
  128,124,121,118,115,112,109,106,103,100, 97, 93, 90, 88, 85, 82,
   79, 76, 73, 70, 67, 65, 62, 59, 57, 54, 52, 49, 47, 44, 42, 40,
   37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 17, 15, 14, 12, 11,
   10,  9,  7,  6,  5,  5,  4,  3,  2,  2,  1,  1,  1,  0,  0,  0,
    0,  0,  0,  0,  1,  1,  1,  2,  2,  3,  4,  5,  5,  6,  7,  9,
   10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35,
   37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76,
   79, 82, 85, 88, 90, 93, 97,100,103,106,109,112,115,118,121,124};


static const uint8_t PROGMEM _NeoPixelGammaTable[256] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,
    3,  3,  4,  4,  4,  4,  5,  5,  5,  5,  5,  6,  6,  6,  6,  7,
    7,  7,  8,  8,  8,  9,  9,  9, 10, 10, 10, 11, 11, 11, 12, 12,
   13, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20,
   20, 21, 21, 22, 22, 23, 24, 24, 25, 25, 26, 27, 27, 28, 29, 29,
   30, 31, 31, 32, 33, 34, 34, 35, 36, 37, 38, 38, 39, 40, 41, 42,
   42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
   58, 59, 60, 61, 62, 63, 64, 65, 66, 68, 69, 70, 71, 72, 73, 75,
   76, 77, 78, 80, 81, 82, 84, 85, 86, 88, 89, 90, 92, 93, 94, 96,
   97, 99,100,102,103,105,106,108,109,111,112,114,115,117,119,120,
  122,124,125,127,129,130,132,134,136,137,139,141,143,145,146,148,
  150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,
  182,184,186,188,191,193,195,197,199,202,204,206,209,211,213,215,
  218,220,223,225,227,230,232,235,237,240,242,245,247,250,252,255};

/*! 
    @brief  Class that stores state and functions for interacting with
            Adafruit NeoPixels and compatible devices.
*/
class Adafruit_NeoPixel {

 public:

  // Constructor: number of LEDs, pin number, LED type
  Adafruit_NeoPixel(uint16_t n, uint16_t pin=6,
    neoPixelType type=NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel(void);
  ~Adafruit_NeoPixel();

  void              begin(void);
  void              show(void);
  void              setPin(uint16_t p);
  void              setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
  void              setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b,
                      uint8_t w);
  void              setPixelColor(uint16_t n, uint32_t c);
  void              fill(uint32_t c=0, uint16_t first=0, uint16_t count=0);
  void              setBrightness(uint8_t);
  void              clear(void);
  void              updateLength(uint16_t n);
  void              updateType(neoPixelType t);
  
  bool              canShow(void) const { return (micros()-endTime) >= 300L; }
  
  uint8_t          *getPixels(void) const { return pixels; };
  uint8_t           getBrightness(void) const;
  
  int16_t           getPin(void) const { return pin; };
  
  uint16_t          numPixels(void) const { return numLEDs; }
  uint32_t          getPixelColor(uint16_t n) const;
  
  static uint8_t    sine8(uint8_t x) {
    return pgm_read_byte(&_NeoPixelSineTable[x]); // 0-255 in, 0-255 out
  }
  
  static uint8_t    gamma8(uint8_t x) {
    return pgm_read_byte(&_NeoPixelGammaTable[x]); // 0-255 in, 0-255 out
  }
  
  static uint32_t   Color(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }
  
  static uint32_t   Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }
  static uint32_t   ColorHSV(uint16_t hue, uint8_t sat=255, uint8_t val=255);
  
  static uint32_t   gamma32(uint32_t x);

  void              pong(uint8_t r, uint8_t g, uint8_t b, bool direction, uint8_t speed);      // This is the Pong Animation
  void              rainbow(uint8_t r, uint8_t g, uint8_t b, uint8_t direction, uint8_t speed);   // This is the rainbow Anima..

 protected:

#ifdef NEO_KHZ400  // If 400 KHz NeoPixel support enabled...
  bool              is800KHz;   ///< true if 800 KHz pixels
#endif
  bool              begun;      ///< true if begin() previously called
  uint16_t          numLEDs;    ///< Number of RGB LEDs in strip
  uint16_t          numBytes;   ///< Size of 'pixels' buffer below
  int16_t           pin;        ///< Output pin number (-1 if not yet set)
  uint8_t           brightness; ///< Strip brightness 0-255 (stored as +1)
  uint8_t          *pixels;     ///< Holds LED color values (3 or 4 bytes each)
  uint8_t           rOffset;    ///< Red index within each 3- or 4-byte pixel
  uint8_t           gOffset;    ///< Index of green byte
  uint8_t           bOffset;    ///< Index of blue byte
  uint8_t           wOffset;    ///< Index of white (==rOffset if no white)
  uint32_t          endTime;    ///< Latch timing reference
#ifdef __AVR__
  volatile uint8_t *port;       ///< Output PORT register
  uint8_t           pinMask;    ///< Output PORT bitmask
#endif
#if defined(ARDUINO_ARCH_STM32) || defined(ARDUINO_ARCH_ARDUINO_CORE_STM32)
  GPIO_TypeDef *gpioPort;       ///< Output GPIO PORT
  uint32_t gpioPin;             ///< Output GPIO PIN
#endif
};

#endif // ADAFRUIT_NEOPIXEL_H
