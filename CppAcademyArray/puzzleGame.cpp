
#include <iostream>
#include <time.h>

//colsole input output
#include <conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iTemp, iIdx1, iIdx2;
	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	iNumber[24] = INT_MAX;

	for (int i = 0; i < 100; ++i)
	{
		iIdx1 = rand() % 24;
		iIdx2 = rand() % 24;

		iTemp = iNumber[iIdx1];
		iNumber[iIdx1] = iNumber[iIdx2];
		iNumber[iIdx2] = iTemp;
	}

	while (true)
	{
		system("cls");
		for (int i = 0; i < 3; ++i)
		{
			cout << "Number[" << i << "] = " << iNumber[i] << endl;
		}
		/*
		for (int i = 0; i < 25; ++i)
		{
			if (i % 5 == 0)
			{
				cout << endl;
			}
			cout << iNumber[i] << "\t";
		}
		cout << endl;
		*/

		int iWidth = 5;
		for (int i = 0; i < iWidth; ++i)
		{
			for (int j = 0; j < iWidth; ++j)
			{
				if (iNumber[iWidth * i + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[iWidth *i + j] << "\t";
			}
			cout << endl;
		}
		cout << "k : 위, j : 아래, h : 왼쪽, l : 오른쪽, q : 종료";
		//_getch() : 문자 1개 입력받으며 Enter를 치지 않아도 해당 문자를 반환하고 종료한다.
		char cInput = _getch();
		static int iNow = 24;
		if (cInput == 'q')
			break;
		switch (cInput)
		{
		case 'h':
		case 'H':
			if ((iNow - 1) < 0)
			{
				iNumber[iNow]= iNumber[iNow + 24];
				iNumber[iNow + 24] = INT_MAX;
				iNow += 24;
				break;
			}
			iNumber[iNow ]= iNumber[iNow - 1];
			iNumber[iNow -1] = INT_MAX;
			iNow -= 1;
			break;
		case 'j':
		case 'J':
			if ((iNow + 5) > 24)
			{
				iNumber[iNow]= iNumber[iNow -20 ];
				iNumber[iNow - 20] = INT_MAX;
				iNow -= 20;
				break;
			}
			iNumber[iNow ]= iNumber[iNow + 5];
			iNumber[iNow +5] = INT_MAX;
			iNow += 5;
			break;
		case 'k':
		case 'K':
			if ((iNow - 5) < 0)
			{
				iNumber[iNow]= iNumber[iNow + 20];
				iNumber[iNow + 20] = INT_MAX;
				iNow += 20;
				break;
			}
			iNumber[iNow ]= iNumber[iNow - 5];
			iNumber[iNow - 5] = INT_MAX;
			iNow -= 5;

			break;
		case 'l':
		case 'L':
			if ((iNow + 1) > 24)
			{
				iNumber[iNow]= iNumber[iNow - 24];
				iNumber[iNow - 24] = INT_MAX;
				iNow -= 24;
				break;
			}
			iNumber[iNow ]= iNumber[iNow + 1];
			iNumber[iNow + 1] = INT_MAX;
			iNow += 1;
			break;
		}
	}
	cout << endl<< "Game Over !!" << endl;

	system("pause");
	return 0;
}