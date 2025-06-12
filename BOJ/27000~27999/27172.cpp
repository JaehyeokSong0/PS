#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int maxElem = -1;
	vector<int> cards(N);
	unordered_set<int> cardSet;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		cards[i] = input;
		maxElem = max(maxElem, input);
		cardSet.insert(input);
	}

	vector<int> scores(maxElem + 1, 0);

	for (auto card : cardSet)
	{
		for (int i = card * 2; i <= maxElem; i += card)
		{
			if (cardSet.find(i) != cardSet.end())
			{
				scores[card]++;
				scores[i]--;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << scores[cards[i]] << " ";
	cout << "\n";

	return 0;
}