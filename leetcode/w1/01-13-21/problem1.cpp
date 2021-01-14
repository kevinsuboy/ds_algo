#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        int prev;
        for (auto a : asteroids)
        {
            if (a > 0)
                s.push(a);
            else
            {
                if (!s.empty())
                    prev = s.top();
                else
                    prev = 0;
                while (prev > 0 && -a > prev)
                {
                    s.pop();
                    if (!s.empty())
                        prev = s.top();
                    else
                        prev = 0;
                }
                if (prev < 0 || s.empty())
                    s.push(a);
                else if (prev == -a)
                    s.pop();
            }
        }
        vector<int> res(s.size());
        while (!s.empty())
        {
            res[s.size() - 1] = s.top();
            s.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tests{{5, 10, -5}, {8, -8}, {10, 2, -5}, {-2, -1, 1, 2}};
    //
    vector<int> res;
    for (auto t : tests)
    {
        res = sol.asteroidCollision(t);
        cout << "[";
        for (auto r : res)
        {
            cout << r << " ";
        }
        cout << "]";
        cout << endl;
    }
}
