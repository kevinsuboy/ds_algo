#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int res = 0;
        int cnt = 0;
        for (auto n : nums)
        {
            cnt = 0;
            while (n > 0)
            {
                cnt++;
                n /= 10;
            }
            if (cnt % 2 == 0)
                res++;
        }
        return res;
    }
};

int main(){
    return 0;
}

