//
//  TBGCJUtils.cpp
//  TestGCJ
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//
#include <sstream>
#include <sys/time.h>
#include "TBGCJUtils.hpp"


long getTimeMsec()
{
    struct timeval crrTime;
    gettimeofday(&crrTime, NULL);
    return crrTime.tv_sec * 1000 + crrTime.tv_usec/1000;
}

std::vector<int> getIntVec(string str)
{
    vector<int> vec;
    stringstream stream(str);
    int n;
    while(stream >> n) {
        vec.push_back(n);
    }
    return vec;
}

std::vector<int> readLine()
{
    string inputStr;
    ws(cin);
    getline(std::cin, inputStr);
    //cout<<"LINE:"<<inputStr<<endl;
    return getIntVec(inputStr);
}

std::string readLineString() //skip space, newline at first
{
    string str;
    ws(cin); //skip space, newline
    getline(cin, str);
    return str;
}

std::string readLineString2()
{
    string str;
    getline(cin, str);
    return str;
}
