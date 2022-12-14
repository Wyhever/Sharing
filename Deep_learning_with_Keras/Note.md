# Deep learning using keras
參考書籍: Deep learning深度學習必讀: Keras大神帶你用Python實作
#### Deep learning, Python, Keras
#### https://github.com/fchollet/deep-learning-with-python-notebooks
## 第一章 何謂深度學習?
1. 演算法
   1. 更好的啟動函數 (activation function)
   2. 更好的權重初始化方式 (weight-initialization schemes)，從分層預訓練開始，可以快速完成訓練
   3. 更好的最佳化方式 (optimization schemes)
## 第二章 開始之前:了解神經網路的數學概念
1. 機器學習的工作程序
    1. 隨機梯度下降
      1. 取出一批次量的訓練樣本x和對應的目標y
      2. 以x為輸入資料，執行神經網路獲得預測值y_pred
      3. 計算這個批次量神經網路的損失值，所謂的損失值，就是y與y_pred間的差距
      4. 計算損失值對神經網路權重的梯度 (反向傳播)
      5. 將參數稍微向梯度的反方向移動，例如W -= step*gradient，從而降低一點批次的損失
2. 小結
    1. 學習就是經由調整模型參數，在給定的訓練資料樣本及其對應目標值，實現損失函數最小化
    2. 學習是透過隨機批次輸入的訓練資料及其目標值，計算該批次損失函數的梯度，然後將神經網路參數(權重)往梯度反方向上移動一點 (移動幅度由學習率定義) 
    3. [損失](loss)是在訓練期間要讓他最小化的量，可以用來衡量神經網路的成功與否
    4. [優化器](optimizer)會用損失函數的梯度來更新神經網路參數
## 第三章 開始使用神經網路
1. 神經網路的核心元件
   1. 訓練神經網路的元件
      1. layers: 用來組成一個神經網路模型
      2. 輸入資料和對應的目標: 用來訓練與檢測一個神經模型
      3. 損失函數: 用來取得學習的回饋訊號
      4. 優化器: 用來決定學習的進行方式
   2. Example
      1. Classifying movie reviews: A binary classification example[demo]
      2. Classifying newswires: A multiclass classification example[demo]
      3. Predicting house prices: A regression example[demo]
## 第四章 機器學習的基礎知識
1. 機器學習的四個分支
   1. 監督式學習: 所有的訓練資料都有對應的標籤，然後由機器來學習將資料集的每筆資料對應到相隨的標籤
   2. 非監督式學習: 主要在輸入資料沒有任何標籤的協助下，找出其中有意義的表示法
   3. 自監督式學習: 自監督式學習是一種沒有人工標註標籤的監督式學習，可以將其視為沒有任何人介入的監督式學習
   4. 增強式學習: 在增強式學習中，代理人接收環境的相關資訊，並學會選擇最大化獎勵的行動
2. 評估機器學習模型
   1. 將資料分成訓練集、驗證集和測試集
      1. 簡單拆分驗證: 將資料分成訓練集和測試集，由訓練集中再切出一部份資料作為驗證集，然後以訓練集進行訓練，以驗證集來調整模型，以測試集來測試模型
      2. K折驗證: 將資料拆分為相同大小的K個區塊，依序選出一個區塊i，以剩餘區塊訓練模型，再用區塊i驗證模型，最終取K次得分的平均值為模型分數
   2. 驗證的注意事項
      1. 資料代表性
      2. 時間的方向性
      3. 資料中的重複現象
3. 資料預處理、特徵工程和特徵學習
   1. 神經網路的資料預處理
      1. 向量化
      2. 數值正規化
      3. 處理缺失值
   2. 特徵工程
4. 過度配適 (overfitting) 和低度配適 (underfitting)
   1. 縮減神經網路的大小[demo]
      1. 防止過度配是最簡單的方法是縮減神經網路模型的size，即減少模型可用來學習的參數數量
   2. 加入權重常規化[demo]
      1. L1常規化: 在損失函數多加一項，叫做代價 (cost) 項，這個項和權重係數的絕對值成正比
      2. L2常規化: 在損失函數多加一項，叫做代價 (cost) 項，這個項和權重係數的平方的絕對值成正比
   3. 丟棄法[demo]
      1. 在訓練過程中隨機丟棄layer的一些輸出特徵
