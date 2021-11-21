#include <iostream>
#include <sstream>
using namespace std;
class row
{
private:
	char* t;
public:
	row();
	friend istream& operator>>(istream& is, row& some);
	row& operator+=(const row&);
	friend ostream& operator<<(ostream& is, row& some);
	int length();
	const char* getText();
	row(const row&);
	row(const char*);
};
struct node
{
	row d;
	node* next;
	node* prev;
	node(row tmp) : d(tmp), next(NULL), prev(NULL) {}
};
class text
{
protected:
	node* head;
	node* tail;
public:
	friend istream& operator>>(istream& is, text& some)
	{
		row t;
		t.empty();
		while (is >> t) //wklepujemy dane do t
			some += t; // i je dodajemy do argumentu
		return is; //zwracamy istream
	}
	friend ostream& operator<<(ostream& o, text& t)
	{
		for (node* tmp = t.head; tmp != nullptr; tmp = tmp->next) // zaczynamy od g³owy ,
			dopoki nie ejst pusta i przesuwamy sie
			o << tmp->d << endl; // wczytujemy do strumienia kazdy row
		return o; //zwracamy strumien
	}
	virtual text& operator+=(const row& some) // virtual!!
	{
		node* tmp = new node(some); // tworzymy tymczasowy obiekt listy
		if (!head) //jezeli brak poczatku
		{
			head = tmp;
		}
		else
		{
			node* current = head; //tworzymy znow tymczasowa
			while (current->next) // sprawdzamy czy nast jest NULL
			{
				current = current->next; // przesuwamy
			}
			current->next = tmp; // jezeli jest pusta to ustawiamy nast jak nasza ktora
			chcielismy dodac
		}
		tail = tmp; // ostatni element to nasz dodany
		return *this;
	}
	operator int()
	{
		int size = 0;
		for (node* tmp = head; tmp != nullptr; tmp = tmp->next)
			size += tmp->d.length();
		return size;
	}
};
class texteditor : public text
{
private:
	node* curr;
public:
	row delline()
	{
		if (!curr)
			throw exception();
		node* some_node = curr;
		if (curr == head)
		{
			head = head->next;
			if (head) head->prev = nullptr;
		}
		else
		{
			if (curr->prev) curr->prev->next = curr->next;
			if (curr->next) curr->next->prev = curr->prev;
		}
		if (curr == tail)
			tail = curr->prev;
		curr = curr->next;
		row d(some_node->d.getText());
		return d;
	}
	texteditor& operator+=(const row& r)
	{
		node* tmp = new node(r);
		if (!curr)
		{
			head = tmp;
		}
		else
		{
			tmp->next = curr->next;
			tmp->prev = curr;
			if (curr->next) curr->next->prev = tmp;
			curr->next = tmp;
		}
		if (curr == tail) tail = tmp;
		curr = tmp;
		return *this;
	}
	texteditor cut(int num_rows)
	{
		int count = num_rows;
		for (node* tmp = curr; tmp != nullptr; tmp = tmp->next)
			--count;
		if (count > 0) // didn't find enough rows of text
			throw exception();
		texteditor result;
		for (int i = 0; i < num_rows; ++i)
			result += delline();
		return result;
	}
	const texteditor& operator=(const texteditor& t)
	{
		if (&t == this)
			return *this;
		while (head)
		{
			node* next = head->next;
			delete head;
			head = next;
		}
		head = nullptr;
		tail = nullptr;
		curr = nullptr;
		for (node* tmp = t.head; tmp != nullptr; tmp = tmp->next)
			text::operator+=(tmp->d);
		return t;
	}
};