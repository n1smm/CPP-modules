/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/11 14:57:09 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"


int	main(void)
{
	int a = 5;
	int b = 10;
	int	c = 5;
	std::string	foo = "hello";
	std::string faa = "mooo";

	std::cout << "original values: a-> " << a << ", b-> " << b 
		<< ", foo-> " << foo << ", faa-> " << faa << std::endl;

	swap(a, b);
	swap(foo, faa);

	std::cout << "swapped values: a-> " << a << ", b-> " << b 
		<< ", foo-> " << foo << ", faa-> " << faa << std::endl;

	swap(a, b);
	swap(foo, faa);

	std::cout << "REswapped values: a-> " << a << ", b-> " << b 
		<< ", foo-> " << foo << ", faa-> " << faa << std::endl;

	std::cout << "min/max values \n";
	std::cout << "min(a,b) = " << min(a, b) << ", max(a,b) = " << max(a,b) << std::endl;
	std::cout << "min(foo,faa) = " << min(foo, faa) << ", max(foo, faa) = " << max(foo, faa) << std::endl;

	std::cout << "same values passed to min/max" << std::endl;
	std::cout << "min(a,c) = " << min(a, c) << ", max(a,c) = " << max(a,c) << std::endl;
	
}
