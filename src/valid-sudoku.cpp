// https://leetcode.com/problems/valid-sudoku/description/
#include <vector>

using namespace std;

constexpr int NUMS_LEN = 9;

class Solution {
    inline int ord(char c) {
        switch (c) {
        case '.': return -1;
        default: return c - '0' - 1;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto &v : board) { // ROWS
            bool nums[NUMS_LEN] {false};

            for (const char &i : v) {
                int idx = ord(i);
                if (idx < 0) continue;

                if (nums[idx]) return false;
                nums[idx] = true;
            }
        }

        for (int j = 0; j < board[0].size(); j++) { // COLUMNS
            bool nums[NUMS_LEN] {false};

            for (int i = 0; i < board.size(); i++) {
                int idx = ord(board[i][j]);
                if (idx < 0) continue;

                if (nums[idx]) return false;
                nums[idx] = true;
            }
        }

        for (int start_i = 0; start_i < board.size(); start_i += 3)
            for (int start_j = 0; start_j < board[0].size(); start_j += 3) { // SUB-BOXES
                bool nums[NUMS_LEN] {0};

                for (int i = start_i; i < start_i + 3; i++)
                    for (int j = start_j; j < start_j + 3; j++) {
                        int idx = ord(board[i][j]);
                        if (idx < 0) continue;
        
                        if (nums[idx]) return false;
                        nums[idx] = true;
                    }
            }

        return true;
    }
};

