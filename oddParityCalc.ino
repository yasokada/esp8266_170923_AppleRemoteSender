#include "oddParityCalc.h"

/*
 * v0.1 Sep. 23, 2017
 *   - add calc_oddParity()
 */

int calc_oddParity(long target)
{
    unsigned long temp = target;
    int cnt = 0;
    for(int loop=0; loop<32; loop++) {
        cnt += ((temp & 0x01) > 0);
        temp >>= 1;
    }
    if (cnt % 2 == 0) {
        return 1;
    } else {
        return 0;   
    }
}


