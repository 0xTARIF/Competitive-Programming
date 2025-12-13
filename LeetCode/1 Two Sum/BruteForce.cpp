/**
 * author       :   Tarif Bin Mehedi
 * created at   :   13th december 2025
 * Leetcode 1   :   Two Sum
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>twoSum(vector<int>& nums, int target) {
        // let 
        // Input: nums = [2,7,11,15], target = 9
        // Output: [0,1]
        int n = nums.size(); //size of the nums for loop
        int needed = 0;     //target - current index value for finding required value
        int firstIndex = 0; //will store current index
        int secondIndex = 0; //will store another index which will be paired with the first index to add up with target

        for(int i = 0; i<n; i++)
        {
            needed = target - nums[i];
            firstIndex = i;
            for(int j = i+1; j<n; j++)
            {
                if(nums[j] == needed)
                {
                    return {i, j}; //this is how to return a vector. Guaranteed to find solution stated by leetcode
                }
            }
        }
    return {}; //since it will return something from inside
         
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;

    vector<int>nums = {3,2,4};
    int target = 6;

    vector<int>result = sol.twoSum(nums, target); //since return {i, j} is used, this represents the vector format

    cout<<"["<<result[0]<<","<<result[1]<<"]";

    return 0;
}
