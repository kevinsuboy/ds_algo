#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;
        else
            return (high - low) / 2 + 1;
    }
};
int main()
{
    return 0;
}
