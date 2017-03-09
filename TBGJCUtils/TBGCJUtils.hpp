//
//  TBGCJUtils.hpp
//  TestGCJ
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#ifndef TBGCJUtils_hpp
#define TBGCJUtils_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

#define ENABLE_LOG_DEBUG 1
#if !ENABLE_LOG_DEBUG
#define printf(...) {}
#endif

long getTimeMsec();
std::vector<int> getIntVec(string str);
std::vector<int> readLine();
std::string readLineString();

#endif /* TBGCJUtils_hpp */
