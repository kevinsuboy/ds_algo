#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int cur = 0;
        for (auto n : nums)
        {
            if (n == 1)
                cur += 1;
            else
                cur = 0;
            res = max(res, cur);
        }
        return res;
    }
};

int main(){
    return 0;
}

