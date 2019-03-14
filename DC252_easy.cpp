
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int a = 1;
	int b = 1;

	vector<int> res;
	
	while(a!=0 && b/a) {
		int ans = ((double)b/a) + 0.99;
		res.push_back(ans);

		a = a*ans - b;
		b = b*ans;
	}

	for(int ans: res) {
		cout <<" "<<ans;
	}
	cout <<endl;
	return 0;
}