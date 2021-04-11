class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (!edges.size() && n) return {0}; // edge case 
//         starting at each node, bfs through the graph
        vector<vector<int>> graph(n);
//         make a vector of indegrees
        vector<int> indegrees(n,0);
        queue<int> q;
//         make an adjacency list
//         const auto& e: edges refers to the edges vector, taking each element in the vector and referencing to the values in each element
        for (const auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
            indegrees[e[0]]++;
            indegrees[e[1]]++;
        }
        
//         get all leave nodes
        for (int i =0; i < n; i++) {
            indegrees[i] = graph[i].size();
            if (indegrees[i] == 1) {
                q.push(i);
                // std::cout << q.back() << std::endl;
            }
        }
//         start bfs
        int vnode = q.size();
        while (vnode < n) {
            int siz = q.size();
            while (siz--) {
                int u = q.front(); q.pop();
                for (int v: graph[u]) {
                    if (--indegrees[v] == 1) {
                        q.push(v);
                        vnode++;
                    }
                }
            }
        }
        
//         add the remaining items on the queue back into results
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};