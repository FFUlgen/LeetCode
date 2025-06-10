#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "string"

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

	Example 1:

		Input: strs = ["eat","tea","tan","ate","nat","bat"]

		Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

	Explanation:

		There is no string in strs that can be rearranged to form "bat".
		The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
		The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

	Example 2:

		Input: strs = [""]

		Output: [[""]]

	Example 3:

		Input: strs = ["a"]

		Output: [["a"]]

 
	Constraints:

		1 <= strs.length <= 104
		0 <= strs[i].length <= 100
		strs[i] consists of lowercase English letters.
*/


// Hash Table : Time Complexity O(n * m) Space Complexity O(m) extra space, O(m * n) space for the output list
// (Where  is the number of strings and is the length of the longest string)
std::vector<std::vector<std::string>> groupAnagrams_1(std::vector<std::string>& strs)
{
	std::unordered_map<std::string, std::vector<std::string>> res;

	for (const auto& s : strs)
	{
		std::vector<int> count(26, 0);

		for(auto& c : s)
		{
			count[c - 'a']++;
		}

		std::string key = std::to_string(count[0]);

		for (int i = 1; i < 26; i++)
		{
			key += "," + std::to_string(count[i]);
		}

		res[key].push_back(s);
	}

	std::vector<std::vector<std::string>> result;

	for (const auto& pair : res)
	{
		result.push_back(pair.second);
	}
	return result;
}

// Sorting : Time Complexity O(n m * nlogn) Space Complexity O(m * n)
// (Where  is the number of strings and is the length of the longest string)
std::vector<std::vector<std::string>> groupAnagrams_2(std::vector<std::string>& strs) {
	std::unordered_map<std::string, std::vector<std::string>> res;

	for (const auto& s : strs) {
		std::string sortedS = s;
		sort(sortedS.begin(), sortedS.end());
		res[sortedS].push_back(s);
	}

	std::vector<std::vector<std::string>> result;

	for (auto& pair : res) {
		result.push_back(pair.second);
	}

	return result;
}