# CPP-introduction
參考至C++全方位學習第四版
## Chapter 01 程式設計概論
### 註解方法:
1. //註解
2. /*註解*/

## Chapter 02 常數變數與資料
1. 宣告常數符號: #define，習慣使用大寫符號區分是由#define宣告的符號
2. 宣告常數: const 必須賦予初值且不能被改變，不配置記憶體
3. 宣告整數變數: int 在記憶體中配置4 byte的記憶體空間
4. 宣告浮點數變數: float, double
5. 宣告字串變數: char[]
6. 宣告邏輯資料: bool
7. 取得資料型態大小: sizeof

## Chapter 03 數學運算
略

## Chapter 04 條件選擇
1. 循序式結構: 從第一個敘述執行到最後一個
2. 選擇式結構: if, if-else, if-elif-else
    1. if ... else if ... else ...: 多個不同判斷條件
    2. switch case: 單個判斷條件
3. 重複式結構: while loop, do-while loop 
4. 條件運算符號 '?'

## Chapter 05 重複迴圈
1. 運算符號
    1. 增量運算符號 ++
    2. 減量運算符號 --
2. 前測試迴圈 while
3. 後測試迴圈 do-while
4. 計數型迴圈 for
5. 巢狀迴圈: 迴圈中包含另一個迴圈，while, do-while, for 皆可形成巢狀迴圈
6. 無窮迴圈:
    1. while (true) { cout << "forever" << endl; }
    2. do { cout << "forever" << endl; } while (true);
    3. for (;;) { cout << "forever" << endl; }
7. 中斷與繼續
    1. break: 提前結束迴圈
    2. continue: 跳過continue到迴圈結束的敘述，返回迴圈起點

## Chapter 06 使用者函數
1. 公用變數 (全域變數)
2. 外部變數 extern: 若有一個公用變數被宣告在函數之後，則使用該變數之前必須現宣告該變數為外部變數
3. 區域變數 auto
    1. 暫存器變數: 
    	1. 只適用於區域變數，且不能超過2個，若超過，編譯器會自動將超過的register變數轉換成auto區域變數。
    	2. 撰寫系統程式或驅動程式時，作為迴圈的計數器，提高運算速度。
    	3. 一般程式，對於使用者感覺不到差別。
4. 靜態變數 (static 變數類型 變數名稱): 區域變數所占用的記憶體會在函數返回 (return) 時被清除，但靜態變數所占用的記憶體位置會被保留到再次被寫入或是程式結束為止
5. Union是一種將不同data types儲存在同一個記憶體空間的特殊自訂型別，union一次只會儲存一個變數資料。
6. 傳遞變數數值: 被呼叫函數只是接收該變數資料，而不能改變被傳遞變數的資料。
7. 傳遞變數位址: 被呼叫函數的參數是一個變數位址，被呼叫函數以宣告的參數名稱存取變數值，若被呼叫函數將新值存入參數名稱，則該值將直接改變變數值。

## Chapter 07 陣列與搜尋
1. 一維陣列: 一維陣列變數只使用一個坐標值來開啟多個記憶體位置
2. 二維陣列
3. 複製陣列:複製單一陣列元素
4. 傳遞陣列
    1. 傳遞陣列元素: 相當於傳遞變數數值給呼叫函式
    2. 傳遞陣列名稱: 相當於傳遞陣列指標給呼叫函式
    3. 陣列長度 int l = sizeof(isource) / sizeof(isource[0]);
5. 定義字串陣列
    1. char str1[6] = { 'C','+','+' };
    2. char str2[4] = "C++";//包含第4個元素'\0'結束符號
6. 排序與搜尋: 參考圖解演算法
    1. 氣泡排序
    2. 選擇排序
    3. 線性搜尋
    4. 二分搜尋
## Chapter 08 記憶體指標
1. 宣告變數為指標變數 (記憶體的位址)，指標變數存放記憶體位址，int *numPtr
    1. 指標(pointer)是一種用來指示資料存在於記憶體中的位址標示器，其宣告方式為	資料型別 *變數名稱 ;
    2. 資料型別通常是基本的資料型別，如int, float, char等，變數名稱與一般變數的命名法則相同，差異處在於名稱前加上一個星號*。只要在變數宣告時，變數名稱加上一個前飾符號*，該變數就是指標變數，例如: int *p ;
    3. 以上的宣告具有三個意義：
        1. p是一個指標變數；
        2. 一旦宣告p是指標變數，則p代表一個記憶體位址,而*p代表此位址的資料內容；
        3. p所指向記憶體位址內的資料的變數型態為整數 (int)。
3. 位址運算符號 '&'
    1. *double 使用 8bytes記憶體空間
    2. *float 使用 4bytes記憶體空間
    3. *int 使用4 bytes記憶體空間
  
4. 輸出number的位址: &number;
5. 指定numPtr的對應位址, 資料型態 *指標名稱 = &變數位址;
    numPtr = &number;
