//
//  MinimumScalarProduct.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/11/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include "MinimumScalarProduct.hpp"
#include "TBGCJUtils.hpp"

bool myComparator1(int a, int b)
{
    return a < b;
}

bool myComparator2(int a, int b)
{
    return a > b;
}

/*
 * Proven for mim scalar prod
 * vecA: a1 <= a2 <= a3 ...
 * vecB: b1 >= b2 >= b2 ...
 * S = a1*b1 + a2*b2 + ...
 * If we swap any element in vecB, for example bn <-> bn+1. It's easily to prove that we will have S' >= S
 */
void solveMinScalarProduct()
{
    int numCase;
    cin >> numCase;
    cin.ignore(); //to ignore newline
    for(int i = 0; i<numCase; ++i)
    {
        int dimension;
        cin >> dimension;
        cin.ignore();
        vector<int> vecA = readLine();
        vector<int> vecB = readLine();
        assert(vecA.size() == dimension && vecB.size() == dimension);
        std::sort(vecA.begin(), vecA.end(), myComparator1);
        std::sort(vecB.begin(), vecB.end(), myComparator2);
        int64_t product = 0;
        for(int j = 0; j<dimension; ++j)
        {
            product += ((int64_t)vecA[j]) * vecB[j]; //It's important to cast if you don't want to get an integer 32 overflow
        }
        cout<<"Case #"<<i+1<<": "<<product<< endl;
    }
}
