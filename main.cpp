#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
/*
 * negative numbers not handled: [-3,4,3,90] target: 0
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution = {0, 0};
    for (int i = 0; i < nums.size(); i++) {
        int a = nums[i];
        if (a > target)
            continue;
        else {
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                if (b > target)
                    continue;
                if (a + b == target) {
                    solution[0] = i;
                    solution[1] = j;
                    return solution;
                }
            }
        }
    }
    return solution;
}
*/

/*
 * slow ... O(n^2)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution = {0, 0};
    for (int i = 0; i < nums.size(); i++) {
        int a = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            int b = nums[j];
            if (a + b == target) {
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }
    return solution;
}
*/

/*
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> solution = {0, 0};
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        int e = nums[i];
        int targetMinusElement = target - e;
        try {
            const int j = m.at(targetMinusElement);
            solution[1] = i;
            solution[0] = j;
            return solution;
        }
        catch (const std::out_of_range&) {
            m.insert({e, i});
        }
    }
    return solution;
}
*/

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> complement;
    int currentIndex = 0;
    for(int& num : nums) {
        if(complement.find(num) != complement.end()) {
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
    // std::cout << "Hello, World!" << std::endl;
    std::vector<int> input = {-3,4,3,90};
    /*
    std::vector<int>::iterator ptr;
    std::cout << "The vector elements are : ";
    for (ptr = v.begin(); ptr < v.end(); ptr++)
        std::cout << *ptr << " ";
    std::cout << std::endl << "Size was: " << v.size() << std::endl;

    std::cout << v[3];
    */
    std::vector<int> solution = twoSum(input, 0);
    std::cout << solution[0] << " " << solution[1];
    return 0;
}