5. 間接運算符號 '*'
    1. 輸出間接取得的資料，回傳位址的數值 *num3Ptr
6. 長度運算符號 sizeof: 取得店數或指標占用記憶體長度，以byte為單位
    1. 計算陣列長度: sizeof array / sizeof array[0]
7. 陣列指標: 陣列名稱即是指標
    1. 資料型態 *指標名稱;
       指標名稱 = 陣列名稱;
	int array[10];
	int *arrayPtr = array;
	arrayPtr
8.  指標運算
    1. *(陣列名稱+n) 相當於 "陣列名稱[n]"
    2. 指標增減
9. 指標與函數: 傳遞變數指標與傳遞變數位址類似，都是傳遞變數的位址給呼叫函數，只是傳遞變數指標是先將變數位址存數變數指標再傳遞
    1. 傳遞陣列指標，因為陣列名稱就是陣列的指標，呼叫的參數直接使用陣列名稱
    2. 傳遞常數指標與傳遞字串指標與傳遞變數指標的函數呼叫是一樣的，只是變數是const參數型態與char參數型態
    3. 傳回函數指標: 就像傳回其他型態的資料一樣
10. 配置動態記憶體 new int
11. 釋放動態記憶體 delete p
12. 配置動態陣列 new int[10]
13. 釋放動態陣列 delete [] p;

## Chapter 09 字元與字串
1. 字串長度 strlen
2. 複製字串 strcpy: 來源字串必須小於目的字串的長度，否則會覆蓋到其他記憶體中的資料
3. 比較字串 srecmp
4. 串接字串 strcat
5. 大小寫轉換
    1. toupper('a')
    2. tolower('B')
6. 字串與數值轉換
    1. atof: 字串轉浮點數
    2. atoi: 字串轉整數
    3. atol: 字串轉長整數
    4. itoa: 整數轉字串
7. 宣告字串 
    1. char name[20] = "Mary";//字串陣列
    2. string s1;
    3. string s2("John");
8. 輸入字串 getline(cin, yourName);
9. 字串陣列 string strArray[] = { "abc","def","ghi","jkl" };
10. 指定資料assign
11. 串接字串append
12. 比較字串compare
13. 對調字串swap
14. 找尋字串find
15. 取代字串replace
16. 插入字串insert
17. 其他
    1. length()
    2. size()
    3. capacity()
    4. max_size()
    5. at()
    
## Chapter 10 結構化資料
1. 建立結構變數
2. 存取結構成員
3. 傳遞結構成員
    1.	結構與指標: 使用方法與一般資料型態的指標一樣
    2.	點號(.)執行順序高於星號(*)
    3.	使用傳址呼叫較節省資源，宣告常數型態防止函數更改原本的資料
4. 傳回結構資料
5. 指標運算符號->: 避免使用間接運算符號存取指標成員時造成混淆
6. 間接運算符號*
    1. *(結構指標.指標成員) // 存取結構的指標成員
    2. (*結構指標).指標成員 // 存取結構指標的成員

## Chapter 11 類別化物件
1. 類別物件
    1. private://類別私用成員
    2. public://類別公用成員
    3. 建立者函數: 建立者函數與類別名稱相同，用來指定資料成員的初值，必須定義為公用函數，不需要指定傳回型態
    4. 破壞者函數: 用來釋放物件所占用的記憶體，類別中的破壞者函數不可多載、不含任何參數與回傳任何值
    5. 成員函數
    6. this指標: 指向資料成員位址,自動傳遞類別中非靜態的函數
    7. friend 函數: 不屬於該類別的成員函數，可以宣告於類別的任何存取類型(public, private, protected)區域中，friend 可以存取該類別的private成員
    8. 靜態變數: 
        1. 其他成員皆可分享該靜態成員的資料
        2. static成員或函數沒有this指標
        3. 靜態成員將保留至下次資料更新或程式關閉
        4. static成員函數不可以呼叫非static成員函數
2. 物件陣列
3. 常數物件 const: 常數物件表示該物件中資料成員與資料函數皆固定，不可以被更改，但可以定義(多載)一個相同名稱與功能的常數行函數

## Chapter 12 多載函數
1. 多載(overloading):重複定義多個相同名稱的函數
    1. 接收不同數量的參數
    2. 傳遞不同型態參數
    3. 傳回不同型態的參數
    4. 適用於一般函數, 類別成員函數, 建立者函數
2. 運算符號函數: 當非成員函數或非friend函數要存取private或protected的資料時，必須先呼叫public的set或get函數，此方法將降低程式效能。使用friend函數雖然非類別成員函數扔可直接存取private或protected的資料。
3. 運算符號多載 (operator overloading)
    1. 多載運算元符號+,-,*,/,
    2. 多載單運算元符號!,>,<
    3. 多載前置運算符號:++a,--b
    4. 多載後置運算符號:a++,b--
