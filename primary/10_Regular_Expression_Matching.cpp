#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 19:45:01 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sn = s.length(), pn = p.length();
        // 注意s或者p可能一方为空，为了防止访问出错，我们申请 (sn+1)*(pn+1) 的空间即可
        std::vector<std::vector<int>> memo(sn + 1, std::vector<int>(pn + 1, true));     // 记忆化容器

        std::function<bool(int, int)> backtrack = [&] (int sindx, int pindx) -> bool {
            if(!memo[sindx][pindx]) return false;//记忆化剪枝

            if(sindx==sn){ 
                memo[sindx][pindx] = pindx==pn||(pindx+1<pn&&p[pindx+1]=='*'&&backtrack(sindx,pindx+2));
                return memo[sindx][pindx];
            }
            else if(pn==pindx) {
                memo[sindx][pindx] = false;
                return false;
            }

            if(s[sindx]==p[pindx]||p[pindx]=='.') { //当前位置成功匹配 

                if(pindx+1<pn&&p[pindx+1]=='*') {
                    //复制+终结+越过
                    memo[sindx][pindx] = backtrack(sindx+1,pindx)||backtrack(sindx+1,pindx+2)||backtrack(sindx,pindx+2);
                    return memo[sindx][pindx];
                }
                else {
                    memo[sindx][pindx] = backtrack(sindx+1,pindx+1);
                    return memo[sindx][pindx];
                } 
            }else{ //未成功匹配
                //找p下一位* 或者匹配失败
                if(pindx+1<pn&&p[pindx+1]=='*') {
                    memo[sindx][pindx] = backtrack(sindx,pindx+2);
                    return memo[sindx][pindx];
                }
                else {
                    memo[sindx][pindx] = false;
                    return false;
                }
            } 
        };

        return backtrack(0, 0);
    }
};
}

int main(int argc, char **argv) {
    std::string s{"aa"};
    std::string p{"a*"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().isMatch(s, p) << '\n';

    return 0;
}

