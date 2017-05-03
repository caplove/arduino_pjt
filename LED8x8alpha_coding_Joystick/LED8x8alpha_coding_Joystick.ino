// VS의 vMicro로 수정함. VS와 GIT 연동 확인용임.
// Vmicro > Open Existing arduino pjt 
// 보기(V) > 솔루션 탐색기 
#include "LedControl.h"


// 핀배열 선언하기

 
LedControl lc=LedControl(22,26,24,1);   // Pins: DIN,CLK,CS,디스플레이개수

// 프레임 사이의 지연 시간
unsigned long delayTime=800;   // ms 단위

const int SW_pin = 53; // digital pin connected to switch output
const int X_pin = 13; // analog pin connected to X output
const int Y_pin = 14; // analog pin connected to Y output
 
// Put values in arrays
// 어레이에 넣는 이미지들 Array는 해피 뉴 이어 입니다.

// 순번을 확인해야 합니다. 1a 는 첫번째 디스플레이(1)의 첫번째 이미지(a) 입니다.

byte Array1a[] ={0x32,0x4a,0x7b,0x2,0x7c,0x1c,0x30,0x3e};  //알
byte Array1b[] ={0x0,0xfa,0x52,0x52,0x53,0x52,0x52,0xfa};  //파
byte Array1c[] ={0xfc,0x4,0x4,0xfc,0x4,0x14,0x10,0xff};    //코
byte Array1d[] ={0xfa,0x82,0x82,0xfa,0x0,0x7c,0x82,0x7c};  //딩
byte Array1e[] ={0x7e,0x40,0x7e,0x8,0xff,0x3c,0x42,0x3c};  //동
byte Array1f[] ={0x32,0x4a,0x4a,0x4b,0x4a,0x4a,0x4a,0x32}; //아
byte Array1g[] ={0x2,0xfa,0xa,0xfa,0x82,0x82,0xfa,0x2};    //리
byte Array1h[] ={0x3c,0x42,0xa5,0x81,0xa5,0x99,0x42,0x3c}; //smile
byte Array1i[] ={0x3c,0x42,0xa5,0x81,0x99,0xa5,0xa5,0x7e}; //찡그림
byte Array1j[] ={0x0,0x72,0x8c,0x88,0x88,0x8c,0x8a,0x71};  //알파3

// 디스플레이 초기화 과정
void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  
}
 
 
// 첫번째 디스플레이로 표현하는 프레임별로 제작하기

void alpha_coding1a()
{
  for (int i = 0; i < 8; i++)    //한 줄씩 8X8이므로 8줄
  {
    lc.setRow(0,i,Array1a[i]);
  }
}
 
void alpha_coding1b()
{
  for (int i = 0; i < 8; i++)    //한 줄씩 8X8이므로 8줄
  {
    lc.setRow(0,i,Array1b[i]);
  }
}

void alpha_coding1c()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1c[i]);
  }
}

  void alpha_coding1d()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1d[i]);
  }
}

  void alpha_coding1e()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1e[i]);
  }
}

  void alpha_coding1f()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1f[i]);
  }
}


  void alpha_coding1g()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1g[i]);
  }
}



  void alpha_coding1h()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1h[i]);
  }
}


  void alpha_coding1i()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1i[i]);
  }
}


  void alpha_coding1j()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,Array1j[i]);
  }
}
// 반복해서 디스플레이에 표현하기
  
void loop()
{
// a 프레임을 양쪽 디스플레이에 표현하기
   alpha_coding1a();    delay(delayTime); joystick_status();
   
//    alpha_coding2a(); delay(delayTime);
// b frame
    alpha_coding1b();    delay(delayTime);joystick_status();
// c frame
    alpha_coding1c();    delay(delayTime);joystick_status();
 // d frame
    alpha_coding1d();    delay(delayTime);joystick_status();
// e frame
    alpha_coding1e();    delay(delayTime);joystick_status();
// f frame
    alpha_coding1f();    delay(delayTime);joystick_status();
// g frame
    alpha_coding1g();    delay(delayTime);joystick_status();
// h frame
    alpha_coding1h();    delay(delayTime); joystick_status();  
// i frame
    alpha_coding1i();    delay(delayTime);joystick_status();
// j frame
    alpha_coding1j();    delay(delayTime);joystick_status();
}

void joystick_status()
{
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
}

