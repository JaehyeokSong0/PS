#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(string a, string b)
	{
		if (a.length() == b.length())
			return a > b;
		else
			return a.length() > b.length();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;
	priority_queue<string, vector<string>, compare> pq;

	cin >> n;
	while (n--)
	{
		cin >> str;
		pq.push(str);
	}

	string lastStr = "";
	while (!pq.empty())
	{
		if (pq.top() != lastStr)
		{
			cout << pq.top() << "\n";
			lastStr = pq.top();
		}
		pq.pop();
	}

	return 0;
}