public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        IList<IList<int>> result = new List<IList<int>>();
        PermuteHelper(nums, 0, result);
        return result;
    }

    private void PermuteHelper(int[] nums, int start, IList<IList<int>> result) {
        if (start == nums.Length - 1) {
            List<int> permutation = new List<int>(nums);
            result.Add(permutation);
            return;
        }

        for (int i = start; i < nums.Length; i++) {
            Swap(nums, start, i);
            PermuteHelper(nums, start + 1, result);
            Swap(nums, start, i); // backtrack
        }
    }

    private void Swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
