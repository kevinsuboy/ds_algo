#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string res = "(";
        int O = 1, C = 0;
        vector<string> arr;
        recursive(arr, res, O, C, n);
        return arr;
    }

private:
    void recursive(vector<string> &arr, string res, int O, int C, int &n)
    {
        if (res.length() == 2 * n)
        {
            arr.push_back(res);
            return;
        }
        if (O < n)
            recursive(arr, res + "(", O + 1, C, n); // left case
        if (C < O)
            recursive(arr, res + ")", O, C + 1, n); // right case
        return;
    }
};
int main(){
    return 0;
}

