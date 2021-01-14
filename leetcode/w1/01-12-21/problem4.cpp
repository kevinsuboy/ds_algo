#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        const int N = arr.size();
        vector<int> arr_cpy = arr;
        int i = 0, j = 0;
        for (; i < N; i++)
        {
            if (j >= N)
                break;
            arr[j++] = arr_cpy[i];
            if (j >= N)
                break;
            if (arr_cpy[i] == 0)
                arr[j++] = arr_cpy[i];
        }
        return;
    }
};

int main(){
    return 0;
}

