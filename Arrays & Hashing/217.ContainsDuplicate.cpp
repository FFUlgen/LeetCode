#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



	Example 1:

		Input: nums = [1,2,3,1]

		Output: true

	Explanation:

		The element 1 occurs at the indices 0 and 3.

	Example 2:

		Input: nums = [1,2,3,4]

		Output: false

	Explanation:

		All elements are distinct.

	Example 3:

		Input: nums = [1,1,1,3,3,4,3,2,4,2]

		Output: true


	Constraints:

	1 <= nums.length <= 105
	-109 <= nums[i] <= 109

*/


// Brute Force : Time Complexity O(n^2) Space Complexity(1)
bool HasDuplicate_1(std::vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] == nums[j]) return true;
		}
	}
	return false;
};

//-------------------------------------------------------------

// Sorting : Time Complexity O(nlogn) Space Complexity(1) or O(n) depending on the sorting algorithm.
bool HasDuplicate_2(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());

	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) return true;
	}
	return false;
};

//-------------------------------------------------------------

// Hash set : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate_3(std::vector<int>& nums)
{
	std::unordered_set<int> seenValues;
	for (int &num : nums)
	{
		if (seenValues.count(num)) return true;
		seenValues.insert(num);
	}
	return false;
};

//-------------------------------------------------------------

// Hash set with find() instead of count() : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate_4(std::vector<int>& nums)
{
	std::unordered_set<int> seenValues;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (seenValues.find(nums[i]) != seenValues.end())
		{
			return true;
		}
		seenValues.insert(nums[i]);
	}
	return false;
};

//-------------------------------------------------------------

// Hash set length : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate_5(std::vector<int>& nums)
{
	return std::unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
};





