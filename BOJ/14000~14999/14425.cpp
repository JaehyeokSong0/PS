// Solved with TRIE

#include <iostream>
using namespace std;

struct trie
{
	bool finish;
	trie* next[26];

	trie()
	{
		finish = false;

		for (int i = 0; i < 26; i++)
			next[i] = nullptr;
	}
};

void insert(trie* curr, string& str, int index)
{
	int ch = str[index] - 'a';

	if (curr->next[ch] == nullptr)
	{
		curr->next[ch] = new trie;
	}

	if (index == str.length())
	{
		curr->finish = true;
		return;
	}
	else
	{
		insert(curr->next[ch], str, index + 1);
	}
}

bool find(trie* curr, string& str, int index)
{
	int ch = str[index] - 'a';
	
	if (index == str.length())
	{
		return (curr->finish == true);
	}
	else if (curr->next[ch] == nullptr)
	{
		return false;
	}
	else
	{
		return find(curr->next[ch], str, index + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;

	trie* const root = new trie;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		insert(root, input, 0);
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;

		if (find(root, input, 0) == true)
			answer++;
	}

	cout << answer << "\n";

	return 0;
}