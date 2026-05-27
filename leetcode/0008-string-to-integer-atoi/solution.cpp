class Solution {
public:
    int helper(string s, int i,double sum,int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return sum*sign;
        }
        sum=sum*10 + (int)s[i]-48;

        if(sign==1&&sum>INT_MAX) return INT_MAX;
        if(sign==-1&&-sum<INT_MIN) return INT_MIN;

        return helper(s,i+1,sum,sign);

    }
    int myAtoi(string s) {
        int i=0;
        double sum=0;
        int sign=1;
        while(i<s.size() && s[i]==' ') i++;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        sum=helper(s,i,sum,sign);
        return sum;
    }
};
