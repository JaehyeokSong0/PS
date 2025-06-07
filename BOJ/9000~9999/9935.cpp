#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str, explosionStr, answer;
	cin >> str >> explosionStr;

	for (char& ch : str)
	{
		answer += ch;

		if (answer.length() >= explosionStr.length() &&
			answer.substr(answer.length() - explosionStr.length(), explosionStr.length()) == explosionStr)
		{
			answer.erase(answer.length() - explosionStr.length(), explosionStr.length());
		}
	}

	if (str.empty())
		cout << "FRULA\n";
	else
		cout << answer << "\n";

	return 0;
}