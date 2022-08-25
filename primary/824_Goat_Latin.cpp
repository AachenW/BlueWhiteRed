#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-21 09:39:30 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string toGoatLatin(std::string &sentence) {
        std::unordered_set<char> st{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

        std::vector<std::string> strs;
        char *token = strtok(sentence.data(), " ");
        while (NULL != token) {
            strs.emplace_back(token);
            token = strtok(NULL, " ");
        }

        std::string ans;
        std::string end{"ma"};
        for (int i = 0; i < strs.size(); ++i) {
            std::string postfix(i + 1, 'a');
            if (st.find(strs[i][0]) != st.end()) {
                ans += strs[i];
            } else {
                char c = strs[i][0];
                ans += strs[i].substr(1) + c;
            }
            ans += end + postfix;
            if (i != strs.size() - 1) {
                ans += " ";
            } 
        }   
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string sentence{"The quick brown fox jumped over the lazy dog"};
    std::cout << leetcode_cpp::Solution().toGoatLatin(sentence) << '\n';

    return 0;
}
