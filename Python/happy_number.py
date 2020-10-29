class Solution:
    def isHappy(self, n: int) -> bool:
        stack=[]
        n=str(n)
        while n not in stack:
            #print(n)
            num=0
            stack.append(n)
            for string in n:
                num+=int(string)**2
            n=str(num)
            if n=='1':
                return True
        return False
