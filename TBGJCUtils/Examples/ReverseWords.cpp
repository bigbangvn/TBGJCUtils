//
//  ReverseWords.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include "ReverseWords.hpp"
#include <iostream>
#include "TBGCJUtils.hpp"

using namespace std;

void reverseWords()
{
    int numCase;
    cin >> numCase;
    assert(numCase > 0);
    printf("Num case: %d\n", numCase);
    for(int i = 0; i<numCase; ++i) {
        string lineStr = readLineString();
        const char* charArr = lineStr.c_str();
        printf("Line: %s\n", charArr);
        int numChar = lineStr.length();
        char* resultArr = (char*) malloc( (numChar + 1) * sizeof(char));
        resultArr[numChar] = '\0';
        int resultIdx = 0;
        
        int rightPos = numChar - 1;
        int leftPos = 0;
        int j = rightPos;
        
        //skip space at last
        while (j >= 0 && isspace(charArr[j])) {
            --j;
        }
        
        for(; j>=0; --j) {
            if(isspace(charArr[j])) {
                leftPos = j+1;
                if(leftPos <= rightPos)
                {
                    //Not the first word -> add space
                    if(resultIdx > 0) {
                        resultArr[resultIdx++] = ' ';
                    }
                    for(int k = leftPos; k <= rightPos; ++k) {
                        assert(resultIdx < numChar);
                        resultArr[resultIdx++] = charArr[k];
                    }
                }
                rightPos = j-1;
            }
        }
        
        if(rightPos >= 0) {
            leftPos = j+1;
            //Not the first word -> add space
            if(resultIdx > 0) {
                resultArr[resultIdx++] = ' ';
            }
            for(int k = leftPos; k <= rightPos; ++k) {
                assert(resultIdx < numChar);
                resultArr[resultIdx++] = charArr[k];
            }
        }
        cout << "Case #" << i+1 <<": " << resultArr <<endl;
        free(resultArr);
    }
}
