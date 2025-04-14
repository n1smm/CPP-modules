/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:52:29 by thiew             #+#    #+#             */
/*   Updated: 2025/02/24 00:33:10 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"
#include <ctime>

std::vector<int> 	mtxToVect(std::string &input)
{
	std::istringstream	iss(input);
	std::string			buff;
	std::string			number_string;
	std::vector<int>		out;

	while (std::getline(iss, buff))
	{
		std::istringstream	word_iss(buff);
		while (std::getline( word_iss, number_string, ' '))
		{
			if (number_string.empty())
				continue ;
			if (!isValidNum(number_string))
				throw std::runtime_error("wrong input at [" + number_string + "]\n");
			out.push_back(atoi(number_string.c_str()));
		}
	}
	return (out);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "you can use the program like this: [" << argv[0] << "] [\"1 9 4 5 6\"]\n"
			<< "or first run make generate and then: [" << argv[0]
			<< "] <\"$(./randomNumGenerator [quantity][min][max])\">\n";
		return (1);
	}

	try
	{
		std::string			input(argv[1]);
		std::vector<int>	original = mtxToVect(input);
		std::vector<int>	my_sort;
		std::deque<int> 	my_deque;
		std::deque<int>		original_deque;

		//LOGIC

		//vector
		clock_t	start = clock();
		my_sort = PmergeMe::MergeVector(input);
		clock_t end = clock();
		double execution_time_vect = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		//deque
		start = clock();
		my_deque = PmergeMe::MergeDeque(input);
		end = clock();
		double execution_time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		//original vector
		start = clock();
		std::sort(original.begin(), original.end());
		end = clock();
		double execution_time_original = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		//original deque
		start = clock();
		std::sort(original_deque.begin(), original_deque.end());
		end = clock();
		double execution_time_original_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;


		//PRINTS
		std::cout << "original input:       " << argv[1] << std::endl;
		std::cout << std::endl;
		std::cout << "my sort:              ";
		for (size_t i = 0; i < my_sort.size(); i++)
			std::cout << my_sort[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "original sort vector: ";
		for (size_t i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "my deque:             ";
		for (size_t i = 0; i < my_deque.size(); i++)
			std::cout << my_deque[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "numbers missing: ";
		for (size_t i = 0; i < original.size(); i++)
		{
			if (std::find(my_sort.begin(), my_sort.end(), original[i]) == my_sort.end())
				std::cout << " " << original[i];
		}
		std::cout << std::endl;
		std::cout << "numbers missing deque: ";
		for (size_t i = 0; i < original.size(); i++)
		{
			if (std::find(my_deque.begin(), my_deque.end(), original[i]) == my_deque.end())
				std::cout << " " << original[i];
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "my size vector: " << my_sort.size() << " my size deque: " << my_deque.size() << " original size: " << original.size();
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "execution time vector: "<< std::fixed << execution_time_vect << "\n";
		std::cout << "execution time original vector: "<< std::fixed << execution_time_original << "\n";
		std::cout << "execution time deque: "<< std::fixed << execution_time_deque << "\n";
		std::cout << "execution time original deque: "<< std::fixed << execution_time_original_deque << "\n";


	} catch (std::exception &e)
	{ std::cerr << e.what(); }

}
