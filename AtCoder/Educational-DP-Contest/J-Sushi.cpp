/*

i = plates containing 1 sushi
j = plates containing 2 sushi
k = plates containing 3 sushi

Each operation on the current state (i, j, k) has 4 possible outcomes:
1. select a one-sushi plate with probability i/n
    next state: (i-1, j, k)
2. select a two-sushi plate with probability j/n
    next state: (i+1, j-1, k)
3. select a three-sushi plate with probability k/n
    next state: (i, j+1, k-1)
4. select an empty plate with probability (n-i-j-k)/n
    next state: (i, j, k)    (Note: same state!)

Expected Value formula:
    E(i, j, k) = 1
        + i/n * E(i-1, j, k)
        + j/n * E(i+1, j-1, k)
        + k/n * E(i, j+1, k-1)
        + (n-i-j-k)/n * E(i, j, k)

    Combine term E(i, j, k):

    E(i, j, k) - (n-i-j-k)/n * E(i, j, k) = 1
        + i/n * E(i-1, j, k)
        + j/n * E(i+1, j-1, k)
        + k/n * E(i, j+1, k-1)

    E(i, j, k) * (1 - (n-i-j-k)/n) = 1
        + i/n * E(i-1, j, k)
        + j/n * E(i+1, j-1, k)
        + k/n * E(i, j+1, k-1)
    
    Simplify by multiplying by n:

    (1-(n-i-j-k)/n)*n = (n-(n-i-j-k)) = (i+j+k)

    E(i, j, k) * (i+j+k) = n
        + i * E(i-1, j, k)
        + j * E(i+1, j-1, k)
        + k * E(i, j+1, k-1)

    Divide to get E(i, j, k) by itself:
    
    E(i, j, k) = n/(i+j+k)
        + i/(i+j+k) * E(i-1, j, k)
        + j/(i+j+k) * E(i+1, j-1, k)
        + k/(i+j+k) * E(i, j+1, k-1)
*/

#include <iostream>
#include <iomanip>

const int N = 301;

int n;
double dp[N][N][N];

double E(int i, int j, int k) {
    if ((i == 0 && j == 0 && k == 0) || i < 0 || j < 0 || k < 0)
        return 0;
    if (dp[i][j][k] != 0.0)
        return dp[i][j][k];
    double t = i + j + k;
    double res = n / t;
    res += i / t * E(i - 1, j, k);
    res += j / t * E(i + 1, j - 1, k);
    res += k / t * E(i, j + 1, k - 1);
    return dp[i][j][k] = res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        std::cin >> s;
        a += s == 1;
        b += s == 2;
        c += s == 3;
    }
    std::cout << std::fixed << std::setprecision(10) << E(a, b, c) << '\n';
}
