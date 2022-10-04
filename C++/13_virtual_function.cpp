﻿// 13_virtual_function.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

int main()
{
    /*多載(overlaoding):
    * 在同一類別中，重複定義多個名稱相同但參數個術或參數型態不同的函數
    * 超載(overriding):
    * 在衍生類別中，重新定義一個與基礎類別名稱相同但參數個術或參數型態可能相同或不同的函數
    * 同名異式(polymorphism):
    * 在基礎類別與衍生類別中多載相同名稱但不同功能的public成員函數，
    * 當類別體系的某函數呼叫此同名的多載函數時，將呼叫同一類別的多載函數
    * 基礎類別指標:
    * 如果將基礎類別物件或衍生類別物件的位址存入基礎物件的指標中，
    * 以此指標呼叫同名異式的函數時，此指標將指向基礎類別的同名函數
    * 虛擬物件指標:
    * 若將同名異式的函數宣告為virtual 函數時，C++將會給予此同名異式的函數不同指標，
    * 因此執行時將依據物件指標存取適當的函數
    * 虛擬類別繼承
    * 純虛擬函數:
    * 指宣告函數並且令虛擬函數等於0，但為定義虛擬函數的本體。
    
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