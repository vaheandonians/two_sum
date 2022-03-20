#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> two_sum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> complement;
    int currentIndex = 0;
    for (int& num : nums) {
        if (complement.find(num) != complement.end()) {
            return { complement[num], currentIndex };
        } else {
            int numberNeeded = target - num;
            complement[numberNeeded] = currentIndex;
        }
        currentIndex++;
    }
    return { -1, -1 };
}

int main() {
    std::vector<int> input = {-3,4,3,90};
    std::vector<int> solution = two_sum(input, 0);
    std::cout << solution[0] << " " << solution[1];
    return 0;
}
