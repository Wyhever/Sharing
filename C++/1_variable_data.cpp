// CPP_learning.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159 //宣告常數符號，習慣使用大寫符號區分是由#define宣告的符號

//宣告常數: 必須賦予初值且不能被改變，不配置記憶體
const float fPI = 3.14159f; //宣告浮點常數符號fPI
const double dPI = 3.141592653; //宣告倍精度常數符號dPI

int main(int argc, char** argv)
{
    //宣告整數變數
    int num1 = -12345;    //在記憶體中配置4 byte的記憶體空間
    unsigned short num2 = 65432;
    long int num3 = 1234567890;
    //宣告浮點數變數
    short radius;
    radius = 5;
    short radius1 = 10;
    float area, circu;
    float circumference, radius2 = 10;
    double pi3 = 3.141592653;
    double dType;

    //宣告字串變數
    char letter = 'C';             // 字元配置1位元組:| C |
    char letter1[2] = "C";          //字串配置2位元組:| C | \0 |
    char str1[3] = {'C','+','+'};  //3位元組
    char str2[4] = "C++";          // 配置4位元組
    char str3[] = "C++學習";       //根據字串長度配置空間

    //宣告邏輯資料bool
    bool fontBold;
    bool fontItalic = true;


    // 使用宣告常數
    // circle1
    area = fPI * float(pow(radius, 2));
    circu = 2 * fPI * radius;
    cout << "circle1 area = " << area
        << "circle1 peremeter = " << circu << endl;

    // circle2
    area = fPI * float(pow(radius1, 2));
    circu = 2 * fPI * radius1;
    cout << "circle2 area = " << area
        << "circle2 peremeter = " << circu << endl;

    //使用宣告常數符號
    circumference = 2 * PI * radius2;

    //整數宣告
    cout << "有號整數" << num1 << endl
        << "無號短整數" << num2 << endl
        << "常整數" << num3 << endl;

    //取得資料型態大小sizeof
    cout << "long int = " << sizeof(long int) << "bytes\n"
        << "int = " << sizeof(int) << "bytes\n"
        << "short = " << sizeof(short) << "bytes\n"
        << "bool = " << sizeof(bool) << "bytes\n"
        << "dType = " << sizeof(dType) << "bytes\n";

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