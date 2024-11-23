#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
	bool isEnd;

	TrieNode* next[10];
	TrieNode()
	{
		isEnd = false;
		for (int i = 0; i < 10; i++)
			next[i] = nullptr;
	}
};

TrieNode* root;
bool result = true;

void Insert(string input)
{
	TrieNode* curr = root;
	int index = 0;

	while (index < input.length())
	{
		int num = input[index] - '0';

		if (curr->next[num] == nullptr)
		{
			curr->next[num] = new TrieNode;
		}
		else
		{
			if (curr->next[num]->isEnd == true)
			{
				result = false;
				break;
			}

			if (index == input.length() - 1)
			{
				result = false;
				break;
			}
		}

		curr = curr->next[num];
		index++;
	}

	if (result == false)
	{
		return;
	}

	curr->isEnd = true;
}

void Reset()
{
	if (root)
		delete root;

	root = new TrieNode;
	result = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	for (int ti = 0; ti < t; ti++)
	{
		cin >> n;

		Reset();
		for (int ni = 0; ni < n; ni++)
		{
			string input;
			cin >> input;

			if (result == true)
			{
				Insert(input);
			}
		}

		if (result == true)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}