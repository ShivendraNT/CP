class Solution {
public:
    void generate(vector<string>& result, const string& num, string path, int i, int target, long long currsum, long long prev_op) {
        if (i == num.size()) {
            if (currsum == target) result.push_back(path);
            return;
        }

        for (int j = i; j < num.size(); j++) {
            // Prevent leading zeros for multi-digit numbers (e.g., "05" is invalid)
            if (j > i && num[i] == '0') break; 
            
            string part = num.substr(i, j - i + 1);
            long long n = stoll(part);

            if (i == 0) {
                generate(result, num, part, j + 1, target, n, n);
            } else {
                // Addition
                generate(result, num, path + '+' + part, j + 1, target, currsum + n, n);
                // Subtraction
                generate(result, num, path + '-' + part, j + 1, target, currsum - n, -n);
                // Multiplication: Backtrack the previous operand to maintain precedence
                generate(result, num, path + '*' + part, j + 1, target, currsum - prev_op + (prev_op * n), prev_op * n);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        generate(result, num, "", 0, target, 0, 0);
        return result;
    }
};
