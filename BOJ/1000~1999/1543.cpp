#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string docs, str;
	getline(cin, docs);
	getline(cin, str);

	int answer = 0;
	for (auto it = docs.begin(); it < docs.end();)
	{
		auto found = docs.find(str, it - docs.begin());
		if (found != string::npos)
		{
			answer++;
			it = docs.begin() + found + str.length(); // it++ º¸Á¤
		}
		else
			it++;
	}

	cout << answer << "\n";

	return 0;
}