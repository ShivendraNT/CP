class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;
        for (int p : planks) {
            freq[p]++;
        }
        vector<int> unique_planks;
        for (auto& [h, count] : freq) {
            unique_planks.push_back(h);
        }

        int maxwidth = 0;
        unordered_map<int, int> total_width;

        for (auto& [h, count] : freq) {
            total_width[h] += count;
            maxwidth = max(maxwidth, total_width[h]);
        }

        int u_sz = unique_planks.size();
        for (int i = 0; i < u_sz; i++) {
            for (int j = i; j < u_sz; j++) {
                int h = unique_planks[i] + unique_planks[j];
                
                if (i == j) {
                    total_width[h] += freq[unique_planks[i]] / 2;
                } else {
                    total_width[h] += min(freq[unique_planks[i]], freq[unique_planks[j]]);
                }
                
                maxwidth = max(maxwidth, total_width[h]);
            }
        }
        return maxwidth;
    }
};
