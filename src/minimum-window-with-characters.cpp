#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    inline bool has(unordered_map<char, int> &ht, char c) {
        return ht.find(c) != ht.cend();
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ht; for (char &c : t) ht[c]++;
        int incomplete = ht.size();

        string res = "";
        int le = 0, ri = 0;

        while (ri < s.size() || (min(ri, (int)s.size() - 1) - le + 1 > t.size() && !incomplete)) {
            while (ri < s.size()) {
                if (!has(ht, s[ri]) || (incomplete -= !--ht[s[ri]] ? 1 : 0)) {
                    ri++;
                    continue;
                }

                break;
            }

            bool completed = false;
            while (!incomplete) {
                if (!has(ht, s[le])) {
                    le++;
                    continue;
                }

                completed = true;
                incomplete += !ht[s[le++]]++ ? 1 : 0;
            }

            if (completed && (res.empty() || min(ri, (int)s.size() - 1) - max(le - 1, 0) + 1 < res.size()))
                res = s.substr(max(le - 1, 0), min(ri, (int)s.size() - 1) - max(le - 1, 0) + 1);

            ri = min(ri + 1, (int)s.size());
        }

        return res;
    }
};
