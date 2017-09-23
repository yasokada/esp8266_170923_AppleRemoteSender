#include "oddParityCalc.h"

/*
 * Sep. 23, 2017
 *    Checked with Apple TV (A1469) with OS version 7.2.2 (8015)
 */

#define BIT_VENDOR (11)
#define BIT_COMMAND_PAGE (5)
#define BIT_DEVICE_ID (8)
#define BIT_CONTROL_COMMAND (7)
#define BIT_ODD_PARITY (1)

static const int kRemoteID = 0x79; // arbitrary set
static void oscWrite(int pinNo, int num);

static long get32bitToSend(int ctrlcmd)
{
  int vendor = 0x43F; // apple
  int cmdpage = 0x0e; // page for up, down, left, right, etc
  int devid = 0x79; // device id
  uint32_t snd;

  snd = vendor;

  snd <<= BIT_COMMAND_PAGE;
  snd |= cmdpage;

  snd <<= BIT_DEVICE_ID;
  snd |= devid;

  snd <<= BIT_CONTROL_COMMAND;
  snd |= ctrlcmd;

  snd <<= BIT_ODD_PARITY;

  //snd = 0x101 << 1; // debug

  snd |= calc_oddParity(snd);
  return snd;
}

static void sendKey(int pinNo, byte key)
{
  long temp = get32bitToSend(key);

  // send preamble
  oscWrite(pinNo, 9000);
  delayMicroseconds(4500); // was originally 3040

  byte bit = 0;
  // send data
  for(int idx = 0; idx < 32; idx++) {
    bit = (temp & 0x01); //was originally "bit = temp % 2;"
    temp = temp >> 1;
    // space
    oscWrite(pinNo, 560);

    // data
    if (bit == 0) {
      delayMicroseconds(560); // was originally 565
    } else {
      delayMicroseconds(1690);
    }
  }
  // end of data header
  oscWrite(pinNo, 560);
}

static void oscWrite(int pinNo, int num)
{
  /*
   Sends a 38kHz carrier pulse
   */

   for(int loop=0; loop < (num / 26) - 1; loop++) {
    digitalWrite(pinNo, HIGH);
    delayMicroseconds(13);
    digitalWrite(pinNo, LOW);
    delayMicroseconds(13);
   }
}

void APPTV_setup(int pinNo)
{
  pinMode(pinNo, OUTPUT);
  digitalWrite(pinNo, LOW);
}

void APPTV_SendKey(int pinNo, int key)
{
  sendKey(pinNo, key);  
}


