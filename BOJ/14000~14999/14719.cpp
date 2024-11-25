#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	int H, W;
	cin >> H >> W;

	vector<int> blocks;
	for (int wi = 0; wi < W; wi++)
	{
		int block;
		cin >> block;
		blocks.push_back(block);
	}

	// tallest보다 크거나 같은 블록을 만났을 때, 혹은 인덱스의 마지막에서 (더 작은 블록의 height) * (블록 간의 거리 = index 차이 - 1) - (중간의 블록 높이 누적합)을 answer에 누적
	// 좌 -> 우 && 크거나 같음
	int tallestHeight = 0;
	int tallestIndex = 0;
	int blockSum = 0;

	for (int i = 0; i < W; i++)
	{
		if (blocks[i] > 0)
		{
			tallestHeight = blocks[i];
			tallestIndex = i;
			break;
		}
	}

	for (int i = tallestIndex + 1; i < W; i++)
	{
		if (blocks[i] >= tallestHeight)
		{
			answer += tallestHeight * (i - tallestIndex - 1) - blockSum;

			tallestHeight = blocks[i];
			tallestIndex = i;
			blockSum = 0;
		}
		else
		{
			blockSum += blocks[i];
		}
	}


	// 우 -> 좌 && 더 큰 블록에 대해서만
	tallestHeight = 0;
	tallestIndex = W - 1;
	blockSum = 0;

	for (int i = W - 1; i >= 0; i--)
	{
		if (blocks[i] > 0)
		{
			tallestHeight = blocks[i];
			tallestIndex = i;
			break;
		}
	}

	for (int i = tallestIndex - 1; i >= 0; i--)
	{
		if (blocks[i] > tallestHeight)
		{
			answer += tallestHeight * (tallestIndex - i - 1) - blockSum;

			tallestHeight = blocks[i];
			tallestIndex = i;
			blockSum = 0;
		}
		else
		{
			blockSum += blocks[i];
		}
	}

	cout << answer;

	return 0;
}