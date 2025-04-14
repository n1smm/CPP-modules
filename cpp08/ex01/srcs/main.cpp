/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:43 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/06 14:40:36 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"
#include <ctime>
#include <iomanip>

int	main()
{
	srand(time(0));

	//basic tests
	try
	{
		clock_t start = clock();
		Span	span(20);
		span.addNumber(20);
		span.printVect();
		for (int i = 0; i < span.size() -1; i++)
			span.addNumber(static_cast<int>(floor(rand() / 100)));
		span.printVect();
		std::cout << "longest span: " << span.longestSpan() << 
			", shortest span: " << span.shortestSpan() << "\n";
		clock_t end = clock();
		double	duration = static_cast<double>(end - start) / (CLOCKS_PER_SEC * 1) ;
		std::cout << std::fixed << std::setprecision(6);
		std::cout << "execution time: " << duration << "\n";
		//outofbound exception
		span.addNumber(111);
	} catch (std::exception &e)
	{ std::cout << e.what(); }

	//big container
	try
	{
		clock_t start = clock();
		Span	big(INT_MAX / 1000);
		for (int i = 0; i < big.size(); i++)
			big.addNumber(static_cast<int>(floor(rand())));
		std::cout << "\nbig container:: size: " << big.size() << "\n";
		std::cout << "longest span: " << big.longestSpan() << 
			", shortest span: " << big.shortestSpan() << "\n";
		clock_t end = clock();
		double	duration = static_cast<double>(end - start) / (CLOCKS_PER_SEC * 1) ;
		std::cout << std::fixed << std::setprecision(6);
		std::cout << "execution time: " << duration << "\n";
	} catch (std::exception &e)
	{ std::cout << e.what(); }

	//no element
	clock_t start = clock();
	try
	{
		Span	noElement(10);
		noElement.printVect();
		std::cout << "\nempty container\n vector content: ";
		noElement.printVect();
		std::cout << "longest span: " << noElement.longestSpan() << 
			", shortest span: " << noElement.shortestSpan() << std::endl;
	} catch (std::exception &e)
	{ std::cout << e.what(); }
	clock_t end = clock();
	std::cout << std::fixed << std::setprecision(6);
	double	duration = static_cast<double>(end - start) / (CLOCKS_PER_SEC * 1) ;
	std::cout << "execution time: " << duration << "\n";
}
