// 28. Implement strStr()
// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        if(haystack.size() < needle.size()){
            return -1;
        }
        if(haystack == needle){
            return 0;
        }
        int i = 0;
        for(i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(int j = 0; j < needle.size(); j++){
                    if(haystack[i + j] != needle[j]){
                        break;
                    }
                    if(j == needle.size() - 1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};



#include <string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        
        if (haystack.find(needle) != string::npos) {
            size_t found = haystack.find(needle);
            return found;
        }
        else {
            return -1;
        }
    }
};