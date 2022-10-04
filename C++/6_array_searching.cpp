// 6_array_searching.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <iomanip>
using namespace std;

void showArrayElement(int var) {
    cout << var << endl;
}

void showArray(int array[], int l) {
    
    for (int i = 0; i < l; i++) {
        cout << i << array[i] << endl;
    }
}


int main()
{   
    //宣告一維陣列
    //一維陣列變數只使用一個坐標值來開啟多個記憶體位置
    int a[5] = {1, 3, 5, 7, 9};

    char b[3];
    b[0] = 'a';
    b[1] = 'b';
    b[2] = 'c';

    char ascii[10] = { '0','1','2','3','4','5','6','7','8','9' };
    cout << "字元\tASCII碼\n";
    cout << "----\t--------\n";
    for (int count = 0; count <= 9; count++) {
        cout << setw(3) << ascii[count] << '\t';
        cout << setw(5) << int(ascii[count]) << endl;
    }

    //宣告二維陣列
    int c[2][3] = { {1, 2, 3},{4, 5, 6} };

    //存取陣列元素
    cout << "c[1][1] = " << c[1][1] << endl;
    
    //複製陣列:複製單一陣列元素
    int isource[5] = { 1,2,3,4,5 };
    int itarget[5];
    itarget[2] = isource[0];

    //傳遞陣列
    //傳遞陣列元素: 相當於傳遞變數數值給呼叫函式
    showArrayElement(isource[0]);

    //傳遞陣列名稱: 相當於傳遞陣列指標給呼叫函式
    int l = sizeof(isource) / sizeof(isource[0]);//陣列長度
    showArray(isource, l);
    
    //定義字串陣列
    char str1[6] = { 'C','+','+' };
    char str2[4] = "C++";//包含第4個元素'\0'結束符號

    /*排序與搜尋: 參考圖解演算法
    * 氣泡排序
    * 選擇排序
    * 線性搜尋
    * 二分搜尋
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
