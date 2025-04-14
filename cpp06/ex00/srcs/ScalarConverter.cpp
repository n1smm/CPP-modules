/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:23:54 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/31 16:33:27 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/Scalar_utils.hpp"
#include <iostream>
#include <cstdlib> 
#include <cerrno> 
#include <string.h>

//constructor - private
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter( const ScalarConverter &copy) { *this = copy; }
ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &other) {  if (this != &other) return (*this); return (*this); }
//deconstructor
ScalarConverter::~ScalarConverter() { std::cout << "scalar deconstructor\n"; }

void	ScalarConverter::convert(std::string &input)
{
	double	num;
	char	*end;
	bool	hasF = false;
	errno = 0;

	try
	{
	//check for special cases  - empty string and alpha characters
	check_empty(input);
	//check for  char or transform to double
	if (input.length() < 2)
	{
		num = input[0];
        end = const_cast<char*>(input.c_str()) + 1;
		*end = 0;
	}
	else
		num = std::strtod(input.c_str(), &end);
	//error checks
	if (errno == ERANGE)
		throw std::runtime_error("Range error occurred");
	else if (end == input)
		throw std::runtime_error("No conversion could be performed");
 	//check if f is the last char
	hasF = check_f(&end);
	//print results
	print_results(num);
	}
	catch (std::exception &e) 
		{ std::cerr << "Error: " << e.what() << hasF; }
}

