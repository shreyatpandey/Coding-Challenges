/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

*/


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(bool end=false) {
        isEnd=end;
    }
    unordered_map<char,TrieNode*> branches;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        destroy(root);
    }

    void destroy(TrieNode* node) {
        for(auto entry : node->branches)
            destroy(entry.second);
        delete node;
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node=root;
        int i;
        for(i=0;i<s.size();i++) {
            if(node->branches.find(s[i])==node->branches.end())
                break;
            else {
                node=node->branches[s[i]];
                node->isEnd=((i==s.size()-1)?true:node->isEnd);
            }
        }
        for(;i<s.size();i++) {
            node->branches[s[i]]=new TrieNode(i==s.size()-1?true:false);
            node=node->branches[s[i]];
        }
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* node=root;
        for(int i=0;i<key.size();i++)
            if(node->branches.find(key[i])==node->branches.end())
                return false;
            else
                node=node->branches[key[i]];
        if(node->isEnd)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++)
            //if(node->branches[prefix[i]]==NULL)
            if(node->branches.find(prefix[i])==node->branches.end())
                return false;
            else
                node=node->branches[prefix[i]];
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
