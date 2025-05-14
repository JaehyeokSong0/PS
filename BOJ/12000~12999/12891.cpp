#include <iostream>
#include <string>
using namespace std;

int A, C, G, T;
int a = 0, c = 0, g = 0, t = 0;
int answer = 0;

/// <summary>
/// op == true => increase
/// op == false => decrease
/// </summary>
void modify(char ch, bool op)
{
	switch (ch)
	{
	case 'A':
		op ? a++ : a--;
		break;
	case 'C':
		op ? c++ : c--;
		break;
	case 'G':
		op ? g++ : g--;
		break;
	case 'T':
		op ? t++ : t--;
		break;
	}
}

void checkAnswer()
{
	if ((a >= A) && (c >= C) && (g >= G) && (t >= T))
		answer++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int S, P;
	string dna;

	cin >> S >> P >> dna
		>> A >> C >> G >> T;

	for (int i = 0; i < P; i++)
		modify(dna[i], true);
	checkAnswer();

	for (int i = 1; i < S - P + 1; i++)
	{
		modify(dna[i - 1], false);
		modify(dna[i - 1 + P], true);
		checkAnswer();
	}

	cout << answer << "\n";

	return 0;
}