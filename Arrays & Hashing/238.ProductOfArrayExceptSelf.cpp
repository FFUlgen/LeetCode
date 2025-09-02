#include <vector>

/*
238. Product of Array Except Self - Explanation

Description
	Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

	Each product is guaranteed to fit in a 32 - bit integer.

	Example 1 :

		Input : nums = [1, 2, 4, 6]

		Output : [48, 24, 12, 8]

	Example 2 :

		Input : nums = [-1, 0, 1, 2, 3]

		Output : [0, -6, 0, 0, 0]

	Constraints :

		2 <= nums.length <= 1000
		- 20 <= nums[i] <= 20
*/

// Time Complexity O(n) Space Complexity O(n) + O(1)
std::vector<int> ProductOfArrayExceptSelf(std::vector<int>& nums)
{
	int product = 1;
	int zeroCount = 0;

	for (int num : nums)
	{
		if (num == 0) zeroCount++;
		else product *= num;
	}

	if (zeroCount > 1) return std::vector<int>(nums.size(), 0);
	
	std::vector<int> res(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		if (zeroCount == 1) res[i] = (nums[i] == 0 ? product : 0);
		else res[i] = product / nums[i];
	}
	return res;
}

// Time complexity :O(n) Space complexity : O(n) + O(1)
std::vector<int> ProductOfArrayExceptSelf(std::vector<int>& nums)
{
	int n = nums.size();
	std::vector<int> res(n, 1);
	
	for (int i = 1; i < n; i++)
	{
		res[i] = res[i - 1] * nums[i - 1];
	}

	int right = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		res[i] *= right;
		right *= nums[i];
	}
	return res;
}