#include <iostream>
#include <set>
#include <functional> 

int main() {
    int n;

    std::set<int, std::greater<int>> numbers;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        numbers.insert(val);
    }
    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}