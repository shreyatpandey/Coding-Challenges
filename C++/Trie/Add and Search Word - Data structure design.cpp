/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class WordDictionary {
private:
    struct Trie {
      unordered_map<char, Trie*> tr;  
      bool isWord = false;
    };
    Trie trie;
    
    bool search(Trie* trie, string& s, int i) {
        if(i == s.size() && trie->isWord) {            
            return true;
        }
        if(i == s.size() + 1) {
            return false;
        }
        if(s[i] != '.') {
            if(trie->tr.find(s[i]) == trie->tr.end()) {
                return false;
            } else {
                return search(trie->tr[s[i]], s, i+1);
            }
        }else{
            for(auto p:trie->tr) {
                if(search(p.second, s, i+1)) {
                    return true;
                }
            }
            return false;
        }
    }    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = &trie;
        for(auto c:word) {
            if(p->tr.find(c) == p->tr.end()) {
                p->tr[c] = new Trie;
            }
            p = p->tr[c];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return search(&trie, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
