#include <iostream>
#include "AVL.h"

using namespace std;

#define MAX_LEN 256


typedef struct binaryTree_s {
	int data;
	struct binaryTree_s* left;
	struct binaryTree_s* right;
} binaryTree;


binaryTree* createNode(int data) {
	binaryTree* newNode = (binaryTree*)malloc(sizeof(binaryTree));
	if (newNode == NULL) {
		printf("Дерево не инициализировано\n");
		exit(1);
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void push(binaryTree** tree, int data) {
	binaryTree* newNode = createNode(data);
	binaryTree* tmp = *tree;
	if (tmp == NULL) {
		*tree = newNode;
	}
	else if (data < tmp->data) {
		if (tmp->left == NULL) {
			tmp->left = createNode(data);
		}
		else {
			push(&(tmp->left), data);
		}
	}
	else if (data > tmp->data) {
		if (tmp->right == NULL) {
			tmp->right = createNode(data);
		}
		else {
			push(&(tmp->right), data);
		}
	}
}

void printInDepthRecursively(binaryTree* tree) {
	if (tree == NULL) {
		return;
	}
	else {
		printf("%d ", tree->data);
		if (tree->left != NULL) {
			printInDepthRecursively(tree->left);
		}
		if (tree->right != NULL) {
			printInDepthRecursively(tree->right);
		}
	}
}

int height(binaryTree* node)
{
	if (!node)
		return 0;

	int h_l = height(node->left);
	int h_r = height(node->right);

	return max(h_l, h_r) + 1;
}


void print(binaryTree* p, int level)
{
	if (p)
	{
		print(p->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->data << endl;
		print(p->right, level + 1);
	}
}


int main() {
	srand(time(0));
	int q = 0, count;
	binaryTree* tree = NULL;
	Avl data;
	int arr[100]{};
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 100 + 1;

	}
	setlocale(LC_ALL, "ru");
	cout << "Кустарник\n1.Ввести вручную\n2.Ввести рандомно\n";
	int vibor;
	cin >> vibor;
	switch (vibor)
	{
	case 1:

		break;
	case 2:
		cout << "Ввод количества узлов:";
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {
			push(&tree, arr[i]);

		}

		cout << "\nБинарное дерево:\n";
		print(tree, height(tree));
		cout << "\n/////////////////////////////\n";
		cout << "Обход в глубину:\n";
		printInDepthRecursively(tree);
		cout << "\n/////////////////////////////\n";
		do {
		cout << "\n1.Отбалансировать дерево\n2.Добавление узла\n3.Удаление узла\n4.Поиск узла\n5.Обход в ширину\n6.Обход в глубину(Pre)\n7.Обход в глубину(In)\n8.Обход в глубину(Post)\n9.Выход\n";
		cin >> vibor;
		
		
			switch (vibor) {

			case 1:
			{
				
				for (int i = 0; i < num; i++) {
					data.insert(arr[i]);

				}
				cout << "\n/////////////////////////////\n";
				data.print();
				cout << "\n/////////////////////////////\n";

				break;


			}

			case 2:
				if ((data.check()) == true)
				{
					cout << "\n/////////////////////////////\n";
					cout << "\nВведите узел: ";
					cin >> count;
					data.insert(count);
					cout << "\n/////////////////////////////\n";
					data.print();
					cout << "\n/////////////////////////////\n";
				}
				else break;
				break;
			case 3:
				if ((data.check()) == true)
				{
					cout << "\n/////////////////////////////\n";
					cout << "Введите ключ:";
					int key; cin >> key;
					int i;
					for (int i = 0; i < 10; i++) {
						data.remove(key);



					}
					cout << "\n/////////////////////////////\n";
					data.print();
					cout << "\n/////////////////////////////\n";
				}
				else break;
				break;
			
			case 4:
				if ((data.check()) == true)
				{
				cout << "\n/////////////////////////////\n";
				cout << "\nВведите узел: ";
				cin >> count;
				cout << "\n/////////////////////////////\n";
				data.search(count);
				cout << "\n/////////////////////////////\n";
				}
				else break;
				break;
				
			case 5:
				if ((data.check()) == true)
				{
				cout << "\n/////////////////////////////\n";
				data.wide();
				cout << "\n/////////////////////////////\n";
				}
				else break;
				break;
				
				case 6:
					if ((data.check()) == true)
					{
					cout << "\n/////////////////////////////\n";
					data.PreOrder();
					cout << "\n/////////////////////////////\n";
					}
					else break;
					break;
					
				case 7:
					if ((data.check()) == true)
					{
					cout << "\n/////////////////////////////\n";
					data.InOrder();
					cout << "\n/////////////////////////////\n";
					}
					else break;
					break;
					
				case 8:
					if ((data.check()) == true)
					{
					cout << "\n/////////////////////////////\n";
					data.PostOrder();
					cout << "\n/////////////////////////////\n";
					}
					else break;
					break;
					
			case 9:
				q = 1;
				break;
			default: {cout << "Неверные данные\n"; break; }
			}

		} while (q != 1);
		break;
	}

}