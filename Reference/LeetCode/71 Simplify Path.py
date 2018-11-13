class Solution(object):
    
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        
        # list repr of input path
        l = list(path.split('/'))
        # list repr of net path
        p = []
        # p-index of current directory
        i = -1 # -1 means root dir
        
        for item in l:
            # redundant slashes
            if item == '':
                continue
            
            # current dir
            if item == '.':
                continue
                
            # parent dir
            if item == '..':
                if i > -1:
                    # pop last element
                    del(p[-1])
                    i -= 1
                continue
            elif item == '..':
                continue
                
            # if new directory name
            i += 1
            p.append(item)
            
        # print the net path
        out = ''
        
        for item in p:
            out += '/' + item
            
        if out == '':
            return '/'
        
        return out
                
            