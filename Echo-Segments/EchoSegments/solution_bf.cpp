#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        unordered_map<int,int> freq;
        for (int i = l; i <= r; i++)
            freq[a[i]]++;

        int ans = 0;
        for (int i = l; i <= r; i++)
            if (freq[a[i]] > 1) ans++;
        cout << ans << "\n";
    }
}
