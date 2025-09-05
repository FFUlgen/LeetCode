#include <string>
#include <stack>
#include <unordered_map>

/*
	20. Valid Parentheses - Explanation


		Description
			You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

			The input string s is valid if and only if:

				Every open bracket is closed by the same type of close bracket.
				Open brackets are closed in the correct order.
				Every close bracket has a corresponding open bracket of the same type.
				Return true if s is a valid string, and false otherwise.

		Example 1:

			Input: s = "[]"

			Output: true

		Example 2:

			Input: s = "([{}])"

			Output: true

		Example 3:

		Input: s = "[(])"

		Output: false

		Explanation: The brackets are not closed in the correct order.

		Constraints:

			1 <= s.length <= 1000
*/

// Stack: Time Complexity O(n) Space Complexity O(n)
bool validParantheses(std::string& s)
{
	std::stack<char> charStack;
	std::unordered_map<char, char> closeToOpen = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};

	for (const char c : s)
	{
		if (closeToOpen.count(c))
		{
			if (!charStack.empty() && charStack.top() == closeToOpen[c])
			{
				charStack.pop();
			}
			else
			{
				return false;
			}
		}
		else
		{
			charStack.push(c);
		}
		
	}
	return charStack.empty();
}