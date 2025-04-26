// https://leetcode.com/problems/group-anagrams/description/
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
    string sorted(string &s) {
        string c = s;
        sort(c.begin(), c.end());
        return c;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ht;

        for (string &s : strs) ht[sorted(s)].push_back(s);

        vector<vector<string>> v;
        v.reserve(ht.size());

        for (auto &[_, val] : ht) v.push_back(::move(val));
        return v;
    }
};

