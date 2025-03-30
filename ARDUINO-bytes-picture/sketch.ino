#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // Lebar layar OLED
#define SCREEN_HEIGHT 64  // Tinggi layar OLED
#define OLED_RESET   -1   // Reset pin (-1 jika tidak digunakan)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// -------------------------------------------------------------------------
// Contoh bitmap 120x64 untuk masing-masing gambar
// Isi array berikut dengan data bitmap sebenarnya (harus sesuai dengan image2cpp)
// -------------------------------------------------------------------------

// Bitmap kecil untuk simbol hati ❤
const unsigned char heart_bitmap[] PROGMEM = {
  0b00001110, 0b01110000,
  0b00011111, 0b11111000,
  0b00111111, 0b11111100,
  0b01111111, 0b11111110,
  0b01111111, 0b11111110,
  0b00111111, 0b11111100,
  0b00011111, 0b11111000,
  0b00001111, 0b11110000,
  0b00000111, 0b11100000,
  0b00000011, 0b11000000,
};

const unsigned char epd_bitmap_WhatsApp_Image_2024_09_24_at_19 [] PROGMEM = {
	0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf1, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 
	0x07, 0xf8, 0x00, 0x00, 0x03, 0x37, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0xfc, 0xc0, 0x00, 0x1f, 
	0x7e, 0x00, 0x00, 0x00, 0x78, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xef, 
	0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0e, 0xe7, 0x00, 
	0x00, 0x40, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0x4f, 0x88, 0x00, 
	0x08, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x03, 0x4f, 0x88, 0x07, 0xe8, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0x89, 0x7f, 0xf8, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0x89, 0xff, 0xf8, 0x00, 0x7f, 
	0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0x89, 0xff, 0xf8, 0x00, 0xff, 0xff, 
	0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0x89, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x88, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0xff, 0x00, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xe0, 0x20, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x0f, 0xff, 0x02, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x73, 0xfe, 0x00, 
	0xfe, 0x00, 0x0e, 0x1f, 0xff, 0x02, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0x00, 0x78, 
	0x00, 0x03, 0x7f, 0xff, 0x02, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x70, 0x00, 
	0x03, 0xff, 0xef, 0x8a, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xf8, 0x00, 0x03, 
	0xff, 0xef, 0xca, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xef, 
	0xef, 0xca, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xef, 0xef, 
	0xca, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x09, 0xef, 0xef, 0xdb, 
	0xff, 0x80, 0x00, 0x1f, 0xff, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xff, 0xef, 0xcf, 0xff, 
	0xc7, 0x81, 0x5e, 0x00, 0xe0, 0x0e, 0x00, 0x70, 0x00, 0xc0, 0x1f, 0xff, 0xef, 0xcf, 0xff, 0x8f, 
	0xff, 0x18, 0x00, 0x40, 0x6c, 0xc0, 0x70, 0xff, 0xf0, 0x17, 0xff, 0xef, 0xdf, 0xff, 0xcf, 0xfb, 
	0xf0, 0x00, 0x03, 0x7c, 0xf0, 0x77, 0xff, 0xc0, 0x03, 0xff, 0xc7, 0xdf, 0xff, 0x8f, 0xe3, 0xb0, 
	0x00, 0x01, 0xfc, 0xd0, 0x3f, 0xff, 0x80, 0x00, 0x43, 0x87, 0xff, 0xff, 0x87, 0x83, 0x20, 0x00, 
	0x1b, 0xfc, 0xc0, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x07, 0x82, 0xe0, 0x00, 0x1f, 
	0xfc, 0x71, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x01, 0x03, 0xa0, 0x00, 0x03, 0xfc, 
	0x00, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x06, 0x03, 0x80, 0x00, 0x00, 0x10, 0x00, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x03, 0x80, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x83, 0xf0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x7e, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0x00, 0xe0, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x00, 0xf0, 0x00, 0x86, 0x00, 0x00, 0x00, 0x06, 0x12, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x02, 0x00, 0xf8, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x00, 0xfb, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xd8, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
	0xfe, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7e, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3f, 0xc0, 
	0x00, 0x00, 0x00, 0x00, 0xe0, 0x38, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x1f, 0x7f, 0xf8, 0x00, 
	0x00, 0x00, 0x00, 0x20, 0x18, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x0e, 0x60, 0x00, 0x17, 0xff, 0xd8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x40, 
	0x00, 0xf8, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x60, 0x01, 
	0xf0, 0x00, 0x00, 0x00, 0x1d, 0x40, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x3e, 0x01, 0xf0, 
	0x00, 0x00, 0x00, 0x1d, 0xc0, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x3f, 0x80, 0xf0, 0x00, 
	0x00, 0x00, 0x1d, 0x80, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x70, 0x00, 0x00, 
	0x00, 0x1d, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0x82, 0x70, 0x00, 0x00, 0x00, 
	0x1d, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x83, 0x60, 0x00, 0x00, 0x00, 0x1d, 
	0x80, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0xe1, 0xf0, 0x00, 0x00, 0x00, 0x1d, 0x80, 
	0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x70, 0x00, 0x00, 0x00, 0x15, 0x80, 0x00
};

