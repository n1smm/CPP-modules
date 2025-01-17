/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:51 by thiew             #+#    #+#             */
/*   Updated: 2025/01/17 14:24:03 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "phoneBook.hpp"


std::string	random_name()
{
	std::string	output;

	for (int i = 0; i < 5; i++)
	{
		int c = 65 + (rand() % 26);
		output.push_back(c);

	}
	return (output);
}


void	populate_contacts(phoneBook &phoneBook)
{
	contact		temp;
	std::string	random_str;

	srand(time(0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			random_str = random_name();
			temp.change_data(random_str, j);
		}
		phoneBook.add(temp);
	}

}

void	first_line()
{

	std::cout <<  RED << std::setw(10) << std::right << "index" << "|"
		<< std::setw(10) << std::right << "first_name" << " | "
		<< std::setw(10) << std::right << "last_name" << " | "
		<< std::setw(10) << std::right << "phone_num" << " | "
		<< std::setw(10) << std::right << "darkest_secret" RESET << std::endl;
}

void	searching(int search_param, phoneBook &phoneBook)
{
	std::string	contact_param;
	bool		match = false;

	if (search_param == 6)
	{
		first_line();
		phoneBook.get_data();
		return ;
	}
	if (search_param > 6 || search_param < 1)
	{
		std::cout << CYAN "wow, you can type. Good for you. Now you can maybe"
			" learn to follow instructions.\n\n" RESET;
		return ;
	}
	std::cout << CYAN " write your search keyword: " RESET;
	std::cin >> contact_param;
	std::cout << std::endl;
	first_line();
	for (int i = 0; i < 8; i++)
	{
		if (contact_param == phoneBook.get_data(i, search_param))
		{
			std::cout << CYAN "index " << i << "  " RESET;
			phoneBook.get_data(i);
			match = true;
			break ;
		}
	}
	if (match == false)
		std::cout << CYAN "invalid search_param\n\n" RESET;
}

void	exit_function()
{
	std::string input = "hello";

	std::cout << CYAN "You are exiting the phoneBook. All contacts will be lost. "
		"Continue? (y/n): \n" RESET;
	while (input != "n" && input != "no" && input != "y" && input != "yes")
	{
		std::cout << "> ";
		std::cin >> input;
		if (input == "n" || input == "no")
			return ;
		else if (input == "y" || input == "yes")
		{
			std::cout << BOLD_WHITE "\nclosing and erasing the phoneBook...\n" RESET;
			exit(0);
		}
		else
			std::cout << CYAN "yes or no?!!! it's not that hard!\n" RESET;
	}
}

int	main(void)
{

	contact	contact;
	phoneBook	phoneBook;
	std::string	input;
	char	str_param[1024];

	populate_contacts(phoneBook);
	std::cout << BOLD_WHITE INTRO RESET;
	do
	{
		std::cout << BOLD_GREEN MAIN_QUESTION RESET;
		if(!(std::cin >> input))
		{
			std::cout << "Input error or EOF detected. Exiting..." << std::endl;
			break;
		}
		if (input == "ADD")
		{
			contact.change_data();
			phoneBook.add(contact);
		}
		else if (input == "SEARCH")
		{
			std::cout << CYAN SEARCH_PARAMS RESET;
			std::cin >> str_param;
			std::cout << std::endl;
			int	int_param = atoi(str_param);
			searching(int_param, phoneBook);

		}
		else if (input == "EXIT")
			exit_function();
		else
			std::cout << CYAN " you have 3 options: ADD, SEARCH or EXIT."
				" Nothing is real, everything else is forbidden" RESET << std::endl;
	}
	while (1);
}
