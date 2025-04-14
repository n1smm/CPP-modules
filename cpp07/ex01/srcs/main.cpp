/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/06 12:15:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <vector>


int	main(void)
{
	//array checks
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	std::cout << "original array\n";
	for(int i = 0; i < 10; i++)
		std::cout << " " << array[i];
	iter(array, 10, add10<int>);
	std::cout << std::endl;
	std::cout << "modified array\n";
	for(int i = 0; i < 10; i++)
		std::cout << " " << array[i];
	std::cout << std::endl;

	//char checks
	std::cout << std::endl;
	std::cout << "original char*\n";
	char	str[6] = "hello";
	std::cout << str << std::endl;
	std::cout << "add10 char*\n";
	iter(str, 5, add10<char>);
	std::cout << str << std::endl;
	std::cout << "hello char*\n";
	iter(str, 5, hello<char>);
	std::cout << str;

	//string checks
	std::cout << std::endl;
	std::cout << "original string\n";
	std::string longish =  "lkjdfklsjalkfjdaslkf";
	std::cout << longish << std::endl;
	iter(longish, longish.length(), hello<char>);
	std::cout << "modified string \n";
	std::cout << longish << std::endl;
	std::cout << "\nmodified string - add10 \n";
	iter(longish, longish.length()-5, add10<char>);
	std::cout << longish << std::endl;

	// int array with char modifiers
	iter(array, 10, hello<int>);
	std::cout << "modified int array with hello template\n";
	for(int i = 0; i < 10; i++)
		std::cout << " " << array[i];

	//vector checks
	std::cout << "\n\nvector tests\n";
	std::vector<double> vect;
    vect.push_back(0.12);
    vect.push_back(12.33);
    vect.push_back(5.456789);
    vect.push_back(123456789.0);
    std::vector<double>::iterator last = vect.end() - 1;
	std::cout << "original vector\n";
	for (std::vector<double>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << *it;
		if (it != last)
			std::cout << ", ";
	}
	std::cout << "\n add by 10; modified vector\n";
	iter(vect, 4, add10<double>);
	for (std::vector<double>::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << *it;
		if (it != last)
			std::cout << ", ";
	}
}
