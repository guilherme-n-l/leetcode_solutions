// https://leetcode.com/problems/encode-and-decode-strings/description/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (string &s : strs) {
            res += to_string(s.size()).size() + '0'; // n_digits
            res += to_string(s.size()); // n_chars
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        auto it = s.cbegin();
        
        vector<string> res;
        while (it != s.cend()) {
            char n_digits = (*it++) - '0';
            unsigned char n_chars = stoi(string(it, next(it, n_digits)));
            it += n_digits;
            
            res.push_back(string(it, next(it, n_chars)));
            it += n_chars;
        }
        
        return res;
    }
};

