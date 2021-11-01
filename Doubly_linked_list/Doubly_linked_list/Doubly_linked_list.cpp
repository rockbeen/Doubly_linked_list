#include <iostream>
using namespace std;
template <class T>
struct item		//the structure is a list node
{
	T data;
	item* next;		//Pointer to the previous node
	item* prev;		//Pointer to the next node
};
template <class T>
class list
{
private:

	item<T>* first;	// Pointer to the first node of the list
	item<T>* last;	// Pointer to the last node in the list
	int size;		// List size

	item<T>* find_element(int position) const;// Method that searches for a node by position

public:

	list() {
		first = nullptr;
		last = nullptr;
		int size = 0;
	}
	~list();
	
	void add_item_top(const T&);				// Adding a node to the top of the list
	void add_item_pos(const T&, int position);	// Adding a node to the specified position
	void add_item_end(const T&);				// Adding a node to the end of the list
	void show_all();				//output of all elements
	void show_data(int position);	//output of an element by position
	void delete_item_top();				//Deleting a node at the top of the list
	void delete_item_pos(int position);	//Deleting a node at the specified position
	void delete_item_end();				//Deleting a node at the end of the list

};
template <class  T>
list<T>::~list() //Destructor
{
	while (first)
	{
		item<T>* current = first->next;//Backup copy of the address of the next link in the list
		delete first;
		first = current;
	}
}
template <class  T>
item<T>* list<T>::find_element(int position) const// Method that searches for a node by position
{
	//The position starts from zero. That is, the first number is zero.
	item<T>* current;
	current = first;
		for (int i = 1; i <= position; ++i)//the cycle goes from the top of the list to the position
			current = current->next;

	return current;
}

template <class T>
void list<T>::add_item_pos(const T& val, int position)// Adding a node to the specified position
{

	if (position == 0)			//adding a node to the top
	{
		add_item_top(val);
	}
	else if (position == size )	//adding a node to the end
	{
		add_item_end(val);
	}
	else if (size != 0 && position > 0 && position < size )			//adding a node by position
	{
		item<T>* newitem = new item<T>;
		newitem->data = val;							//saving data
		newitem->next = find_element(position);			//finding the node at this position
		newitem->next->prev = newitem;					//inserting a new node between them
		newitem->prev = find_element((position - 1));	//finding the previous node
		newitem->prev->next = newitem;
		size++;
	}
	else
	{
		cout << "The position is incorrectly specified!" << endl;
	}
}

template <class T>
void list<T>::add_item_end(const T& val)// Adding a node to the end of the list
{
	item<T>* newitem = new item<T>;
	newitem->data = val;		//saving data
	newitem->next = nullptr;
	if (first != nullptr)		// the list is not empty
	{
		newitem->prev = last;
		last->next = newitem;
		last = newitem;
	}
	else //If the list is empty
	{
		newitem->prev = nullptr;   
		newitem->next = nullptr;  
		first = last = newitem;         //first=last=new element
	}
	size++;


}
template <class T>
void list<T>::add_item_top(const T& val)// Adding a node to the top of the list
{

	item<T>* newitem = new item<T>;
	newitem->data = val;		//saving data
	newitem->prev = nullptr;
	if (first != nullptr)		// the list is not empty
	{
		newitem->next = first;
		first->prev = newitem;
		first = newitem;
	}
	else	//If the list is empty
	{
		newitem->prev = nullptr;    
		newitem->next = nullptr;
		first = last = newitem;			//first=last=new element
	}
	size++;

}
template <class T>
void list<T>::delete_item_pos(int position)//Deleting a node at the specified position
{
	if (position == 0)				//deleting the first node
	{
		delete_item_top();
	}
	else if (position == size-1)	//deleting the last node
	{
		delete_item_end();
	}
	else if (size != 0 && position > 0 && position< size-1)//deleting a node by position
	{
		
		item<T>* current=find_element(position);	//finding its
		current->next->prev = current->prev;		//changing pointers
		current->prev->next = current->next;
		delete current;
		size--;
	}
	else
	{
		cout << "The position is incorrectly specified!" << endl;
	}

}
template <class T>
void list<T>::delete_item_top()//Deleting a node at the top of the list
{
	first->next->prev = nullptr;
	item<T>* newfirst = first->next;
	delete first;
	first = newfirst;	//now the penultimate is the last
	size--;
}
template <class T>
void list<T>::delete_item_end()//Deleting a node at the end of the list
{
	last->prev->next = nullptr;
	item<T>* newlastt = last->prev;
	delete last;
	last = newlastt;	// now the second is the first
	size--;
}
template <class T>
void list<T>::show_all()//output all elements on the screen
{
	item<T>* current = first;
	while (current != nullptr)
	{
		cout << current->data << endl;//data output of each element
		current = current->next;
	}
}
template <class T>
void list<T>:: show_data(int position)//output of an element by position
{
	if (position < size && position >= 0)
	{
		cout << (find_element(position))->data << endl;
	}
	else
	{
	cout << "The position is incorrectly specified!" << endl;
	}
}
int main()
{


	return 0;
}