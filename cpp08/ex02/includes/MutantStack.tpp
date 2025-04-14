#pragma once
//constructors
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};
template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
template<typename T>
MutantStack<T>::~MutantStack() {}
template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &other)
{ 
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

//begin iterator implementations
template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::begin()
{ return std::stack<T>::c.begin(); }
template<typename T>
typename	MutantStack<T>::const_iterator MutantStack<T>::begin() const
{ return std::stack<T>::c.begin(); }
template<typename T>
typename	MutantStack<T>::reverse_iterator MutantStack<T>::rev_begin()
{ return std::stack<T>::c.rbegin(); }
template<typename T>
typename	MutantStack<T>::const_reverse_iterator MutantStack<T>::rev_begin() const
{ return std::stack<T>::c.rbegin(); }

//end iterator implementations
template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::end()
{ return std::stack<T>::c.end(); }
template<typename T>
typename	MutantStack<T>::const_iterator MutantStack<T>::end() const
{ return std::stack<T>::c.end(); }
template<typename T>
typename	MutantStack<T>::reverse_iterator MutantStack<T>::rev_end()
{ return std::stack<T>::c.rend(); }
template<typename T>
typename	MutantStack<T>::const_reverse_iterator MutantStack<T>::rev_end() const
{ return std::stack<T>::c.rend(); }

