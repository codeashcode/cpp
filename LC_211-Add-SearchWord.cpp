class TrieNode {
public:
    vector<TrieNode*> children;
    vector<vector<int>> childLength;
    bool isLeaf;
    TrieNode() {
        children.reserve(26);
        childLength.reserve(26);
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class Trie {
    private:
    TrieNode *root;
    
    bool findInternal(string word, TrieNode *start) {
        for(char c: word) {
            if(c =='.') {
                for(int i=0;i<26;i++) {
                    if(start->children[i] !=NULL && 
                       (find(start->childLength[i].begin(), start->childLength[i].end(), word.size()) != start->childLength[i].end()) &&
                        findInternal(word.substr(1), start->children[i])
                      ) {
                        return true;
                    }
                } 
            } else if(start->children[c-'a'] == NULL) {
                return false;
            } else {
               return findInternal(word.substr(1), start->children[c-'a']); 
            }
        }
        return word.empty() && start->isLeaf; 
    }
    public: 
    Trie() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode *track = root;
        int len = word.size();
        for(int i=0; i<len; i++) {
            char c = word[i];
            cout <<"c:"<<c<<endl;
            if(track->children[c-'a']!=NULL) {
                cout <<"Exist"<<endl;
                track->childLength[c-'a'].push_back(len-i);
                track = track->children[c-'a'];
                
            }
            else {
                cout <<"Doesn't Exist"<<endl;
                TrieNode *child  = new TrieNode();
                track->children[c-'a'] = child;
                cout <<"Updated child"<<endl;
                track->childLength[c-'a'].push_back(len-i);
                cout <<"updated length set"<<endl;
                track = child;
            }
        }
        track->isLeaf = true;
    }
    
    bool findWord(string word) {
        return findInternal(word, root);
    }
};

class WordDictionary {
private:
    Trie *dic;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        dic = new Trie();
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dic->addWord(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dic->findWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */