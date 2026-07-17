class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                diff[left]++;
                diff[right + 1]--;
            }
        }
        
        vector<bool> illuminated(n, false);
        int current_lights = 0;
        for (int i = 0; i < n; i++) {
            current_lights += diff[i];
            if (current_lights > 0) {
                illuminated[i] = true;
            }
        }
        
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (!illuminated[i]) {
                ans++;
                i += 3; 
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
