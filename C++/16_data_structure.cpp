// 16_data_structure.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class Student	//自定Student資料
{
	int student_id;
	char student_name[40];
public:
	friend istream& operator >> (istream& in, Student& obj) {
		in >> obj.student_id >> obj.student_name;
		return in;
	}
	friend ostream& operator << (ostream& out, Student& obj) {
		out << obj.student_id << '\t' << obj.student_name;
		return out;
	}
};

struct link	//定義link資料結構
{
	Student data;	//Student型態資料
	link* next;	//link型態指標
};

class linklist	//串列資料類別
{
	link* firstPtr;	//串列起始指標
	link* lastPtr;	//串列結束指標
public:
	linklist() { firstPtr = lastPtr = NULL; }	//建立者
	void addFront(Student obj);	//宣告插入第一項原型
	void addBack(Student obj);	//宣告插入最後項原型
	void delFront();	//宣告刪除第一項原型
	void delBack();	//宣告刪除最後項原型
	void showItem();	//宣告顯示串列原型
};

void linklist::addFront(Student obj)	//定義插入第一項函數
{
	link* newPtr = new link;
	newPtr->data = obj;
	if (firstPtr == NULL) {				//串列中沒資料
		firstPtr = lastPtr = newPtr;
		lastPtr->next = NULL;
	}
	else {
		newPtr->next = firstPtr;
		firstPtr = newPtr;
	}
}

void linklist::addBack(Student obj)	//定義插入最後項函數
{
	link* newPtr = new link;
	newPtr->data = obj;
	if (firstPtr == NULL) {			//串列中沒資料
		firstPtr = lastPtr = newPtr;
		lastPtr->next = NULL;
	}
	else {
		lastPtr->next = newPtr;
		lastPtr = newPtr;
		lastPtr->next = NULL;
	}
}

void linklist::delFront()	//定義刪除第一項函數
{
	link* tempPtr = firstPtr;
	if (firstPtr == NULL)
		return;
	else {
		firstPtr = firstPtr->next;
		delete tempPtr;
	}
}

void linklist::delBack()	//定義刪除最後項函數
{
	link* tempPtr = lastPtr;
	if (firstPtr == NULL)
		return;
	else {
		if (firstPtr == lastPtr)
			firstPtr = lastPtr = NULL;
		else {
			link* currentPtr = firstPtr;
			while (currentPtr->next != lastPtr)
				currentPtr = currentPtr->next;
			lastPtr = currentPtr;
			lastPtr->next = NULL;
		}
	}
	delete tempPtr;
}

