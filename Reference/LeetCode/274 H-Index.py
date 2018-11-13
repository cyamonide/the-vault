class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        
        """
        [3, 0, 6, 1, 5]
        [0, 1, 3, 5, 6]
        Traverse list backwards, while keeping counter
            6, h = 1, 5 < h? no
            5, h = 2, 3 < h? no
            3, h = 3, 1 < h? yes
            h-index is 3
        """
        
        citations = sorted(citations)
        
        if len(citations) == 0:
            return 0
        
        if citations[-1] == 0:
            return 0
        
        if len(citations) == 1:
            return 1
        
        h = 0
        for i in xrange(len(citations)-1, 0, -1):
            h += 1
            if citations[i-1] <= h:
                return h
            
        return h+1