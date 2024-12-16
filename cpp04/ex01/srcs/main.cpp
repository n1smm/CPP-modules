/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:24:08 by thiew             #+#    #+#             */
/*   Updated: 2024/12/13 16:10:20 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	Brain::fillArray();	
	Animal	*pack[100];
	Brain	brr;

	for (int i = 0; i < 100; i++)
	{
		if (i % 2)
			pack[i] = new Cat();
		else
			pack[i] = new Dog();
		if (pack[i] == NULL)
		{
			perror("allocation failed\n");
			return(1);
		}
	}
	for (int i = 0; i < 100; i++)
		std::cout << i << ".-." << *pack[i];
	
	
	for (int i = 0; i < 100; i++)
		delete pack[i];
}
