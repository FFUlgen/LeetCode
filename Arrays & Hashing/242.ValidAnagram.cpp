#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/* Sorting : Time Complexity O(nlogn + mlogm) Space Complexity O(1) or O(n + m) depending on the sorting algorithm
bool isAnagram(std::string s, std::string t) {
    
	if (s.size() != t.size())
	{
		return false;
	}

	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	return s == t;
}
*/

/* Hash map : Time Complexity O(n + m) Space Complexity O(1).
bool isAnagram(std::string s, std::string t) {

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
*/

/* Hash map using array: Time Complexity O(n + m) Space Complexity O(1).
bool isAnagram(std::string s, std::string t) {
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
*/

