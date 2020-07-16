    #include <iostream>
     
    int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
     
        int tc;
        std::cin >> tc;
        while (tc--) {
            int cash, res = 0;
            std::cin >> cash;
            while (cash >= 10) {
                int cashSpent = cash - cash % 10;
                res += cashSpent;
                cash = cash - cashSpent + cashSpent / 10;
            }
            std::cout << res + cash << '\n';
        }
        return 0;
    }
