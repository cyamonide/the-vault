# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if head == None:
            return None
        
        visited = []
        visited.append(head)
        
        node = head
        
        while node.next != None:
            node = node.next
            if node in visited:
                return node
            else:
                visited.append(node)
                
        return None