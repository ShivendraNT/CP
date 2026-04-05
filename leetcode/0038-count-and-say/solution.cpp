class Solution {
public:

    string counts(int n){
        if(n==1){
            return "1";
        }
        string rle=counts(n-1);
        string s;
        int l=rle.size();
        int sum=1;
        for(int i=0;i<l-1;i++){
            if(rle[i]==rle[i+1]){
                sum++;
                continue;
            }
            s+=to_string(sum);
            s+=rle[i];
            sum=1;
        }
        s+=to_string(sum);
        s+=rle[l-1];
        return s;
    }
    string countAndSay(int n) {
        string s=counts(n);
        return s;
    }
};
