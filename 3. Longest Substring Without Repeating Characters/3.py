class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        head = 0
        maxLength = 0
        seen = {}
        length = len(s)
        for tail in range(length):
            while(s[tail] in seen):
                seen.pop(s[head])
                head += 1
            
            if s[tail] not in seen:
                maxLength = (tail - head + 1) if (tail - head + 1) > maxLength else maxLength
                seen[s[tail]] = tail
                
        return maxLength