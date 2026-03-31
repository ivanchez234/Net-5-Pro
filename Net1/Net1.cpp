#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string text;
    std::cout << "[IN]: ";
    std::getline(std::cin, text);

    std::unordered_map<char, int> n;
    for (char c : text) {
        n[c]++;
    }

    std::vector<std::pair<char, int>> sorted(n.begin(), n.end());

    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; 
        });

    std::cout << "[OUT]:" << std::endl;
    for (const auto& item : sorted) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

    return 0;
}