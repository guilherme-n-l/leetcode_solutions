// https://leetcode.com/problems/container-with-most-water/description/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    inline int area(vector<int> &v, int i, int j) {
        return (j - i) * min(v[i], v[j]);
    }

    inline int argmin(vector<int> &v, int i, int j) {
        return v[i] > v[j] ? j : i;
    }

    int r(vector<int> &v, int i, int j) {
        if (i >= j) return 0;
        int am = argmin(v, i, j);
        return max(area(v, i, j), r(v, am == i ? i + 1 : i, am == j ? j - 1 : j));
    }
public:
    int maxArea(vector<int>& heights) {
        return r(heights, 0, heights.size() - 1);
    }
};
