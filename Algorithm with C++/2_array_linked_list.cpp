// 2_array_linked_list.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip> //操縱子的標頭檔 

using namespace std;



class list //宣告串列結構
{
public:

	int num, score;
	char name[10];
	int coef, exp;
	class list* next;
};

typedef class list node;
typedef node* link;

const int  ROWS = 3;
const int COLS = 3;
void MatrixAdd(int*, int*, int*, int, int);   //宣告陣列相加副程式
void MatrixMultiply(int*, int*, int*, int, int, int); // 宣告陣列相乘副程式

link findnode(link head, int num); //宣告找尋節點副程式
link insertnode(link head, link ptr, int num, int score, char name[10]);// 宣告插入節點副程式

link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a, link b);
int main()
{

	int A[ROWS][COLS] = { {1,3,5},
						 {7,9,11},
						 {13,15,17} };
	int B[ROWS][COLS] = { {9,8,7},
						 {6,5,4},
						 {3,2,1} };
	int C[ROWS][COLS] = { 0 };
	cout << "[矩陣A的各個元素]" << endl; //印出矩陣A的內容
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
	cout << "[矩陣B的各個元素]" << endl; //印出矩陣B的內容
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << B[i][j] << "\t";
		cout << endl;
	}
	MatrixAdd(&A[0][0], &B[0][0], &C[0][0], ROWS, COLS);
	cout << "[顯示矩陣A和矩陣B相加的結果]" << endl;	//印出A+B的內容
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << C[i][j] << "\t";
		cout << endl;
	}

	int M, N, P;
	int i, j;
	//矩陣D部分 
	cout << "請輸入矩陣A的維數(M,N): " << endl;
	cout << "M= ";
	cin >> M;
	cout << "N= ";
	cin >> N;
	int* D = new int[M * N];
	cout << "[請輸入矩陣A的各個元素]" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{
			cout << "c" << i << j << "=";
			cin >> D[i * N + j];
		}
	//矩陣D部分 
	cout << "請輸入矩陣B的維數(N,P): " << endl;
	cout << "N= ";
	cin >> N;
	cout << "P= ";
	cin >> P;
	int* E = new int[N * P];
	cout << "[請輸入矩陣B的各個元素]" << endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < P; j++)
		{
			cout << "d" << i << j << "=";
			cin >> E[i * P + j];
		}
	int* F = new int[M * P];
	MatrixMultiply(D, E, F, M, N, P); //呼叫函數 
	cout << "[DxE的結果是]" << endl;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < P; j++)
			cout << F[i * P + j] << "\t";
		cout << endl;
	}

	//進行矩陣轉置的動作
	int* arrF_t = new int[M * N];
	for (int row = 1; row <= N; row++)
		for (int col = 1; col <= M; col++)
			arrF_t[(col - 1) * N + (row - 1)] = F[(row - 1) + (col - 1) * N];

	cout << "[轉置矩陣內容為]" << endl;
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= M; col++)
		{
			cout << arrF_t[(col - 1) * N + (row - 1)] << "\t";
		}
		cout << endl;
	}

	link head, ptr, newnode;
	int new_num, new_score;
	char new_name[10];
	int position = 0, find, data[12][2];
	char namedata[12][10] = { {"Allen"},{"Scott"},{"Marry"},
	{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
	{"Hanson"},{"Amy"},{"Bob"},{"Jack"} };
	srand((unsigned)time(NULL));
	cout << "座號  成績  座號  成績  座號  成績  座號  成績" << endl;
	cout << "==============================================" << endl;
	for (i = 0; i < 12; i++)
	{
		data[i][0] = i + 1;
		data[i][1] = rand() % 50 + 51;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			cout << "[" << data[j * 3 + i][0] << "]  [" << data[j * 3 + i][1] << "]   ";
		cout << endl;
	}
	head = new node;  //建立串列首
	if (!head)
	{
		cout << "Error!! 記憶體配置失敗!!" << endl;
		exit(1);
	}
	head->num = data[0][0];
	for (j = 0; j < 10; j++)
		head->name[j] = namedata[0][j];
	head->score = data[0][1];
	head->next = NULL;
	ptr = head;
	for (i = 1; i < 12; i++) //建立串列
	{
		newnode = (link)malloc(sizeof(node));
		newnode->num = data[i][0];
		for (j = 0; j < 10; j++)
			newnode->name[j] = namedata[i][j];
		newnode->score = data[i][1];
		newnode->next = NULL;
		ptr->next = newnode;
		ptr = ptr->next;
	}
	while (1)
	{
		cout << "請輸入要插入其後的學生編號，結束輸入-1：";
		cin >> position;
		if (position == -1)//迴圈中斷條件
			break;
		else
		{
			ptr = findnode(head, position);
			cout << "請輸入新插入的學生編號：";
			cin >> new_num;
			cout << "請輸入新插入的學生成績：";
			cin >> new_score;
			cout << "請輸入新插入的學生姓名：";
			cin >> new_name;
			head = insertnode(head, ptr, new_num, new_score, new_name);
		}
	}
	ptr = head;
	cout << "\n\t座號\t    姓名\t成績\n";
	cout << "\t==============================\n";
	while (ptr != NULL)
	{
		cout << "\t[" << ptr->num << "]\t[ " << ptr->name << "]" << setw(6) << "\t[" << ptr->score << "]\n";
		ptr = ptr->next;
	}
	delete head;

	link a, b, c;
	int data1[4] = { 3,1,0,1 }; //多項式A的係數
	int data2[4] = { 6,0,1,1 }; //多項式B的係數
	cout << "原始多項式：" << endl << "A=";
	a = creat_link(data1);  //建立多項式A
	b = creat_link(data2);  //建立多項式B
	print_link(a);   //列印多項式A
	cout << "B=";
	print_link(b);   //列印多項式B
	cout << "多項式相加結果：\nC=";
	c = sum_link(a, b); //C為A、B多項式相加結果
	print_link(c);   //列印多項式C
}

