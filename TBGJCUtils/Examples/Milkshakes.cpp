//
//  Milkshakes.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/11/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include "Milkshakes.hpp"
#include "TBGCJUtils.hpp"

//Total time to solve: 2h
//Num algorithm bug before correct: 3
/*
 * Algorithm: 
 * a array to mark which flavor must be malted
 * Iterate all, if a customer like 1 flavor, and malted -> mark to the list.
 * Iterate all, check if a customer wasn't satisfied and try to set a flavor to malted to satisfy this customer -> recheck from beginning ->...
 * Finally: check flag to determine if possible -> print result
 */

typedef struct Flavor {
    int type;
    int malted;
} Flavor;

void milkShakes()
{
    int numCase;
    cin >> numCase;
    for(int i = 0; i<numCase; ++i)
    {
        int numFlavor, numCustomer;
        cin >> numFlavor;
        cin >> numCustomer;
        Flavor** flavors = (Flavor**) calloc(numCustomer, sizeof(Flavor*));
        int* countArr = (int*) calloc(numCustomer, sizeof(int));
        int* mustBeMalted = (int*)calloc(numFlavor, sizeof(int)); //default all = 0, because we want minimize malted-flavor
        for(int j = 0; j<numCustomer; ++j)
        {
            int t;
            cin >> t;
            countArr[j] = t;
            flavors[j] = (Flavor*)calloc(t,  sizeof(Flavor));
            for(int k = 0; k<t; ++k)
            {
                int x,y;
                cin >> x;
                cin >> y;
                assert(x >= 1 && x <= numFlavor);
                assert(y == 0 || y == 1);
                Flavor* flv = & flavors[j][k];
                flv->type = x - 1; //because: x >= 1 (value from 1 -> numFlavor)
                flv->malted = y;
            }
            if(t==1)
            {
                Flavor* flv = & flavors[j][0];
                if(flv->malted)
                {
                    mustBeMalted[flv->type] = 1; //marked
                }
            }
            //else if t>1 -> at least one unmalted -> satisfied or not but we can't change (and will recheck later)
        }
        
        //Check satisfation
        bool satisfy = false;
        for(int j = 0; j<numCustomer; ++j)
        {
            int t = countArr[j];
            satisfy = false;
            for(int k = 0; k<t; ++k)
            {
                Flavor* flv = & flavors[j][k];
                if(flv->malted == 1 && mustBeMalted[flv->type] == 1)
                {
                    satisfy = true;
                    break;
                } else if(flv->malted == 0 && mustBeMalted[flv->type] == 0)
                {
                    satisfy = true;
                    break;
                }
            }
            if(!satisfy)
            {
                //Try to satisfy this customer if possible (set a flavor to malted)
                for(int k = 0; k<t; ++k)
                {
                    Flavor* flv = & flavors[j][k];
                    if(flv->malted == 1)
                    {
                        mustBeMalted[flv->type] = 1;
                        j = -1;//since we change value in mustBeMalted -> must recheck from the begining
                        satisfy = true;
                        break;
                    }
                }
            }
            
            //finally if can't satisfy -> finish
            if(!satisfy)
            {
                break;
            }
        }
        if(satisfy)
        {
            cout<<"Case #"<<i+1<<": ";
            for(int j = 0; j<numFlavor; ++j)
            {
                cout<<mustBeMalted[j]<<" ";
            }
            cout<< endl;
        } else
        {
            cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }
        
        //Free memory
        for(int j = 0; j<numCustomer; ++j)
        {
            free(flavors[j]);
        }
        free(countArr);
        free(flavors);
        free(mustBeMalted);
    }
}
