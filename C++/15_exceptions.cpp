// 15_exceptions.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#define MAX 80

using namespace std;

void check(char i)	//含有throw的函數
{
	if (i < '0' || i>'9') throw i;	//若輸入超出0-9則throw
	cout << "輸入值 = " << i << endl;	//顯示輸入值
}

bool check1(char i)	//含有throw的函數
{
	try {			//try
		if (i < '0' || i>'9') throw i;	//若輸入超出0-9則throw
		cout << "輸入值 = " << i << endl;	//顯示輸入值
		return true;
	}
	catch (char i) {	//chtch
		cout << "輸入值 = " << i << "，超出範圍！\n";	//顯示訊息
		return false;
	}
}



class Stack	//自定Stack資料類別
{
	int st[MAX];
	int top;
public:
	class Full	//Full錯誤處理類別
	{
	};
	class Empty	//Empty錯誤處理類別
	{
	};
	Stack()		//建立者函數
	{
		top = -1;	//堆疊指標起始值
	}
	void push(int i)	//資料推入堆疊函數
	{
		if (top >= MAX - 1)	//若top大於等於堆疊上限
			throw Full();	//投擲例外並傳遞Full()
		st[++top] = i;	//堆疊指標加1
	}
	int pop()	//取出堆疊資料函數
	{
		if (top < 0)	//若top小於堆疊下限
			throw Empty();	//投擲例外並傳遞Empty()
		return st[top--];	//堆疊指標減1
	}
};
template <class X>
void Swap(X& a, X& b) {
	X temp;
	temp = a;
	a = b;
	b = temp;
}

template <class Type>
class Test {
	Type a;//Type 變數a
public:
	Test(Type m) { a = m; }
	void show() { cout << a << endl; }
};

int main()
{
    /*try區塊用來管理例外
    * throw敘述用來投擲例外
    * catch敘述用來捕捉例外
    */
	//一般例外使用方式
	char ps[9] = "year2022";
	char str[9];
	cout << "請輸入密碼：";
	cin >> str;
	try {
		for (int i = 0; i < 9; i++)
			if (str[i] != ps[i])	//若密碼錯誤
				throw i;	//則投擲例外
		cout << "密碼正確！\n";	//顯示正確訊息
	}
	catch (int i) {	//捕捉例外
		cout << "密碼錯誤！\n";	//顯示錯誤訊息
	}

	//函數錯誤處理: 在函數外設計try-catch
	char n;
	while (1)
	{
		cout << "請輸入0 - 9 的整數：";
		cin >> n;
		try {			//try
			check(n);	//呼叫check函數
		}
		catch (char i) {	//chtch
			cout << "輸入值 = " << i << "，超出範圍！\n";	//顯示訊息
			return 1;	//非正常結束程式
		}
	}

	//函數錯誤處理: 在函數內設計try-catch
	char n1;
	do
	{
		cout << "請輸入0 - 9 的整數：";
		cin >> n1;
	} while (check1(n1));	//呼叫check函數
	
	//類別錯誤處理: try-catch的參數可以是內建型態參數或自訂型態參數
	Stack s;
	try {
		s.push(10);	//top=0; st[0]=10;
		s.push(40);	//top=1; st[1]=40;
		cout << s.pop() << endl;	//傳回st[1]=40; top=0
		cout << s.pop() << endl;	//傳回st[0]=10; top=-1
		cout << s.pop() << endl;	//top<0; throw Empty()
	}
	//類別中建立對應例外型態參數類別
	catch (Stack::Full) {
		cout << "堆疊滿了！\n";
	}
	catch (Stack::Empty) {
		cout << "堆疊空了！\n";
	}
	
	/*函數範本(template) : 代表一總體性函數，它可適用於任何資料型態，
	* 為簡化多載(overload)而設計，但範本本身也可以多載。
	* 使用標準參數是在函數範本中，部分參數使用固定的資料型態
	*/
	int x = 4, y = 10;
	float x1 = 0.4, y1 = 0.8;
	Swap(x, y);
	Swap(x1, y1);

	//類別範本
	Test<double> obj1(1.2);
	Test<char> obj2('B');
	
	obj1.show();
	obj2.show();


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
