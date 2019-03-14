#include<iostream>
#include<string>
#include<exception>

using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
    public:
	    TrieNode * children[ALPHABET_SIZE];
	    bool   isEndNode;

	    TrieNode() {
	    	for(int i=0; i<ALPHABET_SIZE; i++) {
	    		children[i] = NULL;
	    	}
	    	isEndNode = false;
	    }
};

class Trie {
    private:
	    TrieNode * root;

    public:
	    Trie() {
		    root = new TrieNode();
	    }

	    bool insert(string str) {
            try {
	    	    TrieNode *itr = root;
	    	    int len = str.length();

	    	    for(int i=0;i<len; i++) {
	    	    	int index = str[i]-'a';
	    	    	if(itr->children[index] == NULL) {
	    	    		itr->children[index] = new TrieNode();
	    	    		if(i==len-1) {
	    	    			itr->isEndNode = true;
	    	    		}
	    	    	}
	    	    	itr = itr->children[index];
	    	    }
            }
            catch(exception e) {
                return false;
            }
            return true;
	    }

	    bool search(string str) {
            TrieNode *itr = root;
            int len = str.length();

	    	for(int i=0;i<len; i++) {
	    		int index = str[i]-'a';
	    		if(itr->children[index] == NULL) {
                    return false;
	    		}
	    		else {
                    cout <<"Found: " << str[i] << endl;
	    			itr = itr->children[index];
	    		}
	    	}
            return itr->isEndNode;
	    }
};

int main() {
	string str;
	cout << "Enter String: ";
	cin >> str;

	cout << "Entered string: " << str << endl;

	Trie trie;
	for(int i=0; i<str.length(); i++) {
        string suffix = str.substr(i);
		if(!trie.insert(suffix)) {
            cout << "Failed to create TRIE" << endl;
            return 1;
        }
	}
	
    string pattern = "nan";
	cout << pattern << " pattern found?" << trie.search(pattern) << endl;
    
    pattern = "nanu";
	cout << pattern << " pattern found?" << trie.search(pattern) << endl;
	return 0;
}
