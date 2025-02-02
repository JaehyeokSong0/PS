// Solved with unordered set

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;

	int N, M;
	cin >> N >> M;

	unordered_set<string> dict;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		dict.insert(input);
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;

		if (dict.find(input) != dict.end())
		{
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}