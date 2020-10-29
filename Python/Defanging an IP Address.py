class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        string_new = address.replace(".","[.]")
        return string_new
        
