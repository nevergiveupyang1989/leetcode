#usr/local/bin/python

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        times = 1
        
        wordList = set(wordList)
        visited = set()
        visited.add(beginWord)
        
        while endWord not in visited:
            tmp = set()
            for word in visited:
                for i in xrange(len(word)):
                    word = list(word)
                    saveChar = word[i]

                    for j in range(ord('a'), ord('z')+1):
                        word[i] = chr(j)
                        newword = "".join(word)
                        
                        if newword in wordList:
                            wordList.remove(newword)
                            tmp.add(newword)
                            continue 
                        word[i] = saveChar 

            if len(tmp) == 0:
                return 0

            times = times + 1
            visited = tmp

        return times

if __name__ == "__main__":
    s = Solution()
    beginWord ="hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
    res = s.ladderLength(beginWord,endWord,wordList)
    print res
