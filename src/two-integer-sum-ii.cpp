// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include <vector>

using namespace std;

class Solution {
    vector<int> r(const vector<int> &v, size_t i, size_t j, int target) {
        if (i >= j) return vector<int>{};

        if (v[i] + v[j] == target) return vector<int>{(int)++i, (int)++j};

        if (v[i] + v[j] > target) return r(v, i, --j, target);

        return r(v, ++i, j, target);
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        return r(numbers, 0, numbers.size() - 1, target);
    }
};

