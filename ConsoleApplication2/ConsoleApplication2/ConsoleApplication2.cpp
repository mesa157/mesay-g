#include <iostream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;
class real_number
{
	float n;
public:
	real_number() : n(0) {}
	real_number(const float& n) : n(n) {}
	float abs() { return fabs(n); }
	friend ostream& operator<<(ostream& o, real_number& rn)
	{
		return o << rn.n;
	}
	bool operator==(const real_number& other)
	{
		return n == other.n;
	}
};
struct queue_node

{
	real_number n;
	queue_node* next;
	queue_node(real_number rn) : n(rn), next(nullptr) {}
};
class priority_queue
{
protected:
	queue_node* head;
public:
	priority_queue() : head(nullptr) {}
	virtual priority_queue& operator+=(real_number n)
	{
		queue_node* node = new queue_node(n);
		if (!head)
		{
			head = node;
			return *this;
		}
		if (head->n.abs() > node->n.abs())
		{
			node->next = head;
			head = node;
			return *this;
		}
		queue_node* current = head;
		while (current->next)
		{
			if (current->next->n.abs() > node->n.abs())
			{
				node->next = current->next;
				current->next = node;
				return *this;
			}
			current = current->next;
		}
		current->next = node;
		return *this;
	}
	priority_queue& give(priority_queue& other)
	{
		return other += unshift();
	}
	real_number unshift()
	{
		if (!head)
			throw exception();
		queue_node* node = head;
		head = head->next;

		real_number n = node->n;
		delete node;
		return n;
	}
	void clear()
	{
		while (head)
		{
			queue_node* next = head->next;
			delete head;
			head = next;
		}
	}
	priority_queue& operator=(priority_queue& other)
	{
		if (this == &other)
			return *this;
		clear();
		queue_node* node = other.head;
		while (node)
		{
			(*this) += node->n;
			node = node->next;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& o, priority_queue& q)
	{
		queue_node* node = q.head;
		o << "(";
		while (node)
		{
			o << node->n;
			o << (node->next ? ", " : "");
			node = node->next;
		}
		o << ")";
		return o;
	}
};
class set : public priority_queue
{
public:
	bool contains(const real_number& n)
	{
		for (queue_node* current = head; current; current = current->next)
			if (current->n == n)
				return true;
		return false;

	}
	set& operator+=(real_number n)
	{
		if (contains(n))
			throw exception(); // or return *this?
		priority_queue::operator+=(n);
		return *this;
	}
	const set& operator+=(const set& other)
	{
		queue_node* node = other.head;
		while (node)
		{
			if (!contains(node->n))
				(*this) += node->n;
			node = node->next;
		}
		return other;
	}
	friend set operator+(const set& set1, const set& set2)
	{
		set result;
		set1 >> result;
		result += set2;
		return result;
	}
	friend const set& operator>>(const set& src, set& dest)
	{
		queue_node* node = src.head;
		while (node)
		{
			dest += node->n;
			node = node->next;
		}
		return src;
	}
};
int main(int argc, char** argv)
{
	real_number n;
	priority_queue queue1, queue2;
	set set1, set2;
	cout << "Queues:" << endl;
	srand(time(nullptr));
	for (int i = 0; i < 5; ++i)
	{
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);

		queue1 += n;
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);
		queue2 += n;
	}
	cout << queue1 << ", " << queue2 << endl;
	for (int i = 0; i < 3; ++i)
		queue2.give(queue1);
	cout << queue1 << ", " << queue2 << endl;
	for (int i = 0; i < 3; ++i)
	{
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);
		set1 += n;
	}
	cout << "Sets:" << endl;
	set1 >> set2;
	set1 += 0;
	for (int i = 0; i < 2; ++i)
	{
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);
		set2 += n;
	}
	cout << set1 << ", " << set2 << endl;
	set1 += set2;
	cout << "Set OR:" << endl << set1 << endl;
	set1.clear();
	set2.clear();
	for (int i = 0; i < 3; ++i)
	{
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);
		set1 += n;
		n = rand() % 1000 * (rand() % 2 == 0 ? 1 : -1);
		set2 += n;
	}
	cout << "Sets:" << endl << set1 << ", " << set2 << endl;
	set sum = set1 + set2;
	cout << "Sum:" << endl << sum << endl;
	return