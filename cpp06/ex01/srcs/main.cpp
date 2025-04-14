/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/10 14:18:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"



int	main(void)
{
	Data	wrooom = { 12, "mooo", {0}};
	for (int i = 0; i < 10; i++)
		wrooom.sleep[i] = static_cast<double>(i);

	std::cout << "data and address of wroom struct\n";
	std::cout << wrooom;
	std::cout << &wrooom << "\n";
	std::cout << "---------------------------\n";
	
	uintptr_t ptr = Serializator::serialize(&wrooom);
	std::cout << "serialized value of data ptr  " << ptr << "\n";
	std::cout << "---------------------------\n";
	Data *newData = Serializator::deserialize(ptr);
	std::cout << "values and address of new pointer after deserialization\n";
	std::cout << newData << "\n";
	std::cout << *newData;
	std::cout << "---------------------------\n";
	std::cout << (newData == &wrooom ? "\033[32mthe addresses are the same!" : "\033[31mthe addresses are different") << "\033[0m\n";




}
