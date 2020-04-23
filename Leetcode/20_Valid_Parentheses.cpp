// 20. Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Note that an empty string is also considered valid.

// Example 1:
// Input: "()"
// Output: true

// Example 2:
// Input: "()[]{}"
// Output: true

// Example 3:
// Input: "(]"
// Output: false

// Example 4:
// Input: "([)]"
// Output: false

// Example 5:
// Input: "{[]}"
// Output: true

class Solution {
public:
    bool isValid(string s) {
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        stack<char> last;
        if(s.empty()){
            return true;
        }
        for(int i = 0; i < s.size(); i++){
            if(last.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
            if(s[i] == '('){
                flag1++;
                last.push(s[i]);
            }else if(s[i] == ')'){
                flag1--;
                if(last.top() != '('){
                    return false;
                }
                last.pop();
            }else if(s[i] == '['){
                flag2++;
                last.push(s[i]);
            }else if(s[i] == ']'){
                flag2--;
                if(last.top() != '['){
                    return false;
                }
                last.pop();
            }else if(s[i] == '{'){
                flag3++;
                last.push(s[i]);
            }else if(s[i] == '}'){
                flag3--;
                if(last.top() != '{'){
                    return false;
                }
                last.pop();
            }
        }
        if(flag1 == 0 && flag2 == 0 && flag3 == 0){
            return true;
        }else{
            return false;
        }
    }
};