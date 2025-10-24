#include <vector>
#include <algorithm>
/*
15. 3Sum - Explanation

Description:
	Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
	The output should not contain any duplicate triplets.You may return the output and the triplets in any order.

	Example 1:
		Input: nums = [-1, 0, 1, 2, -1, -4]
		Output : [[-1, -1, 2], [-1, 0, 1]]
		Explanation :
			nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
			nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
			nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
			The distinct triplets are[-1, 0, 1] and [-1, -1, 2].

	Example 2:
		Input: nums = [0, 1, 1]
		Output : []
		Explanation : The only possible triplet does not sum up to 0.

	Example 3 :
		Input : nums = [0, 0, 0]
		Output : [[0, 0, 0]]
		Explanation : The only possible triplet sums up to 0.

	Constraints :
		3 <= nums.length <= 1000
		- 10 ^ 5 <= nums[i] <= 10 ^ 5
*/

// Two Pointer : Time Complexity O(n^2), Space Complexity O(m)
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
	std::vector<std::vector<int>> result;

	std::sort(nums.begin(), nums.end());
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > 0) break;

		if (i > 0 && nums[i] == nums[i - 1]) continue;

		int l = i + 1;
		int r = n - 1;


		while (l < r)
		{
			int sum = nums[l] + nums[r] + nums[i];

			if (sum == 0)
			{
				result.push_back({ nums[i], nums[l], nums[r] });
				l++;
				r--;
				while (l < r && nums[l] == nums[l + 1]) l++;
			}
			else if (sum < 0) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	return result;
}