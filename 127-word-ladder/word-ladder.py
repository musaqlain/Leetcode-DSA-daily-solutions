from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # Convert wordList to set for O(1) lookups
        wordSet = set(wordList)
        
        # If endWord is not in wordList, return 0
        if endWord not in wordSet:
            return 0

        # Initialize queue for BFS
        queue = deque([[beginWord, 1]])  # Start with level 1

        while queue:
            word, lvl = queue.popleft()

            # Try changing each letter in the word
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    cp_word = word[:i] + c + word[i + 1:]

                    if cp_word == endWord:
                        return lvl + 1
                    
                    if cp_word in wordSet:
                        wordSet.remove(cp_word)  # Mark as visited
                        queue.append([cp_word, lvl + 1])
        
        return 0  # No transformation sequence found
