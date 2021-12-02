//https://contest.yandex.ru/contest/27794/problems/F/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    int n;
    input >> n;

    std::vector<int> classes(n);
    std::copy_n(std::istream_iterator<int>(input),n,classes.begin());

    int m;
    input >> m;
    //! @brief power, price
    std::vector<std::pair<int,int>> acs(m);
    for(int i = 0; i<m; ++i){
        input >> acs[i].first >> acs[i].second;
    }

    std::sort(classes.rbegin(), classes.rend());
    std::sort(acs.rbegin(), acs.rend());

    std::list<std::pair<int,int>> usefulAcs;
    int iBetter = 0;
    for(int i = 0; i < acs.size(); ++i){
        if(i+1 < acs.size() && acs[i+1].first == acs[i].first){
            continue;
        }
        if(acs[i].second < acs[iBetter].second || i == iBetter){
            usefulAcs.push_back(acs[i]);
            iBetter = i;
        }
    }

    auto ac = usefulAcs.begin();
    unsigned int price = 0;
    for(auto room : classes){
        auto next = std::next(ac,1);
        while (next!=usefulAcs.end() && next->first>=room){
            ac = next;
            next = std::next(ac,1);
        }
        price+=ac->second;
    }

    output << price;
}
