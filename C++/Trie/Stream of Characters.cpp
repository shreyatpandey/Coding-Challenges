//Approach-1: Using Deque
// 23.58% faster
//TC: O(W*L) where W is no of input words and L is the length of each word
//SC: O(W*L)
class TrieNode{
    public:
    unordered_map<char,TrieNode*>branches;
    bool word = false;
    
};

class StreamChecker {
    TrieNode* p_TrieNode = new TrieNode();
    deque<char>stream ;
    
public:
    StreamChecker(vector<string>& words) {
        for ( auto &x:words)
        {
            TrieNode* p_Node = p_TrieNode ;
            reverse(x.begin(),x.end());
            for ( auto &ch:x)
            {
                if ( p_Node->branches[ch] == NULL)
                {
                     p_Node->branches[ch]=new TrieNode();
                }
                p_Node = p_Node->branches[ch];
            }
            p_Node->word = true;
            
        }
    }
    
    bool query(char letter) {
        stream.emplace_front(letter);
        TrieNode* p_QueryNode = p_TrieNode;
        for ( auto &ch:stream)
        {
            if ( p_QueryNode->word == true)
            {
                return true;
            }
             if ( p_QueryNode->branches.count(ch) ==  0 )
             {
                 return false;
             }
            p_QueryNode = p_QueryNode->branches[ch];
        }
        return p_QueryNode->word;
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
