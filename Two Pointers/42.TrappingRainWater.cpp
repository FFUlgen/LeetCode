#include <vector>

/*
42.Trapping Rain Water

	Description:
		You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.
		Return the maximum area of water that can be trapped between the bars.

	Example:
		Input: height = [0,2,0,3,1,0,1,3,2,1]
		Output: 9

	Constraints:
		1 <= height.length <= 1000
		0 <= height[i] <= 1000
*/
int trap(std::vector<int>& height) {
	int n = height.size();
	if (n == 0) return;

	std::vector<int> leftMax(n);
	std::vector<int> rightMax(n);

	leftMax[0] = height[0];
	for (int i = 1; i < n; i++)
	{
		leftMax[i] = std::max(height[i], leftMax[i - 1]);
	}

	rightMax[0] = height[0];
	for (int i = 1; i < n; i++)
	{
		rightMax[i] = std::max(height[i], rightMax[i - 1]);
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += std::min(leftMax[i], rightMax[i]) - height[i];
	}

	return result;
}