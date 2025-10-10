#include <string>
#include <algorithm>
/*
125. Valid Palindrome - Explanation

Description
	Given a string s, return true if it is a palindrome, otherwise return false.
	A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
	Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Example 1:
	Input: s = "Was it a car or a cat I saw?"
	Output: true
	Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:
	Input: s = "tab a cat"
	Output: false
	Explanation: "tabacat" is not a palindrome.

Constraints:
	1 <= s.length <= 1000
	s is made up of only printable ASCII characters.
*/

// Two Pointers: Time Complexity O(n), Space Complexity O(1)
bool isPalindrome(std::string s) {
	s.erase(std::remove_if(s.begin(), s.end(),
		[](unsigned char c) {return !std::isalnum(c); }),
		s.end());
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) {return std::tolower(c); });
	
	int left = 0;
	int right = s.length() - 1;
	while (left < right)
	{
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}

	return true;
}