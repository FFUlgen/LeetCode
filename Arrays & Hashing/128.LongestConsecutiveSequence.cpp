#include <vector>
#include <unordered_set>
#include <unordered_map>
/*
128. Longest Consecutive Sequence - Explanation

	Description:
		Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

		A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

		You must write an algorithm that runs in O(n) time.

	Example 1:

		Input: nums = [2,20,4,10,3,4,5]

		Output: 4

		Explanation: The longest consecutive sequence is [2, 3, 4, 5].

	Example 2:

		Input: nums = [0,3,2,5,4,6,1,1]

		Output: 7

	Constraints:

		0 <= nums.length <= 1000
		-10^9 <= nums[i] <= 10^9
*/

// Hash Set : Time Complexity O(n) Space Complexity O(n)
int longestConsecutive(std::vector<int>& nums) {

	std::unordered_set<int> numsSet(nums.begin(), nums.end());
	int longest = 0;

	for (int num : numsSet)
	{
		if (numsSet.find(num - 1) == numsSet.end())
		{
			int length = 1;
			while (numsSet.find(num + length) != numsSet.end())
			{
				length++;
			}
			longest = std::max(longest, length);
		}
	}
	return longest;
}

// Hash Map : Time Complexity O(n) Space Complexity O(n)
int longestConsecutive(std::vector<int>& nums) {
	std::unordered_map<int, int> numMap;
	int longest = 0;

	for (int num : nums) 
	{
		if (!numMap[num])
		{
			numMap[num] = numMap[num - 1] + numMap[num + 1] + 1;
			numMap[num - numMap[num - 1]] = numMap[num];
			numMap[num + numMap[num + 1]] = numMap[num];
			longest = std::max(longest, numMap[num]);
		}
	}
	return longest;
}