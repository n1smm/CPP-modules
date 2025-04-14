/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomNumGenerator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:41:23 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/13 12:26:03 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect usage -> " << argv[0] << " [quantity] [min] [max] \n"; 
		return (1);
	}
	srand(time(0));
	std::vector<int> rand_container;
	int	temp_num = 0;
	int	min = atoi(argv[2]);
	int max = atoi(argv[3]);

	if (max - min < atoi(argv[1]) * 2)
	{
		std::cerr << "range between min-max number must be 2x the quantity of numbers or more\n";
		return (1);
	}

	for (int i = 0; i < atoi(argv[1]); i++)
	{
		temp_num = min + rand() % (max - min + 1);
		if (std::find(rand_container.begin(), rand_container.end(), temp_num) == rand_container.end())
			rand_container.push_back(temp_num);
		else
			i--;
	}
	for (std::vector<int>::iterator it = rand_container.begin(); it != rand_container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	





}
