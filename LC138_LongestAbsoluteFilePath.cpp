#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
	int myMax(int a, int b) {
		if(a>=b)
			return a;
		else
			return b;
	}
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);

        unordered_map<unsigned,unsigned> dToLength;

        dToLength[0] = 0;

        unsigned max_len = 0;
        
        string token;

        while(getline(ss, token)) {
        	int pos = token.find_last_of("\t");
        	string s = (pos !=string::npos) ? token.substr(pos+1):token;

        	int depth = token.size() - s.size();

        	if(s.find(".") != string::npos) {
        		max_len = myMax(max_len, dToLength[depth] + s.size());
        	}
        	else{
        		dToLength[depth+1] = dToLength[depth] + s.size() + 1;
        	}
        }

        return max_len;
    }
};

int main() {
	Solution sln;

	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";

	//
	//cout << "Enter string to test: ";
	//cin  >> input;

	cout <<"Longest path length: " << sln.lengthLongestPath(input) <<endl;

	return 0;
}

