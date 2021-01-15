#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        set<int>::iterator sit;
        for (auto n : nums)
        {
            s.insert(n);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        sit = s.end();
        sit--;
        if (s.size() < 3)
            return *sit;
        else
        {
            sit--;
            sit--;
            return *sit;
        }
    }
};

int main(){
    return 0;
}

