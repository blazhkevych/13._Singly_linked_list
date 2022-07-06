/*
############################################ ЗАДАНИЕ ###########################################
					Односвязный список
Добавить в класс "Односвязный список" следующие методы:
	 вставка элемента в заданную позицию
void InsertByPosition(char data, int position);
	 удаление элемента по заданной позиции
void RemoveByPosition(int position);
	 поиск заданного элемента по ключу (функция возвращает позицию найденного элемента в
случае успеха или -1 в случае неудачи)
int Find(char key);
	 конструктор копирования
List(const List& obj);
	 перегруженный оператор =
List& operator = (const List & obj);
################################################################################################
		СТАТУС : Готово.
################################################################################################
*/

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	/*
	РАБОТАЕТ. Отключено для удобства.

	// Создаем объект класса List.
	List lst;
	// Тестовая строка.
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << endl;
	// Определяем длину строки.
	int len = strlen(s);
	// Помещаем строку в список.
	for (int i = len - 1; i >= 0; i--)
		lst.Add(s[i]);
	// Распечатываем содержимое списка.
	lst.Print();
	// Удаляем два элемента списка.
	lst.Del();
	lst.Del();
	// Распечатываем содержимое списка.
	lst.Print();
	// Удаляем все элементы списка.
	lst.DelAll();
	// Распечатываем содержимое списка.
	lst.Print();
	*/

	////////////////////////////////////////////
	//////////////////Тесты/////////////////////
	////////////////////////////////////////////
	char data_pos = '0';
	// Создаем объект класса List.
	List list2;
	// Тестовая строка.
	char str[] = "Hello, World !?!\n";
	// Выводим строку.
	cout << str << endl;
	// Определяем длину строки.
	int len = strlen(str);
	// Помещаем строку в список.
	for (int i = len - 1; i >= 0; i--)
		list2.Add(str[i]);
	// Распечатываем содержимое списка.
	// Вставка элемента в заданную позицию.
	/*
	РАБОТАЕТ. Отключено для удобства.

	list2.Print();
	list2.InsertByPosition(data_pos, 0);
	cout << "list2.InsertByPosition(data_pos, 0);" << endl;
	list2.Print();

	char data_pos = '1';
	list2.InsertByPosition(data_pos, 1);
	cout << "list2.InsertByPosition(data_pos, 1);" << endl;
	list2.Print();

	char data_pos = '~';
	list2.InsertByPosition(data_pos, 15);
	cout << "list2.InsertByPosition(data_pos, 15);" << endl;
	list2.Print();

	char data_pos = '~';
	list2.InsertByPosition(data_pos, 16);
	cout << "list2.InsertByPosition(data_pos, 16);" << endl;
	list2.Print(); */

	// Удаление элемента по заданной позиции.
	/*
	РАБОТАЕТ. Отключено для удобства.

	cout << "list2.RemoveByPosition(4);" << endl;
	list2.RemoveByPosition(18);
	list2.Print();
	*/

	// Поиск заданного элемента по ключу(функция возвращает позицию найденного элемента в
	// случае успеха или - 1 в случае неудачи)
	/*
	РАБОТАЕТ. Отключено для удобства.

	char key = '\n';
	cout << list2.Find(key) << endl;
	*/

	// Конструктор копирования.
	List list3 = list2;
	cout << "List list3 = list2;" << endl;
	list3.Print();

	// Перегруженный оператор присваивания с копированием.
	List list4{};
	list4 = list2;
	cout << "list4 = list2;" << endl;
	list4.Print();

	return 0;
}