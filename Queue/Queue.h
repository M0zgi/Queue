#pragma once

#include"MyData.h"
#include"TemplateArray.h"


//QueueRing кольцевая очередь по принципу "элемент, который выходит из начала очереди, будет перемещён в её конец."

template<class T>
class QueueRing
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int size = 0;

public:
	~QueueRing();
	void push(T val);
	T pop();
	T pop_front();//извлечение первого элемента
	T peek();
	int getSize();
	void clear();
	void print() const;
};

template<class T>
inline QueueRing<T>::~QueueRing()
{
	clear();
}

template<class T>
inline void QueueRing<T>::push(T val)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		last = first;
	}

	else
	{
		MyData<T>* temp = new MyData<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}

	size++;
}

template<class T>
inline T QueueRing<T>::pop()
{
	if (size == 0)
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}	

	T val = first->value;

	if (size == 1)
	{
		return val;
	}	

	else
	{		
		/*MyData<T>* temp = new MyData<T>;
		temp->value = first->value;		
		last->next = temp;
		last = temp;

		MyData<T>* temp1 = first->next;
		delete first;
		first = temp1;	*/	

		MyData<T>* temp = first;
		first = first->next ;
		last->next = temp;
		last = temp;
		temp->next = nullptr;
	}

	return val;
}

template<class T>
inline T QueueRing<T>::pop_front()
{
	if (size == 0)
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}

	T val = first->value;

	if (size == 1)
	{		
		delete first;
		first = last = nullptr;		
	}

	else
	{

		MyData<T>* temp = first;
		first = first->next;
		delete temp;
	}

	size--;

	return val;
}

template<class T>
inline T QueueRing<T>::peek()
{
	if (size > 0)
	{
		return last->value;
	}

	else
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}
}

template<class T>
inline int QueueRing<T>::getSize()
{
	return size;
}

template<class T>
inline void QueueRing<T>::clear()
{
	/*MyData<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
		size--;
	}*/

	while (size)
		pop_front();
	first = last = nullptr;
}

template<class T>
inline void QueueRing<T>::print() const
{
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}



//FIFO очередь по принципу "Кто первый пришел, тот первый ушел"
template<class T>
class Queue
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int size = 0;

public:
	~Queue();
	void push(T val);
	T pop();
	T peek();
	int getSize(); 
	void clear(); 
	void print() const;
};

template<class T>
inline Queue<T>::~Queue()
{
	clear();
}

template<class T>
inline void Queue<T>::push(T val)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		last = first;
	}

	else
	{
		MyData<T>* temp = new MyData<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}
	size++;
}

template<class T>
inline T Queue<T>::pop()
{
	if (size == 0)
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}

	T val = first->value;

	if (size == 1)
	{		
		delete first;
		first = last = nullptr;
	}

	else
	{
		MyData<T>* temp = first;
		first = first->next;
		delete temp;
	}

	size--;

	return val;
}

template<class T>
inline T Queue<T>::peek()
{
	if (size > 0)
	{
		return first->value;
	}

	else
	{
		cout << "Очередь пустая!";
		system("pause");
		exit(1);
	}
}

template<class T>
inline int Queue<T>::getSize()
{
	return size;
}

template<class T>
inline void Queue<T>::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}

template<class T>
inline void Queue<T>::print() const
{
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


//Очередь с приоритетом

template<class T>
class QueuePriority
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int size = 0;

public:
	~QueuePriority();
	void push(T val, PRIORITY pri);
	T pop();
	T peek();
	int getSize();     //получение текущего размера
	void clear();      //очистка стека
	void print() const;

};

template<class T>
inline QueuePriority<T>::~QueuePriority()
{
	clear();
}

template<class T>
inline void QueuePriority<T>::push(T val, PRIORITY pri)
{
	if (size == 0)
	{
		first = new MyData<T>;
		first->value = val;
		first->pri = pri;
		last = first;
	}
	else
	{
		MyData<T>* temp = new MyData<T>;
		temp->value = val;
		temp->pri = pri;
		MyData<T>* temp2 = first;
		if (last->pri >= pri)
		{
			last->next = temp;
			last = temp;
		}
		else
		{
			if (pri > first->pri)
			{
				temp->next = first;
				first = temp;
			}
			else
			{
				while (temp2->pri >= pri && temp2->next->pri >= pri)
				{
					temp2 = temp2->next;
				}
				temp->next = temp2->next;
				temp2->next = temp;
			}
		}
	}
	size++;
}

template<class T>
inline T QueuePriority<T>::pop()
{
	if (size == 0)
	{
		cout << "Queue is empty!!!" << endl;
		system("pause");
		exit(1);
	}

	T val = first->value;
	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		MyData<T>* temp = first;
		first = first->next;
		delete temp;
	}
	size--;
	return val;
}

template<class T>
inline T QueuePriority<T>::peek()
{
	if (size > 0)
	{
		return first->value;
	}
	else
	{
		cout << "Queue is empty!!!" << endl;
		system("pause");
		exit(1);
	}
}

template<class T>
inline int QueuePriority<T>::getSize()
{
	return size;
}

template<class T>
inline void QueuePriority<T>::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}

template<class T>
inline void QueuePriority<T>::print() const
{
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}