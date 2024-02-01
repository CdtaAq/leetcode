class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        # Calculate the target number of subarrays
        n = len(nums) // 3

        # Sort the array and reshape it into subarrays of size 3, 
        # while filtering out subarrays where the difference between the max and min is greater than k
        nums = [*filter(lambda x: x[2] - x[0] <= k, reshape(sorted(nums), (len(nums) // 3, 3)))]

        # If the number of valid subarrays is equal to the target, return the subarrays; otherwise, return an empty list
        return nums * (n == len(nums))
