#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
using namespace std;

int main()
{
    std::vector<int> data = { 1, 1, 2, 4, 4, 4, 5, 5, 6 };
 
    auto lower = std::lower_bound(data.begin(), data.end(), 4);
    auto upper = std::upper_bound(data.begin(), data.end(), 4);

    cout <<"Lower value: " << lower - data.begin()<<endl;
    cout <<"Upper value: " << upper - data.begin()<<endl;

    string str1 ="";

    cout <<str1 << endl;
    cout <<str1+"->"<<endl;
    cout <<str1+"->"+"hi"<<endl;
 
}
