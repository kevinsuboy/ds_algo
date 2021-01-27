#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        unordered_map<char, int> hash;
        const int N = S.length();
        int i = 0, j;
        for (; i < N; i++)
        { // create hash
            hash[S[i]] = i;
        }
        vector<int> res;
        i = 0;
        j = hash[S[i]];
        while (i < N)
        {
            while (i < j)
            { // finding partitions
                j = max(j, hash[S[i++]]);
            }
            //found a partition
            res.push_back(j);
            i++;
            j = hash[S[i]];
        }
        i = res.size() - 1;
        for (; i > 0; i--)
        {
            res[i] -= res[i - 1];
            res[i];
        }
        res[0]++;
        return res;
    }
};
int main(){
    return 0;
}

