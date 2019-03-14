//
// Created by Ashok Not Admin on 2019-02-02.
//

#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;

bool bsearch(int val, vector<int> &list) {
    int low = 0, high = list.size()-1;
    int mid;

    while(low<=high) {
        mid = (low+high)/2;
        int eAtMid = list[mid];
        if(eAtMid == val) {
            return true;
        } else if(eAtMid>val) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return false;

}

int main() {
    vector<int> list={1};

    int num = 1;
    string res = bsearch(num,list) ? "Yes": "No";
    cout <<num<<": Found or Not? " << res <<endl;
    num = 88;
    res = bsearch(num,list) ? "Yes": "No";
    cout <<num<<": Found or Not? " << res <<endl;


}


