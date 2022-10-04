// 5_function.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iomanip>
#include "degree.h"//引入標題檔
using namespace std;

//定義函數巨集
#define BEGIN {                 //定義起始符號
#define END }                   //定義結束符號
#define TAB '\t'                //定義定位符號
#define PI 3.1415926            //定義常數符號
#define MAX(x, y) ((x>y) ? x:y)  //定義大於函數巨集
#define MIN(x, y) ((x<y) ? x:y)  //定義小於函數巨集

//公用變數 (全域變數)
int m;
double c;

void swap(int &num1, int &num2) {
    //傳遞變數位址:直接改變變數值
    int buffer;
    buffer = num1;
    num1 = num2;
    num2 = buffer;
}

int total(int n) {
    //靜態變數: 所占用的記憶體位置會被保留到程式結束時或是再次被寫入
    static int sum;
    sum += n;
    return sum;
}

int summation(int n) {
    if (n > 1)
        return n + summation(n - 1);//呼叫函數自身
    else
        return 1;
}

int main()
{
    /*
    傳遞變數數值: 被呼叫函數只是接收該變數資料，而不能改變被傳遞變數的資料。

    傳遞變數位址: 被呼叫函數的參數是一個變數位址，被呼叫函數以宣告的參數名稱存取變數值，
                  若被呼叫函數將新值存入參數名稱，則該值將直接改變變數值。
    */

    //區域變數
    int var1 = 12, var2 = 34;
    int count, oddsum;
    /*暫存器變數: 只適用於區域變數，且不能超過2個，
                  若超過，編譯器會自動將超過的register變數轉換成auto區域變數。
                  撰寫系統程式或驅動程式時，作為迴圈的計數器，提高運算速度。
                  對於一般程式，對於使用者感覺不到差別。
    */
    register double a;

    cout << "對調前:" << endl;
    cout << "A =" << var1 << '\t';
    cout << "B =" << var2 << endl;
    swap(var1, var2);
    cout << "對調後:" << endl;
    cout << "A =" << var1 << '\t';
    cout << "B =" << var2 << endl;
    cout << endl;

    cout << "攝氏\t 華氏\n";
    cout << setprecision(2);
    cout << setiosflags(ios::fixed | ios::right);
    for (c = 36; c <= 40; c++) {
        cout << setw(5) << c << '\t';
        cout << setw(6) << degree() << '\n';
    }

    cout << endl;
    for (count = 1; count <= 100; count+=2) {
        oddsum = total(count);
    }
    cout << "1+3+5+... +99 = " << oddsum << endl;

    //遞迴函數
    cout << "1+2+3+...+10 = " << summation(10) << endl;
    cout << "1+2+3+...+100 = " << summation(100) << endl;
    cout << endl;

    //呼叫巨集函數
    cout << "var1 = " << var1 << "\tvar2 = " << var2 << endl;
    cout << "較大值:" << MAX(var1, var2) << '\t';
    cout << "較小值:" << MIN(var1, var2) << endl;

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
