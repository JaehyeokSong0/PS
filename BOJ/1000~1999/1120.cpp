#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	int maxSameCount = -1;
	
	for (int i = 0; i <= B.length() - A.length(); i++)
	{
		int sameCount = 0;

		for (int j = 0; j < A.length(); j++)
		{
			if (A[j] == B[i + j])
				sameCount++;
		}

		if (maxSameCount < sameCount)
		{
			maxSameCount = sameCount;
		}
	}

	cout << A.length() - maxSameCount << "\n";

	return 0;
}