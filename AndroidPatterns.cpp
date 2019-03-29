#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<algorithm>

using namespace std;


class Pattern {
	private:
		unordered_map<int, vector<int>> next;
		vector<vector<int>> skipLevel;

		vector<int> getNextNumbers(int start, vector<bool> &visited) {
			vector<int> nextNums;

			for(int num: next[start]) {
				if(!visited[num]) {
					nextNums.push_back(num);
				}
				else {
					int skip = skipLevel[start][num];
					if(skip && !visited[skip])
						nextNums.push_back(skipLevel[start][num]);
				}
			}
			return nextNums;
		}

		void getPatterns(vector<int> path, int start, vector<bool> &visited, vector<vector<int>> &results) {
			vector<int> nextNumbers = getNextNumbers(start, visited);
			//cout <<"Finding patterns starting at number: "<<start<<endl;

			if(!nextNumbers.size()) {
				//cout <<"No where to go"<<endl;
				path.push_back(start);
				results.push_back(path);
				return;
			}

			visited[start] = true;
			for(int i=0; i<nextNumbers.size(); i++) {
				path.push_back(start);
				getPatterns(path, nextNumbers[i], visited, results);
				path.pop_back();
			}
			visited[start] = false;
		}
	public:
		void mergeLongestPatterns(vector<vector<int>> &allResults, vector<vector<int>> &results) {

			//cout <<"Merging two size: 1."<<allResults.size()<<" and 2."<<results.size()<<endl;
			int longest = 0;

			for(vector<int> vec: results) {
				longest = longest<vec.size()?vec.size():longest;
			}

			//cout <<"Longest:"<<longest<<endl;

			for(vector<int> vec: results) {
				if(vec.size() == longest)
					allResults.push_back(vec);
			}
		}

		Pattern() {
			next[1] = {2,4,5};
			next[2] = {1,3,6,5,4};
			next[3] = {2,6,5};
			next[4] = {1,2,5,8,7};
			next[5] = {1,2,3,4,6,7,8,9};
			next[6] = {2,3,9,8,5};
			next[7] = {4,5,8};
			next[8] = {4,5,6,9,7};
			next[9] = {5,6,8};

			for(int i=0; i<10; i++) {
				vector<int> vec;
				for(int j=0; j<10; j++) 
					vec.push_back(0);
				skipLevel.push_back(vec);
			}

			skipLevel[1][2] = 3;
			skipLevel[1][4] = 7;
			skipLevel[1][5] = 9;

			skipLevel[2][5] = 8;
			
			skipLevel[3][2] = 1;
			skipLevel[3][5] = 7;
			skipLevel[3][6] = 9;

			skipLevel[4][5] = 6;
			skipLevel[6][5] = 4;

			skipLevel[7][4] = 1;
			skipLevel[7][5] = 3;
			skipLevel[7][8] = 9;

			skipLevel[8][5] = 2;
			
			skipLevel[9][6] = 3;
			skipLevel[9][5] = 1;
			skipLevel[9][8] = 7;
		}

		vector<vector<int>> getAllPatterns() {

			vector<vector<int>> allResults;

			for(int i=1; i<10; i++) {
				vector<vector<int>> results;
				vector<int> path;
				vector<bool> visited(10, false);
				getPatterns(path, i, visited, results);

				mergeLongestPatterns(allResults, results);
				cout <<"After: "<<i<<" Size of results:"<<results.size()<<endl;
				cout <<"Size of All paths:"<<allResults.size()<<endl;
			}
			return allResults;
		}

		void printPaths(vector<vector<int>> results) {

			for(vector<int> vec: results) {
				cout <<endl;
				for(int num: vec) {
					cout <<num<<"->";
				}
				cout <<endl;
			}
		}
};

int main() {
	Pattern ptrn;

	vector<vector<int>> results = ptrn.getAllPatterns();
	//ptrn.printPaths(results);

	return 0;
}