#pragma once
#include <iostream>
#include <cstddef>
#include <algorithm>

template<typename T>
class Vector
{
private:
	T* data;
	std::size_t size_;
	std::size_t capacity;
public:
	Vector();
	Vector(std::size_t size);
	~Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& v);
	friend std::istream& operator>>(std::istream& in,  Vector<T>& v);
	void push_back(T elem);
	void push_front(T elem);
	void pop_back();
	void pop_front();
	void reverse();
	const T operator[](std::size_t index) const;
	T& operator[](std::size_t index);
	std::size_t size() const;
	class iterator;
private:
	void resize();
};

template<typename T>
Vector<T>::Vector()
{
	size_ = 0;                                     // constructor
	capacity = 1;                          
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(std::size_t size)
{
	size_=size;                                   // constructor with vector size
	capacity = size;
	data = new T[size]{};
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
	:size_(other.size_)
	, capacity(other.capacity)
	, data(new T[capacity])                       // copy constructor
{
for (std::size_t i = 0; i < size_; ++i)
	   data[i] = other.data[i];
}

template<typename T>
class Vector<T>::iterator
{
private:
	T* ptr;
};

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other) return *this;                    
	delete[] data;                                          //  operator=
	size_ = other.size_;
	capacity = other.capacity;
	data = new T[capacity];
	for (std::size_t i = 0; i < size_; ++i)
		data[i] = other.data[i];
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{                                       // destructor()
	delete[] data;
}

template<typename T>
void Vector<T>::push_back(T elem)
{
	resize();
	data[size_] = elem;                          // push_back() 
	++size_;
}

template<typename T>                                    
void Vector<T>::push_front(T elem)
{
	resize();
	
	for (std::size_t i = size_; i > 0; --i)         // push_front()
		data[i] = data[i - 1];
	
	data[0] = elem;
	++size_;
}

template<typename T>                                    
void Vector<T>::pop_back()
{
	if (size_ > 0)                         // pop_back
	--size_;
	data[size_].~T();
}

template<typename T>                                    
const T Vector<T>::operator[](std::size_t index) const
{   
	if (index >= size_)                                          // const data[index]
		throw std::out_of_range("Index out of range");
	                                                           
	return data[index];
}

template<typename T>
T& Vector<T>::operator[](std::size_t index)
{                                                      // data[index]
	if (index >= size_) {
		exit(1);
		throw std::out_of_range("Index out of range");
	}
	 return data[index];
 }


template<typename T>
std::size_t Vector<T>::size() const
{                                          // size()
	return size_;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
{
	for (std::size_t i = 0; i < v.size(); ++i)                      // operator<<
		out << v[i] << " ";
	return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, Vector<T>& v)
{
	T elem;
	while (in >> elem)                                      // operator>>
		in >> v[elem];
	return in;
}

template<typename T>
void Vector<T>::reverse()
{
	std::size_t j = size_-1;
	for (std::size_t i = 0; i < size_ / 2; ++i)        // reverse()
	{
		std::swap(data[i], data[j--]);
	}
}

template<typename T>
void Vector<T>::resize()
{
	if (capacity == size_)
	{
		capacity *= 2;
		T* new_data = new T[capacity];
		for (std::size_t i = 0; i < size_; ++i)           // resize()  
		{
				new_data[i] = data[i];
		}
		delete[]data;
		data = new_data;
	}
}
