class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # change wordList to set
        wordSet = set(wordList)

        if endWord not in wordSet:
            return 0

        # queue
        queue = deque([[beginWord, 1]])

        while queue:
            word, lvl = queue.popleft()

            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    cp_word = word[:i] + c + word[i+1:]

                    if cp_word == endWord:
                        return lvl + 1
                    if cp_word in wordSet:
                        wordSet.remove(cp_word)
                        queue.append([cp_word, lvl + 1])

        return 0
