// 0_sorter.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <iomanip>
#include <vector>

#define SIZE 6  //定義陣列大小
#define NUM1 5
#define NUM2 5

using namespace std;

void showdata(int*, int); //宣告列印陣列副程式
void inputarr(int*, int);//宣告輸入陣列副程式

void bubble(int*);   //宣告氣泡排序副程式
void select(int*); //宣告選擇排序法副程序
void inser(int*);//宣告插入排序法副程式
void shell(int*, int);  //宣告謝耳排序法副程式
void quick(int*, int, int, int); //宣告快速排序法副程式
void mergeSort(int[], int, int[], int, int[]); ////宣告合併排序法副程式
void radix(int*, int);	// 基數排序法副程式 

void heap(int*, int); // 堆積排序法副程式
void ad_heap(int*, int, int);
int process = 0;


void showdata(int data[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << data[i]<<"\t";
	cout << endl;
}
void inputarr(int data[], int size)
{
	for (int i = 0; i < size; i++)//利用迴圈輸入陣列資料
	{
		cout << "請輸入第 " << i + 1 << " 個元素：";
		cin >> data[i];
	}
}

void bubble(int data[], int size)
{
	for (int i = size; i >= 0; i--)
	{
		int flag = 0;  //flag用來判斷是否有執行交換的動作
		for (int j = 0; j < i; j++)
		{
			if (data[j + 1] < data[j])
			{
				int tmp;
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
				flag++;    //如果有執行過交換，則flag不為0
			}
		}
		if (flag == 0)
			break;
		/*
		當執行完一次掃描就判斷是否做過交換動作，如果沒有交換過資料
		，表示此時陣列已完成排序，故可直接跳出迴圈
		*/
		cout << "第 " << size - i << " 次排序：\t";
		for (int j = 0; j < size; j++)
			cout << setw(3) << data[j];
		cout << endl;
	}
	cout << "排序後結果為：\t";
	showdata(data,size);
}

void select(int data[], int size)
{
	int smallest, temp;
	int index;
	for (int i = 0; i < size; i++) //掃描5次
	{
		smallest = data[i];
		index = i;
		for (int j = i + 1; j < 6; j++)  //由i+1比較起，比較5次
		{
			if (smallest > data[j]) //找出最小元素 
			{
				smallest = data[j];
				index = j;
			}
		}
		//將最小元素所在位置與第 i 個位置交換 
		temp = data[index];
		data[index] = data[i];
		data[i] = temp;

		cout << "第 " << i + 1 << " 次排序結果：";
		for (int k = 0; k < 6; k++)
			cout << setw(3) << data[k]; //列印排序結果
		cout << endl;
	}
	cout << endl;
}

void inser(int data[], int size)
{
	int i; //i為掃描次數
	int j; //以j來定位比較的元素
	for (i = 1; i < size-1; i++)  //掃描迴圈次數為SIZE-1
	{
		int tmp;  //tmp用來暫存資料
		tmp = data[i];
		j = i - 1;
		while (j >= 0 && tmp < data[j]) //如果第二元素小於第一元素
		{
			data[j + 1] = data[j];		//就把所有元素往後推一個位置		
			j--;
		}
		data[j + 1] = tmp;              //最小的元素放到第一個元素	
		cout << "第 " << i << " 次掃瞄：";
		showdata(data, size);
	}
}

void shell(int data[], int size)
{
	int i;        //i為掃描次數
	int j;        //以j來定位比較的元素
	int k = 1;      //k列印計數
	int tmp;      //tmp用來暫存資料
	int jmp;      //設定間距位移量
	jmp = size / 2;
	while (jmp != 0)
	{
		for (i = jmp; i < size; i++)
		{
			tmp = data[i];
			j = i - jmp;
			while (tmp < data[j] && j >= 0)  //插入排序法
			{
				data[j + jmp] = data[j];
				j = j - jmp;
			}
			data[jmp + j] = tmp;
		}
		cout << "第 " << k++ << " 次排序：";
		showdata(data,size);
		jmp = jmp / 2;    //控制迴圈數
	}
}

void quick(int d[], int size, int lf, int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
	//1:第一筆鍵值為d[lf]
	if (lf < rg)
	{
		lf_idx = lf + 1;
		rg_idx = rg;
		while (1) {
			cout << "[處理過程" << process++ << "]=> ";
			for (int t = 0; t < size; t++)
				cout << "[" << setw(2) << d[t] << "] ";
			cout << endl;
			for (int i = lf + 1; i <= rg; i++)
				//2:由左向右找出一個鍵值大於d[lf]者
			{
				if (d[i] >= d[lf])
				{
					lf_idx = i;
					break;
				}
				lf_idx++;
			}
			for (int j = rg; j >= lf + 1; j--)
				//3:由右向左找出一個鍵值小於d[lf]者
			{
				if (d[j] <= d[lf])
				{
					rg_idx = j;
					break;
				}
				rg_idx--;
			}
			if (lf_idx < rg_idx)
				//4-1:若lf_idx<rg_idx
			{
				tmp = d[lf_idx];
				d[lf_idx] = d[rg_idx];
				//則d[lf_idx]和d[rg_idx]互換
				d[rg_idx] = tmp;      //然後繼續排序 
			}
			else {
				break;    //否則跳出排序過程 
			}
		}
		if (lf_idx >= rg_idx)
			//5-1:若lf_idx大於等於rg_idx
		{       //則將d[lf]和d[rg_idx]互換
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;

			//5-2:並以rg_idx為基準點分成左右兩半
			quick(d, size, lf, rg_idx - 1);
			//以遞迴方式分別為左右兩半進行排序
			quick(d, size, rg_idx + 1, rg);
			//直至完成排序
		}
	}
}

void mergeSort(int list1[], int M, int list2[],
	int N, int list3[])
{
	int i = 0, j = 0, k = 0;
	while (i < M && j < N)
	{
		if (list1[i] <= list2[j])
			list3[k++] = list1[i++];
		else
			list3[k++] = list2[j++];
	}

	while (i < M)
		list3[k++] = list1[i++];
	while (j < N)
		list3[k++] = list2[j++];
}

void radix(int data[], int size)
{
	for (int n = 1; n <= 100; n = n * 10)
		// n為基數，由個位數開始排序 
	{
		int tmp[10][100] = { 0 };
		// 設定暫存陣列，[0~9位數][資料個數]，所有內容均為0 
		for (int i = 0; i < size; i++) // 比對所有資料 
		{
			int m = (data[i] / n) % 10;
			// m為n位數的值，如 36取十位數 (36/10)%10=3 
			tmp[m][i] = data[i];
			// 把data[i]的值暫存於tmp 裡 
		}
		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (tmp[i][j] != 0)
					// 因一開始設定 tmp ={0}，故不為0者即為 
				{
					data[k] = tmp[i][j];
					// data暫存在 tmp 裡的值，把tmp 裡的值放 
					k++;		        // 回data[ ]裡 
				}
			}
		}
		cout << "經過" << setw(3) << n << "位數排序後：";
		showdata(data, size);
	}
}

