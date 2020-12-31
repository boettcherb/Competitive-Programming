    #include <iostream>
     
    const int N = 105;
     
    int main() {
        int n, a, b, arr[N];
        std::cin >> n;
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> arr[i];
        }
        std::cin >> a >> b;
        int res = 0;
        for (int i = a - 1; i < b - 1; ++i) {
            res += arr[i];
        }
        std::cout << res << '\n';
        return 0;
    }