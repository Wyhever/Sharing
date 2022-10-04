// 10_class_object.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Employee 
{
private://類別私用成員
    int EmpId;
    char name[20];

public://類別公用成員

    Employee(int id, char *n);//宣告建立者函數
    //~Employee();//宣告破壞者函數
    /*破壞者函數: 
    用來釋放物件所占用的記憶體，
    類別中的破壞者函數不可多載、不含任何參數與回傳任何值
    */
    void inputEmp()//宣告成員函數
    {
        cout << "EmpId:";
        cin >> EmpId;
        cout << "EmpName:";
        cin >> name;
    }
    void outputEmp()
    {
        cout << "EmpID:" << EmpId << endl;
        cout << "EmpName:" << name << endl;
        //this指標: 指向資料成員位址,自動傳遞類別中非靜態的函數
        cout << "使用資料成員位址" << endl;
        cout << "EmpID:" << this->EmpId << endl;
        cout << "EmpName:" << (*this).name << endl;

    }

    void outputEmp() const
    {
        //this指標: 指向資料成員位址,自動傳遞類別終非靜態的函數
        cout << "使用資料成員位址" << endl;
        cout << "EmpID:" << this->EmpId << endl;
        cout << "EmpName:" << (*this).name << endl;

    }
    void inputEmp1();

    //建立者函數與類別名稱相同，用來指定資料成員的初值，必須定義為公用函數，不需要指定傳回型態
    //Employee()	//定義無參數建立者
    //{
    //    EmpId = 0;
    //    strcpy_s(name, "ZZZ");
    //}
    //Employee(int id, const char* n )	//定義有參數建立者
    //{
    //    EmpId = id;
    //    strcpy_s(name, n);
    //}
    Employee(int id = 0, const char* n = "ZZZ")	//定義有初始值參數建立者
    {
        EmpId = id;
        strcpy_s(name, n);
    }
};

//類別外實現類別的建立者函數
//Employee::Employee(int id = 0, char *n ="zzz")
//{
//    EmpID = id;
//    strcpy_s(name, n);
//}

void Employee::inputEmp1()//類別外實現成員函數，必須使用範圍運算符號(::)
{
    cout << "EmpID:";
    cin >> EmpId;
    cout << "EmpName:";
    cin >> name;
}

class First
{
    int x;
public:
    void setx(int var) {
        x = var;
    }
    /*friend 函數:
    * 不屬於該類別的成員函數
    * 可以宣告於類別的任何存取類型(public, private, protected)
    * friend 可以存取該類別的private成員
    */
    friend int getx(First obj) {	//定義 friend 函數
        return obj.x;
    }
};

class Second
{
    int y;
public:
    void sety(int var) {
        y = var;
    }
    void showxy(First obj) {
        cout << "x = " << getx(obj) << endl;	//呼叫 friend 函數
        cout << "y = " << y << endl;
    }
};

class Oddsum
{
    static int sum;	//宣告靜態資料成員
public:
    /*靜態變數
    * 其他成員皆可分享該靜態成員的資料
    * static成員或函數沒有this指標
    * 靜態成員將保留至下次資料更新或程式關閉
    * static成員函數不可以呼叫非static成員函數
    */
    static void addition(int n);	//宣告靜態成員函數
    void display();	//宣告輸出資料函數
};

int Oddsum::sum = 0;	//起始靜態資料成員

void Oddsum::addition(int n) {	//定義靜態成員函數
    sum += n;	//sum(n+1)=sum(n)+n
}

void Oddsum::display() {	//定義輸出資料成員函數
    cout << "sum = " << sum << endl;
}


class Calculate	//定義Calculate類別
{
    int x;
public:
    Calculate(int);	//建立者函數原型
    Calculate calcSum(Calculate obj);//加法運算後，回傳參數
    void sum(Calculate);	//加法運算函數原型
    
    void display();	//顯示x值函數原型
};

Calculate::Calculate(int n)	//定義建立者函數
{
    x = n;
}

void Calculate::sum(Calculate obj)	//定義加法運算函數
{
    x += obj.x;//傳遞物件參數  
}

Calculate Calculate::calcSum(Calculate obj) 
{
    x += obj.x;
    return *this;//傳回(*this).x
}

void Calculate::display()	//定義顯示 x 值函數
{
    cout << x;
}


int main()
{
    Employee emp1;	//建立無參數物件
    Employee emp2(123, "TOM");	//建立有參數物件
    Employee emp3;	//建立無參數物件

    emp1.outputEmp();	//顯示物件預設值
    emp2.outputEmp();	//顯示物件參數值
    cout << endl;
    emp3.inputEmp();	//顯示物件輸入值
    emp3.outputEmp();

    // 物件陣列
    Employee e[2];
    for (int i = 0; i < 2; i++)
    {
        e[i].inputEmp();
    }
    for (int i = 0; i < 2; i++)
    {
        e[i].outputEmp();
    }
    
    /*常數物件 const: 
    常數物件表示該物件中資料成員與資料函數皆固定，不可以被更改，
    但可以定義(多載)一個相同名稱與功能的常數行函數
    */

    const Employee emp4(456, "Peter");
    emp4.outputEmp();//使用的函數必須在其之後加上const

    First A;
    Second B;
    A.setx(10);
    B.sety(20);
    B.showxy(A);
    

    Oddsum a;
    for (int count = 1; count <= 100; count += 2)	//呼叫函數迴圈
        a.addition(count);	//呼叫addition函數
    a.display();	//呼叫display函數

    Calculate c(100), d(200), f(0);	//定義 a.x=100,b.x=200
    c.display();	//顯示 a.x=100 值
    cout << '+';	//顯示 + 號
    d.display();	//顯示 b.x=200 值
    cout << '=';	//顯示 = 號
    c.sum(d);	//計算 a.x = a.x + b.x
    c.display();	//顯示計算後 a.x=300 值
    cout << endl;	//跳行
    cout << "=====\n";
    f = c.calcSum(d);
    f.display();
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
