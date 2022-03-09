'''
Input:- 
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3,4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
'''

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stack = []
        result = [0] * n
        
        def normalizeProcessTime(processTime):
            return processTime.split(':')  # FB asks about unicode compression
            #if its byte use this :- processTime.encode('ascii','ignore').split(':')
        
        for processTime in logs:
            #print("processTime:",processTime)
            processId, eventType, time = normalizeProcessTime(processTime)
            
            if eventType == "start":
                stack.append([processId, time])
            
            elif eventType == "end":
                processId, startTime = stack.pop()
                timeSpent = int(time) - int(startTime) + 1 # Add 1 cause 0 is included
                result[int(processId)] += timeSpent
                
                # Decrement time for next process in the stack
                if len(stack) != 0:
                    nextProcessId, timeSpentByNextProcess = stack[-1] #
                    result[int(nextProcessId)] -= timeSpent
                    
        return result
