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
	
	
	cout << "\n#######################################\n";
	cout << endl;
	cout << "Тестирование кольцевой очереди (5-ть push(1-5) -> 2-a pop() 1-ый элемент становится в конец очереди -> 1 push(6) -> 1 pop()): \n";

	QueueRing<int> qr;

	qr.push(1);
	qr.push(2);
	qr.push(3);
	qr.push(4);
	qr.push(5);
	qr.print();

	cout << "getSize: ";
	cout << qr.getSize();
	cout << endl;
	
	
	qr.pop();
	qr.pop();
	qr.push(6);
	qr.pop();
	qr.print();
	cout << "getSize: ";
	cout << qr.getSize();
	cout << endl;
	cout << "Просмотр последнего элемента peek(): ";
	cout << qr.peek();
	cout << endl;
	cout << "Удаление 1-го элемента из очереди pop_front(): ";
	qr.pop_front();
	cout << endl;
	qr.print();
	cout << "getSize: ";
	cout << qr.getSize();
	cout << endl;
	cout << "Просмотр последнего элемента peek(): ";
	cout << qr.peek();
	cout << endl;
	cout << "\n#######################################\n";
	cout << endl;
	cout << "Тестирование FIFO (5-ть push() -> 2-a pop(): \n";
	Queue<int> qu;

	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);
	
	qu.print();
	cout << "getSize: ";
	cout << qu.getSize();
	cout << endl;
	qu.pop();
	qu.pop();
	
	qu.print();
	cout << "getSize: ";
	cout << qu.getSize();
	cout << endl;
	cout << "\n#######################################\n";
	cout << endl;
	cout << "Тестирование FIFO + шаблонный Arry (2-а push()): \n";
	
	Queue<MyArray<int>> q;

	MyArray<int> qa(5);
	qa.FillArrayNoSrand();

	MyArray<int> qa1(3);
	qa1.FillArrayNoSrand();

	q.push(qa);
	q.push(qa1);

	q.print();

	cout << "getSize: ";
	cout << q.getSize();
	cout << endl;
	q.clear();
	cout << "clear -> getSize: ";
	cout << q.getSize();
	cout << endl;
	cout << "\n#######################################\n";
	cout << endl;

	cout << "Тестирование очереди с приоритетом (4-а push(): (1, LOW), (2, MEGAHIGH), (3, MEDIUM), (4, MEGAHIGH) ): \n";

	QueuePriority<int> qp;


	qp.push(1, LOW);
	qp.push(2, MEGAHIGH);
	qp.push(3, MEDIUM);
	qp.push(4, MEGAHIGH);
	qp.print();

	cout << "\n#######################################\n";
	cout << endl;
	//тестирование стек + шаблонный Arry
	cout << "Тестирование стек (size = 5) + шаблонный Arry: \n";

	DynamicStack<MyArray<int>, 5> dst;


	MyArray<int> a(5);
	a.FillArrayNoSrand();

	MyArray<int> a1(3);
	a1.FillArrayNoSrand();

	cout << "Проверка - стек пустой: ";
	cout << dst.isEmpty();
	cout << endl;
	cout << "Проверка - стек полный: ";
	cout << dst.isFull();
	cout << endl;

	cout << "Делаем 2-а push(): \n";
	dst.push(a);
	dst.push(a1);

	dst.print();


	cout << "Выводим размер стека: ";
	cout << dst.getSize();
	cout << endl;
	cout << "Проверка - стек пустой: ";
	cout << dst.isEmpty();
	cout << endl;
	cout << "Проверка - стек полный: ";
	cout << dst.isFull();
	cout << endl;
	
	dst.pop();
	cout << "Делаем 1- pop() и выводим размер стека: ";
	cout << dst.getSize();
	cout << endl;
	dst.print();
	cout << "\n#######################################\n";
	cout << endl;

	
	/* тестирование Queue + шаблонный Arry
	
	Queue<MyArray<int>> q;

	MyArray<int> a(5);
	a.FillArrayNoSrand();

	MyArray<int> a1(3);
	a1.FillArrayNoSrand();

	q.push(a);
	q.push(a1);
	

	q.print();

	//q.pop();
	

	q.print();

	cout << q.getSize();
	cout << endl;
	q.clear();

	cout << q.getSize();
	*/

	cout << endl;
	system("pause");	
}