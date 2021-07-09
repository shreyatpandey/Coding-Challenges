/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.


Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int, unordered_set<int>> in_degree, out_degree;
        for (const auto& p : prerequisites) {
            in_degree[p[0]].emplace(p[1]);
            out_degree[p[1]].emplace(p[0]);
        }
        vector<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree.count(i)== 0) {
                stk.emplace_back(i);
            }
        }
        vector<int>Result;
        while (!stk.empty()) {
            const auto node = stk.back(); stk.pop_back();
            Result.emplace_back(node);
            for (const auto& i : out_degree[node]) {
                in_degree[i].erase(node);
                if (in_degree[i].empty()) {
                    stk.emplace_back(i);
                    in_degree.erase(i);
                }
            }
            out_degree.erase(node);
        }
        return in_degree.empty() && out_degree.empty()?Result:vector<int>();
    }
    
};
