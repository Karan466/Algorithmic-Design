#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 1
// Brute-force frequency calculation per query (TLE)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;

        unordered_map<int, int> freq;
        for (int i = l; i <= r; i++)
            freq[a[i]]++;

        int echo = 0;
        for (int i = l; i <= r; i++)
            if (freq[a[i]] > 1)
                echo++;

        cout << echo << "\n";
    }

    return 0;
}
