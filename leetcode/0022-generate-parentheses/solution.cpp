class Solution {
public:
    void generate(vector<string> & result,string curr,int openbracket,int curropen,int n){
        if(curr.size()==n*2){
            result.push_back(curr);
            return;
        }
        if(curropen==0){
            generate(result,curr+"(",openbracket+1,curropen+1,n);
        }
        else if(openbracket==n){
            generate(result,curr+")",openbracket,curropen-1,n);
        }
        else{
            generate(result,curr+"(",openbracket+1,curropen+1,n);
            generate(result,curr+")",openbracket,curropen-1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result,"",0,0,n);
        return result;
    }
};
