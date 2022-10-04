// 11_overloading_function.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;
//多載一般函數
int area(int l, int w)	//計算長方形面積函數
{
	return l * w;
}

int area(int l, int w, int h)	//計算長方體表面積函數
{
	return 2 * ((l * w) + (w * h) + (h * l));
}

class Cuboid	//宣告長方體類別
{
private:
	int length;	//Cuboid的資料成員1
	int width;	//Cuboid的資料成員2
	int height;	//Cuboid的資料成員3
public:
	//多載成員函數
	void setSide(int l, int w)	//設定長方形邊長
	{
		length = l;
		width = w;
		height = 0;
	}
	void setSide(int l, int w, int h)	//設定長方體邊長
	{
		length = l;
		width = w;
		height = h;
	}
	int area()	//計算面積或表面積函數
	{
		if (height == 0)
			return length * width;
		else
			return 2 * (length * width + width * height + height * length);
	}
};

class Timer
{
	int seconds;
public:
	Timer() {		//定義無參數建立者
		seconds = 0;
	}
	Timer(int s) {	//定義整數參數建立者
		seconds = s;
	}
	Timer(char* t) {	//定義指標參數建立者
		seconds = atoi(t);
	}
	int getTime() {	//定義取得seconds函數
		return seconds;
	}
};


class Fracpri	//宣告 Fracpri 類別
{
private:
	int whole;	//整數
	int numer;	//分子
	int denom;	//分母
public:
	int getgcd();	//宣告 getgcd 函數
	friend istream& operator >> (istream& in, Fracpri& obj);
	friend ostream& operator << (ostream& out, Fracpri& obj);
};

int Fracpri::getgcd()	//求 G.C.D 函數
{
	int n = numer < denom ? numer : denom;
	for (; n >= 1; n--)
		if (denom % n == 0 && numer % n == 0)	//二數除以n皆等於0
			break;	//中斷迴圈
	return n;
}

istream& operator >> (istream& in, Fracpri& obj)	//多載>>符號函數
{
	in >> obj.whole >> obj.numer >> obj.denom;
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	return in;
}

ostream& operator << (ostream& out, Fracpri& obj)	//多載<<符號函數
{
	int gcd = obj.getgcd();
	obj.numer = obj.numer / gcd;
	obj.denom = obj.denom / gcd;
	out << obj.whole << ' ' << obj.numer << '/' << obj.denom;
	return out;
}

int main()
{
    /*多載(overloading):重複定義多個相同名稱的函數
    * 1.接收不同數量的參數
    * 2.傳遞不同型態參數
    * 3.傳回不同型態的參數
	* 適用於一般函數, 類別成員函數, 建立者函數
    */
	//多載一般函數
	cout << "長方形面積 = " << area(6, 8);	//輸出長方形面積
	cout << "平方公分\n";
	cout << "長方體表面積 = " << area(6, 8, 10);	//輸出長方體表面積
	cout << "平方公分\n";
	
	//多載成員函數
	Cuboid rt, cb;	//建立Cuboid物件
	rt.setSide(6, 8);	//起始rt物件資料
	cb.setSide(6, 8, 10);	//起始cb物件資料

	cout << "長方形面積 = " << rt.area();	//輸出長方形面積
	cout << "平方公分\n";
	cout << "長方體表面積 = " << cb.area();	//輸出長方體表面積
	cout << "平方公分\n";
	

	//多載建立者函數
	char str[20] = "250";
	Timer t1;		//t1.seconds = 0
	Timer t2(10);	//t2.seconds = 10
	Timer t3(str);	//t3.seconds = 250
	cout << "t1 = " << t1.getTime() << endl;	//輸出t1物件的值
	cout << "t2 = " << t2.getTime() << endl;	//輸出t2物件的值
	cout << "t3 = " << t3.getTime() << endl;	//輸出t3物件的值

	/*運算符號函數:
	* 當非成員函數或非friend函數要存取private或protected的資料時，
	必須先呼叫public的set或get函數，此方法將降低城市效能。
	使用friend函數雖然非類別成員函數扔可直接存取private或protected的資料。
	*/
	Fracpri s1;
	cout << "請輸入帶分數 (整數-分子-分母): ";
	cin >> s1;
	cout << "化簡後的帶分數為：" << s1 << endl;
	
	/*運算符號多載 (operator overloading)
	* 多載運算元符號+,-,*,/,
	* 多載單運算元符號!,>,<
	* 多載前置運算符號:++a,--b
	* 多載後置運算符號:a++,b--
	*/

	/*轉換資料型態
	* 基本型態2基本型態: 使用c++內建函數
	* 基本型態2類別型態: 使用建立者函數
	* 類別型態2基本型態: 使用多載型態符號函數
	* 類別型態2類別型態: 使用建立者函數 + 多載型態符號函數
	*/

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
