#include <iostream>
using namespace std;

int n;
int ret = 0;

int num[3] = { 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n < 10)
        num[1] = num[2] = n;
    else
    {
        num[0] = n / 10;
        num[1] = n % 10;
        num[2] = (num[0] + num[1]) % 10;
    }

    while (true)
    {        
        ret++;
        if (num[1] * 10 + num[2] == n)
            break;
        int tmp = (num[1] + num[2]) % 10;
        num[0] = num[1];
        num[1] = num[2];
        num[2] = tmp;
    }

    cout << ret;

    return 0;
}