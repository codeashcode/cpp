#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }   
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if(!words.size() || !board.size()) return result;
        
        unordered_set<string> result_set;
        
        Trie *trie = new Trie(words);
        TrieNode *root = trie->getRoot();
        
        for(int i=0; i<board.size(); i++) {
            for( int j=0; j<board[0].size(); j++) {
                findWords(board, i, j, result_set, "", root);
            }
        }
        
        for(auto itr=result_set.begin(); itr!=result_set.end(); itr++) {
            result.push_back(*itr);
        }
        
        return result;
    }
    
    void findWords(vector<vector<char>> &board, int x, int y, unordered_set<string> &result_set, string word, TrieNode * root) {
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) {
            return;
        }
        
        if(root->children[board[x][y]-'a'] !=NULL) {
            word+=board[x][y];
            
            root = root->children[board[x][y]-'a'];
            
            if(root->is_end) {
                result_set.insert(word);
            }
            
            char c = board[x][y];
            board[x][y] = ' ';
            
            findWords(board, x+1, y, result_set, word, root);
            findWords(board, x-1, y, result_set, word, root);
            findWords(board, x, y+1, result_set, word, root);
            findWords(board, x, y-1, result_set, word, root);
            
            board[x][y] = c;
        }
        return;
    }
    
};

int main() {
    vector<vector<char>> board = {{'b','a','a','b','a','b'},{'a','b','a','a','a','a'},{'a','b','a','a','a','b'},{'a','b','a','b','b','a'},{'a','a','b','b','a','b'},{'a','a','b','b','b','a'},{'a','a','b','a','a','b'}};

    vector<string> words = {"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba","babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa","babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa","babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba","aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba","ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab","aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa","aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa","abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb","aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb","aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa","abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab","aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba","aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb","aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa"};

    Solution sln;
    cout <<"Words Found"<<endl;
    for(string word: sln.findWords(board, words)) {
        cout << " "<<word;
    }
    cout <<endl;
}