/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:33:10 by thiew             #+#    #+#             */
/*   Updated: 2025/01/12 00:43:14 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//constructors
template <typename T>
					Array<T>::Array() : _array(NULL), _size(0) { std::cout << "def constructor\n"; }

template <typename T>
					Array<T>::Array( unsigned int n ) : _array(new T[n]), _size(n) { std::cout << "arg construct\n"; }

template <typename T>
					Array<T>::Array( const Array &copy) : _array(new T[copy._size]), _size(copy._size) 
{ 
	std::cout << "copy sonctruct\n";
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
					Array<T>::~Array() { delete[] _array; std::cout << "deconstruct\n"; }


//overloads
template <typename T>
Array<T>			&Array<T>::operator=( const Array &other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T					&Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBounds();
	return (_array[i]);

}

//method
template <typename T>
unsigned	int 	Array<T>::size() { return (_size); }


//exception
template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Error: Array index out of bounds";
}
