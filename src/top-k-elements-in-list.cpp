// https://leetcode.com/problems/top-k-frequent-elements/description/
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int &i : nums) m[i]++;

        vector<pair<int, int>> v(make_move_iterator(m.begin()), make_move_iterator(m.end()));

        sort(
            v.begin(),
            v.end(),
            [](auto &i, auto &j) {return i.second > j.second;}
        );


        vector<int> res;
        res.reserve(k);
        for (auto it = v.cbegin(), end = next(it, k); it != end; it++)
            res.push_back((*it).first);

        return res;
    }
};

