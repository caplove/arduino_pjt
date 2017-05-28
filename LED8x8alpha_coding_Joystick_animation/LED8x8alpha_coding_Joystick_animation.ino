//2017.5.28일 19시 작업 파일임
//animation led matrix
//http://xantorohara.github.io/led-matrix-editor/#0010107c10100000|0000003c00000000|006c38fe386c0000|00060c1830600000|60660c1830660600|00003c003c000000|000000365c000000|0000008244281000|6030180c18306000|060c1830180c0600|6030181818306000|060c1818180c0600|7818181818187800|1e18181818181e00|7018180c18187000|0e18183018180e00|0606000000000000|0018180018180000|0c18180018180000|060c0c0c00000000|180018183c3c1800|1800183860663c00|003c421a3a221c00|fc66a6143c663c00|103c403804781000|6c6cfe6cfe6c6c00|383838fe7c381000|10387cfe38383800|10307efe7e301000|1018fcfefc181000|fefe7c7c38381000|1038387c7cfefe00|061e7efe7e1e0600|c0f0fcfefcf0c000|7c92aa82aa827c00|7ceed6fed6fe7c00|10387cfefeee4400|10387cfe7c381000|381054fe54381000|38107cfe7c381000|00387c7c7c380000|ffc7838383c7ffff|0038444444380000|ffc7bbbbbbc7ffff|0c12129ca0c0f000|38444438107c1000|060e0c0808281800|066eecc88898f000|105438ee38541000|1038541054381000|6666006666666600|002844fe44280000|00000000286c6c00|006030180c060000|0000000060303000|0000000c18181800|fe8282c66c381000
#include <Arduino.h>

#include "LedControl.h"


// 핀배열 선언하기
const int DIN_PIN = 22;
const int CLK_PIN = 26;
const int CS_PIN = 24;
const int NO_Display = 4;
const uint64_t IMAGES[] PROGMEM= {
	0x0010107c10100000,
	0x0000003c00000000,
	0x006c38fe386c0000,
	0x00060c1830600000,
	0x60660c1830660600,
	0x00003c003c000000,
	0x000000365c000000,
	0x0000008244281000,
	0x6030180c18306000,
	0x060c1830180c0600,
	0x6030181818306000,
	0x060c1818180c0600,
	0x7818181818187800,
	0x1e18181818181e00,
	0x7018180c18187000,
	0x0e18183018180e00,
	0x0606000000000000,
	0x0018180018180000,
	0x0c18180018180000,
	0x060c0c0c00000000,
	0x180018183c3c1800,
	0x1800183860663c00,
	0x003c421a3a221c00,
	0xfc66a6143c663c00,
	0x103c403804781000,
	0x6c6cfe6cfe6c6c00,
	0x383838fe7c381000,
	0x10387cfe38383800,
	0x10307efe7e301000,
	0x1018fcfefc181000,
	0xfefe7c7c38381000,
	0x1038387c7cfefe00,
	0x061e7efe7e1e0600,
	0xc0f0fcfefcf0c000,
	0x7c92aa82aa827c00,
	0x7ceed6fed6fe7c00,
	0x10387cfefeee4400,
	0x10387cfe7c381000,
	0x381054fe54381000,
	0x38107cfe7c381000,
	0x00387c7c7c380000,
	0xffc7838383c7ffff,
	0x0038444444380000,
	0xffc7bbbbbbc7ffff,
	0x0c12129ca0c0f000,
	0x38444438107c1000,
	0x060e0c0808281800,
	0x066eecc88898f000,
	0x105438ee38541000,
	0x1038541054381000,
	0x6666006666666600,
	0x002844fe44280000,
	0x00000000286c6c00,
	0x006030180c060000,
	0x0000000060303000,
	0x0000000c18181800,
	0xfe8282c66c381000
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;	//IMAGES_LEN은 8x8 짜리 Image 의 개수이다.


LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, NO_Display);   // Pins: DIN,CLK,CS,디스플레이개수
unsigned long delayTime = 1000;   // ms 단위
														  // 디스플레이 초기화 과정
void setup()
{
	lc.shutdown(0, false);  // Wake up displays
	lc.shutdown(1, false);
	lc.shutdown(2, false);  // Wake up displays
	lc.shutdown(3, false);  // Wake up displays

	lc.setIntensity(0, 0);  // Set intensity levels
	lc.setIntensity(1, 1);  // Set intensity levels
	lc.setIntensity(2, 2);  // Set intensity levels
	lc.setIntensity(3, 3);  // Set intensity levels

	lc.clearDisplay(0);     // Clear Displays
	lc.clearDisplay(1);
	lc.clearDisplay(2);     // Clear Displays
	lc.clearDisplay(3);     // Clear Displays

	Serial.begin(115200);
}


// 첫번째 디스플레이로 표현하는 프레임별로 제작하기

void displayImage(uint64_t image) {
	for (int i = 0; i < 8; i++)	{
		byte row = (image >> i * 8) & 0xFF;
		for (int j = 0; j < 8; j++)	{
			lc.setLed(0, i, j, bitRead(row, j));
		}
	}
}

int i = 0;

void loop()
{
	uint64_t image;
	memcpy_P(&image, &IMAGES[i], 8);

	displayImage(image);
	if (++i >=IMAGES_LEN)
	{
		i = 0;
	}
	delay(1000);
}
