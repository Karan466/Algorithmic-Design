#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int n = 10;
    cout << n << " " << n << "\n";
    for (int i = 0; i < n; i++)
        cout << rand() % 5 + 1 << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << 1 << " " << n << "\n";
}
