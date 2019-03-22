#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

vector<char> getNearbyChars(char c) {
	if(c=='g') {
		return {'g','h','f'};
	}

	if(c=='i') {
		return {'i','o','k'};
	}

	return {};
	
}

bool isValidWord(string str) {
	if(str=="go" || str=="hi")
		return true;
	return false;
}

vector<string> getNearbyWords(string word) {
	unordered_set<string> result_set;
	vector<string> result;

	if(!word.size()) return result;

	result_set.insert(word);

	for(int i=0; i<word.size(); i++) {
		vector<char> closeChars = getNearbyChars(word[i]);

		unordered_set<char> closeChars_set;
		for(char c:closeChars) {
			closeChars_set.insert(c);
		}

		string newWord;
		for(char c: closeChars_set) {
			for(string str: result_set) {
				newWord = str.substr(0,i) + c + word.substr(i+1);
				result_set.insert(newWord);	
			}
		}
	}

	for(string str:result_set) {
		if(isValidWord(str))
			result.push_back(str);
	}

	return result;
}

int main() {
	string word = "gi";
	cout <<"All nearby valid words are:" <<endl;
	for(string str: getNearbyWords(word)) {
		cout <<" "<<str;
	}
	cout <<endl;
}