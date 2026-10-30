
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // Step 2: Distance array
        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        // Step 3: Min heap
        // {distance, node, consecutive_count}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // Starting node has one consecutive character
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 4: Dijkstra
        while(!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if(d != dist[node][cnt]) {
                continue;
            }

            // Destination reached
            if(node == n - 1) {
                return d;
            }

            // Explore neighbours
            for(auto &[next, wt] : adj[node]) {

                int newCnt;

                if(labels[node] == labels[next]) {
                    newCnt = cnt + 1;
                }
                else {
                    newCnt = 1;
                }

                // Invalid consecutive sequence
                if(newCnt > k) {
                    continue;
                }

                int newDist = d + wt;

                if(newDist < dist[next][newCnt]) {

                    dist[next][newCnt] = newDist;

                    pq.push({
                        newDist,
                        next,
                        newCnt
                    });
                }
            }
        }

        return -1;
    }
};
