// Bingo Mode   1 : Easy,  2 : Hard
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};		// create an array of 25 sizes.
	int iTemp, idx1, idx2;		// variables for shuffle iNumber.
	int iInput;					// Variable for enter thr number to change to star.
	int iBingo = 0;					// Star number of bingoline
	bool bAcc;					// Variable for checking duplicate inputs.

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
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i*5 +j]<< "\t";
			}
			cout << endl;
			cout << endl;
		}
		cout << "Bingo Line : " << iBingo << endl;
		cout << "Input number, please ( 0: END) :";
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;
		bAcc = true;
		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i])
			{
				bAcc = false;
				iNumber[i] = INT_MAX;
				break;
			}
		}
		
		if (bAcc)
		{
			continue;
		}

		iBingo = 0;
		// Star number of bingoline width, height, cross.
		int iStar_width = 0, iStar_height = 0;
		for (int i = 0; i < 5; ++i)
		{
			iStar_width = iStar_height = 0;
			for (int j = 0; j < 5; ++j)
			{
				// width
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar_width;

				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar_height;
			}
			if (iStar_width == 5)
				++iBingo;
			if (iStar_height == 5)
				++iBingo;
		}

		//break;
	}
	system("pause");
	return 0;
}