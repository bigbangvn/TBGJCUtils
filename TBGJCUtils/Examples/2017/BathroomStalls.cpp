//
//  BathroomStalls.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 4/8/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

typedef struct SpaceGroup
{
    uint64_t min;
    uint64_t max;
    uint64_t numMin;
    uint64_t numMax;
} SpaceGroup;

void solveBathroomStall3(uint64_t N, uint64_t K)
{
    SpaceGroup spaceGroups[65];
    spaceGroups[0].min = spaceGroups[0].max = N;
    spaceGroups[0].numMin = 0;
    spaceGroups[0].numMax = 1;

    int depth = 0;
    uint64_t numNode = 1;
    uint64_t totalNode = numNode;
    while(totalNode < K)
    {
        ++depth;
        numNode *= 2;
        
        SpaceGroup* prevGroup = &spaceGroups[depth-1];
        SpaceGroup* currentGroup = &spaceGroups[depth];
        currentGroup->min =  prevGroup->min == 0 ? 0 : (prevGroup->min - 1)/2;
        uint64_t temp = (prevGroup->max - 1)/2;
        currentGroup->max = prevGroup->max == 0 ? 0 : (prevGroup->max - 1 - temp);
        
        uint64_t Remain = N - totalNode;
        if(currentGroup->min == currentGroup->max)
        {
            currentGroup->numMin = 0;
            currentGroup->numMax = Remain / currentGroup->max;
            assert(currentGroup->numMax * currentGroup->max == Remain);
        } else
        {
            currentGroup->numMax = (Remain - currentGroup->min * numNode) / (currentGroup->max - currentGroup->min);
            currentGroup->numMin = numNode - currentGroup->numMax;
        }
        
        totalNode += numNode;
        
        
        if(totalNode >= K)
            break;
    }
    uint64_t remain = K - (totalNode - numNode);
    SpaceGroup* sp = &spaceGroups[depth];
    //printf("D = %d, R = %llu, %llu %llu %llu %llu\n", depth, remain, sp->min, sp->numMin, sp->max, sp->numMax);
    
    uint64_t finalSpace;
    if(remain <= sp->numMax)
    {
        finalSpace = sp->max;
    } else
    {
        finalSpace = sp->min;
    }
    
    uint64_t LS = (finalSpace - 1)/2;
    uint64_t RS = finalSpace - LS - 1;
    cout <<RS <<" " <<LS <<endl;
}

//Wrong
void solveBathroomStall2(uint64_t N, uint64_t K)
{
    int depth = 0;
    uint64_t numNode = 1;
    uint64_t totalNode = 0;
    uint64_t widthArr[100] = {0};
    widthArr[depth] = numNode;
    while(1)
    {
        totalNode += numNode;
        if(totalNode >= K)
            break;
        ++depth;
        numNode *= 2;
        widthArr[depth] = numNode;
    }
    uint64_t remain = K - (totalNode - numNode); //the last people is at node 'remain' in depth of the B-tree
    assert(remain != 0);
    char* decision = (char*) calloc(depth, 1);
    
    uint64_t nodePos;
    if(remain <= widthArr[depth]/2)
    {
        nodePos = remain*2 - 1;
    } else
    {
        nodePos = (remain - widthArr[depth]/2) * 2;
    }
    
    for(int i = depth; i>0; --i)
    {
        if(nodePos%2 == 1)
        {
            decision[i-1] = 'R';
        } else
        {
            decision[i-1] = 'L';
        }
        nodePos = ceil( ((double)nodePos)/2.0);
    }
    
    uint64_t space = N;
    for(int i = 0; i<depth; ++i)
    {
        uint64_t LS = (space - 1)/2;
        uint64_t RS = space - 1 - LS;
        if(decision[i] == 'R')
        {
            space = RS;
        } else
        {
            space = LS;
        }
    }
    //printf("Final space: %llu\n", space);
    uint64_t LS = (space - 1)/2;
    uint64_t RS = space - LS - 1;
    cout <<RS <<" " <<LS <<endl;
}

//O(n) complexity
void solveBathroomStall(uint64_t N, uint64_t K)
{
    vector<uint64_t> spaces;
    spaces.push_back(N);
    for(uint64_t i = 0; i<K-1; ++i)
    {
        //printf("i = %llu\n", i);
        uint64_t topVal = spaces.back();
        spaces.pop_back();
        uint64_t LS = (topVal - 1)/2;
        uint64_t RS = topVal - LS - 1;
        
        if(RS != 0)
        {
            int64_t j = 0; //int64_t is enough
            for(; j < spaces.size() - 1; ++j)
            {
                if(spaces[j] >= RS)
                    break;
            }
            spaces.insert(spaces.begin() + j, RS);
            if(LS != 0)
                spaces.insert(spaces.begin() + j, LS);
        }
    }
    uint64_t topVal = spaces.back();
    uint64_t LS = (topVal - 1)/2;
    uint64_t RS = topVal - LS - 1;
    cout <<RS <<" " <<LS <<endl;
}

#if 0
int main(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    for(int i = 0; i<numTest; ++i)
    {
        uint64_t N, K;
        cin >> N >> K;
        cout <<"Case #" <<i+1 <<": ";
        solveBathroomStall3(N, K);
    }
}
#endif
