// https://neetcode.io/problems/three-integer-sum
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (auto it = nums.begin(); it <= nums.end() - 3;) {
            auto it2 = it + 1, it3 = nums.end() - 1;

            while (it2 < it3) {
                int dif = *it + *it2 + *it3;
                
                if (!dif) {
                    res.push_back({*it, *it2, *it3});

                    while (*it3 == res[res.size() - 1][2])
                        if (it2 >= --it3) break;

                    while (*it2 == res[res.size() - 1][1])
                        if (++it2 >= it3) break;

                    continue;
                }

                if (dif > 0) {
                    *it3--;
                    continue;
                }
                
                *it2++;
            }

            int val = *it;

            while (*it == val)
                if (++it > nums.end() - 3) break;
        }

        return res;
    }
};
