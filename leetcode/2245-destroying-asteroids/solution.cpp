class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        
        // Use long long to prevent integer overflow during accumulation
        long long current_mass = mass; 
        
        for (int asteroid : asteroids) {
            if (current_mass >= asteroid) {
                current_mass += asteroid;
            } else {
                return false;
            }
        }
        return true;
    }
};
