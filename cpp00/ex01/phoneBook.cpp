/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:55 by thiew             #+#    #+#             */
/*   Updated: 2024/10/18 13:00:10 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include "main.hpp"

void	phoneBook::add(contact &first)
{
	_contacts[_index] = first;
	_index = (_index + 1) % size();
}

void	phoneBook::get_data()
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << CYAN "contact:" << i << RESET;
		_contacts[i].get_data();
	}
}

void	phoneBook::get_data(int i)
{
	_contacts[i].get_data();
}

std::string phoneBook::get_data(int i, int search_param)
{
	std::string	ret_index;

	ret_index.push_back(i + 48);
	switch (search_param)
	{
		case 1:
			if (i < 8)
			{
				return (ret_index);
			}
			else
			{
				std::cout << CYAN "invalid index, maybe try 0 to 7, but who am i to"
					" tell you what to do...\n" RESET;
				return (ret_index);
			}
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			return (_contacts[i].get_data(search_param));
		default:
			std::cout << CYAN "what you thought this contact actually exists??? phahahah\n" RESET;
	}
	return ("invalid something");
}

std::string	phoneBook::get_index()
{
	std::string	str_index;
	char	c;

	c = _index + 48;
	str_index += c;
	return (str_index);
}
	

