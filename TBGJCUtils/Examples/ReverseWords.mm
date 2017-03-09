//
//  ReverseWords.m
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#import "ReverseWords.h"
#include <iostream>
#include "TBGCJUtils.hpp"
using namespace std;

@implementation ReverseWords

@end

void reverseWords2()
{
    int numCase;
    cin >> numCase;
    assert(numCase > 0);
    printf("Num case: %d\n", numCase);
    for(int i = 0; i<numCase; ++i) {
        string lineStr = readLineString();
        const char* charArr = lineStr.c_str();
        printf("Line: %s\n", charArr);
        NSString* str = [NSString stringWithUTF8String:charArr];
        NSArray* strArr = [str componentsSeparatedByString:@" "];
        NSString* result = [[strArr reverseObjectEnumerator].allObjects componentsJoinedByString:@" "];
        cout << "Case #" << i+1 <<": " << result.UTF8String <<endl;
    }
}
