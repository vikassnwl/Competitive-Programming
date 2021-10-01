class Solution {
public:
    
    bool valid_par(string s){
        stack<char> st;
        for(char c: s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        for(int i=0; i<n; i++)
            s += "()";
        sort(s.begin(), s.end());
        do{
            if(valid_par(s)) v.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return v;
    }
};
