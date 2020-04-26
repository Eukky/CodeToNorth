// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = 0;
        int count = 0;
        int i = 0;
        while(str[i] != '\0'){
            len++;
            if(str[i] == ' '){
                count++;
            }
            i++;
        }
        int newlen = len + count * 2;
        if(newlen > length){
            return;
        }
        while(len != newlen){
            cout << newlen << " " << len << endl;
            cout << str << endl;
            if(str[len] == ' '){
                str[newlen] = '0';
                newlen--;
                str[newlen] = '2';
                newlen--;
                str[newlen] = '%';
                newlen--;
                len--;
            }else{
                str[newlen] = str[len];
                newlen--;
                len--;
            }
        }
        return;
	}
};