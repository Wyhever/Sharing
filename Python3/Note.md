# **Python3**
Python3 learning
參考書籍:第一次學Python就上手(2017 陳惠貞)

### Chapter 1: 開始撰寫Python 程式
- 參考程式碼:略

### Chapter 2: 型別、變數與運算子
- 參考程式碼: 0_Type_Variable_Operator.py
- list: 有順序,可改變內容
- tuple: 有順序,不可改變內容
- set: 無順序,無重複,可改變內容
- dict: 無順序,無重複,可改變內容的多個鍵:質對
- Operator 
- 移位運算子
- 位元運算子

### Chapter 3: 數值與字串處理
- 參考程式碼: 1_num_str_process.py

### Chapter 4: 流程控制
- 參考程式碼:略
- if ... elif ... else
- for
- while
- continue, break

### Chapter 5: 函式
- 參考程式碼: 2_function.py
- Python 不支援函示重載(function overloading)
- Python 支援任意引數串列

### Chapter 6: list, tuple, set與dict
- 參考程式碼: 3_sequence_type_dict.py, 3_sequence_type_list.py, 3_sequence_type_tuple.py, 3_sequence_type_set.py
- list: 一串可改變、有順序的資料所組成
  - function: append, extend, insert, remove, pop
  - list comprehension
  - 2D list (nested list)
- tuple: 一串不可改變、有順序的資料所組成，用來存放不會變更的資料，tuple執行效率比list好
  - 不涉及改變元素的運算子皆適用於tuple
- set: 一串可改變、沒有順序、沒有重複的資料所組成，set執行效率比list好
  - 運算子: 集合, 聯集, 交集, 差集, 對稱差集(互斥)
- dict: 可改變、沒有順序、沒有重複的多個鍵:質對，屬於對映型別，已鍵作為索引存取字典裡的值
  -  get, add, edit, remove key: value pair

### Chapter 7:繪圖
- 參考程式碼:略

### Chapter 8: 檔案存取
- 參考程式碼: 4_file_access.py
- open(file, mode)
  - r: 讀取, 若檔案不存在則發生錯誤；預設值
  - w: 寫入，若檔案不存在則建立檔案
  - a: 附加，附加在檔案內容後面，若檔案不存在則建立檔案
  - r+: 讀取,以讀寫模式開啟檔案，檔案指標指向檔案開頭，寫入資料會覆蓋原本內容，若檔案不存在則發生錯誤；預設值
  - w+: 寫入，以讀寫模式開啟檔案並先清除檔案內容，若檔案不存在則建立檔案
  - w+: 附加，以讀寫模式開啟檔案，檔案指標指向檔案結尾，寫入資料會附加在檔案內容後面，若檔案不存在則建立檔案
- with funtion

### Chapter 9: 例外處理
- 參考程式碼: 5_try_except.py 
- 捕捉特定例外
- 自行丟出例外

### Chapter 10: 物件導向
- 參考程式碼: 6_object_oriented.py
- 物件導向(Object Oriented)
  - 1.物件(object)或實體(instance): 生活中的各種物體，如:電腦
  - 2.屬性(attribute)或成員變數(member variable): 描述物件的特性，如:電腦的CPU等級、製造商等等
  - 3.方法(method)或成員函式(member function): 定義物件的動作，如:電腦的開關機、執行應用程式
  - 4.類別(class):物件的分類，就像是物件的藍圖或樣板，如:汽車是一個類別，顏色、廠牌、型號是屬性，開門、關門、發動是方法，白色BMW520汽車就是隸屬於"汽車"類別的一個物件
- 物件導向程式設計(Object Oriented Programing)
  - 1.封裝(encapsulation):將資料與用來處理資料的函式放在一起成為類別，著重物件之間的操作，可設定內部資料或函式的存取等級，保護資料或函式，避免被外部的敘述誤改或竄改
  - 2.繼承(inheritance):從既有的類別定義出新的類別，既有的類別稱父類別，新的類別稱子類別，子類別繼承父類別的非私有成員，可以加入新的成員或覆蓋(override)繼承自父類別的方法，提高軟體的重複使用性
  - 3.多型(polymorphism):指不同的物件收到相同的訊息時，會根據各自的方法來做處理。
    - 飛行器是一個父類別，有起飛與降落兩種方法，直昇機與噴射機是飛行器的子類別，但直升機與噴射機的起飛降落方法不同，因此必須在各自的子類別覆蓋(override)這兩種方法，屆時物件收到起飛或降落的訊息時，便會根據類別的不同，呼叫對應的方法

### Chapter 11: 模組與套件
- 參考程式碼: 7_package_numpy.py
- Numpy 套件
  - 1D array
  - 2D array

### Chapter 12: 使用tkinter開發GUI程式
- 參考程式碼: 略

### Chapter 13: 使用pillow處理圖片
- 參考程式碼: 8_package_pillow.py

### Chapter 14: 使用matplotlib繪製圖表
- 參考程式碼: 9_package_matplotlib.py

