#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

template<typename T>
void print_queue(T q) {
    while(!q.empty()) {
        cout<<" " << q.top();
        q.pop();
    }
    cout << endl;
}


int main() {
    priority_queue<int> q1;

    for(int i: {1,2,3,4,5,6,7,8,9,10}) {
        q1.push(i);
    }
	
    print_queue(q1);


    priority_queue<int, vector<int>, greater<int>> q2;
    for(int i: {1,2,3,4,5,6,7,8,9,10}) {
        q2.push(i);
    }
	
    print_queue(q2);

    auto cmp = [](int a, int b) {return a&b;};
    priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
    for(int i: {1,2,3,4,5,6,7,8,9,10}) {
        q3.push(i);
    }

    print_queue(q3);


	return 0;
}
