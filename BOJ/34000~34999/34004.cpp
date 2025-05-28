#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/// <summary>
/// �̾���� ������ü�� ������ ������ü�� ������ ����� ������ �����ϴ� �Ѹ��� ������ �ѳ��̵� �ּ�
/// n^3 (1, 8, 27, ...)
/// </summary>
/// <param name="size">������ü�� ����</param>
int getMinWidth(int size, vector<int>& cubes)
{
	auto lb = lower_bound(cubes.begin(), cubes.end(), size);
	int lowerRoot = lb - cubes.begin();
	int upperRoot = lowerRoot + 1;

	if (size == *lb)
	{
		return (upperRoot * upperRoot) * 6;
	}

	int remain = size; // ���� ��� ����
	int sum = 0; // �ѳ����� ����

	if (upperRoot * upperRoot * lowerRoot <= remain) // ���� ���̸� �����°� ����
	{
		remain = size - (upperRoot * upperRoot * lowerRoot);
		sum = (upperRoot * upperRoot) * 2 + (lowerRoot * upperRoot) * 4;

		while (remain) // �� �� �� �ױ� ����
		{
			// �ּ� ���簢��
			int sqSize = (int)sqrt(remain); // �� ��
			sum += sqSize * 4;
			remain -= sqSize * sqSize;

			int attached = 0; // ������ ���ο��� ������ ���
			while (remain) // �������� ���簢�� �������� ������ó�� Ȯ��
			{
				if (attached % sqSize == 0) // ���� OR �� �� �� ä��
				{
					sum += 2;
				}

				remain--;
				attached++;
			}
		}
	}
	else // �Ұ���
	{
		int count = 0;
		sum = lowerRoot * lowerRoot * 6;
		remain -= lowerRoot * lowerRoot * lowerRoot;

		while (remain && count < 2) // �� ���� �鿡 ���̱�
		{
			if (remain >= lowerRoot * lowerRoot)
			{
				sum += lowerRoot * 4;
				remain -= lowerRoot * lowerRoot;
				count++;
			}
			else
				break;
		}

		if (count == 2) // �� �࿡ �� �پ��� ��� : remain�� 0 ~ lowerRoot ������ �� 
		{
			if (remain) // ������ �� ���� ƴ�� �޲ٴ� �Ŷ� 1���� ������ ������ ������ �ѳ��̴� ����
			{
				sum += 2;
				remain = 0;
			}
		}
		else
		{
			// �ּ� ���簢��
			int sqSize = (int)sqrt(remain); // �� ��
			sum += sqSize * 4;
			remain -= sqSize * sqSize;

			int attached = 0; // ������ ���ο��� ������ ���
			while (remain) // �������� ���簢�� �������� ������ó�� Ȯ��
			{
				if (attached % sqSize == 0) // ���� OR �� �� �� ä��
				{
					sum += 2;
				}

				remain--;
				attached++;
			}
		}

	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N^3 �迭
	vector<int> cubes;

	for (int i = 1; i <= 101; i++)
		cubes.push_back(i * i * i);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << getMinWidth(N, cubes) << "\n";
	}

	return 0;
}