    #include <iostream>
    #include <algorithm>
     
    int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
     
        int n, myAttack, opAttack, k;
        std::cin >> n >> myAttack >> opAttack >> k;
        int specialsNeeded[n];
        for (int i = 0; i < n; ++i) {
            int monsterHealth;
            std::cin >> monsterHealth;
            monsterHealth = (monsterHealth - myAttack) % (myAttack + opAttack);
            if (monsterHealth <= 0 || monsterHealth > opAttack) {
                specialsNeeded[i] = 0;
            } else {
                int specials = monsterHealth / myAttack;
                specialsNeeded[i] = specials + (monsterHealth - specials * myAttack != 0);
            }
        }
        std::sort(specialsNeeded, specialsNeeded + n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (specialsNeeded[i] > k) {
                break;
            }
            k -= specialsNeeded[i];
            ++res;
        }
        std::cout << res << '\n';
        return 0;
    }
