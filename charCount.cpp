#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	string str ="interviewatkickstart.com";

	vector<char> toBeFound={'a','e','i'};
	unordered_map<char, int> countMap;
	for(char c: toBeFound) {
		countMap[c] = 0;
	}

	for(char c:str) {
		if(countMap.find(c) != countMap.end()) {
			countMap[c]++;
		}
	}

	for(auto itr=countMap.begin(); itr !=countMap.end(); itr++) {
		cout <<itr->first <<":"<< itr->second <<endl;
	}
	cout << endl;

}