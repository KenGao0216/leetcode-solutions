class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        lst = []
        for x in nums:
            lst2 = [int(d) for d in str(x)]
            lst+=lst2

        return lst