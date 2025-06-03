#include <iostream>
#include <vector>
using namespace std;

bool parametricSearch(int M, int target, vector<int>& lectures)
{
	int count = 0;
	int currSum = 0;

	for (int lecture : lectures)
	{
		if (lecture > target)
			return false;

		if (lecture + currSum <= target)
		{
			currSum += lecture;
		}
		else
		{
			count++;
			currSum = lecture;
		}
	}

	count++; // 마지막 녹화본
	
	return (count <= M);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Input
	int N, M;
	cin >> N >> M;

	int totalTime = 0;
	vector<int> lectures(N);
	for (int i = 0; i < N;i++)
	{
		cin >> lectures[i];
		totalTime += lectures[i];
	}

	int left = 1;
	int right = totalTime;
	int mid = (left + right) / M;
	while (left <= right)
	{
		// 주어진 시간으로 녹화 가능 => 크기 줄여야 함
		if (parametricSearch(M, mid, lectures) == true)
			right = mid - 1;
		// 주어진 시간으로 녹화 불가 => 크기 늘려야 함
		else
			left = mid + 1;
		
		if(left <= right)
			mid = (left + right) / 2;
	}

	cout << left << "\n";
	return 0;
}