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
        unordered_map<int, int>indices; //this will store indexes of vectors values

        int needed = 0; // needed = target - current index value
        
        for(int i = 0; i<nums.size(); i++)
        {
            indices[nums[i]] = i; //value of the vector is stored as key, with their inndexes
        }

        for(int i = 0; i<nums.size(); i++)
        {
            needed = target - nums[i]; //this will be looked at the indices hashtable for the index to be returned

            if((indices.find(needed) != indices.end()) && (indices[needed] != i)) //if the value exists and the index is not same as I
            {
                return {i, indices[needed]};
            }
        }
        
        return {};
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
