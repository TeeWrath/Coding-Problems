#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            // Create adjacency list and indegree array
            vector<vector<int>> adj(numCourses); // Adjacency list for the graph
            vector<int> indegree(numCourses, 0);
    
            // Build the graph: for each [course, prereq], add edge prereq -> course
            for (const auto& pair : prerequisites) {
                int course = pair[0];    // The course that has a prerequisite
                int prereq = pair[1];    // The prerequisite course
                adj[prereq].push_back(course); // Directed edge: prereq -> course
                indegree[course]++;      // Increment indegree for the course
            }
    
            // Initialize queue with all courses that have no prerequisites (indegree = 0)
            queue<int> q;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            // Perform topological sort
            vector<int> topo; // Count of courses that can be taken
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                topo.push_back(node);
    
                // For each course that depends on the current node
                for (auto neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            if(topo.size() != numCourses)return {};
            return topo;
        }
    };