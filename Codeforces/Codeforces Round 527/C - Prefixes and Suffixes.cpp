#include <iostream>
#include <string>
#include <algorithm>

const int N = 210;

struct Substring {
    std::string str;
    int index = -1;
    bool operator<(const Substring& other) {
        return str.length() < other.str.length();
    }
};

bool prefix(const std::string& str, const std::string& pre) {
    for (unsigned i = 0; i < pre.length(); ++i) {
        if (str[i] != pre[i]) {
            return false;
        }
    }
    return true;
}

bool suffix(const std::string& str, const std::string& suf) {
    unsigned diff = str.length() - suf.length();
    for (unsigned i = 0; i < suf.length(); ++i) {
        if (str[i + diff] != suf[i]) {
            return false;
        }
    }
    return true;
}

std::string buildAns(const Substring strings[N], const std::string& str) {
    int num = 2 * (int) str.length() - 2;
    std::string res(num, ' ');
    for (int i = 0; i < num; i += 2) {
        if (prefix(str, strings[i].str) && suffix(str, strings[i + 1].str)) {
            res[strings[i].index] = 'P';
            res[strings[i + 1].index] = 'S';
        } else if (suffix(str, strings[i].str) && prefix(str, strings[i + 1].str)) {
            res[strings[i].index] = 'S';
            res[strings[i + 1].index] = 'P';
        } else {
            return "";
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    Substring strings[N];
    int num = 2 * n - 2;
    for (int i = 0; i < num; ++i) {
        std::cin >> strings[i].str;
        strings[i].index = i;
    }
    std::sort(strings, strings + num);
    std::string ans1 = strings[num - 1].str + strings[num - 2].str[n - 2];
    std::string ans2 = strings[num - 2].str + strings[num - 1].str[n - 2];
    std::string res = buildAns(strings, ans1);
    if (res.empty()) {
        res = buildAns(strings, ans2);
    }
    std::cout << res << '\n';
    return 0;
}
