#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

	Input: nums = [2, 7, 11, 15], target = 9
	Output : [0, 1]
	Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].

Example 2 :

	Input : nums = [3, 2, 4], target = 6
	Output : [1, 2]
	Example 3 :

	Input : nums = [3, 3], target = 6
	Output : [0, 1]
*/


// Hash Map (Two Pass) : Time Complexity O(n) Space Complexity O(n)
std::vector<int> TwoSum_1(std::vector<int>& Nums, int Target)
{
	std::unordered_map<int, int> Hash;

	for (int i = 0; i < Nums.size(); i++)
	{
		Hash[Nums[i]] = i;
	}

	for (int i = 0; i < Nums.size(); i++)
	{
		int Complement = Target - Nums[i];
		if (Hash.count(Complement) && Hash[Complement] != i)
		{
			return { i, Hash[Complement] };
		}
	}
}

// Hash Map (One Pass) : Time Complexity O(n) Space Complexity O(n)
std::vector<int> TwoSum_2(std::vector<int>& Nums, int Target)
{
	std::unordered_map<int, int> Hash;

	for (int i = 0; i < Nums.size(); i++)
	{
		int Complement = Target - Nums[i];

		if (Hash.find(Complement) != Hash.end())
		{
			return{ Hash[Complement], i };
		}

		Hash[Nums[i]] = i;
	}
	return {};
}