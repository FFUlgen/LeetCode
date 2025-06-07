#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/* Brute Force : Time Complexity O(n^2) Space Complexity(1)
bool HasDuplicate(std::vector<int>& nums)
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
*/

//-------------------------------------------------------------

/* Sorting : Time Complexity O(nlogn) Space Complexity(1) or O(n) depending on the sorting algorithm.
bool HasDuplicate(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());

	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[i - 1]) return true;
	}
	return false;
};
*/

//-------------------------------------------------------------

/* Hash set : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate(std::vector<int>& nums)
{
	std::unordered_set<int> seenValues;
	for (int &num : nums)
	{
		if (seenValues.count(num)) return true;
		seenValues.insert(num);
	}
	return false;
};
*/

/* Hash set with find() instead of count() : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate(std::vector<int>& nums)
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
*/




//-------------------------------------------------------------

/* Hash set length : Time Complexity O(n) Space Complexity(n).
bool HasDuplicate(std::vector<int>& nums)
{
	return std::unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
};
*/




