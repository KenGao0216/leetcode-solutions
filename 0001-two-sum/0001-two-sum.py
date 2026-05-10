class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arr = sorted((nums, i) for i, nums in enumerate(nums))
        for i in range(len(arr)):
            x = bisect_left(arr, (target - arr[i][0], -1), i+1)
            if(x < len(arr) and arr[x][0] == target-arr[i][0]):
                return [arr[i][1],arr[x][1]]

        return []