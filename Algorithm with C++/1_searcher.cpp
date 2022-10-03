// 1_searcher.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int bin_search(int data[80], int val); // 宣告二元搜尋法副程式
int interpolation_search(int*, int); // 宣告內插搜尋法副程式

int bin_search(int data[80], int val)
{
	int low, mid, high;
	low = 0;
	high = 79;
	cout << "搜尋處理中......" << endl;
	while (low <= high && val != -1)
	{
		mid = (low + high) / 2;
		if (val < data[mid])
		{
			cout << val << " 介於位置 " << low + 1 << "[" << setw(3) << data[low] << "]及中間值 " << mid + 1 << "[" << setw(3) << data[mid] << "]，找左半邊" << endl;
			high = mid - 1;
		}
		else if (val > data[mid])
		{
			cout << val << " 介於中間值位置 " << mid + 1 << "[" << setw(3) << data[mid] << "]及" << high + 1 << "[" << setw(3) << data[high] << "]，找右半邊" << endl;
			low = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

int interpolation_search(int data[80], int val)
{
	int low, mid, high;
	low = 0;
	high = 49;
	cout << "搜尋處理中......" << endl;
	while (low <= high && val != -1)
	{
		mid = low + ((val - data[low]) * (high - low) / (data[high] - data[low])); //內插法公式
		if (val == data[mid])
			return mid;
		else if (val < data[mid])
		{
			cout << val << " 介於位置 " << low + 1 << "[" << setw(3) << data[low] << "]及中間值 "
				<< mid + 1 << "[" << setw(3) << data[mid] << "]，找左半邊" << endl;
			high = mid - 1;
		}
		else if (val > data[mid])
		{
			cout << val << " 介於中間值位置 " << mid + 1 << "[" << setw(3) << data[mid] << "]及"
				<< high + 1 << "[" << setw(3) << data[high] << "]，找右半邊" << endl;
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	// 二元搜尋法
	int num, val = 1, data[80] = { 0 }, way;
	for (int i = 0; i < 80; i++)
	{
		data[i] = val;
		val += (rand() % 5 + 1);
	}
	while (1)
	{
		num = 0;
		cout << "請輸入搜尋鍵值(1-150)，輸入-1結束：";
		cin >> val;
		if (val == -1)
			break;
		cout << "請輸入使用搜尋演算法，輸入-1結束：\t1: 二元搜尋法\t2:內插搜尋法:";
		cin >> way;
		
		if (way == 1) {
			num = bin_search(data, val);
		}
		else if (way == 2) {
			num = interpolation_search(data, val);
		}
		else { 
			break; 
		}

		if (num == -1)
			cout << "##### 沒有找到[" << setw(3) << val << "] #####" << endl;
		else
			cout << "在第 " << setw(2) << num + 1 << "個位置找到 [" << setw(3) << data[num] << "]" << endl;
	}
	cout << "資料內容：" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << setw(3) << i * 10 + j + 1 << "-" << setw(3) << data[i * 10 + j];
		cout << endl;
	}
	cout << endl;
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
