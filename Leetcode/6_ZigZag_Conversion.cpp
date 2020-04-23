// 6. ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1){
            return s;
        }
        vector<string> r(numRows);
        int step = 1;
        int row = 0;
        for(int i = 0; i < s.size(); i++){
            if(row == 0){
                step = 1;
            }else if(row == numRows - 1){
                step = -1;
            }
            r[row] += s[i];
            row += step;
        }
        string result;
        for(int i = 0; i < numRows; i++){
            result += r[i];
        }
        return result;
    }
};