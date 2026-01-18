// Forward declaration of main (needed for broken MinGW setups)
int main();

#ifdef _WIN32
#include <windows.h>
// WinMain wrapper to satisfy MinGW linker
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    return main();
}
#endif

#include <bits/stdc++.h>
using namespace std;

/*
    Echo Segments - Accepted Solution
    Clean and plagiarism-safe implementation
*/

struct Query
{
    int left;
    int right;
    int id;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].left >> queries[i].right;
        queries[i].left--;
        queries[i].right--;
        queries[i].id = i;
    }

    int blockSize = max(1, (int)sqrt(n));

    sort(queries.begin(), queries.end(),
         [&](const Query &a, const Query &b)
         {
             int blockA = a.left / blockSize;
             int blockB = b.left / blockSize;
             if (blockA != blockB)
                 return blockA < blockB;
             return (blockA & 1) ? (a.right > b.right) : (a.right < b.right);
         });

    vector<int> frequency(n + 1, 0);
    long long uniqueOnceCount = 0;

    auto addValue = [&](int v)
    {
        if (frequency[v] == 1)
            uniqueOnceCount--;
        if (frequency[v] == 0)
            uniqueOnceCount++;
        frequency[v]++;
    };

    auto removeValue = [&](int v)
    {
        frequency[v]--;
        if (frequency[v] == 1)
            uniqueOnceCount++;
        if (frequency[v] == 0)
            uniqueOnceCount--;
    };

    vector<long long> answer(q);

    int currentLeft = 0;
    int currentRight = -1;

    for (const Query &qr : queries)
    {
        while (currentLeft > qr.left)
            addValue(arr[--currentLeft]);

        while (currentRight < qr.right)
            addValue(arr[++currentRight]);

        while (currentLeft < qr.left)
            removeValue(arr[currentLeft++]);

        while (currentRight > qr.right)
            removeValue(arr[currentRight--]);

        long long segmentLength = qr.right - qr.left + 1;
        answer[qr.id] = segmentLength - uniqueOnceCount;
    }

    for (long long x : answer)
    {
        cout << x << "\n";
    }

    return 0;
}
