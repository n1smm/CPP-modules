/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:35 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/11 14:44:47 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
		a = b;
		b = tmp;
}

template<typename T>
T	min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T	max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}


