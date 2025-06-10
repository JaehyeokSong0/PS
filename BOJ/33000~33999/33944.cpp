#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;

enum stateType
{
	ground = 0,
	onAir1 = 1, // 1프레임 후 착지
	onAir2 = 2,
	onAir3 = 3
};

void getNextState(ll distance, unordered_set<stateType>& possibleStates, unordered_set<stateType>& nextStates)
{
	if (distance > 3)
	{
		nextStates.insert({ onAir1, onAir2, onAir3 });
	}
	else if (distance == 3)
	{
		for (stateType state : possibleStates)
		{
			switch (state)
			{
			case ground:
				nextStates.insert({ onAir1, onAir2 ,onAir3 });
				break;
			case onAir1:
				nextStates.insert({ onAir2 ,onAir3 });
				break;
			case onAir2:
				nextStates.insert({ onAir3 });
				break;
			}
		}
	}
	else if (distance == 2)
	{
		for (stateType state : possibleStates)
		{
			switch (state)
			{
			case ground:
				nextStates.insert({ onAir2, onAir3 });
				break;
			case onAir1:
				nextStates.insert(onAir3);
				break;
			case onAir3:
				nextStates.insert(onAir1);
				break;
			}

		}
	}
	else if (distance == 1)
	{
		for (stateType state : possibleStates)
		{
			switch (state)
			{
			case ground:
				nextStates.insert(onAir3);
				break;
			case onAir2:
				nextStates.insert(onAir1);
				break;
			case onAir3:
				nextStates.insert(onAir2);
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		ll N;
		int X;
		cin >> N >> X;

		ll currentPosition = 0;
		unordered_set<stateType> possibleStates = { ground };

		bool isPossible = true;
		for (int i = 0; i < X; i++)
		{
			ll spike;
			cin >> spike;

			if (isPossible == false)
				continue;

			ll distance = spike - currentPosition;
			unordered_set<stateType> nextStates;

			// 현재 가능한 상태
			for (stateType state : possibleStates)
			{
				if (distance > 3)
				{
					unordered_set<stateType> tmp = { ground };
					getNextState(distance - (ll)state, tmp, nextStates);
				}
				else
					getNextState(distance, possibleStates, nextStates);
			}

			currentPosition = spike;
			possibleStates = nextStates;

			if (possibleStates.empty())
			{
				isPossible = false;
				continue;
			}
		}

		if (isPossible == true)
			cout << "POSSIBLE\n";
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}