class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for(char c: s){
            if(c=='('){
                if(!st.empty()) res += c;
                st.push(c);
            }
            else{
                st.pop();
                if(!st.empty()) res += c;
            }
        }
        return res;
    }
};
