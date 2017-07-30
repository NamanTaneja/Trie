#include<iostream>

using namespace std;

class TrieNode {
public:
    bool isWord;
    struct TrieNode *next[26];
    string suffix;

    TrieNode() 
    {
        isWord = false;
        for(int i=0;i<26;i++)
            next[i] = NULL;
    }

    int setSuffix(string word) {
        suffix = word;
        return 1;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    int insertLazy(string word, TrieNode* temp = NULL) {
        if(temp==NULL)
            temp = root;

        for(int i = 0;i < word.size(); ++i)
        {

            if(temp -> next[word[i] - 'a'] == NULL) {
                temp -> next[word[i] - 'a'] = new TrieNode();
                temp = temp -> next[word[i] - 'a'];
                temp->setSuffix(word.substr(i+1));
                cout<<"Set suffix : "<<word.substr(i+1)<<" for input "<<word<<endl;
                break;
            }
            else{
                temp = temp -> next[word[i] - 'a'];
                if(temp->suffix.empty() == false){

                    cout<<"Lazily propogated : "<<temp->suffix<<" for input "<<word<<" with common suffix : "<<word.substr(0,i+1)<<endl;
                    insertLazy(temp->suffix,temp);
                    temp->suffix.clear();
                    temp -> isWord = false;
                }
            }
        }

        if(temp -> isWord == false){
            temp -> isWord = true;
        }

        return 1;
    }



    int search(string word) {

        TrieNode* temp = root;
        for(int i = 0;i < word.size(); ++i)
        {
            if(temp -> next[word[i] - 'a'] == NULL)
                return false;

            temp = temp -> next[word[i] - 'a'];
            if(temp->suffix.empty() == false){
                // cout<<"Comparing "<<word.substr(i+1)<<" with "<<(temp->suffix)<<endl;
                return word.substr(i+1).compare(temp->suffix)==0;
            }
        }

        return temp -> isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0;i < prefix.size(); ++i){
            if(temp -> next[prefix[i] - 'a'] == NULL) 
                return false;
            
            temp = temp -> next[prefix[i] - 'a'];
            if(temp->suffix.empty() == false){
                string partOfSuffix = temp->suffix.substr(0,prefix.size()-i-1);
                return prefix.substr(i+1).compare(partOfSuffix)==0;
            }
        }

        return true;
    }


    void printTrie(string out, TrieNode* temp = NULL) {
        if(temp==NULL)
            temp = root;

        if(temp->isWord)
            cout<<out<<temp->suffix<<endl;

        for(int i = 0;i < 26; ++i){
            if(temp -> next[i] != NULL){
                string nextChar(1,('a'+i));
                printTrie(out+nextChar,temp -> next[i]);
            }
        }
    }

};

int main()
{
    Trie trie;
    trie.insertLazy("abc");
    trie.insertLazy("ab");
    trie.insertLazy("acd");
    trie.insertLazy("adog");

    cout<<endl;
    cout << "String search a : " << (trie.search("a") ? "True" : "False" );
    cout<<endl;
    cout << "String search ac : " << (trie.search("ac") ? "True" : "False" );
    cout<<endl;
    cout << "String search acdf : " << (trie.search("acdf") ? "True" : "False" );
    cout<<endl;
    cout << "String search ado : " << (trie.search("ado") ? "True" : "False" );
    cout<<endl;

    cout << "Prefix search a : " << (trie.startsWith("a") ? "True" : "False" );
    cout<<endl;
    cout << "Prefix search ac : " << (trie.startsWith("ac") ? "True" : "False" );
    cout<<endl;
    cout << "Prefix search acdf : " << (trie.startsWith("acdf") ? "True" : "False" );
    cout<<endl;
    cout << "Prefix search ado : " << (trie.startsWith("ado") ? "True" : "False" );
    cout<<endl;

    cout<<endl<<"Printing Trie"<<endl;
    trie.printTrie("");
    cout<<endl;

    return 0;
}
