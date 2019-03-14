#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;

int findMinSum(vector<int> &vec) {

    int maxSum=0;

    for(int num: vec) {
        if(num-maxSum>1) {
            return maxSum + 1;
        }
        maxSum+=num;
    }
    return maxSum+1;
}


int main() {
    vector<int> vec={1, 2, 3, 10};
    if(!vec.size())
        return 1;

    cout << "Min Sum not possible:"<<findMinSum(vec);
    return 0;
}
