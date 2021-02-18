#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> tree;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(4); //소수점 4번째자리까지 출력

	string str;
	int cnt = 0;
	while (true)
	{
		getline(cin, str);
		if (str == "")
			break;
		tree.push_back(str);
		cnt++;
	}
	sort(tree.begin(), tree.end());

	string treeName = tree[0];
	int treeCnt = 1;
	for (int i = 1;i < cnt;i++)
	{
		if (treeName != tree[i])
		{
			cout << treeName << " " << 100 * (double)treeCnt / cnt << "\n";
			treeName = tree[i];
			treeCnt = 1;
		}
		else
			treeCnt++;
	}
	cout << treeName << " " << 100 * (double)treeCnt / cnt;

	return 0;
}