5. 機器學習的通用工作流程
   1. 定義問題並建立資料集
   2. 選擇一種評量成功的準則 (metrics)
      1. 平衡分類 (二元分類) 的問題: 準確度 (accuracy)
      2. 類別不均的問題: 精密度 (precision) 與召回率 (recall)
      3. 排名問題或多標籤分類: 平均精度
   3. 決定驗證程序
      1. 拆分驗證集
      2. K折交叉驗證
      3. 多次洗牌的K折驗證
   4. 準備資料
   5. 開發出優於基準的模型
      1. 為模型選擇正確的輸出層啟動函數和損失函數
   6. 擴大規模: 開發一個過度適配的模型
   7. 常規化模型並調整超參數
## 第五章 電腦視覺的深度學習
1. 捲積神經網路[demo]
   1. 捲積層操作
      1. 密集層: 由輸入的特徵空間中學習全域的pattern
      2. 捲積層: 由輸入的特徵空間中學習局部的pattern
      3. 捲積層特性: 學習到的pattern具平移不變性、學習到pattern的空間層次結構
      4. 捲積層透過在3D輸入特徵圖上滑動3x3或5x5的小窗格，在每個可能的位置停住，萃取窗格上3D區塊的特徵
      5. 邊界效應 (border)和填補 (padding)
      6. 捲積層的步長 (stride)
   2. 最大池化層 MaxPooling 的操作 
      1. 積極地對特徵圖進行縮小採樣 (採樣次數)
      2. 從輸入特徵圖中做採樣並輸出樣本的最大值；通常用2x2窗格和步長2來完成
      3. 縮小採樣主要為了減少處理特徵映射係數的數量，以及透過連續捲積層處理使掃描窗格"相對的"越來越大，並進行空間層次結構萃取
2. 以少量資料集從頭訓練一個捲積神經網路[demo]
   1. 減少overfitting並提升準確度
      1. 資料擴增法
      2. 預先訓練神經網路的特徵萃取法
      3. 微調預先訓練神經網路法
   2. 資料擴增法
      1. 從現有訓練樣本生成更多訓練資料
3. 使用預先訓練的捲積神經網路[demo]
   1. 如果這個原始資料集足夠大量且具通用性，那麼預先訓練神經網路學習的空間層次特徵就足以充當視覺世界的通用model
   2. 特徵萃取
      1. 以一個先前訓練好的神經網路作為convolutional base，透過convolution base捲積基底處理新資料，並以輸出結果訓練新的分類器 
      2. 凍結表示在訓練期間禁止更新權重，若不這樣做，則convolutional base捲積基底先前學習到的表示法，會在訓練期間被修改掉
   3. 微調
      1. 解凍一些捲積基底"頂部"的某些層以用來特徵萃取
4. 視覺化呈現捲積神經網路學習的內容
   1. 視覺化中間層convert的輸出 (中間啟動函數的輸出)
      1. 目的在給定輸入影像的情況下，顯示出convert各個捲積層與池化層輸出的特徵圖
      2. 隨著層越來越高，啟動函數的輸出變得越來越抽象，視覺上也越難被解釋
      3. 越高階的啟動函數輸出越不會帶出關於特定輸入的資訊，但具備更多關於目標的資訊 
   2. 視覺化捲積神經網路過濾器
      1. 目的在查看各filter要過濾的視覺圖案
      2. 方法: 建立一個損失函數，讓convert指定層中指定的濾波器的啟動函數輸出值最大化，然後使用隨機梯度下降來調整輸入影像的像素質，以便最大化此啟動函數輸出值
      3. 過濾器視覺化後，這些視覺畫圖呈現出捲積層如何檢視資訊的全貌
      4. 捲積神經網路中的每一層都學習了一組過濾器，使得輸入資訊可以表示為過濾器的組合
      5. 較高層中的過濾器則會越來越接近自然影像中的紋理:羽毛、眼睛、樹葉等
   4. 視覺化類別激活熱圖
      1. 目的在幫助理解影像中的那些部分會讓convert做出最終分類的決策
      2. 類別激活熱圖是一個2D的分數網格圖，針對輸入影像的每個位置進行計算，然後指示出每個位置相對於目前類別的重要性
      3. 方法: 給定輸入影像，取得捲積層的輸出特徵圖，然後以"這類別對每個channel的梯度值"對這個特徵圖中的每個channel作加權
