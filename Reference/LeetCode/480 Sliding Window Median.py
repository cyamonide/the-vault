
from heapq import *

class Solution(object):
    
    """ This is the brute force method that barely passed """
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        
        # nums is original array
        # window is nums[:k]
        # sort window and get median
        # when window moves right one, remove nums[0] and add [k], maintaining sort
        
        window = sorted(nums[:k])
        
        meds = []
        if k % 2 == 0:
            meds.append((window[k//2]+window[k//2-1])/2.0)
        else:
            meds.append(float(window[k//2]))
        
        for j in xrange(k, len(nums)):
            window.remove(nums[j-k])
            window.append(nums[j])
            window = sorted(window)
            
            if k % 2 == 0:
                meds.append((window[k//2]+window[k//2-1])/2.0)
            else:
                meds.append(float(window[k//2]))
                
        return meds


    """ This is one of the optimized solutions using two heaps """
    def medianSlidingWindowHeap(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        
        # smaller half of numbers
        lo = []
        # larger half of numbers
        hi = []

        # lo can hold n+1 elements if k is odd
        # hi can hold n elements regardless
        # if k is odd, median is lo[0]
        # if k is even, median is average of hi[0] and lo[0]

        balance = 0
        # balance < 0 if lo needs more elements
        # balance > 0 if hi needs more elements
        # balance == 0 if balanced

        k_even = k%2==0

        if k_even:
            lo = dcpy(sorted(nums[:k]))[:k//2]
            hi = dcpy(sorted(nums[:k]))[k//2:k]
        else:
            lo = dcpy(sorted(nums[:k]))[:k//2+1]
            hi = dcpy(sorted(nums[:k]))[k//2+1:k]

        heapq._heapify_max(lo)
        heapq.heapify(hi)

        meds = []

        if k_even:
            meds.append((lo[0]+hi[0])/2.0)
        else:
            meds.append(float(lo[0]))

        invalid = []
        
        for j in xrange(k, len(nums)):
            invalid.append(nums[j-k])

            while lo[0] in invalid:
                invalid.remove(lo.pop(0))
                heapq._heapify_max(lo)
            while hi[0] in invalid:
                invalid.remove(heapq.heappop(hi))
            
            if nums[j] <= lo[0]:
                lo.append(nums[j])
                heapq._heapify_max(lo)

                # lazy removal
                while lo[0] in invalid:
                    invalid.remove(lo.pop(0))
                    heapq._heapify_max(lo)
                while hi[0] in invalid:
                    invalid.remove(heapq.heappop(hi))

                heapq.heappush(hi, lo.pop(0))
                heapq._heapify_max(lo)
            else:
                heapq.heappush(hi, nums[j])

                while lo[0] in invalid:
                    invalid.remove(lo.pop(0))
                    heapq._heapify_max(lo)
                while hi[0] in invalid:
                    invalid.remove(heapq.heappop(hi))

                lo.append(heapq.heappop(hi))
                heapq._heapify_max(lo)

            # lazy removal
            while lo[0] in invalid:
                invalid.remove(lo.pop(0))
                heapq._heapify_max(lo)
            while hi[0] in invalid:
                invalid.remove(heapq.heappop(hi))

            # add to median
            if k_even:
                meds.append((lo[0]+hi[0])/2.0)
            else:
                meds.append(float(lo[0]))

        return meds

    """ This is one of the optimized solutions using two heaps """
    def medianSlidingWindowHeap(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """

        k_even = k%2==0

        lo = sorted(nums[:k])

        if k_even:
            hi = lo[k//2:]
            lo = lo[:k//2]
        else:
            hi = lo[k//2+1:]
            lo = lo[:k//2+1]

        # change all values in lo to negative to implement max heap
        lo = list(map((lambda x : -x), lo))

        map((lambda x : heapify(x)), [hi, lo])

        invalids = []
        meds = []

        # compute first median
        if k_even:
            meds.append((hi[0]-lo[0])/2.0)
        else:
            meds.append(lo[0])

        balance = 0

        # get invalids
        for j in range(k, len(nums)):
            # add new value to invalid
            invalids.append(nums[j-k])

            new = nums[j]

            # insert new element into heaps
            if new <= -lo[0]:
                heappush(lo, -new)
                balance += 1
            else:
                heappush(hi, new)
                balance -= 1

            # rebalance heaps
            if balance > 0: # hi needs more elements
                heappush(hi, -heappop(lo))
                balance -= 1

            if balance < 0: # lo needs more elements
                heappush(lo, -(heappop(hi)))
                balance += 1

            # remove invalid numbers
            while -lo[0] in invalids:
                invalids.remove(-heappop(lo))
            while hi and hi[0] in invalids:
                invalids.remove(heappop(hi))
            if k_even:
                meds.append((hi[0]-lo[0])/2.0)
            else:
                meds.append(-lo[0])

        return meds

sol = Solution()
# print sol.medianSlidingWindowHeap([1, 2, 3, 4, 5, 6, 7, 8], 5)
print sol.medianSlidingWindowHeap([1, 3, -1, -3, 5, 3, 6, 7], 3)
