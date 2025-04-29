// https://leetcode.com/problems/trapping-rain-water/description/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int max_le, max_ri;

    int r(vector<int> &v, int le, int ri) {
        if (le == ri) return 0;

        int sum = max(0, min(max_le, max_ri) - min(v[le], v[ri]));
        max_le = max(max_le, v[le]), max_ri = max(max_ri, v[ri]);

        return sum + r(v, max_le > max_ri ? le : le + 1, max_le > max_ri ? ri - 1 : ri);
    }

public:
    int trap(vector<int>& height) {
        max_le = *height.cbegin(), max_ri = *height.crbegin();
        return r(height, 0, height.size() - 1);
    }
};
