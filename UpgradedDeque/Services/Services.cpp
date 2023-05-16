#include "pch.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

class Services { // класс услуги

private:
	string name_; // наименование компании
	string serv_; // наименование услуги
	int cost_; // цена услуги

public:
	Services() {} // конструктор по умолчанию

	Services(string name, string serv, int cost) // конструктор
	{

		name_ = name;
		serv_ = serv;
		cost_ = cost;
	}

	string Get_name() { // возврат названия компании
		return name_;
	}

	string Get_serv() { // возврат названия услуги
		return serv_;
	}

	int Get_cost() { // возврат цены услуги
		return cost_;
	}

	void print() { // вывод информации об объекте
		cout << "Наименование организации: " << name_ << endl << "Наименование услуги: "
			<< serv_ << endl << "Стоимость: " << cost_ << endl;
	}
};

class deque { // класс двусторонняя очередь

private:
	Services* data; // данные
	deque* next; //указатель на следующий элемент

public:
	deque* root = NULL;
	deque* current;
	deque* end;
	deque* temp;

	deque() { // конструктор по умолчанию
		end = root;
	}

	deque(Services& a) // а - значение первого узла

	{
		current = new deque[sizeof(deque*)];
		root = current;
		root->data = &a;
		root->next = NULL; // это последний узел списка
		end = root;
	}

	deque(deque& obj) { // конструктор копирования
		this->root = obj.root;
	}

	deque* PushFront(Services* number) // добавление узла в конец дека
	{
		if (this->root == NULL) // если очередь пуста
		{
			root = new deque[sizeof(deque*)];
			root->data = number;
			root->next = NULL;
			end = root;
		}
		else { // если очередь не пуста
			current = new deque[sizeof(deque*)];
			current->data = number;
			next = new deque[sizeof(deque*)];
			end->next = current; // сохранение указателя на следующий узел
			current->next = NULL;
			end = current;
		}
		return end;
	}

	deque* PushBack(Services* number) { // добавление узла в начало дека
		current = new deque[sizeof(deque*)];
		current->data = number;
		temp = new deque[sizeof(deque*)];
		temp = root;  // сохранение корня дека
		root = current;
		root->next = temp;
		return root;
	}

	deque* PopFront() // Удаления узла в конце дека
	{
		if (root != NULL) {
			if (root->next == NULL) // если конец дека
				root = NULL;
			else {  // если конец дека
				current = new deque[sizeof(deque*)];
				current = root;
				while (current != NULL)
				{
					if (current->next->next == NULL) current->next = NULL;
					current = current->next;
				}
				end = current;
			}
		}
		return end;
	}

	deque* PopBack() // удаление узла в начале дека
	{
		if (root != NULL) { // если не  дек пустой 
			if (root->next != NULL) {
				temp = new deque[sizeof(deque*)];
				temp = root->next;
				root = temp;
			}
			else // если дек пустой 
				root = NULL;
		}
		return root;
	}

	int isin(string name, string serv) // проверка наличия услуги в данной компании
	{
		current = new deque[sizeof(deque*)];
		current = root;
		while (current != NULL)
		{
			if (name == (*(current->data)).Get_name() &&
				serv == (*(current->data)).Get_serv()
				) {

				return 1;
			}
			current = current->next;

		}
		return 0;
	}

	void print() { // вывод дека
		current = new deque[sizeof(deque*)];
		current = root;
		printf("\n");
		while (current != NULL)
		{
			(*(current->data)).print();
			current = current->next;
		}
	}

	deque* find(string name) // поиск компании в которой, заданная услуга имеет наибольшую стоимость
	{
		current = new deque[sizeof(deque*)];
		current = root;
		deque* company = new deque[sizeof(deque*)];
		int max_cost = 0;
		int k = 0;
		while (current != NULL)
		{

			if (name == (*(current->data)).Get_serv()) {
				k = 1;
				if (max_cost == 0 || max_cost < (*(current->data)).Get_cost())
				{
					max_cost = (*(current->data)).Get_cost();
					company = current;
				}
			}
			current = current->next;
		}
		if (k) {
			cout << "Самая высокая цена услуги " << name << " в компании " << (*(company->data)).Get_name() << ": " << max_cost << endl;
			return 0;
		}
		else
		{
			cout << "Данной услуги нет в списке" << endl;
			return 0;
		}
	}

