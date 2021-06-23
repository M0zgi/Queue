#include"Queue.h"
#include "Stack.h"
#include"TemplateArray.h"
#include"MyData.h"


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	/* тестирование стек + шаблонный Arry
	
	DynamicStack<MyArray<int>, 5> dst;


	MyArray<int> a(5);
	a.FillArrayNoSrand();

	MyArray<int> a1(3);
	a1.FillArrayNoSrand();

	cout << dst.isEmpty();
	cout << endl;
	cout << dst.isFull();
	cout << endl;
	dst.push(a);
	dst.push(a1);

	dst.print();
	cout << endl;
	cout << dst.getSize();
	cout << endl;
	cout << dst.isEmpty();
	cout << endl;
	cout << dst.isFull();
	cout << endl;
	
	dst.pop();
	cout << dst.getSize();
	cout << endl;
	dst.print();
	*/

	Queue<MyArray<int>> q;

	MyArray<int> a(5);
	a.FillArrayNoSrand();

	MyArray<int> a1(3);
	a1.FillArrayNoSrand();

	q.push(a);
	q.push(a1);
	

	q.print();

	q.pop();
	

	q.print();

	cout << endl;
	system("pause");
}