ector<pair<int, int>> toposort(vector<pair<int, int>> input) {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;
    vector<pair<int, int>> res;

    for(auto point : input) {
        graph[point.second].push_back(point.first);
        if(inDegree.find(point.first) == inDegree.end()) inDegree[point.first] = 0;
        if(inDegree.find(point.second) == inDegree.end()) inDegree[point.second] = 0;
        inDegree[point.first]++;
    }

    queue<int> qu;
    for(auto point : inDegree) {
        if(point.second == 0) qu.push(point.first);
    }

    while(!qu.empty()) {
        int node = qu.front();
        qu.pop();

        for(auto neighbor : graph[node]) {
            res.push_back({neighbor, node});
            if(--inDegree[neighbor] == 0) {
                qu.push(neighbor);
            }
        }
    }
    return res;
}


int main() {
    vector<pair<int, int>> input = {{1,10}, {2,20}, {3,30}, {10,200}, {20,100}};
    toposort(input);
}
