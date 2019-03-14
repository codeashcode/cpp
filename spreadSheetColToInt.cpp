#include <iostream>
#include <vector>
#include <numeric>
#include <string>


using namespace std;


int fun(string sscol) {
    int res = accumulate(begin(sscol), end(sscol), 0, [](int res, char c) { 
               return res*26+c-'A'+1;
               });
    return res;

}

int main() {

    string sscol ="ZZ";
    cout << fun(sscol);

}
