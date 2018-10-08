class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        
        numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
        
        # convert formula to list of strings
        formula = list(formula)
        f = []
        
        while formula:
            if formula[0] == '(':
                formula.pop(0)
                f.append('(')
            elif formula[0] == ')':
                formula.pop(0)
                f.append(')')
            elif formula[0] in numbers:
                # check remaining
                num = formula.pop(0)
                while formula and formula[0] in numbers:
                    num += formula.pop(0)
                f.append(num)
            else:
                name = formula.pop(0)
                while formula and formula[0].islower():
                    name += formula.pop(0)
                f.append(name)
                if formula and formula[0].isupper():
                    f.append('1')
                elif formula and formula[0] == ')':
                	f.append('1')
                elif formula and formula[0] == '(':
                	f.append('1')
                elif not formula:
                	f.append('1')
        
        # traverse backwards and multiply numbers involved in parentheses by factor
        factor = 1
        factor_stack = []
        for i in xrange(len(f)-1, -1, -1):
        	if f[i] == '(':
        		f.pop(i)
        		factor //= factor_stack.pop(-1)
        		continue
        	elif f[i] == ')':
        		f.pop(i)
        		continue
        	try:
        		int(f[i])
        		if f[i-1] == ')':
        			factor *= int(f[i])
        			factor_stack.append(int(f[i]))
        			f.pop(i)
        		else:
        			f[i] = str(int(f[i])*factor)
        	except ValueError:
        		continue

        retval = {}
        for i in xrange(0, len(f), 2):
        	try:
        		retval[f[i]] += int(f[i+1])
        	except KeyError:
        		retval[f[i]] = int(f[i+1])

        lookup = sorted(retval)

        printval = ""

        for a in lookup:
        	printval += a
        	if retval[a] != 1:
        		printval += str(retval[a])

        return printval


            
        # if parentheses encountered, multiply everything in parentheses by its factor
        
        # move parentheses factors to the beginning of the parentheses
        
sol = Solution()
print sol.countOfAtoms("Mg(OH)2")
print sol.countOfAtoms("K4(ON(SO3)2)2")