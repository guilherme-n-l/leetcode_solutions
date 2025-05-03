// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <string>
#include <algorithm>
#include <bitset>
#include <cstddef>

using namespace std;

constexpr size_t ASCII_LEN = 128; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<ASCII_LEN> bs;
        int max_len = 0, len = 0;

        for (auto l = s.cbegin(), r = l; r != s.cend(); r++) {
            if (bs.test(*r)) do bs.reset(*l), len--; while (*l++ != *r);
            bs.set(*r), max_len = max(max_len, ++len);
        }

        return max_len;
    }
};
