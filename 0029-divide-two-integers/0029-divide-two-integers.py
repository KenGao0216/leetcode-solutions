class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        
        if dividend == -(1<<31) and divisor == -1:
            return 1<<31 -1

        neg = (dividend <0) != (divisor < 0)

        dividend = abs(dividend)
        divisor = abs(divisor)
        ans = 0
        while dividend >= divisor:
            tmp = divisor
            cnt = 1
            while (tmp<<1) <= dividend:
                tmp<<=1
                cnt<<=1
            dividend-=tmp
            ans+=cnt
        
        return -ans if neg else ans

