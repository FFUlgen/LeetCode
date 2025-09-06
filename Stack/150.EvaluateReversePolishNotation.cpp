#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <functional>
/*
150. Evaluate Reverse Polish Notation - Explanation

	Description
		You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

	Return the integer that represents the evaluation of the expression.

		The operands may be integers or the results of other operations.
		The operators include '+', '-', '*', and '/'.
		Assume that division between integers always truncates toward zero.

	Example 1:

		Input: tokens = ["1","2","+","3","*","4","-"]

		Output: 5

		Explanation: ((1 + 2) * 3) - 4 = 5

	Constraints:

		1 <= tokens.length <= 1000.
		tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].
*/

// Stack : Time Complexity O(n) Space Complexity O(n)
int evalRPN(std::vector<std::string>& tokens) {
	std::stack<int> stack;
	std::unordered_map<std::string, std::function<int(int, int)>> operations =
	{
		{"+", [](int a, int b) {return b + a; }},
		{"-", [](int a, int b) {return b - a; }},
		{"*", [](int a, int b) {return b * a; }},
		{"/", [](int a, int b) {return b / a; }}
	};
	for (const auto& token : tokens)
	{
		if (operations.find(token) != operations.end())
		{
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			stack.push(operations[token](a, b));
		}
		else
		{
			stack.push(std::stoi(token));
		}
	
	}
	return stack.top();
}