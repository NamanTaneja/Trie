#include<iostream>

using namespace std;

class TrieNode {
public:
    bool isWord;
    struct TrieNode *next[26];
    string suffix;
    int prefixCount;

    TrieNode() 
    {
        isWord = false;
        for(int i=0;i<26;i++)
            next[i] = NULL;
        prefixCount = 0;
    }

    int setSuffix(string word) {
        suffix = word;
        return 1;
    }

    int deleteChildren(){
        for(int i=0;i<26;i++)
            if(next[i] != NULL){
                next[i]->deleteChildren();
                delete next[i];
                next[i] = NULL;
            }
        return true;
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
            temp->prefixCount++;

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
                    temp->prefixCount--;
                }
            }
        }

        if(temp -> isWord == false){
            temp -> isWord = true;
            temp -> prefixCount++;
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



    int deleteWord(string word) {
        
        TrieNode* temp = root;

        if(search(word) == false)
            return false;

        for(int i = 0;i < word.size(); ++i)
        {
            temp->prefixCount--;
            TrieNode* nextNode = temp -> next[word[i] - 'a'];

            if(nextNode->prefixCount == 1){
                nextNode->deleteChildren();
                delete nextNode;
                temp -> next[word[i] - 'a'] = NULL;
                return true;
            }
            temp = nextNode;
        }

        temp->isWord = false;
        temp->prefixCount--;
        return true;
    }


    void printTriePrefixes(string out, TrieNode* temp = NULL) {
        if(temp==NULL)
            temp = root;

        if(temp)
            cout<<out<<temp->suffix<<" : "<<temp->prefixCount<<" : "<<temp->isWord<<endl;

        for(int i = 0;i < 26; ++i){
            if(temp -> next[i] != NULL){
                string nextChar(1,('a'+i));
                printTriePrefixes(out+nextChar,temp -> next[i]);
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
    cout << "String search ab : " << (trie.search("ab") ? "True" : "False" );
    cout<<endl;
    cout << "String search adog : " << (trie.search("adog") ? "True" : "False" );
    cout<<endl;
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
    trie.printTriePrefixes("");
    cout<<endl;


    trie.deleteWord("ab");

    cout<<endl;
    cout << "String search a : " << (trie.search("a") ? "True" : "False" );
    cout<<endl;
    cout << "String search ac : " << (trie.search("ac") ? "True" : "False" );
    cout<<endl;
    cout << "String search acdf : " << (trie.search("acdf") ? "True" : "False" );
    cout<<endl;
    cout << "String search ado : " << (trie.search("ado") ? "True" : "False" );
    cout<<endl;
    cout << "String search ab : " << (trie.search("ab") ? "True" : "False" );
    cout<<endl;
    cout << "String search adog : " << (trie.search("adog") ? "True" : "False" );
    cout<<endl;
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
    cout<<"Prefix : prefixCount : isWord"<<endl;
    trie.printTriePrefixes("");
    cout<<endl;

    return 0;
}
