#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Description
	Given an integer array nums and an integer k, return the k most frequent elements within the array.

	The test cases are generated such that the answer is always unique.

	You may return the output in any order.

	Example 1:

		Input: nums = [1, 2, 2, 3, 3, 3], k = 2

		Output : [2, 3]

	Example 2 :

		Input : nums = [7, 7], k = 1

		Output : [7]

	Constraints :

		1 <= nums.length <= 10 ^ 4.
		- 1000 <= nums[i] <= 1000
		1 <= k <= number of distinct elements in nums.
*/

// Bucket Sort : Time Complexity O(n) Space Complexity O(n)
std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
    std::unordered_map<int, int> count;
    std::vector<std::vector<int>> freq(nums.size() + 1);

    for (int n : nums) {
        count[n]++;
    }
    for (const auto& entry : count) {
        freq[entry.second].push_back(entry.first);
    }

    std::vector<int> res;
    for (int i = freq.size() - 1; i > 0; --i) {
        for (int n : freq[i]) {
            res.push_back(n);
            if (res.size() == k) {
                return res;
            }
        }
    }
    return res;
}