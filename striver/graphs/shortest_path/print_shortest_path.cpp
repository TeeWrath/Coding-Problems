#include<bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> createWeightedUndirectedGraph(int n, int m) {
    std::vector<std::vector<std::pair<int, int>>> adjacent(n);
    std::cout << "Creating Undirected Weighted Graph" << std::endl;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        std::cout << "Enter node values for edges (u and v): ";
        std::cin >> u >> v;
        std::cout << "Enter weight between u and v: ";
        std::cin >> wt;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid node index!" << std::endl;
            i--;
            continue;
        }
        if (wt < 0) {
            std::cout << "Negative weights are not allowed!" << std::endl;
            i--;
            continue;
        }
        adjacent[u].push_back({v, wt});
        adjacent[v].push_back({u, wt});
    }
    return adjacent;
}

void printWeightedGraph(const std::vector<std::vector<std::pair<int, int>>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        std::cout << "Node " << i << ": ";
        for (auto it : graph[i]) {
            std::cout << "{" << it.first << "," << it.second << "} ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    std::vector<int> dijkstra(int V, const std::vector<std::vector<std::pair<int, int>>>& adj, int src, int destination) {
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        std::vector<long long> distance(V, LLONG_MAX);
        std::vector<int> parent(V, -1);
        distance[src] = 0;
        parent[src] = src;
        pq.push({0, src});

        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edgeWeight = it.second;
                if (dist + edgeWeight < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        std::vector<int> pathToDest;
        if (distance[destination] == LLONG_MAX) {
            return pathToDest; // Destination unreachable
        }

        int node = destination;
        while (node != -1) {
            pathToDest.push_back(node);
            node = parent[node];
        }
        std::reverse(pathToDest.begin(), pathToDest.end());
        return pathToDest;
    }
};

int main() {
    int n, m;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> m;
    if (n <= 0 || m < 0) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }
    auto wug = createWeightedUndirectedGraph(n, m);
    printWeightedGraph(wug);
    std::cout << "Enter source node: ";
    int src;
    std::cin >> src;
    std::cout << "Enter destination node: ";
    int dest;
    std::cin >> dest;
    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        std::cout << "Invalid source or destination!" << std::endl;
        return 1;
    }
    Solution sol;
    std::vector<int> path = sol.dijkstra(n, wug, src, dest);
    std::cout << "Shortest path is: ";
    if (path.empty()) {
        std::cout << "No path exists!" << std::endl;
    } else {
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}