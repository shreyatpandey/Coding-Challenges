class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        points.sort(key=lambda x: x[0]*x[0] + x[1]*x[1])
        return points[:K]
        
