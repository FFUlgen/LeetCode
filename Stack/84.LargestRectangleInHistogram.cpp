#include <vector>
#include <stack>
/*
84. Largest Rectangle In Histogram - Explanation

Description
	You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.
	Return the area of the largest rectangle that can be formed among the bars.
	Note: This chart is known as a histogram.

Example 1:
	Input: heights = [7,1,7,2,2,4]
	Output: 8

Example 2:
	Input: heights = [1,3,7]
	Output: 7

Constraints:
	1 <= heights.length <= 1000.
	0 <= heights[i] <= 1000
*/

// Stack One Pass : Time Complexity O(n)   Space Complexity O(n)
int largestRectangleArea(std::vector<int>& heights) {
	int maxArea = 0;

	std::stack<std::pair<int, int>> stack; // index,height

	for (int i = 0; i < heights.size(); i++)
	{
		int IndexToAdd = i;
		while (!stack.empty() && heights[i] < stack.top().second)
		{
			int index = stack.top().first;
			int height = stack.top().second;
			int area = height * (i - index);
			if (area > maxArea) maxArea = area;
			IndexToAdd = index;
			stack.pop();
		}
		stack.push({ IndexToAdd, heights[i] });

	}
	while (!stack.empty())
	{
		int index = stack.top().first;
		int height = stack.top().second;
		int area = height * (heights.size() - index);
		if (area > maxArea) maxArea = area;
		stack.pop();
	}
	return maxArea;
}