## 第六章 文字和序列資料的深度學習
1. 文件資料的預處理 Preprocessing
   1. 文件向量化
      1. 將文件分解成小單元 (token) 的過程稱為分詞或斷詞，再經由一個字典對照表將 token 編碼成數值向量化
   2. 分詞方法:
      1. 將文件拆解成單字，對每個單字轉換成一個向量
      2. 將文件拆解成字元，對每個字元轉換成一個向量
      3. 取n個的文字或字元，組成n元語法，然後將每個n元語法轉換成向量
   3. Token轉換成向量的方法[demo]
      1. token 的 one-hot encoding
      2. token嵌入法
   4. 單字和字元的one-hot encoding[demo]
      1. 先建立一個字典，將收入到字典的單字當作鍵 (key)，然後給每一個鍵一個唯一的整數最為鍵值 (value)
      2. 二進位、稀疏且具有非常高的維度
   5. 文字嵌入法 Word Embeddings
      1. 低維度的浮點向量 
      2. 法1: 訓練模型時，使用embedding layer同時學習問字嵌入向量。相同於學習神經網路權重的方式；目標將人類語言投射到幾何空間，合理情況下，意思相近的詞應該嵌入到相近的文字向量[demo]
      3. 法2: 直接使用其他機器學習模型以計算 (訓練) 好的文字嵌入向量。這種方式稱為預先訓練文字嵌入法[demo]
2. 循環神經網路 RNN [demo]
   1. 原理
      1. 透過一個持續與過去資訊有關的狀態 (state) 來迭代處理序列資料；在一個for 迴圈中，重複使用前一次迭代計算所得到的數值
      2. SimpleRNN 是處理批次量的序列資料
   2. 了解LSTM和GRU層
      1. 長期短期記憶 (Long short-term Memory, LSTM) 增加一種跨多個時間點承載資料的方法
      2. 同時有一條傳送帶與正在處理的序列資料，序列資料中的資訊可以在任何時候跳到傳送帶上，傳送到稍後的時間點，並在需要時完好無損的取出
      3. LSTM單元的作用，就是允許之後重新注入過去的資訊，從而解決梯度消失問題
3. 循環神經網路的進階使用方法[demo]
   1. 三種方法:
      1. 循換丟棄: 使用丟棄法來解決循環層中過度適配的問題
      2. 堆疊循環層: 增加神經網路的轉換表示能力
      3. 雙向循環層: 以不同方式向循環神經網路提供相同的資訊，進而提高準確度並減少神經網路的遺忘問題
   2. 閘控循環單元 (gated recurrent unut, GRU)
      1. 與LSTM原理相同，但經過些許簡化，使執行成本較低，缺點是模型表示能力較差   
   3. 使用循環丟棄法來降低過度適配
      1. 在每個步驟 (時間點) 中都使用相同的丟棄遮罩 (相同的剔除單元)，而不是隨著時間點的增加隨機變化的丟棄遮罩
   4. 堆疊循環層
      1. 增加神經網路容量
   5. 雙向RNN
      1. 使用兩個一班RNN，每個層在不同方向上處理輸入序列資料 (按時間順序和反時間順序)，然後合併各自的結果
