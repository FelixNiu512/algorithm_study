//
//  ReverseString.h
//  algorithms
//
//  Created by Constant Cody on 1/2/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#ifndef ReverseString_h
#define ReverseString_h

/**
    字符串反转（oc）
 */
void reverseString(NSString *str) {
    if (!str || !str.length) {
        return ;
    }
    NSMutableString *reverStr = str.mutableCopy;
    for (NSInteger i = 0; i < (str.length+1)/2; i++) {
        [reverStr replaceCharactersInRange:NSMakeRange(i, 1) withString:[str substringWithRange:NSMakeRange(str.length-i-1, 1)]];
        [reverStr replaceCharactersInRange:NSMakeRange(str.length-i-1, 1) withString:[str substringWithRange:NSMakeRange(i, 1)]];
    }
    NSLog(@"%@ => %@", str, reverStr);
    
    // C
    char ch[100];
    memcpy(ch, [str cStringUsingEncoding:NSUTF8StringEncoding], str.length);
    // 字符串头尾指针
    char *begin = ch;
    char *end = ch + strlen(ch) - 1;
    while (begin < end) {
        char temp = *begin;
        *(begin++) = *end;
        *(end--) = temp;
    }
    NSLog(@"%@ => %s", str, ch);
}

#endif /* ReverseString_h */
