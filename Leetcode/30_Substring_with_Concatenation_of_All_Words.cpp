// 30. Substring with Concatenation of All Words
// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// Example 1:
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.

// Example 2:
// Input:
//   s = "wordgoodgoodgoodbestword",
//   words = ["word","good","best","word"]
// Output: []

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.size() == 0 || words.size() == 0){
            return result;
        }
        unordered_map<string, int> map;
        int len = words[0].size();
        int n = words.size();
        if(s.size() < len * n){
            return result;
        }
        bool flag = true;
        for(int i = 0; i <= s.size() - len * n; i++){
            map.clear();
            for(string word : words){
            map[word]++;
            }
            string stmp = s.substr(i, len * n);
            for(int j = 0; j <= stmp.size() - len; j = j + len){
                map[stmp.substr(j, len)]--;
                if(map[stmp.substr(j, len)] < 0){
                    flag = false;
                    break;
                }else{
                    flag = true;
                }
            }
            if(flag == true){
                result.push_back(i);
            }
        }
        return result;
    }
};