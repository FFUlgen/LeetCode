#include "string"
#include "iostream"
#include "vector"

/*
271. Encode and Decode Strings - Explanation

Description
	Design an algorithm to encode a list of strings to a single string.The encoded string is then decoded back to the original list of strings.

	Please implement encode and decode

	Example 1:

		Input: ["neet", "code", "love", "you"]

		Output : ["neet", "code", "love", "you"]

	Example 2 :

		Input : ["we", "say", ":", "yes"]

		Output : ["we", "say", ":", "yes"]

	Constraints :

		0 <= strs.length < 100
		0 <= strs[i].length < 200
		strs[i] contains only UTF - 8 characters.
*/
std::string Encode(std::vector<std::string>& strs)
{
	std::string res = "";

	for (std::string& str : strs)
	{
		res += std::to_string(str.length()) + "#" + str;
	}
	return res;
}

std::vector<std::string> Decode(std::string& str)
{
	std::vector<std::string> res;

	int i = 0;

	while (i < str.length())
	{
		int j = i;

		while (str[j] != '#')
		{
			j++;
		}

		int length = std::stoi(str.substr(i, j - i));
		i = j + 1;
		j = i + length;
		res.push_back(str.substr(i, length));

		i = j;
	}



	return res;
}





























// Time Complexity : O(m) for each Encode() and Decode() calls, Space Complexity O(m + n) for each Encode() and Decode() function calls. 
// m is sum of lengths of all the strings and n is the number of strings.
std::string Encode(std::vector<std::string>& strs)
{
	std::string res = "";


	for (std::string s : strs)
	{
		res += std::to_string(s.length()) + "#" + s;
	}
	return res;
}

std::vector<std::string> Decode(std::string& str)
{
	std::vector<std::string> res;

	int i = 0;

	while (i < str.size())
	{
		int j = i;
		while (str[j] != '#')
		{
			j++;
		}
		int length = std::stoi(str.substr(i, j - i));
		i = j + 1;
		j = i + length;
		res.push_back(str.substr(i, length));
		i = j;
	}

	return res;
}