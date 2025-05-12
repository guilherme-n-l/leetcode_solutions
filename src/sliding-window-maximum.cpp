// https://leetcode.com/problems/sliding-window-maximum/description/
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> ht;
        vector<int> res;
        for (int i = 0, j = 0; j < nums.size(); i += ++j >= k ? 1: 0) {
            ht[nums[j]]++;
            if (j < k - 1) continue;
            if (i && !--ht[nums[i - 1]]) ht.erase(nums[i - 1]);
            res.push_back((*ht.rbegin()).first);
        }

        return res;
    }
};
