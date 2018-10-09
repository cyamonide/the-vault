class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        
        m = {}
        
        if t < 0:
            return False
        if k == 0:
            return False
        if len(nums) <= 1:
            return False
        
        if t == 0:
            for i in xrange(len(nums)):
                # check if element already exists in dict
                try:
                    if m[nums[i]] != None:
                        return True
                except KeyError:
                    pass

                # add element to dict
                m[nums[i]] = 1

                # remove out-of-window element if required
                if i >= k:
                    m[nums[k]] = None
        else:
            for i in xrange(len(nums)):
                # check if element already exists in dict
                try:
                    if m[nums[i]//t] != None:
                        return True
                except KeyError:
                    pass

                # add element to dict
                m[nums[i]//t] = nums[i]

                # check left and right for elements
                try:
                    if m[nums[i]//t-1] != None and abs(m[nums[i]//t-1]-nums[i]) <= t:
                        return True
                except KeyError:
                    pass

                try:
                    if m[nums[i]//t+1] != None and abs(m[nums[i]//t+1]-nums[i]) <= t:
                        return True
                except KeyError:
                    pass

                # remove out-of-window element if required
                if i >= k:
                    m[nums[i-k]//t] = None
        
        return False
            
sol = Solution()
print(sol.containsNearbyAlmostDuplicate([3, 6, 0, 2], 2, 2))