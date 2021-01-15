#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int i = arr.size() - 1;
        int prev = arr[i], tmp;
        arr[i--] = -1;
        for (; i >= 0; i--)
        {
            tmp = arr[i];
            arr[i] = max(arr[i + 1], prev);
            prev = tmp;
        }
        return arr;
    }
};

int main(){
    return 0;
}

