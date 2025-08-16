class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end() or beginWord == endWord)
            return 0;
            
        queue<string> Q;
        Q.push(beginWord);
        int ans = 0;

        while (!Q.empty()) {
            int qSize = Q.size();
            ans++;
            for (int i = 0; i < qSize; i++) {
                string node = Q.front();
                Q.pop();

                if (node == endWord)
                    return ans;

                for (int j = 0; j < node.size(); j++) {
                    char original = node[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (original == ch)
                            continue;
                        node[j] = ch;
                        if (words.find(node) != words.end()) {
                            Q.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }
        return 0;
    }
};