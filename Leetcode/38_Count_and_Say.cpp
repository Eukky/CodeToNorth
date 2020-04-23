// 38. Count and Say
// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:
// Input: 1
// Output: "1"

// Example 2:
// Input: 4
// Output: "1211"

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if(n == 1){
            return result;
        }
        while(n > 1){
            string tmp = "";
            int count = 0;
            char ch = '\0';
            for(int i = 0; i < result.size(); ++i){
                if(count == 0){
                    ch = result[i];
                }
                count++;
                if((result[i] != result[i + 1] && i < result.size() - 1) || i == result.size() - 1){
                    tmp += count + '0';
                    tmp += ch;
                    count = 0;
                }    
            }
            n--;
            result = tmp;        
        }
        return result;
    }
};