#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobSequence(vector<Job> &jobs) {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), comp);
    
    // Find maximum deadline
    int maxDead = 0;
    for (const auto &job : jobs) {
        maxDead = max(maxDead, job.deadline);
    }
    
    // Initialize slot array (-1 means free)
    vector<int> slot(maxDead + 1, -1);
    int jobsDone = 0;
    int totalProfit = 0;
    
    // Try to schedule each job
    for (int i = 0; i < jobs.size(); i++) {
        // Find the latest possible slot for the current job
        for (int j = min(maxDead, jobs[i].deadline); j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id; // Assign job to this slot
                jobsDone++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    return {jobsDone, totalProfit};
}

int main() {
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    pair<int, int> ans = jobSequence(jobs);
    cout << "Total jobs done: " << ans.first << " Total profit earned: " << ans.second << endl;
    return 0;
}