4. 使用卷積神經網路進行序列資料處理
   1. 類似於提取2D區塊並對每個區塊與卷積核進行點乘積再進行轉換。使用1D卷積，從序列資料中提取局部1D區塊 (子序列資料) 進行轉換
   2. 結合速度快的卷積神經網路與對順序敏感的RNN
      1. 使用1D卷積神經網路作為RNN前的預處理步驟，對於長時間序列資料導致RNN無法處理時特別有效
      2. 卷積神經網路會將長時間輸入序列資料轉換成較短的高階特徵序列資料
      3. 萃取後的特徵序列資料再作為RNN神經網路的輸入
## 第七章 進階深度學習的最佳實作方式
1. Keras 函數式API
   1. 函數式API   
      1. Keras在程式庫後端會取得從輸入張量到輸出張量所有參與的層，將他們組成一個圖形的資料結構，也就是一個Model物件
   2. 多輸入模型
      1. 在神經網路某些節點上會將多數入合併入一個層中，合併的方式可能包含相加或串接
   3. 多輸出模型
      1. 由於梯度下降要求純量最小化，因此必須將這些損失值結合成單一數值才能訓練模型，損失值的總和，稱為全域損失
      2. 若有非常不平衡的損失會導致模型優先針對最大損失的任務進行優化，而犧牲其他任務。為了解決這個問題，可以加入loss_weights參數，為損失值分配不同程度的重要性
   4. 層的有向無環圖
      1. INCEPTION模組: 由一堆 Inception 模組組成，這些模組本身看起來像小型獨立神經網路，內部具有幾個並行的分支
      2. Xception: 採用將channel特徵與空間特徵的學習分離成邏輯極值的想法
      3. 殘差連接: 主要將上游層的輸出作為下游層的輸入，進而有效地在序列神經網路中建立捷徑；解決梯度消失和轉換瓶頸
   5. 層的權重共享
      1. 函數式API的一項重要特性，是能夠重複使用層物件
      2. 允許建構出共享分支的模型，並讓數個分支都擁有相同的設定知識並執行相同操作
   6. 將模型作為層
      1. 將模型A放到另一個模型B之中來使用，將模型A視為一個"更大的層"
2. 使用Keras回呼 (callbacks) 和TensorBoard檢查和監控深度學習模型
   1. 在訓練期間使用回呼來對模型進行操作
      1. 模型檢查點: 在訓練期間保存模型在不同時間點的權重
      2. 早期停止: 當驗證損失不再改善時中斷訓練
      3. 在訓練期間動態調整某些參數的值，例如優化器的學習速率
      4. 在訓練期間記錄訓練和驗證指標，或在模型更新時視覺化模型已學習到的表示法 (權重)
   2. TensorBoard 簡介: Tensorflow視覺化框架
      1. 在訓練期間視覺化呈現監控指標
      2. 視覺化模型架構
      3. 視覺化啟動函數結果和梯度變化的直方圖
      4. 以3D方式探索嵌入向量
      5. TensorBoard可以選擇降維演算法，自動將嵌入空間縮小為2D或3D: 主成分分析或t分布隨機鄰居嵌入
3. 模型成效最大化
   1. 進階架構模式
      1. 批次正規化: 在訓練期間依所檢視到批次量資料的均值和變異數，持續保持內部的一個指數移動平均值；主要影響在於協助梯度傳遞，允許建構更深的神經網路
      2. 深度可分離捲積: 在通過逐點卷積(1x1卷積)前，深度可分離卷積層獨立地在其輸入的每個channel上執行空間捲積(3x3卷積)；參數更少，計算量更少
   2. 超參數優化
      1. 選擇一組超參數 (自動)
      2. 建構對應模型
      3. 以訓練資料進行訓練，並測量驗證資料的最終成效
      4. 選擇要嘗試的下一組超參數 (自動)
      5. 重複執行
      6. 最終，測量測試資料的成效
   3. 模型集成
      1. 將多個不同模型的預測結果整合起來，以產生更好的預測
      2. 不強調最好的模型有多好，而是取決於使用模型集合的多樣性 
