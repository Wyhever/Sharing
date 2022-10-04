// 3_condition_selection.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
/*
1.循序式結構: 從第一個敘述執行到最後一個
2.選擇式結構: if, if-else, if-elif-else
3.重複式結構: while loop, do-while loop 
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    char letter;

    // if ... else if ... else ...: 多個不同判斷條件
    cout << "請輸入一個整數:" << endl;
    cin >> num;
    if (num > 0)
    {
        cout << num << "大於0" << endl;
    }
    else if (num < 0)
    {
        cout << num << "小於0" << endl;
    }
    else
    {
        cout << num << "等於0" << endl;
    }

    cout << "請按打字鍵:" << endl;
    cin >> letter;
    if (letter >= 'A' && letter <= 'Z')
    {
        cout << letter << "為大寫鍵" << endl;
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        cout << letter << "為小寫鍵" << endl;
    }
    else if (letter >= '0' && letter <= '9')
    {
        cout << letter << "為數字鍵" << endl;
    }
    else
    {
        cout << letter << "為符號鍵" << endl;
    }

    //switch case: 單個判斷條件
    switch (letter)
    {
        case 'Y':
            cout << "Yes" << endl;
            break;
        case 'y':
            cout << "Yes" << endl;
            break;
        case 'N':
            cout << "No" << endl;
            break;
        case 'n':
            cout << "No" << endl;
            break;
        default:
            cout << "unexpected" << endl;
    }
    //條件運算符號 ?:
    cout << "請輸入一個整數:" << endl;
    cin >> num;
    cout << num;
    cout << ((num > 0) ? "是正數\n" : "是負數\n");

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