4. 轉換資料型態
    1. 基本型態to基本型態: 使用c++內建函數
    2. 基本型態to類別型態: 使用建立者函數
    3. 類別型態to基本型態: 使用多載型態符號函數
    4. 類別型態to類別型態: 使用建立者函數 + 多載型態符號函數

## Chapter 13 繼承類別
1. 繼承型式: public, private, protected
    1. public繼承型式，只能存取基礎類型的public與protected成員，不能直接存取private成員，但可透過基礎類型的public與protected成員函數間接存取private成員。public成員可以被程式中所有函數存取
    2. private只能被基礎類別的函數成員或friend函數存取
    3. protected成員可被基礎類別與衍生類別的成員函數與friend函數所存取
2. 單一類別繼承
3. 間接繼承
4. 多重繼承
5. 傳遞參數到基礎類別
6. 繼承與包含
    1. 繼承: 建立在子類別繼承父類別成員，並可直接存取父類別的public與protected成員
    2. 包含: 建立在母類別中包含子類別的物件，利用母類別中的子類別物件去取存取其他類別的public成員
    
## Chapter 14 虛擬函數
1. 多載(overlaoding): 在同一類別中，重複定義多個名稱相同但參數個術或參數型態不同的函數
2. 超載(overriding): 在衍生類別中，重新定義一個與基礎類別名稱相同但參數個術或參數型態可能相同或不同的函數
3. 同名異式(polymorphism): 在基礎類別與衍生類別中多載相同名稱但不同功能的public成員函數，當類別體系的某函數呼叫此同名的多載函數時，將呼叫同一類別的多載函數
4. 基礎類別指標: 如果將基礎類別物件或衍生類別物件的位址存入基礎物件的指標中，以此指標呼叫同名異式的函數時，此指標將指向基礎類別的同名函數
5. 虛擬物件指標: 若將同名異式的函數宣告為virtual 函數時，C++將會給予此同名異式的函數不同指標，因此執行時將依據物件指標存取適當的函數
6. 虛擬類別繼承
7. 純虛擬函數: 指宣告函數並且令虛擬函數等於0，但為定義虛擬函數的本體。

## Chapter 15 檔案管理
1. 開啟檔案物件: 檔案物件.open("檔案名稱",ios::開啟模式)
    1. 開啟模式:
        1. app: 附加模式
        2. ate: 開啟檔案，並將指標移到檔案結束位置
        3. binary: 開啟二進位輸入輸出的資料檔
        4. in: 輸入模式，並將讀取指標移到檔案最前面
        5. out: 輸出模式
        6. trunc: 刪除已存在檔案，再開啟資料檔
2. 關閉檔案物件(代號): 檔案物件.close()
3. 寫入單一字元: 物件名稱.put('字元')
4. 讀取單一字元: 物件名稱.get('字元')
5. 檔案結束位置 eof: 輸入檔案物件.eof()
6. 移動讀取指標: 輸入檔案物件.seekg(移動距離,ios::起始位置)
7. 移動寫入指標: 輸出檔案物件.seekp(移動距離,ios::起始位置)
    1. ios::beg = 檔案起始位置向後移動
    2. *ios::cur = 目前指標位置向後移動
    3. ios::end = 檔案結束位置向前移動
8. 取得讀取指標: 輸入檔案物件.tellg()
9. 移動寫入指標:
10. 輸出檔案物件.tellp()

## Chapter 16 例外與範本
1. 例外
    1. try區塊用來管理例外
    2. throw敘述用來投擲例外
    3. catch敘述用來捕捉例外
2. 一般例外使用方式
3. 函數錯誤處理: 在函數外設計try-catch
4. 函數錯誤處理: 在函數內設計try-catch
5. 類別錯誤處理: try-catch的參數可以是內建型態參數或自訂型態參數
    1. 類別中建立對應例外型態參數類別
6. 函數範本(template) : 代表一總體性函數，它可適用於任何資料型態，為簡化多載(overload)而設計，但範本本身也可以多載。
    1. 標準參數: 在函數範本中，部分參數使用固定的資料型態

## Chapter 17 資料結構
1. 串列資料結構(linked list):動態線性資料結構，可以機動性配合資料的新增或減少，增加或減少記憶體空間，同時結構類似於一維陣列的排列方式
    1. 堆疊 (stack): 後進先出的資料結構
    2. 佇列 (queue): 先進先出的資料結構
2. 二元樹 (binary tree) 是非線性的連結結構，每個節點可以連結到左右兩個節點。
    1. 顯示二元樹
        1. inorder: 先處理左副分支，再處理節點，最後處理右副分支
        2. preorder: 先處理節點，再處理左副分支，最後處理右副分支
        3. postoredr: 先處理左副分支，再處理右副分支，最後處理節點
	
## Chapter 18 遞迴函數
1. 遞迴函數: 函數中包含一個呼叫自己的敘述
    1. 計算階層
    2. 計算最大公因數
    3. 選擇排序 (選擇排序巢狀遞迴函數)
    4. 二分搜尋法
2. 類別中使用遞迴函數
