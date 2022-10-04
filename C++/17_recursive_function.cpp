// 17_recursive_function.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iomanip>


using namespace std;
//階層
long factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}
//最大公因數
int gcd(int a, int b, int n)
{
	if (a % n == 0 && b % n == 0)	//二數除以n皆等於0
		return n;
	else
		return gcd(a, b, n - 1);
}
//最小公倍數
int lcm(int a, int b, int n)
{
	if (n % b == 0)	//n除以b等於0
		return n;
	else
		return lcm(a, b, n + a);
}
//選擇排序巢狀遞迴函數
const int MAX = 5;	//MAX = 陣列最大範圍
int minimum, mindex;	//定義公用變數
void innerSort(int number[], int j);
void outerSort(int number[], int i)
{
	if (i < MAX) {
		mindex = i;	//mindex=最小值索引
		minimum = number[i];	//minimum=最小值
		innerSort(number, i + 1);	//呼叫innerSort
		number[mindex] = number[i];	//number[最小值索引]=較大值
		number[i] = minimum;	//number[i]=最小值
		outerSort(number, i + 1);	//遞回呼叫outerSort
	}
}

void innerSort(int number[], int j)
{
	if (j < MAX) {
		if (number[j] < minimum) {	//若number[j]<最小值
			minimum = number[j];	//minimum=新最小值
			mindex = j;	//mindex=新最小值索引
		}
		innerSort(number, j + 1);	//遞回呼叫innerSort
	}
}
//二分法搜尋
void search(int number[], int low, int high, int nav)
{
	int middle;	//宣告整數變數
	if (low <= high) {
		if ((low + high) % 2 > 0.5)	//計算搜尋位置
			middle = (low + high) / 2 + 1;
		else
			middle = (low + high) / 2;

		if (nav < number[middle])	//計算搜尋上限
			search(number, low, middle - 1, nav);	//遞回呼叫
		else if (nav > number[middle])	//計算搜尋下限
			search(number, middle + 1, high, nav);	//遞回呼叫
		else if (nav == number[middle])	//找到相符數值
			cout << "\n找到數值：" << nav << endl;
	}
	else {
		cout << "\n找不到數值：" << nav << endl;
	}
}

class Division
{
	int a, b, q;
public:
	Division(int a1, int b1)
	{
		a = a1;
		b = b1;
		q = 0;
	}
	int quotient()
	{
		if (a >= b) {	//a仍大於等於b
			a -= b;	//a = a - b
			q++;
			return quotient();	//遞回呼叫
		}
		else
			return q;	//傳回商數
	}
	int remainder()
	{
		if (a >= b) {	//a仍大於等於b
			a -= b;	//a = a - b
			return remainder();	//遞回呼叫
		}
		else
			return a;	//傳回餘數
	}
};

int main()
{
    //遞迴函數: 函數中包含一個呼叫自己的敘述
	//計算階層
	int count = 1;	//while 迴圈初值
	cout << "計數\t" << setw(8) << "階乘\n";	//輸出字串
	do {
		cout << setw(3) << count << '\t';	//輸出計數值
		cout << setw(7) << factorial(count) << endl;	//輸出階乘
	} while (++count <= 10);

	//計算最大公因數
	int a, b, n;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> a >> b;	//輸入a, b二數
	n = a;
	cout << "GCD = " << gcd(a, b, n) << endl;		//輸出GCD
	cout << "LCM = " << lcm(a, b, n) << endl;		//輸出LCM
	
	//選擇排序
	int i, navigate;	//宣告整數變數
	int number[MAX] = { 57, 19, 33, 92, 6 };	//宣告一維陣列

	cout << "排序前：";	//顯示排序前資料
	for (i = 0; i < MAX; i++)
		cout << number[i] << ' ';
	cout << "\n排序後：";	//顯示排序後資料
	outerSort(number, 0);
	for (i = 0; i < MAX; i++)
		cout << number[i] << ' ';
	cout << endl;
	//二分搜尋法
	cout << "\n請輸入要搜尋數值：";
	cin >> navigate;	//輸入搜尋值
	search(number, 0, MAX - 1, navigate);

	//類別中使用遞迴函數
	int c, d;	//宣告變數
	cout << "請輸入二個整數 (a b)：";	//輸出訊息
	cin >> c >> d;	//輸入a, b二數
	Division div(c, d);

	cout << c << " / " << d << " = " << div.quotient();		//輸出商
	cout << " R " << div.remainder() << endl;		//輸出餘數
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
