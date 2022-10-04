// 4_loop.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	//增量運算符號 ++
	//減量運算符號 --
	int num = 1;
	cout << "++num = " << ++num << endl;//前置，先執行++num = 2，再輸出num
	num = 1;
	cout << "num++ =" << num++ << endl;//後置，先輸出num，再執行++num = 2

	//前測試迴圈 while
	double count = 0;
	double power;
	cout << "計數\t" << "2的n次方\n";
	while (count++ <10)
	{
		power = pow(2, count);
		cout << setw(3) << count << '\t';
		cout << setw(6) << power << '\n';
	}

	//後測試迴圈 do-while
	count = 1;
	double factor = 1;
	cout << "計數\t" << setw(8) << "階乘\n";
	do
	{
		factor *= count;
		cout << setw(3) << count << '\t';
		cout << setw(8) << factor << '\n';

	} while (++count <= 10);

	//計數型迴圈 for
	for (int i = 0; i < 10; i++)
	{
		cout << 2 * i << endl;
	}

	//巢狀迴圈: 迴圈中包含另一個迴圈，while, do-while, for 皆可形成巢狀迴圈
	//無窮迴圈:
	/*
	while (true) { cout << "forever" << endl; }
	
	do { cout << "forever" << endl; } while (true);
	
	for (;;) { cout << "forever" << endl; }

	*/

	//中斷與繼續
	//break: 提前結束迴圈
	//continue: 跳過continue到迴圈結束的敘述，返回迴圈起點

	//找尋質數
	cout << "1到30之間的質數:";
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			if (i == 2 && j == 2) 
				cout << i << ' ';
			else if (i % j == 0)
				break;
			else if (j == i - 1)
				cout << i << ' ';
		}
	}
	cout << endl;

	//找尋最大公因數
	int a, b, n;
	cout << "請輸入兩個整數 (a,b):" << endl;
	cin >> a >> b;
	for (n = a; n >= 1; n--) {
		if (a % n == 0 && b % n == 0) {
			break;
		}
	}
	cout << "最大公因數:" << n << endl;

	//找尋最小公倍數
	cout << "請輸入兩個整數 (a,b):" << endl;
	cin >> a >> b;
	for (n = a; n <= a*b; n+=a) {
		if (n % b == 0) {
			break;
		}
	}
	cout << "最小公倍數:" << n << endl;

	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
