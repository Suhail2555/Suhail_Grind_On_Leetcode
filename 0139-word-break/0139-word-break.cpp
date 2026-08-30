#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        int max_len = 0;
        for (const std::string& word : wordDict) {
            max_len = std::max(max_len, (int)word.length());
        }
        
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= std::max(0, i - max_len); --j) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};