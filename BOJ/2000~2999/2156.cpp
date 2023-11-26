#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 10001

int wine[MAXSIZE] = { 0, },
    memo[MAXSIZE] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ret;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> wine[i];

    memo[0] = wine[0];
    memo[1] = wine[0] + wine[1];
    memo[2] = max(wine[0] + wine[2], wine[1] + wine[2]);
    memo[3] = max(wine[3] + memo[1], wine[3] + wine[2] + memo[0]);
    ret = max(max(memo[1], memo[2]), memo[3]);

    for (int i = 4; i < n; i++)
    {
        memo[i] = max(max(wine[i] + wine[i - 1] + memo[i - 4] , wine[i] + wine[i - 1] + memo[i - 3]), wine[i] + memo[i - 2]);
        ret = max(ret, memo[i]);
    }

    cout << ret;

    return 0;
}