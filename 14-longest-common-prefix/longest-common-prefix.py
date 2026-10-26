class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        
        # Start with the first string as your prefix base
        prefix = strs[0]
        
        for string in strs[1:]:
            # Shorten the prefix until the current string starts with it
            while not string.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
                    
        return prefix

        