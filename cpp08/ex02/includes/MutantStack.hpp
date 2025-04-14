/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:44:32 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/12 20:49:02 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		//constructors
		MutantStack( void );
		MutantStack( const MutantStack &copy);
		~MutantStack( void );
		//overload
		MutantStack	&operator=(const MutantStack &other);	

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rev_begin();
		reverse_iterator rev_end();
		const_reverse_iterator rev_begin() const;
		const_reverse_iterator rev_end() const;
};

#include "MutantStack.tpp"







