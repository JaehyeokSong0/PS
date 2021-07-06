#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define MAXSIZE 100000+1
vector<int> ddr;
int memo[5][5][MAXSIZE] = { 0, }; //왼발, 오른발, 인덱스

//이동에 드는 힘을 반환하는 함수
int getCost(int start, int end)
{
    if (start == end)
        return 1;
    else if ((start == 0) || (end == 0))
        return 2;
    else if (abs(start - end) == 2)
        return 4;
    else
        return 3;
}
int dp(int left, int right, int index)
{
    if (index == ddr.size())
        return 0;
    if (memo[left][right][index] != 0) //memoization 이용
        return memo[left][right][index];
    return memo[left][right][index] = min(dp(ddr[index], right, index + 1) + getCost(left, ddr[index]), dp(left , ddr[index], index + 1) + getCost(right, ddr[index]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int left = 0, right = 0; //왼발, 오른발
    int input;
    while (cin >> input)
    {
        if (input == 0)
            break;
        ddr.push_back(input);
    }

    cout << dp(0, 0, 0);

    return 0;
}