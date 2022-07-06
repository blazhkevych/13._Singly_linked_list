#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	// Изначально список пуст.
	m_head = nullptr;
	m_count = 0;
}

// Конструктор копирования.
List::List(const List& obj)
{
	// Новый список.
	this->m_head = new Element{ 0,nullptr };
	this->m_count = obj.m_count;

	const Element* temp = obj.m_head;

	char* arr = new char[obj.m_count];
	int i{ 0 };
	while (temp != nullptr)
	{
		arr[i] = temp->data;
		InsertByPosition(arr[i], i);
		i++;
		temp = temp->next;
	}

	delete temp;
}

// Перегруженный оператор присваивания с копированием.
List& List::operator=(const List& obj)
{
	// Проверка на самоприсваивание.
	if (this == &obj)
		return *this;
	// Удаление старого списка.
	this->DelAll();

	// Новый список.
	this->m_head = new Element{ 0,nullptr };
	this->m_count = obj.m_count;

	const Element* temp = obj.m_head;

	char* arr = new char[obj.m_count];
	int i{ 0 };
	while (temp != nullptr)
	{
		arr[i] = temp->data;
		InsertByPosition(arr[i], i);
		i++;
		temp = temp->next;
	}

	delete temp;

	return *this;
}

List::~List()
{
	// Вызов функции удаления.
	DelAll();
}

int List::GetCount() const
{
	// Возвращаем количество элементов.
	return m_count;
}

// Вставка элемента в заданную позицию.
void List::InsertByPosition(char data, int position)
{
	// Добавление елемента перед нулевым.
	// Создание нового элемента.
	if (position == 0)
	{
		Add(data);
	}
	// Добавление после 0го до вставки после последнего елемента включительно.
	else if (position > 0 && position <= m_count)
	{
		Element* temp = m_head;
		int iterator{ 0 };
		while (iterator != m_count - 1)
		{
			if (iterator == position - 1)
			{
				// Создаем новый елемент.
				Element* newElement = new Element;
				// Переписываем из текущего елемента поле некст новому.
				newElement->next = temp->next;
				// Записываем в поле некст текущего елемента, адрес нового елемента.
				temp->next = newElement;
				// Помещаем входящие данные в новый елемент.
				newElement->data = data;
				// Увеличиваем число елементов на 1.
				m_count++;
				return;
			}
			temp = temp->next;
			iterator++;
		}
	}
}

// Удаление элемента по заданной позиции.
void List::RemoveByPosition(int position)
{
	// Удаление елемента в 0 позиции.
	if (position == 0)
	{
		Del();
	}
	// Удаление 1го и до последнего елемента включительно.
	if (position > 0 && position <= m_count)
	{
		Element* temp = m_head;
		int iterator{ 0 };
		while (iterator != m_count - 1)
		{
			if (iterator == position - 1)
			{
				Element* prev = temp;
				temp = temp->next;
				prev->next = temp->next;
				delete temp;
				m_count--;
				return;
			}
			temp = temp->next;
			iterator++;
		}
	}
}

// Поиск заданного элемента по ключу(функция возвращает позицию найденного элемента в
// случае успеха или - 1 в случае неудачи).
int List::Find(char key) const
{
	int position{ 0 };
	// Запоминаем адрес головного элемента.
	const Element* temp = m_head;
	// Пока еще есть элементы.
	while (temp != nullptr)
	{
		if (key == temp->data)
		{
			return position;
		}
		// Переходим на следующий элемент.
		temp = temp->next;
		position++;
	}

	return -1;
}

void List::Add(char data)
{
	// Создание нового элемента.
	Element* temp = new Element;

	// Заполнение данными.
	temp->data = data;
	// Следующий элемент - головной элемент списка.
	temp->next = m_head;

	// Новый элемент становится головным элементом списка.
	m_head = temp;

	m_count++;
}

void List::Del()
{
	if (m_head)
	{
		// Запоминаем адрес головного элемента.
		Element* temp = m_head->next;
		// Перебрасываем голову на следующий элемент.
		delete m_head;
		// Удаляем бывший головной элемент.
		m_head = temp;
		m_count--;
	}
}

void List::DelAll()
{
	// Пока еще есть элементы.
	while (m_head != nullptr)
		// Удаляем элементы по одному.
		Del();
}

void List::Print() const
{
	// Запоминаем адрес головного элемента.
	const Element* temp = m_head;
	if (temp == nullptr)
	{
		cout << "List is empty!";
		return;
	}
	// Пока еще есть элементы.
	while (temp != nullptr)
	{
		// Выводим данные
		cout << temp->data;
		// Переходим на следующий элемент.
		temp = temp->next;
	}
	cout << endl;
}