void heap(int* data, int size)
{
	int i, j, tmp;
	for (i = (size / 2); i > 0; i--)
		//建立堆積樹節點	
		ad_heap(data, i, size - 1);
	cout << "\n堆積內容：";
	for (i = 1; i < size; i++)
		//原始堆積樹內容
		cout << "[" << setw(2) << data[i] << "] ";
	cout << endl;
	for (i = size - 2; i > 0; i--)
		//堆積排序
	{
		tmp = data[i + 1];
		//頭尾節點交換      
		data[i + 1] = data[1];
		data[1] = tmp;
		ad_heap(data, 1, i);
		//處理剩餘節點
		cout << "\n處理過程：";
		for (j = 1; j < size; j++)
			cout << "[" << setw(2) << data[j] << "] ";
	}
}
void ad_heap(int* data, int i, int size)
{
	int j, tmp, post;
	j = 2 * i;
	tmp = data[i];
	post = 0;
	while (j <= size && post == 0)
	{
		if (j < size)
		{
			if (data[j] < data[j + 1])
				//找出最大節點
				j++;
		}
		if (tmp >= data[j])
			//若樹根較大，結束比較過程
			post = 1;
		else
		{
			data[j / 2] = data[j];
			//若樹根較小，則繼續比較
			j = 2 * j;
		}
	}
	data[j / 2] = tmp;
	//指定樹根為父節點
}

