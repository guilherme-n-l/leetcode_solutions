// https://leetcode.com/problems/product-of-array-except-self/description/
#include <vector>

using namespace std;

using iter = vector<int>::const_iterator;

class Solution {
    vector<int> res;

    int r(iter it, const iter &end, int prod = 1) {
        if (it == end) return 1;

        int rest = r(next(it), end, prod * *it);
        res.push_back(prod * rest);

        return *it * rest;
    }

public:
    vector<int> productExceptSelf(vector<int>& nums) {
        r(nums.cbegin(), nums.cend());
        return vector<int>(res.crbegin(), res.crend());
    }
};
