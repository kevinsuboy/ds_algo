#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> hash;
        for (auto a : arr)
        {
            if (a % 2 == 0)
            {
                if (hash.find(a / 2) != hash.end())
                    return true;
            }
            if (hash.find(a * 2) != hash.end())
                return true;
            hash.insert(a);
        }
        return false;
    }
};

int main(){
    return 0;
}

