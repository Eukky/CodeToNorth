class Solution:
    def validPalindrome(self, s: str) -> bool:
        def isPalindrome(low,high):
            i = low
            j = high
            while i < j:
                if s[i] == s[j]:
                    i += 1
                    j -= 1
                else:
                    return False
            return True
        
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return isPalindrome(i, j-1) or isPalindrome(i+1,j)
        return True