#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class T>
class Vector
{
public:
	Vector();
	Vector(const int &n);
	Vector(const int &n, T elem);
	~Vector();

	void assert(const int &n, T elem);
	T &operator[](const int &index) const;
	void push_back(T elem);
	unsigned int size() const;
	void erase(const int &idx);

private:
	unsigned int capacity;
	unsigned int maxsize;
	T *data;
};

template <class T>
void Vector<T>::assert(const int &n, T elem)
{
	for (int i = 0; i < n; i++)
	{
		data[i] = elem;
	}
}

template <class T>
T &Vector<T>::operator[](const int &index) const
{
	return data[index];
}

template <class T>
void Vector<T>::push_back(T elem)
{
	if (data == 0)
	{
		maxsize = 1;
		data = new T[maxsize];
	}
	if (capacity == maxsize)
	{
		maxsize = maxsize * 2;
		T *new_data = new T[maxsize];
		for (int i = 0; i < capacity; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
	}
	data[capacity] = elem;
	capacity++;
};

template <class T>
unsigned int Vector<T>::size() const
{
	return capacity;
}


template <class T>
void Vector<T>::erase(const int &idx)
{
    for (size_t i = idx; i < capacity - 1; ++i)
		data[i] = data[i + 1];

	capacity--;
}

template <class T>
Vector<T>::Vector()
{
	capacity = 0;
	maxsize = 0;
	data = 0;
}

template <class T>
Vector<T>::Vector(const int &n)
{
	capacity = n;
	maxsize = n;
	data = new T[capacity];
	assert(n, T());
}

template <class T>
Vector<T>::Vector(const int &n, T elem)
{
	capacity = n;
	maxsize = n;
	data = new T[capacity];
	assert(n, elem);
}

template <class T>
Vector<T>::~Vector()
{
	delete[] data;
}

#endif