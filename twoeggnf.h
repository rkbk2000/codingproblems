// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/submissions/
// https://brilliant.org/wiki/egg-dropping/
#include <math.h>

class Solution
{
public:
    int twoEggDrop(int n)
    {

        // Quadratic equation
        // x+x(x-1)+(x-2)+...+2+1>=n
        // (x(x+1))/2=n
        // x= (-1 + sqrt(1+8n))/2
        // n = number of floors
        auto min = ceil((-1 + sqrt(1 + (8 * n))) / 2);
        return min;
    }
};