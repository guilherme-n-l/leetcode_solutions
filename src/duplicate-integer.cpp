// https://leetcode.com/problems/contains-duplicate/description/
#include <set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        bool has = false;

        for (int &i : nums) {
            if ((has |= s.find(i) != s.end())) break;
            s.insert(i);
        }

        return has;
    }
};
