#include <vector>

/*
167. Two Sum II Input Array Is Sorted - Explanation

Description
	Given an array of integers numbers that is sorted in non-decreasing order.
	Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
	There will always be exactly one valid solution.

Example 1:
	Input: numbers = [1,2,3,4], target = 3
	Output: [1,2]
	Explanation:
		The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2].

Constraints:
	2 <= numbers.length <= 1000
	-1000 <= numbers[i] <= 1000
	-1000 <= target <= 1000
*/

// Two Pointers: Time Complexity O(n), Space Complexity O(1)
std::vector<int> twoSum(std::vector<int>& numbers, int target) {
	int left = 0;
	int right = numbers.size() - 1;

	while (left < right)
	{
		int sum = numbers[left] + numbers[right];

		if (sum == target)
			return { left + 1, right + 1 };
		else if (sum > target)
			right--;
		else
			left++;
	}
	return {};
}