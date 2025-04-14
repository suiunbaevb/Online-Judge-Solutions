#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> numMap;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }

        numMap[nums[i]] = i;
    }

    return result;
}

int main() {
    std::vector<int> nums = {3, 3};
    int target = 6;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No valid indices found." << std::endl;
    }

    return 0;
}
