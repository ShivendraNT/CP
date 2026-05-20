class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> count(n+1,0);
        vector<int> C;
        int commoncount=0;
        for(int i=0;i<n;i++){
            if(count[A[i]]==1){
                commoncount++;
            }
            count[A[i]]++;
            if(count[B[i]]==1){
                commoncount++;
            }
            count[B[i]]++;
            C.push_back(commoncount);
        }
        return C;
    }
};
