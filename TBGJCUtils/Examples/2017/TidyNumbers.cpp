//
//  TidyNumbers.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 4/8/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long powInterger(int b, int n)
{
    if(b == 0)
    {
        assert(0);
        return 1;
    }
    if(n == 0) return 1;
    if(n == 1) return b;
    unsigned long long result = b;
    for(int i = 1; i<n; ++i)
    {
        result = result * b;
    }
    return result;
}

unsigned long long findLastTidyNumber(unsigned long long N)
{
    if(N<10)
        return N;
    
    //Convert to array
    const int len = 20;
    int index = len - 1;
    int arr[len] = {0};
    unsigned long long temp = N;
    while(temp > 0)
    {
        int a = temp % 10;
        temp = temp/10;
        arr[index--] = a;
    }
    
    //Solve
    for(int i = len-1; i> index+1; --i)
    {
        if(arr[i] < 0)
        {
            arr[i] = 9;
            --arr[i-1];
        }
        if(arr[i] < arr[i-1])
        {
            --arr[i-1];
            for(int j = i; j<len; ++j)
            {
                arr[j] = 9;
            }
        }
        
//        if(currMax == 0)
//        {
//            return powInterger(10, (len-1) - (index+1)) - 1;
//        }
    }
    
    unsigned long long result = 0;
    unsigned long long gain = 1;
    for(int i = len - 1; i >= index + 1; --i)
    {
        if(arr[i] >= 0)
        {
            result += arr[i]*gain;
            gain *= 10;
        } else
        {
            break;
        }
    }
    return result;
}

#if 0
int main(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    for(int i = 0; i<numTest; ++i)
    {
        unsigned long long N;
        cin >> N;
        unsigned long long result = findLastTidyNumber(N);
        cout <<"Case #" <<i+1 <<": " <<result <<endl;
    }
}
#endif
