class Solution {
public:
    int maxDepth(string s) {
        stack<int> Stack;
        int maxsize=0;
        for (char i:s){
            if(i=='('){
                Stack.push(i);
            }
            else{
                if(Stack.size()>0 && i==')'){
                Stack.pop();
            }
            }
            if(Stack.size()>maxsize){
                maxsize=Stack.size();
            }
        }
        return maxsize;
    }
};
