class Solution:
    def largestOddNumber(self, num: str) -> str:
        ln = len(num) - 1
        for i in range(ln, -1, -1):
            ch = num[i]
            if int(ch) % 2 != 0:
                return num[:i + 1]
        return ""
