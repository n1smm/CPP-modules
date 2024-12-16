/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:36 by thiew             #+#    #+#             */
/*   Updated: 2024/10/07 17:52:05 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cctype>

std::string	to_upper( std::string input)
{
	std::string	result;

	for (size_t i = 0; i < input.size(); i++)
		result += toupper(input[i]);
	return (result);
}

std::string	arg_to_string(char *argv[])
{
	std::ostringstream	result;

	for (int i = 1; argv[i]; i++)
		result << argv[i];
	std::string	output = result.str();
	return (output);
}

int	main(int argc, char *argv[])
{
	std::string	args;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	args = arg_to_string(argv);
	args = to_upper(args);
	std::cout << args << std::endl;
	return (0);
}

