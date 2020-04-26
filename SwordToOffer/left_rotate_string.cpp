// 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str == ""){
            return str;
        }
        int size = str.size();
        for(int i = 0, j = n - 1; j > i; ++i, --j){
            swap(str[i], str[j]);
        }
        for(int i = n, j = size - 1; j > i; ++i, --j){
            swap(str[i], str[j]);
        }
        for(int i = 0, j = size - 1; j > i; ++i, --j){
            swap(str[i], str[j]);
        }
        return str;
        
    }
};