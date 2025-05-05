// https://leetcode.com/problems/permutation-in-string/description/
#include <string>

using namespace std;

constexpr int LEN_ABC = 26;

class Solution {
    inline int ord(char c) {return c - 'a';}

    bool check(int *c1, int *c2) {
        for (int i = 0; i < LEN_ABC; i++)
            if (c1[i] && (c1[i] + c2[i])) return false;

        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int c1[LEN_ABC] {0}, c2[LEN_ABC] {0};
        for (char &c : s1) c1[ord(c)]--;
        
        for (int le = 0, ri = 0; ri < s2.size(); ri++, (le = ri < s1.size() ? le : ++le)) {
            c2[ord(s2[ri])]++;
            if (le) c2[ord(s2[le - 1])]--;
            if (check(c1, c2)) return true;
        }

        return false;
    }
};
