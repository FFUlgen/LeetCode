#include <vector>
#include <stack>
/*
739. Daily Temperatures - Explanation

Description
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day.
If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]
Output: [1,4,1,2,1,0,0]

Example 2:

Input: temperatures = [22,21,20]
Output: [0,0,0]

Constraints:

1 <= temperatures.length <= 1000.
1 <= temperatures[i] <= 100
*/

//Brute Force Time complexity: O(n^2) Space complexity : O(1) extra space.O(n) space for the output array.
std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
	std::vector<int> answer(temperatures.size(), 0);
	int size = temperatures.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (temperatures[i] == 100) continue;
		for (int j = i + 1 ; j < size; j++)
		{
			if (temperatures[j] > temperatures[i])
			{
				answer[i] = j - i;
				break;
			}
		}
	}
	return answer;

}

// Monotonic Stack: Time Complexity: O(n) || Space Complexity: O(n)
std::vector<int> dailyTemperatures2(const std::vector<int>& temperatures)
{
	std::vector<int> result(temperatures.size(), 0);
	std::stack<std::pair<int, int>> stack; // pair:{temperature, index}

	for (int i = 0; i < temperatures.size(); i++)
	{
		int t = temperatures[i];
		while (!stack.empty() && t > stack.top().first)
		{
			auto pair = stack.top();
			stack.pop();
			result[pair.second] = i - pair.second;
		}
		stack.push({ t, i });
	}
	return result;
}