#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int h[99999];
    for (int i = 0; i < N; i++)
        cin >> h[i];
    int maxHeight = 0;
    int ret = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (maxHeight < h[i])
        {
            ret++;
            maxHeight = h[i];
        }
    }
    cout << ret << endl;
    return 0;
}