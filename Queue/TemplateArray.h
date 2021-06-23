#pragma once

#include<iostream>
#include <Windows.h>
#include<string>
#include<typeinfo>

using namespace std;


struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "������"; }
	std::string do_falsename() const { return "������"; }
};

template<class T>
class MyArray
{
public:

	//����������� ��� ����������
	MyArray(){}
	
	//����������� �������� ������� � ����� ����������

	explicit MyArray(int s);

	//����������� �����������

	MyArray(const MyArray& obj);

	//�������� ������������ =
	MyArray& operator = (const MyArray& obj);

	//�������� Array + int ��������� �������� � ����� �������
	MyArray operator + (T n);

	//�������� Array + Array
	MyArray operator + (const MyArray& obj);

	//�������� Array += Array (�������� ����������� �������� ��������)
	void operator += (const MyArray& obj);

	//�������� Array -= Array (�������� ����������� �������� ��������)
	void operator -= (const MyArray& obj);

	//�������� ��������� ==
	bool operator == (const MyArray& obj);

	//�������� ����������� !=
	bool operator != (const MyArray& obj);

	//�������� ������ > ��������� ���������� �� ����� ��������� ��������
	bool operator > (const MyArray& obj);

	//�������� ������ < ��������� ���������� �� ����� ��������� ��������
	bool operator < (const MyArray& obj);

	//�������� ��������� �������� ������������ ������� �� �������
	T operator [] (int index) const;

	//�������� ��������� �������� ������� �� �������
	T& operator [] (int index);

	//�������� Array * Array ������� ������ � ������ ���������� ���������� ���� ��������
	MyArray operator * (const MyArray& obj);

	//�������� Array % Array ������� ������ � ���������� �������������� ���������� ���� ��������
	MyArray operator % (const MyArray& obj);



	//�������
	int GetSize();

	//����������
	~MyArray();

	//����� ������� �� �����
	void print() const;

	//���������� �������
	void FillArrayNoSrand();

	template<class T>
	friend MyArray<T> operator+(T n, const MyArray<T>& obj);

	template<class T>
	friend ostream& operator << (ostream& out, const MyArray<T>& obj);

	template<class T>
	friend istream& operator >> (istream& in, const MyArray<T>& obj);

private:

	T* array = nullptr;
	int size = 0;

};


template<class T>
MyArray<T>::MyArray(int s)
{
	if (s > 0)
	{
		size = s;
		array = new T[size];
	}
}


template<class T>
inline MyArray<T>::MyArray(const MyArray<T>& obj)
{
	size = obj.size;

	array = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (array != nullptr)
	{
		delete[] array;
	}

	size = obj.size;

	array = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator+(T n)
{
	MyArray<T> temp = MyArray<T>(size + 1);

	for (size_t i = 0; i < size; i++)
	{
		temp.array[i] = array[i];
	}

	temp.array[size] = n;

	return temp;
}

template<class T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& obj)
{

	MyArray<T> temp = MyArray<T>(size + obj.size);

	for (size_t i = 0; i < size; i++)
	{
		temp.array[i] = array[i];
	}

	for (size_t i = 0; i < obj.size; i++)
	{
		temp.array[size + i] = obj.array[i];
	}

	return temp;
}



template<class T>
inline void MyArray<T>::operator+=(const MyArray<T>& obj)
{
	if (size >= obj.size)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			array[i] = array[i] + obj.array[i];
		}

	}

	else
	{
		MyArray<T> temp = MyArray<T>(obj.size);

		for (size_t i = 0; i < size; i++)
		{
			temp.array[i] = array[i] + obj.array[i];

		}

		for (size_t i = 0; i < obj.size - size; i++)
		{
			temp.array[size + i] = obj.array[size + i];
		}

		if (array != nullptr)
			delete[]array;

		size = obj.size;
		array = new T[size];

		for (size_t i = 0; i < size; i++)
		{
			array[i] = temp.array[i];
		}
	}
}

template<class T>
inline void MyArray<T>::operator-=(const MyArray& obj)
{
	if (size >= obj.size)
	{
		for (size_t i = 0; i < obj.size; i++)
		{
			array[i] = array[i] - obj.array[i];
		}
	}

	else
	{
		MyArray<T> temp = MyArray<T>(obj.size);

		for (size_t i = 0; i < size; i++)
		{
			temp.array[i] = array[i] - obj.array[i];
			cout << temp.array[i] << " ";
		}

		for (size_t i = 0; i < obj.size - size; i++)
		{
			temp.array[size + i] = 0 - obj.array[size + i];
		}

		if (array != nullptr)
			delete[]array;

		size = obj.size;
		array = new T[size];

		for (size_t i = 0; i < size; i++)
		{
			array[i] = temp.array[i];
		}
	}
}

