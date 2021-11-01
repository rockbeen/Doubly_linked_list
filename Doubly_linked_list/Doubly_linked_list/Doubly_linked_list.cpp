#include <iostream>
using namespace std;
template <class T>
struct item
{
	T data;
	item* next;
	item* prev;
};
template <class T>
class list
{
private:

	item<T>* first;
	item<T>* last;
	int size=0;

public:

	list() {
		first = nullptr;
		last = nullptr;
	}
	//~list();
	//	list(const list & );//Default Constructor
	item<T>& find_element(int position, bool up) const;
	void add_item_top(const T&);//
	void add_item_pos(const T&, int position);
	void add_item_end(const T&);
	void show_all();
	void show_data(int position);
	void delete_item_top();
	void delete_item_pos(int position);
	void delete_item_end();
	//	void show_size();
	//	void display_last();
	//	void deleting_equals(T d);
	//	list<T>& operator=(const list<T>& );
};
template <class  T>
item<T>& list<T>::find_element(int position, bool up)  const
{
	item<T>* current;
	if (up)
	{
		current = first;
		for (int i = 1; i <= position; ++i)
			current = current->next;
	}
	else
	{
		current = last;
		for (int i = size-2 ; i >= position; --i)
			current = current->prev;
	}

	return *current;
}

template <class T>
void list<T>::add_item_pos(const T& val, int position)
{


	if (position == 0)
	{
		add_item_top(val);
	}
	else if (position >= size)
	{
		add_item_end(val);
	}
	else if (size != 0)
	{
		item<T>* newitem = new item<T>;
		newitem->data = val;
		newitem->next = &find_element(position, 1);
		(newitem->next)->prev = newitem;
		newitem->prev = &find_element((position - 1), 1);
		(newitem->prev)->next = newitem;
		size++;
	}

}

template <class T>
void list<T>::add_item_end(const T& val)//adding an item to the end of the list
{
	item<T>* newitem = new item<T>;
	newitem->data = val;
	newitem->next = nullptr;
	if (first != nullptr)
	{
		newitem->prev = last;
		last->next = newitem;
		last = newitem;
	}
	else //Если список пустой
	{
		newitem->prev = nullptr;   
		newitem->next = nullptr;  //Предыдущий элемент указывает в пустоту
		first = last = newitem;              //Голова=Хвост=тот элемент, что сейчас добавили
	}
	size++;

}
template <class T>
void list<T>::add_item_top(const T& val)
{

	item<T>* newitem = new item<T>;
	newitem->data = val;
	newitem->prev = nullptr;
	if (first != nullptr)
	{
		newitem->next = first;
		first->prev = newitem;
		first = newitem;
	}
	else
	{
		newitem->prev = nullptr;    
		newitem->next = nullptr;//Предыдущий элемент указывает в пустоту
		first = last = newitem;
	}
	size++;

}

template <class T>
void list<T>::delete_item_end()//deleting to end of list
{
	item<T>* current = first->next;
	delete first;
	first = current;

}

template <class T>//display all elements on the screen
void list<T>::show_all()
{
	item<T>* current = last;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->prev;
	}
}

int main()
{
	list<int> a;
	a.add_item_top(10);
	a.add_item_top(9);
	a.add_item_top(8);
	a.show_all();
	a.add_item_end(11);
	a.show_all();
	a.add_item_pos(30,1);
	a.show_all();

	return 0;
}