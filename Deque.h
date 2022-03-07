#pragma once
#include <iostream>


using namespace std;

enum Priority 
{
	rear_high,
	rear_medium,
	rear_low,
};

class Deque
{
private:
	struct Node
	{
		int data;
		Node* next;
		Priority priority;
	};
	int count;
	Node* head;
	Node* rear_h;
	Node* rear_m;
	Node* rear_l;
	void clear();
	void Clone(const Deque&);
	

public:
	
	Deque();//создание списка
	Deque(const Deque& rhs);// конструктор копирования
	Deque(Deque&& rhs) noexcept;
	void move(Node*& rhs1, Node*& rhs2) noexcept;
	void Insert(Node*& rhs1, Node*& rhs2) noexcept;
	Deque& operator=(const Deque& rhs);//оператор присваивания
	Deque& operator=(Deque&& rhs) noexcept;
	
	~Deque();// Очистка памяти, удаление списка
	int size() const;// Возвращает количество элементов в списке
	int sizePriority(Priority) const;// Возвращает количество элементов в определенном приоритете
	void push(int data,Priority);// Добавление элемента
	void pop();// Удаление 
	bool IsEmpty() const;//проверка на пустоту
	int getFirstValue() const;
	string getFirstPriority() const;
	friend ostream& operator<<(ostream& ost, const Deque& value);//оператор вывода
	
};
