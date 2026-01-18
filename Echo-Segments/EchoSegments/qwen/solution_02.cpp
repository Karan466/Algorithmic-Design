#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 2
// Misinterprets echo value as number of distinct elements

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

        set<int> distinct;
        for (int i = l; i <= r; i++)
            distinct.insert(a[i]);

        // WRONG: echo value is not distinct count
        cout << distinct.size() << "\n";
    }

    return 0;
}
