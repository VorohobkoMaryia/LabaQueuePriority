#include <iostream>
#include "Deque.h"
#pragma warning(disable : 4996)

using namespace std;

void Deque::clear()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		pop();
	}
}
Deque::~Deque()
{
	clear();
}
void Deque::Clone(const Deque& rhs)
{
	
	Node* tmp = rhs.head;
	while (tmp != nullptr)
	{
		push(tmp->data, tmp->priority);
		tmp = tmp->next;
	}
}

Deque::Deque()
{
	count = 0;
	head = nullptr;
	rear_h = nullptr;
	rear_m = nullptr;
	rear_l = nullptr;
}
Deque::Deque(const Deque& rhs)
{
	clear();
	Clone(rhs);
}
Deque::Deque(Deque&& rhs) noexcept {
	move(head, rhs.head);
}
void Deque::move(Node*& rhs1, Node*& rhs2) noexcept {
	rhs1 = rhs2;
	rhs2 = nullptr;
}

Deque& Deque::operator=(const Deque& rhs)
{
	if (this != &rhs)
	{
		clear();
		Clone(rhs);
	}
	return *this;
}
Deque& Deque::operator= (Deque&& rhs) noexcept {
	if (this != &rhs) {
		clear();
		move(head, rhs.head);
	}
	return *this;
}
void Deque::Insert(Node*& rhs1, Node*& rhs2) noexcept {
	rhs1->next = rhs2;
	rhs2 = rhs1;
}
int Deque::size() const
{
	return count;
}
int Deque::sizePriority(Priority priority) const
{
	int counter = 0;
	Node* tmp = head;
	for (int i = 0; i < count; i++)
	{
		if (tmp->priority == priority)
			counter++;
		tmp = tmp->next;
	}
	return counter;
}
int Deque::getFirstValue() const
{
	if (count == 0)
		throw exception("ERROR: queue is empty");
	return head->data;
}
string Deque::getFirstPriority() const
{
	if (count == 0)
	{
		throw exception("ERROR: queue is empty");
	}
	switch (head->priority)
	{
	case Priority::rear_low:
		return "low";
	case Priority::rear_medium:
		return "medium";
	case Priority::rear_high:
		return "high";
	}
}
void Deque::push(int Data, Priority priority) {
	Node* tmp = new Node;
	tmp->data = Data;
	tmp->priority = priority;
	count++;
	switch (priority) {
	case Priority::rear_high:
	{
		if (rear_h != nullptr)
		{
			Insert(tmp, rear_h->next);
		}
		else
		{
			Insert(tmp, head);
		}
		rear_h = tmp;
		break;
	}
	case Priority::rear_medium: {
		if (rear_m != nullptr) {
			Insert(tmp, rear_m->next);
		}
		else if (rear_h != nullptr) {
			Insert(tmp, rear_h->next);
		}
		else {
			Insert(tmp, head);
		}
		rear_m = tmp;
		break;
	}
	case Priority::rear_low: {
		if (rear_l != nullptr) {
			Insert(tmp, rear_l->next);
		}
		else if (rear_m != nullptr) {
			Insert(tmp, rear_m->next);
		}
		else if (rear_h != nullptr) {
			Insert(tmp, rear_h->next);
		}
		else {
			Insert(tmp, head);
		}
		rear_l = tmp;
		break;
	}
	}
}

bool Deque::IsEmpty() const
{
	return (count == 0);
}
void Deque::pop()
{
	if (count == 0)
		throw exception("ERROR: queue is empty");

	Node* tmp = head;
	if (count == 1 || head->priority != head->next->priority)
	{
			switch (head->priority) 
			{
			case rear_high:
				rear_h = nullptr;
				break;
			case rear_medium:
				rear_m = nullptr;
				break;
			case rear_low:
				rear_l = nullptr;
				break;
			}
	}
	head = head->next;
	delete tmp;
	count--;

}
ostream& operator<<(ostream& ost, const Deque& value)//оператор вывода
{
	Deque::Node* tmp = value.head;
	ost << "Список :\n";
	while (tmp != nullptr) {
		ost << tmp->data << "\n";
		tmp = tmp->next;
	}
	return ost;
}