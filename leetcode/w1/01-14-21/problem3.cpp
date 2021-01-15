#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        const int N = arr.size();
        if (N < 3)
            return false;
        int i = 0;
        while (i < N - 1 && arr[i] <= arr[i + 1])
        { // check for strict incr
            if (arr[i] == arr[i + 1])
                return false;
            i++;
        }
        if (i == 0 || i == N - 1)
            return false; // no room from decr
        while (i < N - 1 && arr[i] >= arr[i + 1])
        { // check for strict decr
            if (arr[i] == arr[i + 1])
                return false;
            i++;
        }
        return i == N - 1; // needs to have finished the arr
    }
};

int main(){
    return 0;
}

