
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {

        string res="";
        if(t.length() > s.length())
            return res;
        if(t==s)
            return s;

        map<char, int> cfq;
        for(char c:t) {
            cfq[c]++;
        }

        int counter = cfq.size();
        int start=0, end=0;

        int minLength = s.length();
        int minStart=0, minEnd=counter-1;

        while(end<s.length()) {
            char eChar = s[end];

            if(cfq.find(eChar) != cfq.end()) {
                cfq[eChar] = cfq[eChar]-1;
                if(cfq[eChar] ==0)
                    counter--;
            }
            end++;

            while(counter ==0) {
                char sChar = s[start];
                if(cfq.find(sChar) !=cfq.end()) {
                    cfq[sChar] = cfq[sChar]+1;
                    if(cfq[sChar] >0) {
                        counter++;
                    }
                }
                if(end-start>=t.length()) {
                    if(end-start<=minLength) {
                        minStart = start;
                        minEnd   = end;
                        minLength = minEnd-minStart;
                    }
                }
                start++;
            }
        }

        return s.substr(minStart,minEnd-minStart);
    }
};

int main() {
    // "cabwefgewcwaefgcf"
    //"cae"
    Solution sln;
    cout <<"Ans: "<<sln.minWindow("cwaefgcf","cae")<<endl;
    return 0;
}

