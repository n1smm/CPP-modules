/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:33:15 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/31 16:49:27 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Scalar_utils.hpp"
#include <string>
#include <cctype>

std::string		uppedCase(std::string &input)
{
	std::string res(input.length(), 0);
	for (size_t i = 0; i < input.length(); i++)
		res[i] = std::toupper(input[i]);
	return (res);
}

bool	check_naan(std::string &input)
{
	std::string	naans[8] = {"nan", "-nan", "nanf", "-nanf", "inf", "-inf", "inff", "-inff"};
	for (int i = 0; i < 8; i++)
	{
		if (input == naans[i] || uppedCase(input) == uppedCase(naans[i]))
		{
			std::cout << naans[i];
				return (true);
		}
	}
	return (false);
}

void	check_empty(std::string &input)
{
	int	alpha = 0;

	if (input[0] == 0)
	{
		std::cout << " empty string passed as parameter \n";
		throw	std::runtime_error("empty string");
	}
	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (std::isalpha(input[i]))
				alpha ++;
	}
	if (alpha > 1 && !check_naan(input))
		throw	std::runtime_error("No conversion could be done, to many alpha characters");
}

bool	check_f(char **end)
{
	if ( *end[0] && **end == 'f' && !*(*end + 1))
	{
		**end = 0;
		return  (true);
	}
	return (false);
}

static	bool	check_special_case(double num)
{
	double		all_cases[3] = {NAN, -INFINITY, INFINITY};

	if (std::isnan(num))
		return (true);

	for (int i = 0; i < 3 ; i++)
	{
		if (num == all_cases[i])
			return (true);
	}
	return (false);
}

// return 0 if no limit-break, 1 for char, 2 for int, 3 for both
int	out_of_bound(double num)
{
	int	i = 0;
	if (		num > std::numeric_limits<int>::max() 
			||	num < std::numeric_limits<int>::min())
		i += 2;
	if (num > 127 || num < 32)
		i += 1;
	return (i);
}

void	write_special(double num, std::string result[])
{
	std::ostringstream	oss;
	std::string			strNum;

	oss << num;
	strNum = oss.str();
	result[0] += "impossible";
	result[1] += "impossible";
	result[2] += strNum + "f";
	result[3] += strNum;
}


void	write_num(double num, std::string result[])
{
	std::ostringstream	oss;
	std::string			strNum;
	int					problem;

	problem = out_of_bound(num);

	//char
	char numC = static_cast<char>(num);
	oss << numC;
	strNum = oss.str();
	result[0] += (problem > 0 ? "unprintable" : strNum);

    oss.str("");
    oss.clear();

	//int
	int	numI = static_cast<int>(num);
	oss << numI;
	strNum = oss.str();
	result[1] += (problem > 1 ? "out of bound" : strNum);

    oss.str("");
    oss.clear();

	//float
	float numF = static_cast<float>(num);
	oss << numF;
	strNum = oss.str();
	result[2] += strNum + "f";

    oss.str("");
    oss.clear();

	//double
	oss << num;
	strNum = oss.str();
	result[3] += strNum;

}

void	print_results(double num)
{
	std::string result[4] = { "char: ", "int: ", "float: ", "double: " };

	if (check_special_case(num))
		write_special(num, result);
	else
		write_num(num, result);
	for (int i = 0; i < 4; i++)
		std::cout << result[i] << "\n";
}
