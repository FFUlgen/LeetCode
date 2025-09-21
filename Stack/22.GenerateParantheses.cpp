#include <vector>
#include <string>
#include <cmath>

/*
22. Generate Parentheses - Explanation

	Description
		You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

	Example 1:

		Input: n = 1

		Output: ["()"]

	Example 2:

		Input: n = 3

		Output: ["((()))","(()())","(())()","()(())","()()()"]

	You may return the answer in any order.

	Constraints:

		1 <= n <= 7
*/

// Bit Manipulation with Brute Force: Time Complexity O(2^2n * n) Space Complexity O(2^2n * n)
std::vector<std::string> generateParenthesis(int n) {
	int total = std::pow(2, 2 * n);
	std::vector<std::string> result;

	for (int i = 0; i < total; i++)
	{
		std::string s;
		int open = 0;
		int close = 0;
		bool valid = true;
		for (int j = 2 * n - 1; j >= 0; j--)
		{
			if (i & (1 << j)) {
				s += "(";
				open++;
			}
			else
			{
				s += ")";
				close++;
			}
			if (close > open)
			{
				valid = false;
				break;
			}
		}
		if (valid && open == close)
		{
			result.push_back(s);
		}
	}
	return result;
}


// Backtracking : Time Complexity : O(4^n / sqrt(n)) Space Complexity O(n)
void backtrack(std::vector<std::string>&result, std::string & current,
	int open, int close, int max) {

	if (current.length() == max * 2) {
		result.push_back(current);
		return;
	}

	if (open < max) {
		current.push_back('(');
		backtrack(result, current, open + 1, close, max);
		current.pop_back();
	}

	if (close < open) {
		current.push_back(')');
		backtrack(result, current, open, close + 1, max);
		current.pop_back();
	}
}
std::vector<std::string> generateParenthesis2(int n) {
	std::vector<std::string> res;
	std::string stack;
	backtrack(res, stack, 0, 0, n);
	return res;
}