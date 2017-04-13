//
//  InfiniteHouseOfPancakes.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/26/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

//26/03/2017
//10h53 ->

//Strategy
//num interrupt + max pancakes should be smallest
//move pancakes from dinner who has max number, and only move < half of that number

//Just interrupt from the beginning
//Iterate until number of interruption = max pancakes / 2, then find the minimum

#include "InfiniteHouseOfPancakes.hpp"
#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include "TBGCJUtils.hpp"

using namespace std;
#define printf(...)

int getMin(vector<int> vec)
{
    int min = INT_MAX;
    for(int i = 0; i<vec.size(); ++i)
    {
        if(min > vec[i])
            min = vec[i];
    }
    return min;
}

int getMax(vector<int> vec)
{
    int max = INT_MIN;
    for(int i = 0; i<vec.size(); ++i)
    {
        if(vec[i] > max)
            max = vec[i];
    }
    return max;
}

vector<int> _collectedScores;
int _maxInteruption = 0;

//search all possible solution, but very slow
void solvePancakes2(vector<int> dinners, int numInterruption)
{
    cout<<__func__<<" "<<numInterruption<<endl;
    int maxCake = getMax(dinners);
    _collectedScores.push_back(maxCake + numInterruption);
    if(numInterruption >= _maxInteruption)
        return;
    for(int i = 0; i<dinners.size(); ++i)
    {
        int n = dinners[i];
        for(int j = 1; j < n; ++j)
        {
            vector<int> nextDinners = dinners;
            nextDinners[i] = n - j;
            nextDinners.push_back(j);
            solvePancakes2(nextDinners, numInterruption + 1);
        }
    }
}

int getNumMove(int numCake, int numCakeEveryMove)
{
    int numMove = ceilf( ((float)numCake)/numCakeEveryMove) - 1;
    return max(0, numMove);
}

void solvePancakes()
{
    printf("START\n");
    int numTest;
    cin >> numTest;
    printf("num test: %d\n", numTest);
    for(int i = 0; i<numTest; i++)
    {
        int numDinner;
        cin >> numDinner;
        vector<int> dinner = readLine();
        assert(dinner.size() == numDinner);
        printf("Num dinner: %d\n", numDinner);
        
        //Solve this case
#if 0
        cout<<" i= "<<i <<endl;
        _collectedScores.clear();
        _maxInteruption = getMax(dinner) - 1;
        solvePancakes2(dinner, 0);
        int min = getMin(_collectedScores);
#else
        int maxPancakes = getMax(dinner);
        vector<int> scores; //number of minute to finish the breakfast
        scores.push_back(maxPancakes);
        
        printf("max cake: %d\n", maxPancakes);
        for(int x = maxPancakes - 1; x>=1; --x)
        {
            int totalMove = 0;
            for(int j = 0; j<dinner.size(); ++j)
            {
                totalMove += getNumMove(dinner[j], x);
            }
            scores.push_back(x+totalMove);
        }
        
        /* Wrong strategy
        int numInterruption = 0;
        int maxInterruption = maxPancakes - 1;
        while(numInterruption <= maxInterruption)
        {
            int indexOfMax = -1;
            int maxVal = -1;
            for(int j = 0; j<dinner.size(); ++j)
            {
                int numCake = dinner[j];
                if(maxVal < numCake)
                {
                    maxVal = numCake;
                    indexOfMax = j;
                }
            }
            assert(indexOfMax >= 0);
            assert(maxVal >= 0);
            
            //Try to interrupt
            printf("lift pancake from %d\n", indexOfMax);
            ++numInterruption;
            dinner[indexOfMax] = (int) maxVal/2; //take half of pancakes from this dinner
            dinner.push_back(maxVal - dinner[indexOfMax]);
            //Calculate score
            scores.push_back(numInterruption + getMax(dinner));
            printf("Score: %d\n", scores.back());
        }
         */
        
        //Select the min value
        int min = getMin(scores);
#endif
        cout<<"Case #" <<i+1 <<": " <<min <<endl;
    }
}

int mainIHP(int argc, const char * argv[]) {
    solvePancakes();
    return 0;
}
