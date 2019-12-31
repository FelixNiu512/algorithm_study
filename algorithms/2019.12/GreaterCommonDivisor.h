//
//  GreaterCommonDivisor.h
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#ifndef GreaterCommonDivisor_h
#define GreaterCommonDivisor_h

/**
    辗转相除法（while循环）：1. 判断b是否为0，是则返回a；否则令r=a%b，a=b，b=r，重复步骤1.
 */
int gcd1(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**
   辗转相除法（递归）：1. 判断b是否为0，是则返回a；否则令r=a%b，a=b，b=r，重复步骤1.
*/
int gcd2(int a, int b) {
    if (b != 0) {
        return gcd2(b, a%b);
    }
    return a;
}

/**
    更相减损法（等值算法）：不约2的情况（简洁）
 */
int gcd3(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

/**
    更相减损法（等值算法）：约2的情况（麻烦）
 */
int gcd4(int a, int b) {
    int index = 0;
    while (a%2 == 0 && b%2 == 0) {
        a /= 2;
        b /= 2;
        index++;
    }
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return index > 0 ? a*index*2 : a;
}

#endif /* GreaterCommonDivisor_h */
