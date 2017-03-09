//
//  T9Spelling.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include "T9Spelling.hpp"
#include "TBGCJUtils.hpp"

void t9Spelling()
{
    //Init the map
    const int numChar = 'z' - 'a' + 1;
    printf("Num character (except space): %d\n", numChar);
    char* map[numChar];
    for(int i = 0; i<numChar; ++i)
    {
        map[i] = (char*)malloc( 2 * sizeof(char*));
    }
    map['a' - 'a'][0] = '2';
    map['a' - 'a'][1] = 1;
    map['b' - 'a'][0] = '2';
    map['b' - 'a'][1] = 2;
    map['c' - 'a'][0] = '2';
    map['c' - 'a'][1] = 3;
    
    map['d' - 'a'][0] = '3';
    map['d' - 'a'][1] = 1;
    map['e' - 'a'][0] = '3';
    map['e' - 'a'][1] = 2;
    map['f' - 'a'][0] = '3';
    map['f' - 'a'][1] = 3;
    
    map['g' - 'a'][0] = '4';
    map['g' - 'a'][1] = 1;
    map['h' - 'a'][0] = '4';
    map['h' - 'a'][1] = 2;
    map['i' - 'a'][0] = '4';
    map['i' - 'a'][1] = 3;
    
    map['j' - 'a'][0] = '5';
    map['j' - 'a'][1] = 1;
    map['k' - 'a'][0] = '5';
    map['k' - 'a'][1] = 2;
    map['l' - 'a'][0] = '5';
    map['l' - 'a'][1] = 3;
    
    map['m' - 'a'][0] = '6';
    map['m' - 'a'][1] = 1;
    map['n' - 'a'][0] = '6';
    map['n' - 'a'][1] = 2;
    map['o' - 'a'][0] = '6';
    map['o' - 'a'][1] = 3;
    
    map['p' - 'a'][0] = '7';
    map['p' - 'a'][1] = 1;
    map['q' - 'a'][0] = '7';
    map['q' - 'a'][1] = 2;
    map['r' - 'a'][0] = '7';
    map['r' - 'a'][1] = 3;
    map['s' - 'a'][0] = '7';
    map['s' - 'a'][1] = 4;
    
    map['t' - 'a'][0] = '8';
    map['t' - 'a'][1] = 1;
    map['u' - 'a'][0] = '8';
    map['u' - 'a'][1] = 2;
    map['v' - 'a'][0] = '8';
    map['v' - 'a'][1] = 3;
    
    map['w' - 'a'][0] = '9';
    map['w' - 'a'][1] = 1;
    map['x' - 'a'][0] = '9';
    map['x' - 'a'][1] = 2;
    map['y' - 'a'][0] = '9';
    map['y' - 'a'][1] = 3;
    map['z' - 'a'][0] = '9';
    map['z' - 'a'][1] = 4;
    const int MAX_MSG_LEN = 15;
    const int MAX_T9_MSG_LEN = MAX_MSG_LEN * 4;
    
    int numCase;
    cin >> numCase;
    printf("Num test case: %d\n", numCase);
    for(int i = 0; i<numCase; ++i)
    {
        string lineStr = readLineString();
        const char* charArr = lineStr.c_str();
        int n = lineStr.length();
        char crrChar = -1;
        
        char crrKeyboardChar = -1;
        char prevKeyboardChar = -1;
        
        char result[MAX_T9_MSG_LEN];
        int resultIdx = 0;
        for(int j = 0; j<n; ++j)
        {
            crrChar = charArr[j];
            if(isspace(crrChar))
            {
                result[resultIdx++] = '0';
            } else
            {
                char* mapVal = map[crrChar - 'a'];
                crrKeyboardChar = mapVal[0];
                
                if(crrKeyboardChar >= 0 && crrKeyboardChar == prevKeyboardChar) //if consecutive characters are on the same button -> space
                {
                    //Add a space to indicate a pause
                    result[resultIdx++] = ' ';
                }
                prevKeyboardChar = crrKeyboardChar;
                
                int repeat = mapVal[1];
                for(int k = 0; k<repeat; ++k)
                {
                    result[resultIdx++] = crrKeyboardChar;
                }
            }
        }
        result[resultIdx++] = '\0';
        assert(resultIdx < MAX_T9_MSG_LEN);
        cout<<"Case #" << i+1 <<": " << result <<endl;
    }
    
    //Free memory
    for(int i = 0; i<numChar; ++i) {
        free(map[i]);
    }
}
