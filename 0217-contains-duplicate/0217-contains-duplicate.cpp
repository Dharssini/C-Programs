class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return distance(unique(nums.begin(), nums.end()), nums.end());
    }
         
};