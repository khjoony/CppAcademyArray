// Bingo Game
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iMetrix, iWidth;
	int iTemp, iIdx1, iIdx2;
	int iBingo, iBingoFive = 0;
	cout << "빙고 게임 메트릭스 가로 크기를 입력하시오 : ";
	cin >> iWidth;
	iMetrix = iWidth * iWidth;
	iBingo = iWidth * 2 + 2;

	//int *iNumber = new int[iMetrix];
	vector<int> iVector(iMetrix);
	cout << "iVector size = " << iVector.size() << endl;
	for (int i = 0; i < iMetrix; ++i)
	{
		iVector[i] = i + 1;
	}


	for (int i = 0; i < iMetrix * 4; ++i)
	{
		iIdx1 = rand() % iMetrix;
		iIdx2 = rand() % iMetrix;

		iTemp = iVector[iIdx1];
		iVector[iIdx1] = iVector[iIdx2];
		iVector[iIdx2] = iTemp;
	}
	vector<int> iPlayer(iWidth);
	vector<int> iBingoLine(iBingo);
	while (true)
	{
		/*for (int i = 0; i < iBingo; ++i)
		{
			iBingoLine[i] = 0;
		}*/
		if (iBingoFive < 5)
		{
		system("cls");
			for (int i = 0; i < iWidth; ++i)
			{
				for (int j = 0; j < iWidth; ++j)
				{
					if (iVector[i * iWidth + j] == INT_MAX)
					{
						cout << "X\t";
					}
					else {
						cout << iVector[i * iWidth + j] << "\t";
					}
				}
				cout << endl;
				cout << endl;
			}
			cout << "iBingoLine = " << iBingoLine[0] << endl;
			cout << "iBingoFive = " << iBingoFive << endl;
			cout << "숫자를 입력하세요 Bingo~~ " << endl << endl;
			bool bAcc = false;
			for (int i = 0; i < iWidth; ++i)
			{

				while (true)
				{
					cout << i + 1 << "번째 숫자를 입력하시오 :";
					cin >> iPlayer[i];
					for (int j = 0; j <= i; ++j)
					{
						if (i != j && iPlayer[i] == iPlayer[j]) {
							cout << endl << "이미 입력한 숫자 입니다 " << endl << endl;
							bAcc = true;
						}
					}
					if (iPlayer[i] < 0 || iPlayer[i] > iMetrix) {
						cout << iMetrix - iMetrix << "~ " << iMetrix << "사이의 숫자를 입력하시오. " << endl << endl;
						continue;
					}
					else if (bAcc)
					{
						bAcc = false;
						continue;
					}

					break;
				}



				for (int i = 0; i < iMetrix; ++i)
				{
					for (int j = 0; j < iWidth; ++j)
					{
						if (iPlayer[j] == iVector[i])
						{
							iVector[i] = INT_MAX;
						}
					}
				}
				for (int i = 0; i < iWidth; ++i)
				{
					for (int j = 0; j < iWidth; ++j)
					{
						if (iVector[i * iWidth + j] == INT_MAX)
						{
							cout << "X\t";
						}
						else {
							cout << iVector[i * iWidth + j] << "\t";
						}
					}
					cout << endl;
					cout << endl;
				}

				//if (iBingoFive < 5)
				//{
				for (int i = 0; i < iBingo; ++i)
				{
					iBingoLine[i] = 0;
					iBingoFive = 0;
				}
				for (int i = 0; i < iWidth; ++i)
				{

					if (iVector[i] == iVector[i + iWidth] && iVector[i] == iVector[i + iWidth * 2] && iVector[i] == iVector[i + iWidth * 3] && iVector[i] == iVector[i + iWidth * 4])
					{
						++iBingoLine[i];
					}
					if (iVector[i*iWidth] == iVector[i*iWidth + 1] && iVector[i*iWidth] == iVector[i*iWidth + 2] && iVector[i*iWidth] == iVector[i*iWidth + 3] && iVector[i*iWidth] == iVector[i*iWidth + 4])
					{
						++iBingoLine[i + iWidth];
					}
					if (iVector[0] == iVector[6] && iVector[0] == iVector[12] && iVector[0] == iVector[18] && iVector[0] == iVector[24])
					{
						iBingoLine[10] = 1;
					}
					if (iVector[4] == iVector[8] && iVector[4] == iVector[12] && iVector[4] == iVector[16] && iVector[4] == iVector[20])
					{
						iBingoLine[11] = 1;
					}
				}
				for (int i = 0; i < iBingo; ++i)
				{
					cout << "iBingoLine = [" << i << "]" << iBingoLine[i] << endl;
					
					if (iBingoLine[i] == 1)
						++iBingoFive;
				}

			}
		}
		else
		{
			break;
		}
	}
	cout << "BINGO !!!!! Congratulation !!" << endl;
	system("pause");
	return 0;

}