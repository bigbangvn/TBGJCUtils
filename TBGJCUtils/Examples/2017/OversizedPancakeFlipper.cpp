//
//  OversizedPancakeFlipper.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 4/8/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

//8h28 -> 10h AM

#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;
const char* _originalS = NULL;
int _currentTestCase = -1;
#define printf(...)

void flip(char* S, int pos, int range)
{
    assert(pos + range - 1 < strlen(S));
    for(int i = 0; i<range; ++i)
    {
        if(S[pos + i] == '-')
            S[pos + i] = '+';
        else
            S[pos + i] = '-';
    }
}
bool checkCompleted(const char* S)
{
    size_t n = strlen(S);
    for(size_t i = 0; i<n; ++i)
    {
        if(S[i] == '-')
            return false;
    }
    return true;
}

//Wrong
bool solveOPF_bruteForce(const char* S, int len, int K, int numFlip)
{
    printf("S = %s\n", S);
    if(checkCompleted(S))
    {
        cout << "Finish: " << numFlip <<endl;
        return true;
    }
    if(numFlip > 0 && strcmp(S, _originalS) == 0)
    {
        printf("Stop this branch\n");
        return false;
    }
    char* copiedS = (char*)calloc(len+1, 1);
    for(int i = 0; i<= len-K; ++i)
    {
        strcpy(copiedS, S);
        flip(copiedS, i, K);
        if(solveOPF_bruteForce(copiedS, len, K, numFlip + 1))
        {
            break; //found
        }
    }
    return false;
}

int findFirstBlank(const char* S, int len)
{
    for(int i = 0; i<len; ++i)
    {
        if(S[i] == '-')
            return i;
    }
    return -1;
}

void solveOPF(char* S, int len, int K, int numFlip)
{
    int firstBlankPos = findFirstBlank(S, len);
    if(firstBlankPos < 0)
    {
        cout << "Case #" <<_currentTestCase <<": " <<numFlip <<endl;
        return;
    } else
    {
        if(firstBlankPos + K - 1 > len - 1)
        {
            cout <<"Case #" <<_currentTestCase <<": IMPOSSIBLE"<<endl;
            return;
        }
    }
    flip(S, firstBlankPos, K);
    solveOPF(S, len, K, numFlip + 1);
}

#if 0
int main(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    for(int i = 0; i<numTest; ++i)
    {
        _currentTestCase = i+1;
        string S;
        cin >> S;
        int K;
        cin >> K;
        printf("S = %s, k = %d\n", S.c_str(), K);
        _originalS = S.c_str();
        
        char* copiedS = (char*)calloc(S.length()+1, 1);
        strcpy(copiedS, _originalS);
        solveOPF(copiedS, (int)S.length(), K, 0);
        
    }
    return 0;
}
#endif
