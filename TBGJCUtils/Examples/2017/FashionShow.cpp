//
//  FashionShow.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 4/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void initEmpty(char* stage, int N)
{
    for(int row = 0; row<N; ++row)
    {
        for(int col = 0; col<N; ++col)
        {
            stage[row*N + col] = '.';
        }
    }
}

void showStage(char* stage, int N)
{
    for(int row = 0; row<N; ++row)
    {
        for(int col = 0; col<N; ++col)
        {
            printf("%c", stage[row*N + col]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    for(int i = 0; i<numTest; ++i)
    {
        cout <<"Case #" <<i+1 <<": " <<endl;
        int N, M;
        cin >> N >> M;
        char* stage = (char*)malloc(N*N);
        initEmpty(stage, N);
        for(int j = 0; j<M; ++j)
        {
            char style;
            cin >> style;
            int row, col;
            cin >> row >> col;
            //adjust index
            row = row - 1;
            col = col - 1;
            stage[row*N + col] = style;
        }
        showStage(stage, N);
    }
}
