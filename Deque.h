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
	
	Deque();//�������� ������
	Deque(const Deque& rhs);// ����������� �����������
	Deque(Deque&& rhs) noexcept;
	void move(Node*& rhs1, Node*& rhs2) noexcept;
	void Insert(Node*& rhs1, Node*& rhs2) noexcept;
	Deque& operator=(const Deque& rhs);//�������� ������������
	Deque& operator=(Deque&& rhs) noexcept;
	
	~Deque();// ������� ������, �������� ������
	int size() const;// ���������� ���������� ��������� � ������
	int sizePriority(Priority) const;// ���������� ���������� ��������� � ������������ ����������
	void push(int data,Priority);// ���������� ��������
	void pop();// �������� 
	bool IsEmpty() const;//�������� �� �������
	int getFirstValue() const;
	string getFirstPriority() const;
	friend ostream& operator<<(ostream& ost, const Deque& value);//�������� ������
	
};
