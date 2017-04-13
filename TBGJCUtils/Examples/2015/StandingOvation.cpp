//
//  StandingOvation.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/26/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

//26/03/2017
//10h02 -> 10h 45
#include <iostream>
#include <vector>
#include <assert.h>
#include "StandingOvation.hpp"
using namespace std;
#define printf(...)
void standingOvation()
{
    printf("START\n");
    //Get input
    int numTest;
    cin >> numTest;
    printf("Num test: %d \n", numTest);
    vector<vector<int>> datas;
    
    for(int i = 0; i<numTest; ++i)
    {
        vector<int> data;
        int sMax;
        cin >> sMax;
        data.push_back(sMax);
        
        string audience;
        ws(cin);
        getline(cin, audience);
        printf("smax: %d, audience: %s\n", sMax, audience.c_str());
        datas.push_back(data);
        
        assert(audience.length() == sMax + 1);
        
        int neededToInvite = 0;
        int standing = 0;
        for(int j = 0; j<sMax+1; ++j)
        {
            int k = audience.at(j) - '0';
            printf("%d ", k);

            if(j > standing)
            {
                int additionalInvitation = j - standing;
                neededToInvite += additionalInvitation;
                standing += additionalInvitation;
            }
            standing += k;
        }
        cout<<"Case #" <<i+1 <<": "<<neededToInvite <<endl;
        printf("\n");
    }
}
