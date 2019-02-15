// Array Cpp Academy
#include <iostream>
#include <time.h>
using namespace std;


int main() {
	// Star Diamond
	// Level : iLevel
	// Space : iLevel/2, iLevel/2 - 1, ....3,2,1,0,1,2,3....iLevel/2 +1, iLevel/2
	// iCount: i  if(i >iLevel/2) i -=1
	// Star  : icount*2+1
	/*
	int iLevel;
	int iCount = 0;
	cout << "Please input a number to create a Diamond : ";
	cin >> iLevel;

	for (int i = 0; i <= iLevel; ++i)
	{
		iCount = i;
		if (i > iLevel / 2)
		{
			iCount = iLevel - i;
		}
		for (int j = 0; j <= iLevel / 2 - iCount; ++j)
		{
			cout << " ";
		}

		for (int k = 0; k < iCount * 2 + 1; ++k)
		{
			cout << "*";
		}
		cout << endl;
	}
	 */

	int iArray[10] = {};
	for (int i = 0; i < 10; ++i)
	{
		cout << "iArray[" << i << "] = " << iArray[i] << endl;
	}
	system("cls");

	srand((unsigned int)time(0));

	// Base Ball Game
	int iBase[9] = {};

	for (int i = 0; i < 9; ++i)
	{
		iBase[i] = i + 1;
	}

	int iTemp, iNum1, iNum2;

	for (int j = 0; j < 100; ++j)
	{
		iNum1 = rand() % 9;
		iNum2 = rand() % 9;

		iTemp = iBase[iNum1];
		iBase[iNum1] = iBase[iNum2];
		iBase[iNum2] = iTemp;
	}
int iResult[3] = {};
	for (int k = 0; k < 3; ++k)
	{
		iResult[k] = iBase[k];
	}
	int iInput[3] = {};
	while (true)
	{
		for (int m = 0; m < 3; ++m)
		{
			while (true)
			{
			cout << (m + 1) << "번째 숫자를 입력해 주세요 : ";
				cin >> iInput[m];
				if (iInput[m] < 1 || iInput[m] > 9) {
					cout << "1 부터 9 사이의 숫자를 입력해 주세요 !!" << endl;
				}
				else if (m > 0 && iInput[m] == iInput[m - 1])
				{
					cout << "이미 입력한 숫자 입니다. 다른 숫자를 입력하세요 !" << endl;
				}
				else
					break;
			}
		}
		int iStrike = 0, iBall = 0;
		for (int n = 0; n < 3; ++n)
		{
			for (int i = 0; i < 3; ++i)
			{
				if (iResult[n] == iInput[i])
				{
					if (n == i)
						++iStrike;
					else
						++iBall;
				}
				/*
				switch (n) {
				case 0:
					if (iResult[n] == iInput[n])
					{
						iStrike += 1;
					}
					else if (iResult[n + 1] == iInput[n])
					{
						iBall += 1;
					}
					else if (iResult[n + 2] == iInput[n])
					{
						iBall += 1;
					}
					break;
				case 1:
					if (iResult[n] == iInput[n])
					{
						++iStrike;
					}
					else if (iResult[n - 1] == iInput[n])
					{
						++iBall;
					}
					else  if(iResult[n + 1] == iInput[n])
					{
						++iBall;
					}
					break;
				default:
					if (iResult[n] == iInput[n])
					{
						iStrike += 1;
					}
					else if (iResult[n - 1] == iInput[n])
					{
						iBall += 1;
					}
					else  if(iResult[n - 2] == iInput[n])
					{
						iBall += 1;
					}
					break;
					*/
			}

		}


		
		cout << "Your score is " << iStrike << " strike " << iBall << " ball !!" << endl;

		if (iStrike == 3)
		{
			for (int c = 0; c < iStrike; ++c)
			{
				cout << "iResult[" << c << "] = " << iResult[c] << endl;
			}
			cout << "Congratulation !!! " << endl;
			break;
		}
		cout << "더욱 분발해 주세요 화이팅 ~~ ^^ " << endl;
	}
	system("pause");
	return 0;
}