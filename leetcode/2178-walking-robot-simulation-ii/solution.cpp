#include <vector>
#include <string>

using namespace std;

class Robot {
public:
    int width, height;
    int x = 0, y = 0, dir = 0;
    
    // East, North, West, South
    vector<int> xdir = {1, 0, -1, 0};
    vector<int> ydir = {0, 1, 0, -1};
    vector<string> directions = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void step(int num) {
        int p = 2 * (width + height - 2);
        num %= p;

        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; 
            else if (x == width - 1 && y == 0) dir = 0;
            else if (x == width - 1 && y == height - 1) dir = 1;
            else if (x == 0 && y == height - 1) dir = 2;
        }

        while (num > 0) {
            int nx = x + xdir[dir];
            int ny = y + ydir[dir];

            
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                dir = (dir + 1) % 4; 
            } else {
                x = nx;
                y = ny;
                num--;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return directions[dir];
    }
};
