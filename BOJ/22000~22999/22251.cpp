#include <iostream>
#include <vector>
using namespace std;

const vector<bool> nums[10] =
{
	{1,1,1,0,1,1,1}, // 0
	{0,0,1,0,0,1,0}, // 1
	{1,0,1,1,1,0,1}, // 2
	{1,0,1,1,0,1,1}, // 3
	{0,1,1,1,0,1,0}, // 4
	{1,1,0,1,0,1,1}, // 5
	{1,1,0,1,1,1,1}, // 6
	{1,0,1,0,0,1,0}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,1,1,0,1,1}, // 9
};

void getDiff(vector<vector<int>>& diff) 
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			int sum = 0;

			for (int elem = 0; elem < 7; elem++)
			{
				if (nums[i][elem] != nums[j][elem])
					sum++;
			}

			diff[i][j] = sum;
		}
	}
}

/// <summary>
/// 입력받은 num을 digit vector로 변환하는 함수
/// </summary>
vector<int> getDigits(int num, int K) 
{
	vector<int> result(K, 0);

	for (int i = K - 1; i >= 0; i--)
	{
		result[i] = num % 10;
		num /= 10;
	}

	return result;
}

/// <summary>
/// 입력받은 digit vector를 num으로 변환하는 함수
/// </summary>
int getNum(vector<int>& digits)
{
	int result = 0;

	for (int digit : digits) 
	{
		result = result * 10 + digit;
	}

	return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, P, X;
    cin >> N >> K >> P >> X;

    vector<vector<int>> diff(10, vector<int>(10, 0));
    getDiff(diff);

    vector<int> X_digits = getDigits(X, K);

    int answer = 0;

    for (int i = 1; i <= N; i++)
	{
        if (i == X) // 현재 층은 확인 불필요
			continue; 

		// i번째 층을 digit 형태로 변환
        vector<int> target_digits = getDigits(i, K);
        
        // 자릿수별 비교
		int changes = 0;
        for (int j = 0; j < K; j++) 
		{
            changes += diff[X_digits[j]][target_digits[j]];
        }

        if (1 <= changes && changes <= P) 
		{
            answer++;
        }
    }

    cout << answer;

    return 0;
}