void MatrixAdd(int* arrA, int* arrB, int* arrC, int dimX, int dimY)
{
	if (dimX <= 0 || dimY <= 0)
	{
		cout << "矩陣維數必須大於0" << endl;
		return;
	}
	for (int row = 1; row <= dimX; row++)
		for (int col = 1; col <= dimY; col++)
			arrC[(row - 1) * dimY + (col - 1)] = arrA[(row - 1) * dimY + (col - 1)]
			+ arrB[(row - 1) * dimY + (col - 1)];
}


void MatrixMultiply(int* arrA, int* arrB, int* arrC, int M, int N, int P)
{
	if (M <= 0 || N <= 0 || P <= 0)
	{
		cout << "[錯誤:維數M,N,P必須大於0]" << endl;
		return;
	}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < P; j++)
		{
			int Temp;
			Temp = 0;
			for (int k = 0; k < N; k++)
				Temp = Temp + arrA[i * N + k] * arrB[k * P + j];
			arrC[i * P + j] = Temp;
		}
}

link findnode(link head, int num)
{
	link ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr->num == num)
			return ptr;
		ptr = ptr->next;
	}
	return ptr;
}

link insertnode(link head, link ptr, int num, int score, char name[10])
{
	link InsertNode;
	InsertNode = new node;
	if (!InsertNode)
		return NULL;
	InsertNode->num = num;
	InsertNode->score = score;
	strcpy_s(InsertNode->name, name);
	InsertNode->next = NULL;
	if (ptr == NULL) //插入第一個節點
	{
		InsertNode->next = head;
		return InsertNode;
	}
	else
	{
		if (ptr->next == NULL)//插入最後一個節點
		{
			ptr->next = InsertNode;
		}
		else //插入中間節點
		{
			InsertNode->next = ptr->next;
			ptr->next = InsertNode;
		}
	}
	return head;
}

link creat_link(int data[4])//建立多項式副程式
{
	link head=0, newnode, ptr=0;
	for (int i = 0; i < 4; i++)
	{
		newnode = new node;
		if (!newnode)
		{
			cout << "Error!! 記憶體配置失敗!!" << endl;
			exit(1);
		}
		if (i == 0)
		{
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			head = newnode;
			ptr = head;
		}
		else if (data[i] != 0)
		{
			newnode->coef = data[i];
			newnode->exp = 3 - i;
			newnode->next = NULL;
			ptr->next = newnode;
			ptr = newnode;
		}
	}
	return head;
}
void print_link(link head) //列印多項式副程式
{
	while (head != NULL)
	{
		if (head->exp == 1 && head->coef != 0)//X^1時不顯示指數
			cout << head->coef << "X + ";
		else if (head->exp != 0 && head->coef != 0)
			cout << head->coef << "X^" << head->exp << " + ";
		else if (head->coef != 0)           //X^0時不顯示變數
			cout << head->coef;
		head = head->next;
	}
	cout << endl;
}
link sum_link(link a, link b) //多項式相加副程式
{
	int sum[4], i = 0;
	link ptr;
	ptr = b;
	while (a != NULL) //判斷多項式1
	{
		b = ptr; //重複比較A及B的指數
		while (b != NULL)
		{
			if (a->exp == b->exp)//指數相等，係數相加
			{
				sum[i] = a->coef + b->coef;
				a = a->next;
				b = b->next;
				i++;
			}
			else if (b->exp > a->exp)//B指數較大，指定係數給C
			{
				sum[i] = b->coef;
				b = b->next;
				i++;
			}
			else if (a->exp > b->exp)//A指數較大，指定係數給C
			{
				sum[i] = a->coef;
				a = a->next;
				i++;
			}
		}
	}
	return creat_link(sum);//建立相加結果串列C
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
