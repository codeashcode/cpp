#include<iostream>
#include<string>
#include<vector>

using namespace std;

int nextToDie(int c, int k, int N, vector<int> pr) {

    while(k) {
        if(pr[c] !=0) {
            k--;
            if(k)
                c++;
        }
        else {
            c++;
        }
        c = c % N;
    }
    return c;
}

int prisoners(int N, int k) {

    int elementsLeft = N;

    if(N <= 0 || k<=0) {
        return -1;
    }

    if(k==1) {
        return N;
    }

    vector<int> pr;
    for(int i=0; i<N; i++) {
        pr.push_back(i+1);
    }

    int c = 0;
    while(elementsLeft !=1) {
       c = nextToDie(c, k, N, pr);

       pr[c] = 0;
       cout << "Killing at Index:" << c << endl;
       elementsLeft--;
    }
    while(pr[c] ==0) {
        c = (c+1) % N;
    }
    //convert to position: index+1
    return c+1;
}

int main() {
    int n=41, k=2;

    cout <<"Survival of intelligent position: " << prisoners(n, k);

    return 0;
}