## 第八章 生成式深度學習
1. 使用LSTM 產生文字資料[]
   1. 如何生成序列資料
      1. 使用LSTM 層，從文字語料庫 (text corpus) 中萃取N的字元的字串作為輸入，然後訓練模型以預測第N+1個字元
   2. 取樣策略的重要性
      1. 貪婪取樣: 主要在所有可能的字元中選擇最可能的下一個字元。但會導致出現重複的預測字串，使產生的文字資料看起來不像連貫的語言
      2. 隨機取樣: 從下一個字元的機率分布中取樣，並在取樣的過程中導入隨機性
      3. 較少商將使生成的緒料具有可預測的結構 (看起來更逼真)，更多的商將導致更令人驚訝和創造性的序列
   3. 訓練語言模型並從中取樣
      1. 給定到目前生成的文字，從模型中計算下一個字元的機率分布
      2. 將分布重新調整到一特定temperature
      3. 根據重新加權的分佈隨機取樣取得下一個字元
      4. 在現有文字的末尾加上新字元
2. DeepDream[demo]
   1. 原理:
      1. DeepDream 是一種藝術圖片修改技術。DeepDream演算法與卷積神經網路過濾器視覺化技術完全相同，主要運作一個反降卷積神經網路，也就是對卷積網路的輸入進行梯度上升，以便最大限度地啟動卷積神經網路上層過濾器
3. 神經風格轉換[demo]
   1. 目的:
      1. 主要是將參考圖片的風格應用於目標圖片，同時保留目標圖片的內容
      2. 風格本質上意味圖片在各種空間比例上的紋理、顏色和視覺形式
      3. 內容指的是圖片中的高階抽象結構
   2. 透過維持目標圖片和生成圖片在CNN高階層啟動函數值的相似，使得CNN看到目標影像與生成影像含有相同的內容   
   3. 透過低階層和高階層啟動含數值中保持相似的關聯性來保留風格
4. 使用變分自編碼器Variational Autoencoders生成圖像[demo]
   1. 圖像生成的關鍵想法是學習出一個"低維"潛在空間的表示法，其中任何點 (向量) 都可以對應成逼真的圖像
   2. 學習圖像潛在空間的策略
      1. VAE非常適合學習結構良好的潛在空間，其資料中的特定方向會編碼成有意義的變化軸
      2. GAN生成的圖像可以非常逼真，但它們來自的潛在空間可能沒那麼有結構性和連續性
   3. 變分自編碼器 (Variational Autoencoders, VAE)
      1. 主要是一種將輸入資料編碼到低維潛在空間，然後將其解碼回來的神經網路
      2. VAE 使用均值和變異數作為參數，隨機地對此分布取樣一個元素 (向量)，並將該元素解碼回原始輸入圖像
      3. 使用兩個損失函數進行訓練: 重建損失、常規化損失
5. 生成對抗神經網路簡介 Generative Adversarial Network[demo]
   1. 原理: 偽造神經網路和專家神經網路，每個神經網路都經過最好的訓練
      1. 生成神經網路: 將隨機向量作為輸入，並將其解碼，生成合成圖像 
      2. 鑑別氣神經網路 (對抗神經網路) : 將圖像作為輸入，並預測圖像是來自訓練集還是由生成器神經網路創造的
      3. 優化過程尋求不是最小，而是兩力之間的平衡
## 第九章 結語 
1. 通用的機器學習工作流程
   1. 定義問題
   2. 衡量目標成功與否的方法
   3. 評估模型的驗證過程
   4. 將資料轉換成向量並對其進行預先處理
   5. 開發第一個模型
   6. 調整超參數和加入常規化來逐步優化模型架構
   7. 注意驗證集的過度適配
2. 關鍵的神經網路架構
   1. 向量資料: 密集連接神經網路
   2. 影像資料: 2D 卷積神經網路
   3. 聲音資料: 1D 卷積神經網路 (首選) 或RNN
   4. 文字資料: 1D 卷積神經網路 (首選) 或RNN
   5. 時間序料資料: RNN (首選) 或1D 卷積神經網路 
   6. 其他類型的序列資料: RNN 或1D 卷積神經網路 
   7. 影音資料: 3D 卷積神經網路 
   8. 體積資料: 3D 卷積神經網路 
