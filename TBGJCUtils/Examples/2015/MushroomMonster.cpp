//
//  MushroomMonster.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 4/14/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define printf(...)

//Small: mi max = 100
//Large: mi max = 10000

void solveMushroomMonster(vector<int> miVec)
{
#define PERIOD 10.0 //sec
    int N = miVec.size();
    //First method
    long long y = 0;
    for(int i = 1; i<N; ++i)
    {
        y += max(0, miVec[i-1] - miVec[i]);
    }
    
    //Second method
    long long x = 0;
    double speed = 0;
    while(1)
    {
        int i = 1;
        x = 0;
        for(; i<N; ++i)
        {
            if(miVec[i-1] - nearbyint(PERIOD * speed) > miVec[i])
            {
                speed = (miVec[i-1] - miVec[i])/PERIOD;
                printf("Adjust speed: %f\n", speed);
                break;
            } else
            {
                int canEat = nearbyint(speed*PERIOD);
                int realEat = min(miVec[i-1], canEat);
                printf("eat: %d\n", realEat);
                x += realEat;
            }
        }
        if(i>=N)
            break;
    }
    cout <<y <<" " <<x <<endl;
}

int main(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    for(int i = 0; i<numTest; ++i)
    {
        int N;
        cin >> N;
        vector<int> miVec;
        for(int j=0; j<N; ++j)
        {
            int mi;
            cin >> mi;
            miVec.push_back(mi);
        }
        cout <<"Case #" <<i+1 <<": ";
        solveMushroomMonster(miVec);
    }
}
