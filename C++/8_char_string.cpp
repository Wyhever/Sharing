// 8_char_string.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    //字串長度 strlen
    char fixstr[80] = "string";
    int fixlen = strlen(fixstr);
    cout << "字串長度: " << fixlen << endl;

    //複製字串 strcpy: 來源字串必須小於目的字串的長度，否則會覆蓋到其他記憶體中的資料
    char source[80] = "string";
    char target[80];
   
    strcpy_s(target, source);
    cout << "target: " << target << endl;

    //比較字串 srecmp
    char password[80] = "100";
    char instring[80];
    cout << "請輸入密碼:\n";
    cin.getline(instring, 80, '\n');
    int flag = strcmp(password, instring);//0 代表相等, -1 代表不同
    cout << "比較字串結果" << flag << endl;
    
    //串接字串 strcat
    char first[80] = "hello";
    char last[80] = "world";
    char full[160] = "";
    strcat_s(full, first);
    strcat_s(full, " ");
    strcat_s(full, last);

    cout << "串接字串: " << full << endl;

    //大小寫轉換
    cout << "大寫a: " << char(toupper('a')) << endl;;
    cout << "小寫B: " << char(tolower('B')) << endl;;

    //字串與數值轉換
    /*
    atof: 字串轉浮點數
    atoi: 字串轉整數
    atol: 字串轉長整數
    itoa: 整數轉字串
    */

    //宣告字串
    char name[20] = "Mary";//字串陣列
    string s1;
    string s2("John");
    string s3 = "Peter";
    string s4('a', 4);

    //輸入字串
    string yourName;
    cout << "請輸入你的名字:";
    getline(cin, yourName);
    cout << "你的名字是:" << yourName << endl;
    
    //字串陣列
    string strArray[] = { "abc","def","ghi","jkl" };

    //指定資料assign
    string a1, a2("Hello");
    a1.assign(a2);
    cout << a1 << endl;
    a1.assign(a2, 0, 3);
    cout << a1 << endl;
    a1[2] = 'y';
    cout << a1 << endl;

    //串接字串append
    string a3("Good"), a4("morning");
    a3 += ' ';
    a3.append(a4);
    cout << a3 << endl;

    //比較字串compare
    string a5("aaabbb"), a6("bbbbbb");
    cout << a5.compare(0, 5, a6, 0, 5) << endl;
    cout << a5.compare(3, 5, a6, 0, 2) << endl;

    //對調字串swap
    a5.swap(a6);
    cout << "a5 = " << a5 << endl;
    cout << "a6 = " << a6 << endl;

    //找尋字串find
    int p;
    p = a5.find(a6);
    cout << p << endl;
    p = a5.find("bbb");
    cout << p << endl;

    //取代字串replace
    cout << "original string:" << a6 << endl;
    unsigned int p1 = a6.find('b');
    while (p1 < a6.length()) {
        a6.replace(p1, 1, "-");
        p1 = a6.find("b", ++p);//找下一個目標:b
    }
    cout << "b replaced as -:" << a6 << endl;

    //插入字串insert
    string a7("Good"), a8("aaaaa");
    a7.insert(2, a8);
    cout << a7 << endl;;

    //其他
    string a9 = "Hello world!";
    cout << a9.length() << endl;
    cout << a9.size() << endl;
    cout << a9.capacity() << endl;
    cout << a9.max_size() << endl;
    cout << a9.at(7) << endl;
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
