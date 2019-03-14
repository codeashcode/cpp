#include<iostream>
#include<string>

using namespace std;

template<class T>
class Node {
private:
    T value;
    Node *next;
public:
    Node(T val) {
        value = val;
        next = NULL;
        cout << "New node created" << endl;
    }
};

template<class T>
class LinkList {
private:
    Node<T> *head;
public:
    LinkList() {
        cout <<"Link List created";
    }
    bool insert(T val) {
        Node<T> *itr = head;
        Node<T> *prev=NULL;
        Node<T> *next = itr;

        while(itr) {
            if(itr->value < val) {
                itr=itr->next;
                prev = itr;
            } else if(itr->value == val) {
                cout <<"Already Exists" << cout;
                return true;
            }
            else {
                next = itr;
            }
        }

        Node<T> newNode = new Node<int>(val);
        if(!head || head->value>val) {
            newNode.next = head;
            head = newNode;
        }
        else {

        }


        return true;
    }

    bool search(T val) {
        return true;
    }
};

int main() {
    LinkList<int> ll;
    ll.insert(10);
    ll.search(10);

    return 0;
}


