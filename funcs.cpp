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

    unsigned int iAc = 0;
    unsigned int price = 0;
    for(auto room : classes){
        unsigned int j = iAc, minPrice = acs[iAc].second, minJ = iAc;
        ++j;
        while (j<acs.size() && acs[j].first >= room){
            if(acs[j].second < minPrice){
                minPrice = acs[j].second;
                minJ = j;
            }
            ++j;
        }
        iAc = minJ;
        price += minPrice;
    }

    output << price;
}
