/*2017. Visual Studio로 Github repo만들고 
vMicro로 complie 하기위해 existing ino 파일 열고 에디팅
솔루션 탐색기 - 폴더보기 상태에서 
LED8x8 우측키 누르면, 커밋옵션 보임.
끝나고, Github로 commit 함 */

#include "LedControl.h"


// 핀배열 선언하기
 
LedControl lc=LedControl(22,26,24,4);   // Pins: DIN,CLK,CS,디스플레이개수

// 프레임 사이의 지연 시간
unsigned long delayTime=1000;   // ms 단위
 
// Put values in arrays
// 어레이에 넣는 이미지들 HNY는 해피 뉴 이어 입니다.

// 순번을 확인해야 합니다. 1a 는 첫번째 디스플레이(1)의 첫번째 이미지(a) 입니다.

byte HNY1a[] = {0x32,0x4a,0x7b,0x2,0x7c,0x1c,0x30,0x3e}; //알
byte HNY1b[] ={0x0,0xfa,0x52,0x52,0x53,0x52,0x52,0xfa};  //파
byte HNY1c[] ={0xfc,0x4,0x4,0xfc,0x4,0x14,0x10,0xff};    //코
byte HNY1d[] ={0xfa,0x82,0x82,0xfa,0x0,0x7c,0x82,0x7c};  //딩
byte HNY1e[] ={0x7e,0x40,0x7e,0x8,0xff,0x3c,0x42,0x3c};  //동
byte HNY1f[] ={0x32,0x4a,0x4a,0x4b,0x4a,0x4a,0x4a,0x32}; //아
byte HNY1g[] ={0x2,0xfa,0xa,0xfa,0x82,0x82,0xfa,0x2};    //리
byte HNY1h[] ={0x0,0x0,0x0,0x18,0x18,0x4,0x0,0x0};       //알파1
byte HNY1i[] ={0x0,0x2,0x1c,0x24,0x24,0x1c,0x2,0x0};     //알파2
byte HNY1j[] ={0x0,0x72,0x8c,0x88,0x88,0x8c,0x8a,0x71};  //알파3

// 디스플레이 초기화 과정
void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
}
 
 
// 첫번째 디스플레이로 표현하는 프레임별로 제작하기

void sHNY1a()
{
  for (int i = 0; i < 8; i++)    //한 줄씩 8X8이므로 8줄
  {
    lc.setRow(0,i,HNY1a[i]);
  }
}
 
void sHNY1b()
{
  for (int i = 0; i < 8; i++)    //한 줄씩 8X8이므로 8줄
  {
    lc.setRow(0,i,HNY1b[i]);
  }
}

void sHNY1c()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1c[i]);
  }
}

  void sHNY1d()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1d[i]);
  }
}

  void sHNY1e()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1e[i]);
  }
}

  void sHNY1f()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1f[i]);
  }
}


  void sHNY1g()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1g[i]);
  }
}



  void sHNY1h()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1h[i]);
  }
}


  void sHNY1i()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1i[i]);
  }
}


  void sHNY1j()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,HNY1j[i]);
  }
}
// 반복해서 디스플레이에 표현하기
  
void loop()
{
// a 프레임을 양쪽 디스플레이에 표현하기
    sHNY1a(); delay(delayTime);
//    sHNY2a(); delay(delayTime);
// b frame
    sHNY1b();    delay(delayTime);
// c frame
    sHNY1c();    delay(delayTime);
 // d frame
    sHNY1d();    delay(delayTime);
// e frame
    sHNY1e();    delay(delayTime);
// f frame
    sHNY1f();    delay(delayTime);
// g frame
    sHNY1g();    delay(delayTime);
// h frame
    sHNY1h();    delay(delayTime);   
// i frame
    sHNY1i();    delay(delayTime);
// j frame
    sHNY1j();    delay(delayTime);  
}

