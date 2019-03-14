#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }

        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            return true;
        }
        return false;
    }

    string toGoatLatin(string S) {

        string res="", newWord="", suffix2="ma", suffix1="", suffix3="";
        bool start = true;

        for(char c:S) {
            cout <<"char: "<<c <<" " <<"start: "<<start;

            if(start) {
                newWord="";
                suffix3+="a";
                suffix1="";
                start=false;

                if(isVowel(c)) {
                    newWord=c;
                }
                else{
                    suffix1=c;
                }
            }
            else {
                if(c==' ') {
                    res+=newWord+suffix1+suffix2+suffix3+c;
                    start = true;
                } else {
                    newWord+=c;
                    start = false;
                }
            }
        }
        res+=newWord+suffix1+suffix2+suffix3;
        return res;
    }
};

int main() {

    return 0;
}
