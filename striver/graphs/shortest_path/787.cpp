#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }

        vector<int> totalPrice(n, 1e9);
        queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}

        totalPrice[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int stops = current.first;
            int node = current.second.first;
            int cost = current.second.second;

            if (stops > k) continue; // No need to process further if stops exceed k
            for (auto neighbor : adj[node]) {
                int city = neighbor.first;
                int price = neighbor.second;
                int newPrice = cost + price;

                if (newPrice < totalPrice[city] && stops <= k) {
                    totalPrice[city] = newPrice;
                    q.push({stops + 1, {city, newPrice}});
                }
            }
        }

        if(totalPrice[dst] == 1e9)return -1;
        return totalPrice[dst];
    }
};