void linklist::showItem()	//定義顯示串列資料函數
{
	link* currentPtr = firstPtr;
	while (currentPtr != NULL) {
		cout << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
}

class Stack	//定義堆疊資料類別
{
	link* stackPtr;	//堆疊指標
public:
	Stack() { stackPtr = NULL; }	//建立者
	void push(Student obj); 	//宣告推入資料原型
	Student pop();	//宣告取回資料原型
};

void Stack::push(Student obj) 	//定義推入資料函數
{
	link* newPtr = new link;
	newPtr->data = obj;
	newPtr->next = stackPtr;
	stackPtr = newPtr;
}

Student Stack::pop()	//定義取回資料函數
{
	link* tempPtr = stackPtr;
	Student tempData;
	string error = "堆疊空了！\n";
	if (stackPtr == NULL) {
		throw error;
	}
	else {
		tempData = tempPtr->data;
		stackPtr = stackPtr->next;
		delete tempPtr;
	}
	return tempData;
}

class Queue	//定義佇列資料類別
{
	link* headPtr;	//佇列起始指標
	link* tailPtr;	//佇列結束指標
public:
	Queue() { headPtr = tailPtr = NULL; }	//建立者
	void push(Student obj);	//宣告推入資料原型
	Student pop();	//宣告取回資料原型
};

void Queue::push(Student obj)	//定義推入資料原型
{
	link* newPtr = new link;
	newPtr->data = obj;
	if (headPtr == NULL) {
		headPtr = tailPtr = newPtr;
		tailPtr->next = NULL;
	}
	else {
		newPtr->next = headPtr;
		headPtr = newPtr;
	}
}

Student Queue::pop()	//定義取回資料原型
{
	link* tempPtr = tailPtr;
	Student tempData;
	string error = "佇列空了！\n";
	if (headPtr == NULL) {
		throw error;
	}
	else {
		if (headPtr == tailPtr)
			headPtr = tailPtr = NULL;
		else {
			link* currentPtr = headPtr;
			while (currentPtr->next != tailPtr)
				currentPtr = currentPtr->next;
			tailPtr = currentPtr;
			tailPtr->next = NULL;
		}
		tempData = tempPtr->data;
		delete tempPtr;
	}
	return tempData;
}

struct TreeNode {	//定義TreeNode結構資料
	int data;
	TreeNode* left;
	TreeNode* right;
};

class BinaryTree {	//定義二元樹資料類別
	TreeNode* root;
	void showInOrder(TreeNode*);	//顯示InOrder資料原型
	void showPreOrder(TreeNode*);	//顯示PreOrder資料原型
	void showPostOrder(TreeNode*);	//顯示PostOrder原型
	void deleteNode(int num, TreeNode*& nodePtr); //刪除節點函數原型
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//插入節點函數原型
	void coutInOrder() { showInOrder(root); }	//呼叫InOrder資料函數
	void coutPreOrder() { showPreOrder(root); }	//呼叫PreOrder資料函數
	void coutPostOrder() { showPostOrder(root); }	//呼叫PostOrder函數
	bool searchNode(int num);	//搜尋資料函數原型
	void removeNode(int num) { deleteNode(num, root); } //呼叫刪除節點原型

};

void BinaryTree::insertNode(int num)	//插入節點函數
{
	TreeNode* newNode = new TreeNode;	//newNode為新節點指標
	TreeNode* tempNode;	//tempNode為暫存節點
	newNode->left = newNode->right = NULL;	//令新節點左右指標=NULL
	newNode->data = num;	//資料存入新節點的緩衝區
	if (root == NULL) {	//若二元樹還沒有資料
		root = newNode;	//令根節點=新節點
	}
	else {		//若二元樹中已有資料
		tempNode = root;	//令tempNode指向root
		while (tempNode) {	//當tempNode不等於NULL
			if (num < tempNode->data) {	//新資料 < tempNode->data
				if (tempNode->left) {	//若tempNode->left != NULL
					tempNode = tempNode->left;	//tempNode->left為臨時指標
				}
				else {	//若tempNode->left == NULL
					tempNode->left = newNode;	//新節點插入tempNode->left
					break;
				}
			}
			else if (num > tempNode->data) {	//新資料 > tempNode->data
				if (tempNode->right) {	//若tempNode->right!=NULL
					tempNode = tempNode->right;	//tempNode->right為臨時指標
				}
				else {	//若tempNode->right==NULL
					tempNode->right = newNode;	//新節點插入tempNode->right
					break;
				}
			}
			else {	//新資料 == tempNode->data
				cout << "資料重複！";
				break;
			}
		}
	}
}

void BinaryTree::showInOrder(TreeNode* nodePtr)	//顯示InOrder資料函數
{
	if (nodePtr)	//若nodePtr不等於NULL
	{
		showInOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		cout << nodePtr->data << ' ';	//處理節點資料
		showInOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
	}
}

void BinaryTree::showPreOrder(TreeNode* nodePtr)	//顯示PreOrder資料函數
{
	if (nodePtr)	//若nodePtr不等於NULL
	{
		cout << nodePtr->data << ' ';	//處理節點資料
		showPreOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		showPreOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
	}
}

void BinaryTree::showPostOrder(TreeNode* nodePtr)	//顯示PostOrder函數
{
	if (nodePtr)	//若nodePtr不等於NULL
	{
		showPostOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		showPostOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
		cout << nodePtr->data << ' ';	//處理節點資料
	}
}

bool BinaryTree::searchNode(int num)	//搜尋二元樹資料函數
{
	TreeNode* nodePtr = root;	//令nodePtr等於root
	while (nodePtr)	//當nodePtr不等於NULL
	{
		if (num == nodePtr->data)	//若搜尋資料==節點資料
			return true;
		else if (num < nodePtr->data)	//若搜尋資料<節點資料
			nodePtr = nodePtr->left;
		else if (num > nodePtr->data)	//若搜尋資料>節點資料
			nodePtr = nodePtr->right;
	}
	return false;
}

void BinaryTree::deleteNode(int num, TreeNode*& nodePtr)
{					//刪除二元樹節點函數
	if (num < nodePtr->data)	//若搜尋資料<節點資料
		deleteNode(num, nodePtr->left);	//遞回呼叫deleteNode
	else if (num > nodePtr->data)	//若搜尋資料>節點資料
		deleteNode(num, nodePtr->right);	//遞回呼叫deleteNode
	else {		//若搜尋資料==節點資料
		TreeNode* tempNode;	//建立臨時節點
		if (nodePtr == NULL)	//若nodePtr等於NULL
			cout << "不能刪除空節點！";
		else if (nodePtr->right == NULL)	//若nodePtr->right等於NULL
		{
			tempNode = nodePtr;	//令tempNode要刪除的節點
			nodePtr = nodePtr->left;	//令nodePtr = nodePtr->left
			delete tempNode;	//刪除tempNode節點
		}
		else if (nodePtr->left == NULL)	//若nodePtr->left等於NULL
		{
			tempNode = nodePtr;	//令tempNode要刪除的節點
			nodePtr = nodePtr->right;	//令nodePtr=nodePtr->right
			delete tempNode;	//刪除tempNode節點
		}
		else		//以上皆非
		{
			tempNode = nodePtr->right;	//令tempNode=nodePtr->right
			while (tempNode->left)	//tempNode->left不等於NULL
				tempNode = tempNode->left;	//令tempNode=左邊子節點
			tempNode->left = nodePtr->left;
			tempNode = nodePtr;	//tempNode為要刪除節點
			nodePtr = nodePtr->right;	//令nodePtr=nodePtr->right
			delete tempNode;	//刪除tempNode節點
		}
	}
}

int main()
{
    /*串列資料結構(linked list):
    * 動態線性資料結構，可以機動性配合資料的新增或減少，
    * 增加或減少記憶體空間，同時結構類似於一維陣列的排列方式
    */
	Student studata;	//定義Student物件
	linklist ls;	//定義linklist物件
	char n;

	
	
	while (0) {
		cout << "1.插入第一項\t2.插入最後項\t"
			<< "3.刪除第一項\t4.刪除最後項\t"
			<< "0.結束\t";
		cout << "請選擇(1-4 或 0): ";
		cin >> n;
		switch (n) {
		case '1':
			cout << "請輸入學號與姓名：";
			cin >> studata;
			ls.addFront(studata);
			ls.showItem();
			break;
		case '2':
			cout << "請輸入學號與姓名：";
			cin >> studata;
			ls.addBack(studata);
			ls.showItem();
			break;
		case '3':
			ls.delFront();
			ls.showItem();
			break;
		case '4':
			ls.delBack();
			ls.showItem();
			break;
		case '0':
			cout << "結束" << endl;
			return 0;
		}
		cout << endl;
	}

	//堆疊 (stack): 後進先出的資料結構
	Stack ls1;
	try {
		while (0) {
			cout << "1.推入資料項  2.取出資料項  0.結束  請選擇(1,2或0): ";
			cin >> n;
			switch (n) {
			case '1':
				cout << "請輸入學號與姓名：";
				cin >> studata;
				ls1.push(studata);
				break;
			case '2':
				studata = ls1.pop();
				cout << studata << endl;
				break;
			case '0':
				exit(0);
			}
			cout << endl;
		}
	}
	catch (string error) {
		cout << error;
	}

	//佇列(queue) : 先進先出的資料結構
	Queue ls2;
	try {
		while (0) {
			cout << "1.推入資料項  2.取出資料項  0.結束  請選擇(1,2或0): ";
			cin >> n;
			switch (n) {
			case '1':
				cout << "請輸入學號與姓名：";
				cin >> studata;
				ls2.push(studata);
				break;
			case '2':
				studata = ls2.pop();
				cout << studata << endl;
				break;
			case '0':
				exit(1);
			}
			cout << endl;
		}
	}
	catch (string error) {
		cout << error;
	}
	
	//二元樹 (binary tree) 是非線性的連結結構，每個節點可以連結到左右兩個節點。
	BinaryTree intTree;
	cout << "插入節點...";
	intTree.insertNode(5);	//呼叫insertNode函數
	intTree.insertNode(9);	//呼叫insertNode函數
	intTree.insertNode(1);	//呼叫insertNode函數
	intTree.insertNode(6);	//呼叫insertNode函數
	intTree.insertNode(4);	//呼叫insertNode函數
	cout << "完成\n";
	/*顯示二元樹
	* 1. inorder: 先處理左副分支，再處理節點，最後處理右副分支
	* 2. preorder: 先處理節點，再處理左副分支，最後處理右副分支
	* 3. postoredr: 先處理左副分支，再處理右副分支，最後處理節點
	*/
	cout << "\n顯示PreOrder資料：";
	intTree.coutPreOrder();	//呼叫coutPreNode函數
	cout << "\n顯示PostOrder資料：";
	intTree.coutPostOrder();	//呼叫coutPostNode函數
	cout << "\n顯示InOrder資料：";
	intTree.coutInOrder();	//呼叫coutInNode函數
	cout << endl;
	
	//二元樹搜尋
	if (intTree.searchNode(3))	//呼叫searchNode函數
		cout << "\n在二元樹資料結構中找到 3\n";
	else
		cout << "\n在二元樹資料結構中找不到 3\n";
	

	//刪除節點
	cout << "\n刪除節點 9";
	intTree.removeNode(9);	//呼叫removeNode函數
	cout << "\n刪除節點 1";
	intTree.removeNode(1);	//呼叫removeNode函數
	cout << "\n顯示InOrder資料：";
	intTree.coutInOrder();	//呼叫coutInNode函數
	cout << endl;
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
