#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int N = nums.size();
        int wr = 0, rd = 0;
        while (rd < N)
        {
            if (nums[rd] != 0)
                nums[wr++] = nums[rd];
            rd++;
        }
        while (wr < N)
            nums[wr++] = 0;
        return;
    }
};

int main(){
    return 0;
}

