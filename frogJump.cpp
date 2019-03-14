#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {

        int len = stones.size();

        map<pair<int,int>,bool> visited;

        queue<pair<int,int>> qp;

        map<int,bool> stonesMap;

        for(int s:stones) {
            stonesMap[s] = true;
        }

        int target = stones[len-1];

        if(stones[1]!= 1) {
            return false;
        }

        qp.push(pair<int,int>{1,1});
        cout <<"Pushed to Q: 1 1"<<endl;

        while(!qp.empty()) {
            auto point = qp.front();
            qp.pop();

            int curState = point.first;
            int k = point.second;


            if( curState == target) {
                return true;
            }
            else{
                    for(int j=k-1;j<=k+1;j++) {
                        if (j > 0) {
                            pair<int, int> newPoint{curState + j, j};

                            if (visited.find(newPoint) == visited.end()) {
                                if (stonesMap.find(curState + j) != stonesMap.end()) {
                                    cout << "Pushed  to Q and marked visited: " << newPoint.first << " "
                                         << newPoint.second << endl;
                                    qp.push(newPoint);
                                    visited[newPoint] = true;
                                }
                            }
                        }
                    }
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    vector<int> input={0,1,3,5,6,8,12,17};
    bool res = sln.canCross(input);
    string resStr = res?"yes":"no";

    cout << endl << "Possible or not?: " << resStr << endl;

    return 0;
}
