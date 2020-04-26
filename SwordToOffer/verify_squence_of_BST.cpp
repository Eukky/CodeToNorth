// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
    bool judge(vector<int> sequence, int l, int r){
        if(sequence.size() == 0 || l > r){
            return false;
        }
        int num = sequence[r];
        int i = l;
        for(; i < r; ++i){
            if(sequence[i] > num){
                break;
            }
        }
        for(int j = i; j < r; ++j){
            if(sequence[j] < num){
                return false;
            }
        }
        bool left = true;
        if(i > l){
            left = judge(sequence, l, i - 1);
        }
        bool right = true;
        if(r - 1 > i){
            right = judge(sequence, i, r - 1);
        }
        return left && right;
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
         
        return judge(sequence, 0, sequence.size() - 1);
    }
};