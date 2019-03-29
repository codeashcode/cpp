#include<sstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(string mainString, char delimiter=' ') {
	vector<string> res;
	string token;
	istringstream iss(mainString);

	while(getline(iss, token, delimiter)) {
		res.push_back(token);
	}

	return res;

}

int main() {
	string mainString = "Elephant is a large animal";

	cout <<endl;
	for(string s: split(mainString, ',')) {
		cout <<"s:"<<s <<endl;
	}
	cout <<endl;
}