int main()
{
	cout << "排序法練習範例:\n";
	int size, data[100] = { 0 }, way;
	
	
	while (1) {
		cout << "================\n";
		cout << "1. 改良氣泡排序法：\n2. 選擇排序法\n3. 插入排序法\n4. 謝耳排序法\n"
			 << "5. 快速排序法\n6. 合併排序法\n7. 基數排序法\n8. 堆積排序法\n";
		cout << "請選擇排序法，輸入-1退出程式: ";
		cin >> way;
		if (way == 1) {
			//改良氣泡排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			bubble(data, size);
		}
		else if (way == 2) {
			// 選擇排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			select(data, size);
		}
		else if (way == 3) {
			//插入排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			inser(data, size);
		}
		else if (way == 4) {
			// 謝耳排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			shell(data, size);
		}
		else if (way == 5) {
			// 快速排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			quick(data, size, 0, size - 1);
			showdata(data, size);
		}
		else if (way == 6) {
			// 合併排序法
			int data1[NUM2] = { 0 }, data2[NUM1 + NUM2] = { 0 };
			cout << "請輸入第一陣列，陣列大小為：" << NUM1 << endl;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, NUM1);
			showdata(data, NUM1);
			
			cout << "請輸入第二陣列，陣列大小為：" << NUM2 << endl;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data1, NUM2);
			showdata(data1, NUM2);
			cout << "排序前：";
			cout << "\nlist1[]：";
			int i;

			for (i = 0; i < NUM1; i++)
				cout << data[i] << " ";

			cout << "\nlist2[]：";
			for (i = 0; i < NUM2; i++) {
				//list2[i] = rand() % 100; 
				cout << data1[i] << " ";
			}
			cout << "\n";
			process = 0;
			quick(data, NUM1, 0, NUM1 - 1);
			quick(data1, NUM2, 0, NUM2 - 1);

			cout << "\n排序後：";
			cout << "\nlist1[]：";
			for (i = 0; i < NUM1; i++)
				cout << data[i] << " ";
			cout << "\nlist2[]：";
			for (i = 0; i < NUM2; i++)
				cout << data1[i] << " ";

			// 合併排序法
			mergeSort(data, NUM1, data1, NUM2, data2);

			cout << "\n合併排序法\n合併後：";
			for (i = 0; i < NUM1 + NUM2; i++)
				cout << data2[i] << " ";
			cout << endl;
		}
		else if (way == 7) {
			//基數排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			showdata(data, size);
			radix(data, size);
		}
		else if (way == 8) {
			//堆積排序法
			cout << "請輸入陣列大小(100以下)：";
			cin >> size;
			cout << "您輸入的原始資料是：" << endl;
			inputarr(data, size);
			
			//原始陣列內容
			cout << "原始陣列：";
			for (int i = 1; i < size; i++)
				cout << "[" << setw(2) << data[i] << "] ";
			heap(data, size);
			//建立堆積樹
			cout << "\n排序結果：";
			for (int i = 1; i < size; i++)
				cout << "[" << setw(2) << data[i] << "] ";
			cout << endl;
		}
		else {
			break;
			}
	}
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
