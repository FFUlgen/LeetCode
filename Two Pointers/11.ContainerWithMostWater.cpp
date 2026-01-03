#include <vector>
/*
11. Container With Most Water - Explanation
Description:
	You are given an integer array heights where heights[i] represents the height of the ith bar.
	You may choose any two bars to form a container.Return the maximum amount of water a container can store.

Example 1:
	Input: height = [1, 7, 2, 5, 4, 7, 3, 6]
	Output : 36

Example 2 :
	Input : height = [2, 2, 2]
	Output : 4

Constraints :
	2 <= height.length <= 1000
	0 <= height[i] <= 1000
*/

int maxArea(std::vector<int>& height) 
{
	int maxArea = 0;
	int l = 0;
	int r = height.size() - 1;
	while (l < r)
	{	
		int result = (r - l) * std::min(height[l], height[r]);
		maxArea = std::max(maxArea, result);

		if (height[l] >= height[r])
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	return maxArea;
}