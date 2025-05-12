// https://leetcode.com/problems/valid-parentheses/description/
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &c : s) {
            switch (c) {
            case '(': case '[': case '{':
                st.push(c);
                break;
            default:
                if (st.empty() || st.top() != c - (c == ')' ? 1 : 2)) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
