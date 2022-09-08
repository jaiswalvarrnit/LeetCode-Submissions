class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        cumm = sum(nums)
        lsum = 0
        rsum = 0;
        for i in range(n):
            rsum = cumm - lsum - nums[i]
            if(lsum == rsum):
                return i
            lsum += nums[i]
        return -1