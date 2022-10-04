// 9_structure_data.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

struct Time //宣告型態資料結構
{
	//宣告成員變數
	int hour;
	int minute;
	int second;
};

struct Employee
{
	int id;
	char name[20];
};

struct Date
{
	int year;
	int month;
	int day;
};

struct Datep
{
	int *month;
	int *day;
};

//結構與陣列
struct Booklist 
{
	char title[25];
	char author[9];
	char number[9];
	int price;
	Date pubDate; //巣狀結構
};


void printTime(int h, int m, int s) {
	cout << (h == 0 || h == 12) ? 12 : h % 12;
	cout << ":" << ((m < 10) ? "0" : "") << m;
	cout << ":" << ((s < 10) ? "0" : "") << s;
	cout << ((h < 12) ? "AM" : "PM") << endl;
}

void printTime(Time t) {
	cout << t.hour << ":";
	cout << t.minute << ":";
	cout << t.second << endl;
}

Time getTime(void) {
	Time t;
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.second;
	return t;
}
void printTime1(const Time& t) {
	//使用傳址呼叫較節省資源，宣告常數型態防止函數更改原本的資料
	cout << t.hour << ":";
	cout << t.minute << ":";
	cout << t.second << endl;
}

int main()
{
	//建立結構變數
	Time midnight;
	//存取結構成員
	midnight.hour = 12;
	midnight.minute = 15;
	midnight.second = 30;
	cout << midnight.hour << ":";
	cout << midnight.minute << ":";
	cout << midnight.second << " AM" << endl;

	Employee emp1 = { 100,"John" };//建立並起始emp1初值
	
	//傳遞結構成員
	Time breakfast = {6,30,0};
	printTime(breakfast.hour, breakfast.minute, breakfast.second);

	//傳遞結構成員
	printTime(breakfast);

	printTime1(breakfast);

	//傳回結構資料
	Time lunch;
	cout << "請輸入午餐時間:" << endl;
	lunch = getTime();
	printTime(lunch);

	//結構與指標: 使用方法與一般資料型態的指標一樣
	//點號(.)執行順序高於星號(*)
	Date newyear;
	Date* pnewyear = &newyear;
	(*pnewyear).month = 1;
	(*pnewyear).day = 31;
	cout << (*pnewyear).month << "月";
	cout << (*pnewyear).day << "日\n";

	//指標運算符號->
	pnewyear->month = 2;
	pnewyear->day = 28;
	cout << pnewyear->month << "月";
	cout << pnewyear->day << "日\n";

	//間接運算符號*
	/*
	* *(結構指標.指標成員) // 存取結構的指標成員
	* (*結構指標).指標成員 // 存取結構指標的成員
	*/

	Datep newyear1;
	Datep *pnewyear1 = &newyear1;
	//*pnewyear1->month = 1;//會報錯
	//*pnewyear1->day = 1;
	//cout << *pnewyear1->month << "月";
	//cout << *pnewyear1->day << "日\n";

	

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