template<class T>
bool MyArray<T>::operator==(const MyArray<T>& obj)
{
	if (size != obj.size)
		return false;

	else
	{
		int count = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == obj.array[i])
				count++;
		}

		return count == size;
	}
}

template<class T>
bool MyArray<T>::operator!=(const MyArray<T>& obj)
{
	if (size != obj.size)
		return true;

	else
	{
		int count = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == obj.array[i])
				count++;
		}

		return !(count == size);
	}
}

template<class T>
bool MyArray<T>::operator>(const MyArray<T>& obj)
{
	int sum1 = 0, sum2 = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum1 += array[i];
		sum2 += obj.array[i];
	}

	return sum1 > sum2;
}

template<class T>
bool MyArray<T>::operator<(const MyArray<T>& obj)
{
	int sum1 = 0, sum2 = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum1 += array[i];
		sum2 += obj.array[i];
	}

	return sum1 < sum2;
}

template<class T>
T MyArray<T>::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cout << "���������� ������� ��� � �������: " << index;

		return index;
	}

	else
		return array[index];
}

template<class T>
T& MyArray<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		cout << "���������� ������� ��� � �������: " << index;

		return index;
	}

	else
		return array[index];
}

template<class T>
MyArray<T> MyArray<T>::operator*(const MyArray<T>& obj)
{
	int count = 0, countsize = 0, key = 0;

	MyArray<T> temp = MyArray<T>(size + obj.size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < obj.size; j++)
		{
			if (array[i] == obj.array[j])
			{
				count++;
			}

			if (count > 0)
			{

				for (size_t k = 0; k < countsize; k++)
				{
					if (array[i] == temp.array[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					temp.array[countsize] = array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}

	for (size_t i = 0; i < obj.size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (obj.array[i] == array[j])
			{
				count++;
			}

			if (count > 0)
			{
				for (size_t k = 0; k < countsize; k++)
				{
					if (obj.array[i] == temp.array[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					temp.array[countsize] = obj.array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}

	MyArray<T> result = MyArray<T>(countsize);
	for (size_t i = 0; i < countsize; i++)
	{
		result.array[i] = temp.array[i];
	}

	return result;

}

template<class T>
MyArray<T> MyArray<T>::operator%(const MyArray<T>& obj)
{

	int count = 0, countsize = 0, key = 0;

	MyArray<T> temp = MyArray<T>(size + obj.size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < obj.size; j++)
		{
			if (array[i] != obj.array[j])
			{
				count++;
			}

			if (count == obj.size)
			{

				for (size_t k = 0; k < countsize; k++)
				{
					if (array[i] == temp.array[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					temp.array[countsize] = array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}

	for (size_t i = 0; i < obj.size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (obj.array[i] != array[j])
			{
				count++;
			}

			if (count == size)
			{
				for (size_t k = 0; k < countsize; k++)
				{
					if (obj.array[i] == temp.array[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					temp.array[countsize] = obj.array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}

	MyArray<T> result = MyArray<T>(countsize);
	for (size_t i = 0; i < countsize; i++)
	{
		result.array[i] = temp.array[i];
	}

	return result;
}

template<class T>
int MyArray<T>::GetSize()
{
	return size;
}

template<class T>
MyArray<T>::~MyArray()
{
	delete[] array;
}

template<class T>
void MyArray<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

template<class T>
void MyArray<T>::FillArrayNoSrand()
{
	for (size_t i = 0; i < size; i++)
	{
		if (typeid(T).name() == (string)"int")
			array[i] = rand() % 100;
		if (typeid(T).name() == (string)"float" || typeid(T).name() == (string)"double")
			array[i] = (rand() % 1000) / 10.;
		if (typeid(T).name() == (string)"char")
			array[i] = ('a' + rand() % ('z' - 'a'));
	}
}

//������������� ������� ���������� ��������� + (int + Array) ��������� �������� � ������ �������

template<class T>
MyArray<T> operator+(T n, const MyArray<T>& obj);

//������������� ������� ���������� cout
template<class T>
ostream& operator << (ostream& out, const MyArray<T>& obj);

//������������� ������� ���������� cin
template<class T>
istream& operator >> (istream& in, const MyArray<T>& obj);

template<class T>
MyArray<T> operator+(T n, const MyArray<T>& obj)
{
	MyArray<T> temp(obj.size + 1);
	temp.array[0] = n;

	for (size_t i = 0; i < obj.size; i++)
	{
		temp.array[i + 1] = obj.array[i];
	}

	return temp;
}

template<class T>
ostream& operator<<(ostream& out, const MyArray<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		out << obj.array[i] << " ";
	}

	out << endl;

	return out;
}

template<class T>
istream& operator>>(istream& in, const MyArray<T>& obj)
{
	cout << "������� �������� ��� ������ ������� ����������� " << obj.size << " ���������: ";

	for (size_t i = 0; i < obj.size; i++)
	{
		in >> obj.array[i];
	}

	return in;
}