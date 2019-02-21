// Bingo Mode   1 : Easy,  2 : Hard
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int iTemp, idx1, idx2;

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << iNumber[i*5 +j]<< "\t";
			}
			cout << endl;
			cout << endl;
		}
		break;
	}
	system("pause");
	return 0;
}