// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

class Solution {
    void reverse(string &str, int left, int right){
        while(left < right){
            swap(str[left++], str[right--]);
        }
    }
public:
    string ReverseSentence(string str) {
        if(str == ""){
            return str;
        }
        reverse(str, 0, str.size() - 1);
        int left = -1; 
        int right = 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == ' '){
                right = i;
                reverse(str, left + 1, right - 1);
                left = right;
            }
        }
        reverse(str, left + 1, str.size() - 1);
        return str;
        
    }
};