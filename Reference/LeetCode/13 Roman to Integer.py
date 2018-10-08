class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """

        values = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }

        s = list(s)

        retval = 0
        while s:
            # check for compounds
            try:
                compound = ''.join(s[:2])
                if compound == "IV":
                    retval += 4
                elif compound == "IX":
                    retval += 9
                elif compound == "XL":
                    retval += 40
                elif compound == "XC":
                    retval += 90
                elif compound == "CD":
                    retval += 400
                elif compound == "CM":
                    retval += 900
                else:
                    raise IndexError
                s.pop(0)
                s.pop(0)
                continue
            except IndexError:
                pass

            # check for individual/multiple instances of s[0]
            this_symb = s.pop(0)
            this_symb_count = 1
            try:
                while s[0] == this_symb:
                    this_symb_count += 1
                    s.pop(0)
            except IndexError:
                pass

            retval += values.get(this_symb)*this_symb_count

        return retval
