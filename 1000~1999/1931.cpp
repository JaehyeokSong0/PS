#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y)
{
	if (y.second == x.second)
		return y.first > x.first;
	return y.second > x.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, start, end, ret = 1;
	vector<pair<int, int>> meeting;

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> start >> end;
		meeting.push_back({ start, end });
	}

	sort(meeting.begin(), meeting.end(), compare);

	pair<int, int> lastMeeting = meeting[0];

	for (int i = 1;i < meeting.size();i++)
	{
		if (meeting[i].first >= lastMeeting.second)
		{
			lastMeeting = meeting[i];
			ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}