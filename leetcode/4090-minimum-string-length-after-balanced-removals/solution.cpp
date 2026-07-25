class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                }
                else{
                    st.push('a');
                }
            }
            else{
                if(!st.empty() && st.top()=='a'){
                    st.pop();
                }
                else{
                    st.push('b');
                }
            }
        }
        return st.size();
    }
};
