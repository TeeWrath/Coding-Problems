#include <bits/stdc++.h>
using namespace std;

// Function to calculate the squared distance between two points
int squared_distance(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool isSquare(int l, int r, int d, int u)
{
    // Coordinates of the four points
    vector<pair<int, int>> points = {{-l, 0}, {r, 0}, {0, -d}, {0, u}};

    // Vector to store all squared distances between points
    vector<int> distances;

    // Calculate all 6 pairwise distances
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            int dist = squared_distance(points[i].first, points[i].second, points[j].first, points[j].second);
            distances.push_back(dist);
        }
    }

    // Sort the distances
    sort(distances.begin(), distances.end());

    // Check if we have 4 equal side lengths and 2 equal diagonal lengths
    return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] &&
           distances[4] == distances[5];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;

        // Output the result for each test case
        cout << (isSquare(l, r, d, u) ? "YES" : "NO") << endl;
    }

    return 0;
}
