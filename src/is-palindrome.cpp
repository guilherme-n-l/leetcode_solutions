// https://leetcode.com/problems/valid-palindrome/description/
#include <string>
#include <cctype>

using namespace std;

class Solution {
    bool r(string &s, size_t i, size_t j) {
        if (i >= j) return true;
        if (!isalnum(s[i])) return r(s, ++i, j);
        if (!isalnum(s[j])) return r(s, i, --j);
        return tolower(s[i]) == tolower(s[j]) && r(s, ++i, --j);
    }
public:
    bool isPalindrome(string s) {
        return !s.size() || r(s, 0, s.size() - 1);
    }
};
