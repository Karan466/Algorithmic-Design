#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 3
// Uses global frequency instead of range-specific frequency

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> globalFreq;
    for (int x : a)
        globalFreq[x]++;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int echo = 0;
        for (int i = l; i <= r; i++)
        {
            if (globalFreq[a[i]] > 1)
                echo++;
        }

        cout << echo << "\n";
    }

    return 0;
}
