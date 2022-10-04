// 2_math_calculation.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
	char name[100];
	int age;
	const double PI = 3.151592653;
	char sentence[80];
	double a, b, c, d;
	unsigned seed;
	double x;
	double m1, m2, n1, n2;

	cout << "請輸入姓名:" << endl;
	cin >> name;
	cout << "請輸入年齡:" << endl;
	cin >> age;
	cout << "name:" << name << endl
		<< "age:"<< setw(3) << age << endl;//設定輸出字元長度，如果字元長度不足則向右對齊補空白

	

	cout << setprecision(10) << PI << endl;//設定字元輸出長度
	cout << setprecision(8) << PI << endl;
	cout << setprecision(6) << PI << endl;

	cout.width(3);//設定字元輸出長度=3
	cout.precision(5);//設定輸出有效位數=5
	cin.width(3);//設定字元輸入長度=3
	cin.precision(5);//設定輸入有效位數=5

	cout << "請輸入句子:" << endl;
	cin.getline(sentence, 50);//讀取鍵盤輸入資料，若字元數大於指定輸入長度時。大於的部分將刪除
	cout << "輸入句子:" << sentence << endl;

	//多重指定
	a = b = c = d = 10;
	//混合指定
	a += 1;//a = a + 1
	
	//產生固定亂數
	cout << "產生固定亂數:" << rand()<<rand()<<rand() << endl;
	
	//使用種子數產生亂數
	cout << "輸入種子數:" << endl;
	cin >> seed;
	srand(seed);
	cout << "產生種子亂數:" << rand() << rand() << rand() << endl;
	
	//使用時間產生隨機亂數
	srand(time(NULL));
	cout << "產生隨機亂數:" << rand() << rand() << rand() << endl;

	//三角函數
	x = 30 * (3.14159 / 180);
	a = sin(x);
	b = cos(x);
	c = tan(x);
	//指數對數
	a = log(2);
	b = log10(2);
	c = exp(2);
	//次方與開根號
	a = pow(2, 3);
	b = sqrt(100);
	//取整數
	m1 = ceil(3.14);
	n1 = floor(3.14);
	m2 = ceil(-3.14);
	n2 = floor(-3.14);
	//取絕對值
	a = fabs(-99.9);

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
