class Solution(object):        
    
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        
        # switch flowers to a zero-indexed positioning system
        for i in range(len(flowers)):
            flowers[i] -= 1
        
        # garden full on last day
        # represent a full garden as a linked list
        
        garden = [[i-1, i+1] for i in range(len(flowers))]
        garden[0][0] = None
        garden[-1][1] = None
        
        latest_ans = -1
        ￼
        for day in range(len(flowers)-1, -1, -1):
            cur = flowers[day]
            print garden
            print cur

            left, right = garden[cur]
            
            # check if removal of flower means distance of k created
            if left != None and right != None:
                if right - left - 1 == k:
                    print left, right
                    latest_ans = day
            
            # remove flower from linked list
            if left != None:
                garden[left][1] = right
            if right != None:
                garden[right][0] = left
            
        return latest_ans
            
            
sol = Solution()

sol.kEmptySlots([3,9,2,8,1,6,10,5,4,7], 1)