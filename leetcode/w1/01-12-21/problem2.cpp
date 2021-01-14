#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        const int N = nums.size();
        int cnt = 0, i = 0;
        while (i < N)
        {
            if (nums[i] != val)
                nums[cnt++] = nums[i];
            i++;
        }
        return cnt;
    }
};

int main(){
    return 0;
}