const unsigned char epd_bitmap_IMG_20240617_WA0060_11zon [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
	0x00, 0x00, 0x00, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x81, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x3f, 0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 
	0xfc, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x1f, 0x00, 0x00, 0x06, 0x01, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x1e, 0x00, 0x00, 0x03, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0x00, 0x0f, 0x03, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x80, 0x38, 0x00, 0x1f, 0x80, 0x9f, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xc0, 0x38, 0x00, 0x02, 0x00, 0x1f, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xc0, 0x38, 0x0f, 0xfe, 0x00, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x80, 0x18, 0x0f, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x38, 0x02, 0x10, 0x20, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x38, 
	0x01, 0x00, 0x00, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x30, 0x00, 
	0xf0, 0x00, 0xb2, 0x0f, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x3e, 
	0x00, 0x31, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x09, 0x80, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xb9, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3d, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x0d, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x02, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x4f, 0xff, 0xff, 0xf7, 0xff, 0x00, 0x00, 0x00, 0x01, 0xdf, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0x5f, 0xff, 0xff, 0xff, 0xf8, 0x0e, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xfe, 0x5f, 0xff, 0xff, 0xf9, 0xdc, 0x7f, 0xf8, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0x1f, 0xff, 0xff, 0xfc, 0xc7, 0x79, 0xff, 0x18, 0x00, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x9f, 
	0xff, 0xff, 0xf0, 0xc7, 0xe7, 0xcf, 0xd8, 0x08, 0xef, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xaf, 0xff, 
	0xff, 0xff, 0xff, 0x39, 0x8f, 0xc0, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 
	0xdf, 0xff, 0xf8, 0x07, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x43, 0xff, 0x9f, 0xff, 
	0xef, 0xfe, 0x22, 0x00, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x03, 0x80, 0x00, 0xff, 0xef, 0xff, 0xcf, 
	0xff, 0xb2, 0x00, 0x10, 0x02, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf3, 0xff, 0x8f, 0xff, 
	0xc0, 0x00, 0x10, 0x00, 0x3f, 0xfc, 0xff, 0xff, 0x00, 0x01, 0xff, 0xf8, 0xfe, 0x7f, 0xff, 0xf0, 
	0x01, 0x02, 0x00, 0x1e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xf0, 0x07, 
	0x80, 0x00, 0x1f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xff, 0x1f, 0xe7, 0xff, 0xc0, 0x07, 0xbf, 
	0x01, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0xff, 0xc7, 0x39, 0xef, 0x00, 0x07, 0xfe, 0x7b, 
	0xc7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xf9, 0xfc, 0x00, 0x07, 0xd8, 0x00, 0x0e, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xfb, 0xfb, 0xf0, 0x00, 0x04, 0xc0, 0x00, 0x3c, 0x00
};


