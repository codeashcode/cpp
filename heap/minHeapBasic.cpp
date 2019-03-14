#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>

using namespace std;

template<class T>
class maxHeap {
private:
    vector<T> container;
    int len;
    void heapify() {
        int startIndex = len;
        while(startIndex !=0) {
            if(container[startIndex] > container[(startIndex-1)/2]) {
                T temp;
                temp = container[(startIndex-1)/2];
                container[(startIndex-1)/2] = container[startIndex];
                container[startIndex] = temp;
                startIndex = (startIndex-1)/2;
            }
            else {
                break;
            }
        }
    }

public:
    maxHeap() {
        len = 0;
    }

    bool insert(T val) {
        container.push_back(val);
        heapify();
        len++;
        return true;
    }

    T getMax() {
        if(len) {
            return container[0];
        }
        else {
            throw "Not Found";
        }

    }

    bool remove(T val) {
      cout <<"Not supported"<<endl;
      return true;
    }


};
int main() {
    maxHeap<int> h;

    try {
        for(int i=0; i<25;i++) {
            cout <<"Insert: "<<i <<endl;
            h.insert(i);
        }

        cout << "highest1:" << h.getMax();
        h.remove(25);
        cout << "highest2:" << h.getMax();

    } catch(exception e) {
        cout <<"Caught exception"<<endl;
    }

    return 0;
}
