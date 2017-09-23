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

