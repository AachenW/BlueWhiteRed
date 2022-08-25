#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-02-28 17:02:54
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string validIPAddress(std::string queryIP) {
        if (is4(queryIP)) {
            return "IPv4";
        } else if (is6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    bool is4(std::string ipAddress) {
        std::vector<std::string> ip;
        split(ipAddress, ip, '.');
        if (4 != ip.size()) {
            return false;
        }

        for (const auto &s: ip) {
            if (0 == s.size() || (s.size() > 1 && s[0] == '0') || s.size() > 3) {
                return false;
            }
            for (const char c: s) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            int digit = std::stoi(s);
            if (digit < 0 || digit > 0xFF) {
                return false;
            }
        }
        return true;
    }

    bool is6(std::string ipAddress) {
        std::vector<std::string> ip;
        split(ipAddress, ip, ':');
        if (8 != ip.size()) {
            return false;
        }

        for (const auto &s: ip) {
            if (s.size() == 0 || s.size() > 4) {
                return false;
            }
            for (const char c: s) {
                if (c < '0' || c > '9' && c < 'A' || c > 'F' && c < 'a' || c > 'f') {
                    return false;
                }
            }
        }

        return true;
    }

    void split(std::string &strIn, std::vector<std::string> &ip, char delim) {
        std::stringstream ss(strIn);
        std::string tmp;

        while (std::getline(ss, tmp, delim)) {
            ip.emplace_back(tmp);
        }

        if (strIn.size() > 0 && strIn.back() == delim) {
            ip.push_back({});
        }
    }
};
}
