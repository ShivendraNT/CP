class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        vector<char> stack={};
        int top=-1;
        for (char i : s){
            if (i=='('){
                if(!stack.empty()){
                    result+=i;
                }
                stack.push_back(i);
            }

            else{
                stack.pop_back();
                if(!stack.empty()){
                    result+=i;
                }
            }
        }
        return result;
    }
};
