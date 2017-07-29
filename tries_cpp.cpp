#include<iostream>

using namespace std;

class TrieNode {
public:
    bool isWord;
    struct TrieNode *next[26];
    int prefixCount;

    TrieNode() 
    {
        isWord = false;
        for(int i=0;i<26;i++)
            next[i] = NULL;

        prefixCount = 0;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) 
    {

        TrieNode* temp = root;
        for(int i = 0;i < word.size(); ++i)
        {

            if(temp -> next[word[i] - 'a'] == NULL) {
                temp -> next[word[i] - 'a'] = new TrieNode();
            }

            temp = temp -> next[word[i] - 'a'];
        }

        temp -> isWord = true;
    }

// Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0;i < word.size(); ++i){
            if(temp -> next[word[i] - 'a'] == NULL) 
                return false;
            else 
                temp = temp -> next[word[i] - 'a'];
        }

        if(temp -> isWord == true) 
            return true;

        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0;i < prefix.size(); ++i){
            if(temp -> next[prefix[i] - 'a'] == NULL) 
                return false;
            else 
                temp = temp -> next[prefix[i] - 'a'];
        }

        return true;
    }

};

int main()
{
    Trie trie;
    trie.insert("a");
    cout << (trie.search("a") ? "true" : "false" );
    cout<<endl;
    cout << (trie.startsWith("a") ? "true" : "false" );
    cout<<endl;

    return 0;
}
