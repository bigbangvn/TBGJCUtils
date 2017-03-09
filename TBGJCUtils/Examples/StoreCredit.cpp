//
//  StoreCredit.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <assert.h>
#include "TBGCJUtils.hpp"
#include "StoreCredit.hpp"

void solve(int caseIdx, int C, int I, int* P) {
    for(int i = 0; i<I-1; ++i) {
        for(int j = i+1; j<I; ++j) {
            if(P[i] + P[j] == C) {
                cout << "Case #" <<caseIdx <<": "<<(i+1) <<" "<<(j+1) <<endl;
            }
        }
    }
}

void storeCredit1()
{
    int numCase;
    cin >> numCase;
    for(int i = 0; i<numCase; ++i) {
        //Get input
        int credit, numProduct = 1;
        cin >> credit;
        cin >> numProduct;
        vector<int> pricesVec = readLine();
        assert(pricesVec.size() == numProduct);
        
        //Solve
        solve(i+1, credit, numProduct, pricesVec.data());
    }
}
