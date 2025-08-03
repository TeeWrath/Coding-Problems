#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int landFinish = max(landStartTime[i], 0) + landDuration[i];
                int waterStartAfterLand = max(waterStartTime[j], landFinish);
                int total1 = waterStartAfterLand + waterDuration[j];
                
                int waterFinish = max(waterStartTime[j], 0) + waterDuration[j];
                int landStartAfterWater = max(landStartTime[i], waterFinish);
                int total2 = landStartAfterWater + landDuration[i];
                
                minTime = min(minTime, min(total1, total2));
            }
        }
        
        return minTime;
    }
};