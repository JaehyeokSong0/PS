#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	int sum = 0;
	stack <pair<int, int>> partials; // { 부분 개수, 해당 숫자 }
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '(')
		{
			partials.push({ sum - 1 , S[i - 1] - '0' });
			sum = 0;
		}
		else if (S[i] == ')')
		{
			sum = sum * partials.top().second + partials.top().first;
			partials.pop();
		}
		else
		{
			sum++;
		}
	}

	cout << sum << "\n";

	return 0;
}