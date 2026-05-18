class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stack;
        string result="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(stack.empty()){
                    stack.push('(');
                    continue;
                }
                else{
                    stack.push('(');
                    result+='(';
                }
            }
            else{
                stack.pop();
                if(stack.empty()){
                    continue;
                }
                result+=')';
            }
        }
        return result;
    }
};
