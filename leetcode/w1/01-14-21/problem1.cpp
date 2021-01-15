#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        const int N = nums.size();
        int i = 1;
        int res = nums[0];
        for (; i < N; i++)
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            res = max(nums[i], res);
        }
        return res;
    }
};

int main(){
    return 0;
}

