// https://leetcode.com/problems/valid-anagram/
#include <string>

using namespace std;

constexpr int LETTERS = 26;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int s1[LETTERS] {0}, t1[LETTERS] {0};

        for (int i = 0; i < s.size(); i++) {
            s1[s[i] - 'a']++;
            t1[t[i] - 'a']--;
        }

        for (int i = 0; i < LETTERS; i++)
            if (s1[i] + t1[i]) return false;

        return true;
    }
};

