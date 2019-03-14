#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        set<int> cur;

        for(int i = nums.size()-1; i >= 0; i --) {

            cout << endl<<"Before Inserting: " <<nums[i];
            cur.insert(nums[i]);

            cout << endl << "Set size: " <<cur.size();

            auto iter= cur.lower_bound(nums[i]);
            int cnt = distance(iter, cur.begin());
            //cout << endl << "Count: "<<cnt << endl;
            //ans.push_back(cnt);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    Solution sln;
    vector<int> input={5,2,6,1};

    cout<<"Count: " << endl;
    vector<int> res = sln.countSmaller(input);

    for(int n: res) {
        cout << " "<< n;
    }

    return 0;
}

