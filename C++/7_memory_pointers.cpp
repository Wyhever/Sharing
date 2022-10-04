// 7_memory_pointers.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;

void swap(int *num1, int *num2) {
    int buffer;
    buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}

void showArray(int* array) {
    for (int i = 0; i <= 2; i++) {
        cout << *(array + i) << endl;
    }
}

int *maximum(int *array) {
    static int value;
    static int* max = &value;
    *max = 0;
    for (int i = 0; i <= 4; i++) {
        //cout << max;
        if (*max < *(array + i)) {
            *max = *(array + i);
        }

    }
    cout << max << "\t" << *max << endl;
    return max;//傳回max指標
}

int main()
{
    int *numPtr, number; //宣告指標變數與整數變數
    int* num1Ptr, num2Ptr; //宣告同列變數為指標變數 (記憶體的位址)，指標變數存放記憶體位址

    /*位址運算符號 &
     *double 使用 8bytes記憶體空間
     *float 使用 4bytes記憶體空間
     *int 使用4 bytes記憶體空間
    */
    number = 10;
    cout << &number;//輸出number的位址

    numPtr = &number;//指定numPtr的對應位址, 資料型態 *指標名稱 = &變數位址;
    cout << endl;

    //間接運算符號 *
    int number3 = 10;
    int *num3Ptr = 0;
    cout << "number = " << number3 << endl;
    cout << "numPtr(未起始) = " << num3Ptr << endl;
    num3Ptr = &number3;//num3Ptr是number3的指標
    cout << "*number = " << *num3Ptr << endl;//輸出間接取得的資料，回傳位址的數值
    cout << "numPtr = &number" << num3Ptr << endl;//輸出number的指標，回傳位址

    //長度運算符號 sizeof: 取得店數或指標占用記憶體長度，以byte為單位
    // 計算陣列長度: sizeof array / sizeof array[0]
    cout << sizeof(bool)<<endl;
    cout << sizeof(int) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;

    char array[] = { '1','2','3' };
    int count = sizeof(array) / sizeof(array[0]);
    cout << count << endl;

    //陣列指標: 陣列名稱即是指標
    int array1[10];
    int *array1Ptr;
    array1Ptr = array1;

    short array2[] = {1,2,3,4,5,6,7};
    short* array2Ptr;
    const int SIZE = sizeof(array2) / sizeof(array2[0]);

    for (int i = 0; i < SIZE; i++) {
        array2Ptr = &array2[i];
        cout << "array2[" << i << "]:";
        cout << *array2Ptr << endl;
    }

    //指標運算
    cout << "array2[0]=" << *array2 << endl;
    cout << "array2[1]=" << *(array2+1) << endl;
    cout << "array2[2]=" << *(array2+2) << endl;
    cout << "array2[3]+5=" << *(array2 + 3)+5 << endl;

    //指標增減
    array2Ptr = array2;
    cout << "array2[0]=" << *array2Ptr << endl;//第0元素
    cout << "array2[1]=" << *(array2Ptr += 1) << endl;//第1元素
    cout << "array2[4]=" << *(array2Ptr += 3) << endl;//第4元素

    //指標與函數
    //傳遞變數指標與傳遞變數位址類似，都是傳遞變數的位址給呼叫函數，只是傳遞變數指標是先將變數位址存數變數指標再傳遞
    int var1 = 12, var2 = 34;
    cout << "對調前: ";
    cout << "A = " << var1 << "\t";
    cout << "B = " << var2 << "\n";
    swap(&var1, &var2);
    cout << "對調後: ";
    cout << "A = " << var1 << "\t";
    cout << "B = " << var2 << "\n";
    //傳遞陣列指標，因為陣列名稱就是陣列的指標，呼叫的參數直接使用陣列名稱
    int array3[] = {1,2,3};
    showArray(array3);

    //傳遞常數指標與傳遞字串指標與傳遞變數指標的函數呼叫是一樣的，只是變數是const參數型態與char參數型態

    //傳回函數指標: 就像傳回其他型態的資料一樣
    int number4[5] = { 10,560,31,46,36 };
    cout << "最大值: " << *maximum(number4) << endl;

    //配置動態記憶體
    int *newPtr;            //宣告指標變數
    newPtr = new int;       //配置動態記憶體
    *newPtr = 200;          //起始指標變數值
    cout << newPtr << endl;
    int* new2Ptr = new int(200); //單行敘述

    //釋放動態記憶體
    delete newPtr;
    cout << newPtr << endl;

    //配置動態陣列
    int* p = new int[10];
    for (int i = 0; i <= 9; i++) {
        p[i] = i;
    }
    cout << p << endl;

    //釋放動態陣列
    delete [] p;
    cout << p;

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
