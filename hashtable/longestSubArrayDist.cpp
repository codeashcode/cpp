//
// Created by Ashok Not Admin on 2019-02-05.
//

#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

int findLongest(const vector<char> & elements) {
    unordered_map<char, size_t> eToIndex;
    int noDupIndex = 0;
    int len = 0;
    int eLen = elements.size();

    for(int i=0; i<eLen; i++) {

        auto [insertedE, inserted] = eToIndex.emplace(elements[i], i);

        if(!inserted) {
            if(insertedE->second >= noDupIndex) {
                len = max(len, i-noDupIndex);
                noDupIndex = insertedE->second+1;
            }
            insertedE->second = i;
        }
    }
    return max(len, eLen-noDupIndex);
}

int main() {

    cout << "longest length: " << findLongest({'f','s','f','e','t','w','e','n','w','e'});

    return 0;
}


