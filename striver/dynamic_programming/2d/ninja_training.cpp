#include<bits/stdc++.h>
using namespace std;

// recursion
int fr(int day, int last, vector<vector<int>>& training){
    int maxi=0;
    if(day == 0){
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, training[day][i]);
            }
        }

        return maxi;
    }

    maxi =0;
    for(int i=0; i<3; i++){
        if(i != last){
            int points = training[day][i] +fr(day-1,i,training);
            maxi = max(maxi,points);
        }
    }

    return maxi;
}

// memoization
int fm(int day, int last, vector<vector<int>>& training, vector<vector<int>>& dp){
    int maxi=0;
    if(day == 0){
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, training[day][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1)return dp[day][last];

    maxi =0;
    for(int i=0; i<3; i++){
        if(i != last){
            int points = training[day][i] + fm(day-1, i, training,dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}

// tabulation
int ninjaTraining(int n, vector<vector<int>> points){
    vector<vector<int>> dp(n,vector<int>(4,0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;

            for(int task=0;task<=2;task++){
                if(task != last){
                    int activity =points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],activity);
                }
            }
        }
    }

    return dp[n-1][3];
}

// space optimization
int ninjaTraining(int n, vector<vector<int>> points){
    vector<int> dp(4,0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;

            for(int task=0;task<=2;task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }

    return dp[3];
}

int main(){
    // vector<vector<int>> training = {{10,40,70},{20,50,80},{30,60,90}};
    // cout << "Max points: " << fm(training.size()-1,-1,training);
    return 0;
}