	deque operator =(deque& obj) // перезагрузка оператора присваивания
	{
		this->root = obj.root;
		return *this;
	}

	int isempty() { // проверка наличия элементов в деке
		if (root == NULL) {

			return 1;
		}
		else {

			return 0;
		}
	}

	~deque() { // деструктор
		root = NULL;
	}
};

int main() {

	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251); // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	int k;
	deque lst;

	while (true) {
		int price;
		string name;
		string serv;

		cout << "Введите 1, чтобы проверить пуста ли очередь." << endl;
		cout << "Введите 2, чтобы добавить услугу в конец очереди." << endl;
		cout << "Введите 3, чтобы добавить услугу в начало очереди." << endl;
		cout << "Введите 4, чтобы удалить услугу в конце очереди." << endl;
		cout << "Введите 5, чтобы удалить услугу в начале очереди." << endl;
		cout << "Введите 6, чтобы вывесити очередь на экран." << endl;
		cout << "Введите 7, чтобы найти в какой организации заданная услуга имеет наибольшую стоимость." << endl;
		cout << "Введите 0, чтобы выйти из программы." << endl;


		if (!(scanf_s("%d", &k) && (getchar() == '\n'))) // перехват ошибки ввода
		{
			cout << "Ошибка! Нажмите Enter!";
			while (getchar() != '\n');
			getchar();
			system("cls");
			continue;
		}

		switch (k) {
		case 1: // проверка наличия элементов в очереди
			if (lst.isempty())
				cout << "Очередь пуста" << endl;
			else
				cout << "Очередь не пуста" << endl;
			break;
		case 2: // добавление элемента в конец дека
			cout << "Введите название компании" << endl;

			getline(cin, name);
			cout << "Введите название услуги" << endl;
			getline(cin, serv);
			cout << "Введите цену услуги" << endl;

			if (!(scanf_s("%d", &price) && (getchar() == '\n') && (price > 0))) { // перехват ошибки ввода
				cout << "Ошибка! ";
				while (getchar() != '\n');
				break;
			}

			if (lst.isin(name, serv))
				cout << "В этой компании уже есть такая услуга" << endl;
			else {
				lst.PushFront(new Services(name, serv, price));
				cout << "Услуга добавлена" << endl;
			}
			break;
		case 3: // добавление элемента в начало дека
			cout << "Введите название компании" << endl;
			getline(cin, name);
			cout << "Введите название услуги" << endl;
			getline(cin, serv);
			cout << "Введите цену услуги" << endl;

			if (!(scanf_s("%d", &price) && (getchar() == '\n') && (price > 0))) { // перехват ошибки ввода
				cout << "Ошибка! ";
				while (getchar() != '\n');

				break;
			}

			if (lst.isin(name, serv))
				cout << "В этой компании уже есть такая услуга" << endl;
			else {
				lst.PushBack(new Services(name, serv, price));
				cout << "Услуга добавлена" << endl;
			}
			break;
		case 4: // удаление элемента в конце дека
			if (lst.isempty())
				cout << "Очередь пуста" << endl;
			else {
				lst.PopFront();
				cout << "Элемент удален" << endl;
			}
			break;
		case 5: // удаление элемента в начале дека
			if (lst.isempty())
				cout << "Очередь пуста" << endl;
			else
			{
				lst.PopBack();
				cout << "Элемент удален" << endl;
			}
			break;
		case 6: // вывод всей очереди в консоль
			if (lst.isempty())
				cout << "Очередь пуста" << endl;
			else
				lst.print();
			break;
		case 7: // поиск компании в которой, заданная услуга имеет наибольшую стоимость
			if (lst.isempty())
				cout << "Очередь пуста" << endl;
			else
			{
				string tmp;
				cout << "Введите название услуги: " << endl;
				getline(cin, tmp);
				lst.find(tmp);

			}
			break;
		case 0: // Выход из программы
			cout << "Выход"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";
			return 0;
		default: cout << "Такого пункта меню не существует! Попробуйте снова!" << endl;
			break;
		}

		cout << "Нажмите Enter" << endl;
		getchar();

		system("cls");
	}

	return 0;
}
