/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:18:40 by thiew             #+#    #+#             */
/*   Updated: 2024/10/18 14:12:42 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "main.hpp"

std::string	contact::format_column(std::string &input)
{
	if (input.length() > 10)
		return (input.substr(0,9) + ".");
	return (input);
}

void	contact::get_data()
{
	std::cout << YELLOW " " << "|"
		<< std::setw(10) << std::right << format_column(_first_name) << " | "
		<< std::setw(10) << std::right << format_column(_last_name) << " | "
		<< std::setw(10) << std::right << format_column(_phone_number) << " | "
		<< std::setw(10) << std::right << format_column(_darkest_secret) << RESET << std::endl;
}

std::string		contact::get_data(int search_param)
{
	switch (search_param)
	{
		case 1:
			return ("hello this is Error, who are you?");
			break;
		case 2:
			return (_first_name);
		case 3:
			return (_last_name);
		case 4:
			return (_phone_number);
		case 5:
			return (_darkest_secret);
		default:
			return ("Error here, who si phone?");
	}

}

void	contact::change_data()
{
	
    std::cout << CYAN "\nenter first_name: " RESET;
	std::cin.ignore(1, '\n');
    std::getline(std::cin, _first_name);
    std::cout << CYAN "\nenter last_name: " RESET;
    std::getline(std::cin, _last_name);
    std::cout << CYAN "\nenter phone_number: " RESET;
    std::getline(std::cin, _phone_number);
    std::cout << CYAN "\nenter darkest_secret: " RESET;
    std::getline(std::cin, _darkest_secret);
}

void	contact::change_data(std::string input, int param)
{
	switch (param)
	{
		case 1:
			_first_name = input;
			break;
		case 2:
			_last_name = input;
			break;
		case 3:
			_phone_number = input;
			break;
		case 4:
			_darkest_secret = input;
			break;
		default:
			break ;
	}
}
