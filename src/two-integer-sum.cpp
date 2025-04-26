// https://leetcode.com/problems/two-sum/description/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;

        for (int i = 0; i < nums.size(); i++) {
            if (ht.find(nums[i]) != ht.end())
                return {ht[nums[i]], i};

            if (ht.find(target - nums[i]) == ht.end())
                ht[target - nums[i]] = i;
        }

        return {};
    }
};


