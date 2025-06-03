#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    
    for (int asteroid : asteroids) {
        bool destroyed = false;
        while (!st.empty() && asteroid < 0 && st.top() > 0) { // Collision: left-moving vs right-moving
            if (abs(st.top()) < abs(asteroid)) {
                st.pop(); // Top asteroid is smaller, destroy it
                continue; // Check next stack top
            } else if (abs(st.top()) == abs(asteroid)) {
                st.pop(); // Equal size, both destroyed
                destroyed = true;
                break;
            } else {
                destroyed = true; // Current asteroid is smaller, destroy it
                break;
            }
        }
        if (!destroyed) {
            st.push(asteroid); // No collision or no destruction, add to stack
        }
    }
    
    // Transfer stack to result vector in correct order
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    
    return ans;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = asteroidCollision(asteroids);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}