#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createDirectedGraph(int n, int m)
{
    vector<vector<int>> adjacent(n); // 0-based indexing
    cout << "Creating Directed Graph" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter node values for edges (from u to v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    return adjacent;
}

void printGraph(vector<vector<int>> graph)
{
    // Print only nodes 0 to n-1
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Node " << i << ": ";
        for (int j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Create adjacency list and indegree array
        vector<vector<int>> adj(numCourses); // Adjacency list for the graph
        vector<int> indegree(numCourses, 0);

        // Build the graph: for each [course, prereq], add edge prereq -> course
        for (const auto &pair : prerequisites)
        {
            int course = pair[0];          // The course that has a prerequisite
            int prereq = pair[1];          // The prerequisite course
            adj[prereq].push_back(course); // Directed edge: prereq -> course
            indegree[course]++;            // Increment indegree for the course
        }

        // Initialize queue with all courses that have no prerequisites (indegree = 0)
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Perform topological sort
        int cnt = 0; // Count of courses that can be taken
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            // For each course that depends on the current node
            for (auto neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // If cnt equals numCourses, all courses can be taken (no cycle)
        return cnt == numCourses;
    }
};