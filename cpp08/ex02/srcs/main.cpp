/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:43 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/06 17:26:31 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main()
{
	MutantStack<int>	stacky;
	int i = 10;

	for (int i = 0; i < 10; ++i)
		stacky.push(i);

	std::cout << "original values \n";
    for (MutantStack<int>::iterator it = stacky.begin(); it != stacky.end(); ++it)
	{	std::cout << *it << std::endl; }

	for (MutantStack<int>::iterator it = stacky.begin(); it != stacky.end(); it++)
	{
		*it = i++;
	}

	std::cout << "\niterator again after changing values\n";
    for (MutantStack<int>::iterator it = stacky.begin(); it != stacky.end(); ++it)
	{ std::cout << *it << std::endl; }

	//reverse
	std::cout << "\nreverse iterator \n";
    for (MutantStack<int>::reverse_iterator it = stacky.rev_begin(); it != stacky.rev_end(); ++it)
	{ std::cout << *it << std::endl; }

	//const
	std::cout << "\nconst iteration\n";
	MutantStack<const int*>	consty;
	const	int	arr[5] = {1,2,3,4,5};
	for (int i = 0; i < 5; i++)
		consty.push(&arr[i]);
	for (MutantStack<const int*>::const_iterator it = consty.begin(); it != consty.end(); ++it)
        std::cout << **it << std::endl;

}
