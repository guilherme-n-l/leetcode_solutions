// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Solution using sets
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(make_move_iterator(nums.begin()), make_move_iterator(nums.end())), visited;

        int res = 0;
        for (const int &i : s) {
            if (visited.find(i) != visited.end()) continue;

            int tmp_i = i - 1, tmp = 1;
            while (s.find(tmp_i) != s.end()) visited.insert(tmp_i--), tmp++;
            tmp_i = i + 1;
            while (s.find(tmp_i) != s.end()) visited.insert(tmp_i++), tmp++;

            res = max(res, tmp);
        }

        return res;
    }
};

// Solution using hashtables
class Solution2 {
    template<typename K, typename V> bool has(unordered_map<K, V> &ht, K &&k) {
        return ht.find(k) != ht.end();
    }

public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> ht;

        for (int &n : nums) {
            if (has(ht, n + 0))
                continue;

            int u_v = n;
            if (has(ht, n + 1)) {
                u_v = max(max(n + 1, ht[n + 1]), n);

                if (u_v != n && abs(ht[u_v] - u_v) > abs(n - u_v)) continue;
                if (u_v != ht[n + 1] && ht[n + 1] != n + 1) ht.erase(ht[n + 1]);
                if (u_v != n + 1) ht.erase(n + 1);
            }

            int l_v = n;
            if (has(ht, n - 1)) {
                l_v = min(min(n - 1, ht[n - 1]), n);
                
                if (l_v != n && abs(ht[l_v] - l_v) > abs(n - l_v)) continue;
                if (l_v != ht[n - 1] && ht[n - 1] != n - 1) ht.erase(ht[n - 1]);
                if (l_v != n - 1) ht.erase(n - 1);
            }

            ht[l_v] = u_v;
            ht[u_v] = l_v;
        }

        int res = 0;

        for (auto &p : ht) res = max(res, abs(p.first - p.second));

        return res + 1;
    }
};
