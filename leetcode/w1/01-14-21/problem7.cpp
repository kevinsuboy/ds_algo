#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        const int N = nums.size();
        int i = 1;
        // color array with ones count... [1,0,1,1,0] -> [1,0,1,2,0]
        for (; i < N; i++)
            if (nums[i] != 0)
                nums[i] += nums[i - 1];
        i -= 2;
        // color array... [1,0,1,2,0] -> [1,0,2,2,0]
        int res = 1;
        for (; i >= 0; i--)
        {
            if (nums[i] != 0 && nums[i + 1] != 0)
                nums[i] = nums[i + 1];
            res = max(res, nums[i]);
        }
        // find res
        int l, r;
        i++;
        for (; i < N; i++)
        {
            l = (i - 1 >= 0) ? nums[i - 1] : 0;
            r = (i + 1 < N) ? nums[i + 1] : 0;
            if (nums[i] == 0)
                res = max(res, 1 + l + r);
        }
        return res;
    }
};

int main(){
    return 0;
}

