#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> snowflakes(n);
        for (int i = 0; i < n; ++i) {
            cin >> snowflakes[i];
        }

        unordered_map<int, int> lastSeen;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            int snow = snowflakes[right];

            if (lastSeen.count(snow) && lastSeen[snow] >= left) {
                left = lastSeen[snow] + 1;
            }

            lastSeen[snow] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        cout << maxLen << '\n';
    }

    return 0;
}
