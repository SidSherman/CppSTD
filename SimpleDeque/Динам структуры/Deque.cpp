#include "pch.h"
#include <stdio.h>
#include <stdlib.h>


/*
*
* Список в данный момент работает только с int
*
*/


class deque {
private:
	int data; // данные
	deque* next; //указатель на следующий элемент

public:



	deque* root = NULL;
	deque* current;
	deque* end;
	deque* temp;

	deque(int a) // а - значение первого узла
	{

		// выделение памяти под начало списка

		current = (deque*)malloc(sizeof(deque*));
		root = current;
		root->data = a;
		root->next = NULL; // это последний узел списка
		end = root;


	}

	deque(deque& obj) { // конструктор копирования
		this->root = obj.root;
	}


	deque* additeminend(int number) //добавление узла
	{
		current = (deque*)malloc(sizeof(deque*));
		current->data = number;
		end->next = current; // сохранение указателя на следующий узел
		current->next = NULL;
		end = current;
		return end;
	}

	deque* additeminbegin(int number) {
		current = (deque*)malloc(sizeof(deque*));
		current->data = number;
		temp = (deque*)malloc(sizeof(deque*));
		temp = root;
		root = current;
		root->next = temp;
		return root;


	}

	deque* deliteminend()
	{
		current = (deque*)malloc(sizeof(deque*));
		current = root;
		while (current != NULL)
		{

			if (current->next->next == NULL) current->next = NULL;

			current = current->next;

		}
		end = current;
		return end;

	}


	deque* deliteinbegin()
	{
		temp = (deque*)malloc(sizeof(deque*));
		temp = root->next;
		root = temp;

		return root;
	}
	void print() { // вывод списка

		current = (deque*)malloc(sizeof(deque*));
		current = root;
		printf("\n");
		while (current != NULL)
		{
			printf("%d ", current->data);
			current = current->next;

		}


	}

};


int main() {

	int a = 1;

	printf("ENTER ARRAY'S ELEMENTS, TO FINISH ENTER 0\n");

	scanf_s("%d", &a);
	deque lst(a);

	while (a != 0)
	{
		scanf_s("%d", &a);
		if (a != 0)
			lst.additeminend(a);
	}
	printf("Entered list:\n");
	lst.print();
	printf("List with deleted first and last elemet:\n");
	lst.deliteinbegin();
	lst.deliteminend();
	lst.print();

	scanf_s("%d", &a);

	return 0;

}
