'''
The idea is to use bruteforce: simulate our process and check all possibilities, but do it carefully.

First we need to choose direction where each figure will move, it is kept in dirs tuple of pairs.
Also we have stopped_mask variable, which is to understand if we stopped or not. 
For example 101 mask will mean that we stopped on the second figure and did not stop on first and third.
When we do one step, we need to decide where we continue and where we are not. 
For example if we have mask 101, then we have 4 options: we can continue move for first and third figure, we can stop on one of them or stop on both.
Also we need to deal with cases when two figures are on the same place and that we did not reach out of board.
'''

'''
Complexity
Time complexity is O(29^4) for the case of 4 queens, space complexity is O(1).
'''
class Solution:
    def countCombinations(self, pieces, positions):
        positions = [tuple(x) for x in positions]
        self.ans = set()

        def dfs(pos, dirs, stopped_mask):   
            if stopped_mask == 0: return
            self.ans.add(tuple(pos))
            for active in range(1<<len(dirs)):
                if stopped_mask & active != active: continue
                new_pos = list(pos)
                new_mask = stopped_mask ^ active

                for i in range(len(new_pos)):
                    new_pos[i] = (new_pos[i][0] + dirs[i][0]*((new_mask>>i)&1), new_pos[i][1] + dirs[i][1]*((new_mask>>i)&1))

                if len(Counter(new_pos)) < len(dirs): continue
                all_c = list(chain(*new_pos))
                if min(all_c) <= 0 or max(all_c) > 8: continue
                dfs(new_pos, dirs, new_mask)

        poss = {}
        poss["rook"] = ((1, 0), (-1, 0), (0, 1), (0, -1))
        poss["bishop"] = ((1, 1), (1, -1), (-1, 1), (-1, -1))
        poss["queen"] = ((1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))

        for dirs in product(*(poss[i] for i in pieces)):
            dfs(positions, dirs, (1<<len(pieces)) - 1)

        return len(self.ans)
