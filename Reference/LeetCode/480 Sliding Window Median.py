class Solution(object):
    
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
            