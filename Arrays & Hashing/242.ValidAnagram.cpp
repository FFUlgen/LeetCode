#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.



	Example 1:

		Input: s = "anagram", t = "nagaram"

		Output: true

	Example 2:

		Input: s = "rat", t = "car"

		Output: false



	Constraints:

		1 <= s.length, t.length <= 5 * 104
		s and t consist of lowercase English letters.
*/


// Sorting : Time Complexity O(nlogn + mlogm) Space Complexity O(1) or O(n + m) depending on the sorting algorithm
bool isAnagram_1(std::string s, std::string t) {
    
	if (s.size() != t.size())
	{
		return false;
	}

	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	return s == t;
}

//-------------------------------------------------------------

// Hash map : Time Complexity O(n + m) Space Complexity O(1).
bool isAnagram_2(std::string s, std::string t) {

	if (s.length() != t.length())
	{
		return false;
	}

	std::unordered_map<char, int> countS;
	std::unordered_map<char, int> countT;
	for (int i = 0; i < s.length(); i++)
	{
		countS[s[i]]++;
		countT[t[i]]++;
	}
	return countS == countT;
}

//-------------------------------------------------------------

// Hash map using array: Time Complexity O(n + m) Space Complexity O(1).
bool isAnagram_3(std::string s, std::string t) {
	if (s.length() != t.length()) {
		return false;
	}
	
	int count[26] = {0};
	for (int i = 0; i < s.length(); i++) {
		count[s[i] - 'a']++;
		count[t[i] - 'a']--;
	}

	for (int val : count) {
		if (val != 0) {
			return false;
		}
	}
	return true;
}


