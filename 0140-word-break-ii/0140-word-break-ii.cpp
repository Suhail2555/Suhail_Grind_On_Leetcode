class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(string &s, int start) {
        // If we reached the end
        if (start == s.size()) {
            return {""};
        }

        // Already calculated
        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> result;

        // Try every possible word
        for (int end = start; end < s.size(); end++) {
            string word = s.substr(start, end - start + 1);

            // If word is present in dictionary
            if (dict.count(word)) {

                vector<string> remaining = solve(s, end + 1);

                for (string sentence : remaining) {

                    if (sentence.empty()) {
                        result.push_back(word);
                    } 
                    else {
                        result.push_back(word + " " + sentence);
                    }
                }
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            dict.insert(word);
        }

        return solve(s, 0);
    }
};