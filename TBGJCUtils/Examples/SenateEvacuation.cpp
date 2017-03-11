//
//  SenateEvacuation.cpp
//  TBGJCUtils
//
//  Created by trongbangvp@gmail.com on 3/9/17.
//  Copyright © 2017 trongbangvp@gmail.com. All rights reserved.
//

#include "SenateEvacuation.hpp"
#include "TBGCJUtils.hpp"

typedef struct PoliticalParty
{
    char name;
    int numPeopleRemain;
} PoliticalParty;

char getPartyName(char partyIndex)
{
    return 'A' + partyIndex;
}
void senateEvacuation()
{
    int numCase;
    cin >> numCase;
    for(int i = 0; i<numCase; ++i)
    {
        int numParty;
        cin >> numParty;
        vector<int> partyMember = readLine();
        assert(numParty == partyMember.size());
        vector<PoliticalParty> parties;
        for(int j = 0; j<numParty; ++j)
        {
            if(partyMember[j] > 0)
            {
                PoliticalParty aParty = { getPartyName(j), partyMember[j]};
                parties.push_back(aParty);
            } else
            {
                assert(0);
            }
        }
        assert(numParty == parties.size());
        printf("\nNum party: %d\n", numParty);
        
        cout<<"Case #"<<i+1<<":";
        while(true)
        {
            if(numParty >= 3)
            {
                int idxOfMax = -1;
                int maxNumPeople = 0;
                for(int k = 0; k<numParty; ++k)
                {
                    PoliticalParty * aParty = & parties[k];
                    if(aParty->numPeopleRemain > maxNumPeople)
                    {
                        maxNumPeople = aParty->numPeopleRemain;
                        idxOfMax = k;
                    }
                }
                assert(idxOfMax >= 0);
                cout <<" "<<parties[idxOfMax].name;
                --parties[idxOfMax].numPeopleRemain;
                if(parties[idxOfMax].numPeopleRemain == 0)
                {
                    parties.erase(parties.begin() + idxOfMax);
                }
            } else if( numParty == 2)
            {
                if(parties[0].numPeopleRemain > parties[1].numPeopleRemain)
                {
                    cout <<" "<<parties[0].name;
                    --parties[0].numPeopleRemain;
                } else if(parties[0].numPeopleRemain < parties[1].numPeopleRemain)
                {
                    cout <<" "<<parties[1].name;
                    --parties[1].numPeopleRemain;
                } else
                {
                    cout <<" "<<parties[0].name<<parties[1].name;
                    --parties[0].numPeopleRemain;
                    if(parties[0].numPeopleRemain == 0)
                    {
                        break;//finish
                    }
                    --parties[1].numPeopleRemain;
                }
            } else if(numParty == 1)
            {
                assert(0);
            } else
            {
                break;//finish
            }
            numParty = parties.size();
        };
        cout<<endl;
    }
    printf("\nFinished\n");
}
