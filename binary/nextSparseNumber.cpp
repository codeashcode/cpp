//
// Created by Ashok Not Admin on 2019-02-07.
//

#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

bool isSparse(int n) {
    int count =0;
    while(n) {
        count++;
        n = n & (n<<1);
    }

    return count>1?false:true;
}

int nextSparse(int x) {
    stack<int> st;
    if(isSparse(x)) {
        return x;
    }

    int ones=0;
    int zeros=0;

    while(x) {
        int nextBit = x %2;
        x=x>>1;
        if(nextBit ==0) {
            if(ones>1) {
                int zeros = ones;
                while(ones) {
                    st.pop();
                    ones--;
                }
                while(zeros) {
                    st.push(0);
                    zeros--;
                }
                st.push(1);
                ones++;
            }
            else {
                st.push(0);
                ones = 0;
            }
        }
        else {
            st.push(1);
            ones++;
        }
    }
    cout << "Ones: "<<ones << endl;
    if(ones>1) {
        int zeros = ones;
        while(ones) {
            st.pop();
            ones--;
        }
        while(zeros) {
            st.push(0);
            zeros--;
        }
        st.push(1);
    }

    int res = 0;
    while(!st.empty()) {
        res = res*2+st.top();
        st.pop();
    }
    return res;
}

int main() {
    int n;
    while(1) {
        cout << "Enter next number (0 to terminate): ";
        cin >> n;
        if(n==0)
            break;
        cout << "For number: "<<n<<" Next sparse number is::" << nextSparse(n) << endl;
    }
    return 0;
}

