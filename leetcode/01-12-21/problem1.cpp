#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        const int N = nums.size();
        int cnt = 0, i = 0;
        while (i < N)
        {
            nums[cnt++] = nums[i++];
            while (i < N && nums[i - 1] == nums[i])
                i++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tests{{1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};
    //
    int res;
    for (auto t : tests)
    {
        res = sol.removeDuplicates(t);
        cout << "[";
        for (auto r : t)
        {
            cout << r << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}
