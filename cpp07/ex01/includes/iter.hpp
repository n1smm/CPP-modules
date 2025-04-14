/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:35 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/11 16:51:50 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


template<typename T, typename T_function>
void	iter(T &array, size_t size, T_function func)
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template<typename T>
void	add10(T &i)
{
	i += 10;
}

template<typename T>
void	hello(T &i)
{
	static int	elem;
    T array[12] = {'h', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd'};
	i = array[elem];
	elem++;
	if (elem > 11)
		elem = 0;
}
