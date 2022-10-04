// 14_file_management.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	int student_id;
	char student_name[40];
};

int main()
{
	ofstream filePtr;	//建立檔案物件(代號)
	/*檔案物件.open("檔案名稱",ios::開啟模式)
	* 開啟模式:
	* app: 附加模式
	* ate: 開啟檔案，並將指標移到檔案結束位置
	* binary: 開啟二進位輸入輸出的資料檔
	* in: 輸入模式，並將讀取指標移到檔案最前面
	* out: 輸出模式
	* trunc: 刪除已存在檔案，再開啟資料檔
	*/
	filePtr.open("D:\\learning plan\\plan coding language\\plan C++\\14_file_management\\14_file_management\\VC1501.txt", ios::out);	//開啟輸出檔VC1501.txt
	if (!filePtr.is_open()) {	//若開啟檔案代號錯誤
		cout << "開啟檔案錯誤！\n";
		system("PAUSE");
		exit(1);	//非正常結束程式
	}
	else {		//否則
		filePtr << "Life is not easy, but in the long run \n";
		filePtr << "it's easier than going to elaborate ends \n";
		filePtr << "to deny it.\n";	//寫入字串到檔案
	}
	filePtr.close();	//關閉檔案物件(代號)

	/*寫入單一字元:
	* 物件名稱.put('字元')
	* 讀取單一字元:
	* 物件名稱.get('字元')
	* 檔案結束位置 eof
	* 輸入檔案物件.eof()
	* 移動讀取指標:
	* 輸入檔案物件.seekg(移動距離,ios::起始位置)
	* 移動寫入指標:
	* 輸出檔案物件.seekp(移動距離,ios::起始位置)
	* *ios::beg = 檔案起始位置向後移動
	* *ios::cur = 目前指標位置向後移動
	* *ios::end = 檔案結束位置向前移動
	* 取得讀取指標:
	* 輸入檔案物件.tellg()
	* 移動寫入指標:
	* 輸出檔案物件.tellp()
	*/
	Student stuData;
	ifstream filePtr1;

	filePtr1.open("D:\\learning plan\\plan coding language\\plan C++\\14_file_management\\14_file_management\\VC1505.dat", ios::binary | ios::in);	//開啟輸入檔
	if (!filePtr1) {
		cout << "開啟輸入檔錯誤！\n";
		exit(1);	//非正常結束程式
	}
	else {
		filePtr1.seekg(0, ios::end);	//移動指標到檔尾
		int endpos = filePtr1.tellg();	//取得檔案位元組數
		int n = endpos / sizeof(stuData);	//除以緩衝器大小
		cout << "d:\\VC++15\\VC1505.dat 共有 " << n << " 筆資料";	//顯示資料筆數
	}
	filePtr1.close();
	cout << endl;
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
