// 12_inheritance.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

int area(int l, int w)	//計算長方形面積函數
{
	return l * w;
}

int area(int l, int w, int h)	//計算長方體表面積函數
{
	return 2 * ((l * w) + (w * h) + (h * l));
}

//======================
class TwoD		//定義TwoD類別
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
	}
	void showxy() {
		cout << "平面座標 : p(" << x << ", "
			<< y << ") " << endl;
	}
};

class ThreeD : public TwoD	//以public繼承TwoD
{
protected:
	int z;
public:
	void setz(int o) {
		z = o;
	}
	void showxyz() {
		cout << "空間座標 : s(" << x << ", " << y
			<< ", " << z << ") " << endl;
	}
};
//======================
class Cube : public ThreeD	//以public繼承ThreeD
{					//間接繼承TwoD類別
public:
	void showarea() {
		cout << "面積 = " << x * y << endl;	//間接存取x, y值
	}
	void showcube() {
		cout << "體積 = " << x * y * z	//間接存取x y,直接存取z
			<< endl;
	}
};

//======================

class PointXY	//宣告基礎類別1,PointXY
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
	}
};

class PointZ	//宣告基礎類別2,PointZ
{
protected:
	int z;
public:
	void setz(int o) {
		z = o;
	}
};

class Cube1 : public PointXY, public PointZ	//以public繼承PointXY
{					//以public繼承PointZ
public:
	void showxy() {
		cout << "平面座標 : p(" << x << ", " 	//存取x, y值
			<< y << ") " << endl;
	}
	void showxyz() {
		cout << "空間座標 : s(" << x << ", " << y	//存取x, y, z
			<< ", " << z << ") " << endl;
	}
	void showarea() {
		cout << "面積 = " << x * y << endl;	//存取x, y值
	}
	void showcube() {
		cout << "體積 = " << x * y * z << endl;	//存取x, y, z
	}
};
int main()
{
/*繼承型式: public, private, protected
* public繼承型式，只能存取基礎類型的public與protected成員，不能直接存取private成員
* 但可透過基礎類型的public與protected成員函數間接存取private成員。
* public成員可以被程式中所有函數存取
* private只能被基礎類別的函數成員或friend函數存取
* protected成員可被基礎類別與衍生類別的成員函數與friend函數所存取
*/
	//單一類別繼承
	cout << "長方形面積 = " << area(6, 8);	//輸出長方形面積
	cout << "平方公分\n";
	cout << "長方體表面積 = " << area(6, 8, 10);	//輸出長方體表面積
	cout << "平方公分\n";

	//間接繼承
	Cube p;		//建立Cube類別物件
	p.setxy(2, 5);	//直接呼叫基礎類別成員
	p.showxy();	//直接呼叫基礎類別成員
	p.showarea();	//直接呼叫衍生類別2成員
	cout << endl;
	p.setz(8);	//直接呼叫衍生類別1成員
	p.showxyz();	//直接呼叫衍生類別1成員
	p.showcube();	//直接呼叫衍生類別2成員
	return 0;

	//多重繼承
	Cube1 p1;		//建立衍生類別Cube物件
	p.setxy(2, 5);	//直接呼叫基礎類別1成員
	p.showxy();	//直接呼叫衍生類別成員
	p.showarea();	//直接呼叫衍生類別成員
	cout << endl;
	p.setz(8);	//直接呼叫基礎類別2成員
	p.showxyz();	//直接呼叫衍生類別成員
	p.showcube();	//直接呼叫衍生類別成員

	//傳遞參數到基礎類別

	/*繼承與包含
	* 繼承是建立在子類別繼承父類別成員，並可直接存取父類別的public與protected成員
	* 包含是建立在母類別中包含子類別的物件，利用母類別中的子類別物件去取存取其他類別的public成員
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
