#include <iostream>
#include <vector>

int find_k(const std::vector<int> &a) {
    int n = a.size();
    int left_product = 1;
    int right_product = 1;
    for (int i = 0; i < n; i++) {
        left_product *= a[i];
        right_product *= a[n-i-1];
        if (left_product == right_product) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int result = find_k(a);
        std::cout << result << std::endl;
    }
    return 0;
}
