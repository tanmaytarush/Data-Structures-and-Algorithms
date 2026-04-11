/*

Leetcode Link -> https://leetcode.com/problems/walking-robot-simulation/description/

A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

Note:

There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
 

Example 1:

Input: commands = [4,-1,3], obstacles = []

Output: 25

Explanation:

The robot starts at (0, 0):

Move north 4 units to (0, 4).
Turn right.
Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.

Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]

Output: 65

Explanation:

The robot starts at (0, 0):

Move north 4 units to (0, 4).
Turn right.
Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
Turn left.
Move north 4 units to (1, 8).
The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

Example 3:

Input: commands = [6,-1,-1,6], obstacles = [[0,0]]

Output: 36

Explanation:

The robot starts at (0, 0):

Move north 6 units to (0, 6).
Turn right.
Turn right.
Move south 5 units and get blocked by the obstacle at (0,0), robot is at (0, 1).
The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.
 

Constraints:

1 <= commands.length <= 104
commands[i] is either -2, -1, or an integer in the range [1, 9].
0 <= obstacles.length <= 104
-3 * 104 <= xi, yi <= 3 * 104
The answer is guaranteed to be less than 231.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    static const long long HASH_MULTIPLIER = 60013; // next prime beyond largest INT
    long long hashCoordinates(long long x, long long y)
    {
        return x + HASH_MULTIPLIER * y;
    }

    int roboSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<long long> obstacleSet;
        for(auto &obstacle : obstacles)
        {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }

        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistance = 0;
        int currentDirection = 0;
        
        for(int command : commands)
        {
            if(command == -1)
            {
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if(command == -2)
            {
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            vector<int> direction = directions[currentDirection];
            for(int step = 0; step < command; ++step)
            {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                
                if(obstacleSet.find(hashCoordinates(nextX, nextY)) != obstacleSet.end())
                {
                    break;
                }

                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistance = max(maxDistance, currentPosition[0]*currentPosition[0] + currentPosition[1]*currentPosition[1]);
        }

        return maxDistance;
    }
};

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> commands(n);
    for(int i=0; i<n; ++i)
    {
        cin>>commands[i];
    }

    vector<vector<int>> obstacles(m, vector<int>(2));
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            cin>>obstacles[i][j];
        }
    }

    Solution sol;
    int result = sol.roboSim(commands, obstacles);
    cout<<result;

    return 0;
}