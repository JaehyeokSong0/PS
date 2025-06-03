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

	count++; // ������ ��ȭ��
	
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
		// �־��� �ð����� ��ȭ ���� => ũ�� �ٿ��� ��
		if (parametricSearch(M, mid, lectures) == true)
			right = mid - 1;
		// �־��� �ð����� ��ȭ �Ұ� => ũ�� �÷��� ��
		else
			left = mid + 1;
		
		if(left <= right)
			mid = (left + right) / 2;
	}

	cout << left << "\n";
	return 0;
}