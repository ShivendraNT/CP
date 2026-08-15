class Solution {
public:
    
    int kthDigit(long long k) {
        vector<long long> count;
        count.push_back(9);
        long long power_of_10 = 10;

        for (int i = 2; i <= 15; i++) {
            count.push_back(1LL * 9 * power_of_10 * i);
            power_of_10 *= 10; 
        }
        int i=0;
        for(;i<count.size();i++){
            if(k<=count[i]){
                break;
            }
            k-=count[i];
        }
        k-=1;
        i++;
        long long b;
        if(i==1){
            b=0;
        }
        else{
            b=1;
            for (int j = 2; j < i; j++) {
                b *= 10;
            }
        }
        long long passed=k/(i*10);
        b+=passed;
        long long want=k%(i*10);
        long long num_index = want / i;
        int digit_index = want % i;
        long long actual_number;
        if(b==0){
            actual_number=num_index+1;
        }
        else if (b % 2 == 0) {
            actual_number=b*10+num_index;
        }
        else{
            actual_number=b*10+(9-num_index);
        }
        string num_str = to_string(actual_number);
        return num_str[digit_index] - '0';
    }
};
