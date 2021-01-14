#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        const int N = nums.size();
        int i = 0, j = N - 1, k = N - 1;
        vector<int> res(N);
        while (i <= j)
        {
            if (abs(nums[i]) < abs(nums[j]))
            {
                res[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                res[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}

