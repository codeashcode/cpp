#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;

        if(p.length()>s.length())
            return res;

        map<char,int> cfq;
        for(char c:p) {
            cfq[c]++;
        }

        int begin=0, end=0;
        int counter = cfq.size();

        while(end<s.size()) {

            char e = s[end];

            if(cfq.find(e) != cfq.end()) {
                cfq[e] = cfq[e]-1;
                if(cfq[e] == 0) {
                    counter--;
                }
            }
            end++;

            while(counter==0) {
                char b = s[begin];
                if(cfq.find(b) != cfq.end()) {
                    cfq[b]++;
                    if(cfq[b] > 0) {
                        counter++;
                    }
                }

                if(end-begin == p.length()) {
                    res.push_back(begin);
                }
                begin++;
            }
        }
        return res;
    }
};


int main() {
    Solution sln;
    auto res = sln.findAnagrams("cbaebabacd", "abc");
    cout << "Indexes: "<<endl;
    for(int i:res) {
        cout <<" "<<i;
    }
    cout <<endl;
    return 0;
}

