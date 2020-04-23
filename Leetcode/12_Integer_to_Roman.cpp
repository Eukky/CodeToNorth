// 12. Integer to Roman
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:
// Input: 3
// Output: "III"

// Example 2:
// Input: 4
// Output: "IV"

// Example 3:
// Input: 9
// Output: "IX"

// Example 4:
// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.

// Example 5:
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int I = num % 10;
        int X = num / 10 % 10;
        int C = num / 100 % 10;
        int M = num / 1000 % 10;
        for(int i = 0; i < M; i++){
            result += 'M';
        }
        if(C == 4){
            result += "CD";
        }else if(C == 9){
            result += "CM";
        }else if(C >= 5){
            result += 'D';
            for(int i = 0; i < C - 5; i++){
                result += 'C';
            }
        }else if (C < 4){
            for(int i = 0; i < C; i++){
                result += 'C';
            }
        }
        if(X == 4){
            result += "XL";
        }else if(X == 9){
            result += "XC";
        }else if(X >= 5){
            result += 'L';
            for(int i = 0; i < X - 5; i++){
                result += 'X';
            }
        }else if (X < 4){
            for(int i = 0; i < X; i++){
                result += 'X';
            }
        }
        if(I == 4){
            result += "IV";
        }else if(I == 9){
            result += "IX";
        }else if(I >= 5){
            result += 'V';
            for(int i = 0; i < I - 5; i++){
                result += 'I';
            }
        }else if (I < 4){
            for(int i = 0; i < I; i++){
                result += 'I';
            }
        }
        return result;
        
    }
};