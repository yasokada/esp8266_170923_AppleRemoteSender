#ifndef APPLE_REMOTE_SENDER_H
#define APPLE_REMOTE_SENDER_H

/*
 * Apple Remote Sender in C implementation
 * 
 * Original work is done by Casey Callendrello
 * https://github.com/squeed/AppleRemoteSender
 * Copyright (c) 2008, Casey Callendrello
 * c1 at caseyc.net // caseyc.net
 * 
 * Following modifications was done by Yasuhiko OKADA (Sep. 23, 2017)
 * - change from CPP implementation to C implementation
 *   (in order to work on ESP8266 + Arduino IDE v1.6.6)
 * - add function APPTV_SendKey() to send a specified key
 * - add function get32bitToSend() to calculate the 32bit
 * - modify values of KEY_XXX (e.g. KEY_UP for 0x05) to use with get32bitToSend()
 * - modify timing to send 32bit key
 *   (checked with ESP8266)
 *   
 * License: GPL v3
 */

#define KEY_MENU (0x01)
#define KEY_PLAY (0x02)
#define KEY_RIGHT (0x03)
#define KEY_LEFT (0x04)
#define KEY_UP (0x05)
#define KEY_DOWN (0x06)

void APPTV_setup(int pinNo);
void APPTV_SendKey(int pinNo, int key);

#endif