// 'IMG-20240711-WA0024_11zon', 120x64px
const unsigned char epd_bitmap_IMG_20240711_WA0024_11zon [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x02, 0x0f, 0x80, 0x7f, 0x80, 
	0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x01, 0xe9, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xc1, 0x3f, 0xff, 0xff, 0xff, 0xcf, 
	0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xf8, 0xff, 0xff, 0x00, 0x03, 0xfc, 0x00, 
	0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x28, 0x7f, 0xff, 0xff, 0x80, 0x00, 0xfe, 0x00, 0x1f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x60, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x00, 0x77, 0xf0, 0xbf, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x80, 0x27, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xb4, 0x00, 0x00, 0x00, 0xff, 0xff, 
	0xe0, 0x07, 0x00, 0x03, 0x87, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x00, 0x1f, 0xf0, 0x0f, 0xff, 0x07, 
	0xff, 0xc0, 0x3f, 0x00, 0xc3, 0xff, 0xf8, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x0f, 0xfe, 0xc0, 0x00, 
	0x40, 0x38, 0x1f, 0xe3, 0x08, 0xe0, 0xff, 0xfe, 0x00, 0x01, 0x00, 0x07, 0xff, 0x00, 0x3f, 0xe0, 
	0x00, 0x3f, 0xff, 0xf8, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf8, 0x02, 
	0x39, 0x3c, 0xf8, 0x3f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x20, 0x7f, 
	0x80, 0x00, 0x1c, 0x7e, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x10, 0x30, 0x8c, 
	0x10, 0xfc, 0x38, 0x01, 0x81, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x38, 0x1c, 0x1c, 
	0x07, 0x00, 0x07, 0x80, 0xff, 0xff, 0x07, 0xff, 0xe3, 0xff, 0xf8, 0x03, 0xfc, 0x6f, 0xf9, 0xcf, 
	0xc7, 0x80, 0x00, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x1c, 0x1f, 0xfe, 0xff, 0xf8, 
	0x30, 0x01, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xef, 0xec, 0xff, 0x00, 0x70, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x63, 0xf0, 0x30, 0x01, 0xe0, 0x00, 
	0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x19, 0x60, 0x00, 0x1f, 0x80, 0x00, 0x1f, 
	0xff, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x06, 0x0e, 0x00, 0x7f, 0x00, 0x00, 0x07, 0xff, 
	0xc0, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x03, 0xff, 0x00, 0x00, 0x00, 0xff, 0xfe, 
	0x03, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 
	0xff, 0x80, 0x00, 0x00, 0x00, 0x3f, 0xfe, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 
	0x00, 0x1f, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x3e, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 
	0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe7, 0xff, 
	0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xdf, 0xff, 0xff, 
	0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xbf, 0xff, 0xff, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0xf7, 0xe7, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xe3, 0xef, 0xef, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0xef, 0xdf, 0xdf, 0xcf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1f, 0xdf, 0x3f, 0xfe, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0x7f, 0xfc, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
	0xfe, 0xff, 0xfc, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfc, 
	0xff, 0xf9, 0x82, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xf9, 0xff, 
	0xf9, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf3, 0xff, 0xf8, 
	0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xe7, 0xff, 0xf9, 0xfc, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xfe, 0x3f
};

// Pointer array untuk menyimpan banyak gambar
const unsigned char* images[] = { epd_bitmap_WhatsApp_Image_2024_09_24_at_19, epd_bitmap_IMG_20240617_WA0060_11zon, epd_bitmap_IMG_20240711_WA0024_11zon };
const int numImages = sizeof(images) / sizeof(images[0]);

// -------------------------------------------------------------------------
// Setup: Inisialisasi OLED, countdown, dan tampilkan gambar secara bergantian
// -------------------------------------------------------------------------
void setup() {
  Wire.begin();      // Inisialisasi I2C
  delay(100);        // Waktu tambahan untuk inisialisasi OLED

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Ganti alamat jika perlu
    while (true);   // Loop forever jika inisialisasi gagal
  }
  
  // Countdown sebelum menampilkan gambar
  display.clearDisplay();
  display.setTextSize(2);       // Ukuran teks countdown
  display.setTextColor(SSD1306_WHITE);
  for (int angka = 3; angka > 0; angka--) {
    display.clearDisplay();     // Bersihkan layar setiap iterasi
    display.setCursor(10, 0);
    display.print("");
    display.setCursor(60, 30);
    display.print(angka);
    display.display();          // Perbarui tampilan
    delay(1000);                // Tunda 1 detik
  }
  
  // Tampilkan setiap gambar dengan delay 2 detik
  for (int i = 0; i < numImages; i++) {
    display.clearDisplay();
    // Menggambar bitmap di tengah layar dengan offset x = (128 - 120)/2 = 4, y = 0
    display.drawBitmap(4, 0, images[i], 120, 64, SSD1306_WHITE);
    display.display();  // Perbarui tampilan untuk menunjukkan gambar
    delay(2000);        // Tunda 2 detik sebelum gambar berikutnya
  }

  // Tampilkan pesan teks di akhir
  display.clearDisplay();
  display.setTextSize(1);       // Ukuran teks
  display.setTextColor(SSD1306_WHITE);
  
  // Tampilkan teks pesan
  display.setCursor(0, 0);  // Koordinat baris pertama (x=0, y=0)
  display.println("hi azaria");
  display.println("i really like u,");
  display.println("everything about u,");
  display.println("i'm proud to have u");
  
  // Gambar simbol hati di sudut kanan bawah
  display.drawBitmap(100, 48, heart_bitmap, 16, 10, SSD1306_WHITE);
 
  display.display();  // Perbarui layar untuk menampilkan hasil
}



void loop() {
  // Jika ingin gambar bergantian terus-menerus, Anda bisa memasukkan
  // loop pengulangan gambar di sini.
}
