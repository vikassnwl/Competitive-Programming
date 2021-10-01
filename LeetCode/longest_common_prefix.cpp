class Solution {
public:
    
    struct Trie{
        map<char, Trie*> mp;  
    };
    
    Trie* getNode(){
        Trie* node = new Trie;
        return node;
    }
    
    void insert(Trie* root, string s){
        Trie* tempRoot = root;
        for(char c: s){
            if(tempRoot->mp.find(c)==tempRoot->mp.end()){
                tempRoot->mp[c] = getNode();
            }
            tempRoot = tempRoot->mp[c];
        }
        tempRoot->mp['*'];
    }
	
    string res = "";
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = getNode();
        for(string s: strs){
            insert(root, s);
        }
        Trie* tempRoot = root;
        while(tempRoot->mp.size()==1 and tempRoot->mp.find('*')==tempRoot->mp.end()){
            for(auto x: tempRoot->mp){
                res += x.first;
                tempRoot = tempRoot->mp[x.first];
            }
        }
        return res;
    }
};
