#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums1_cpy = nums1;
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1_cpy[i] < nums2[j])
            {
                nums1[k++] = nums1_cpy[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }
        while (i < m)
            nums1[k++] = nums1_cpy[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
        return;
    }
};

int main(){
    return 0;
}

