/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:33:35 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/21 16:15:25 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2 || (!argv[1] && argv[1][0] == 0))
			throw std::runtime_error("wrong number of args// " 
					"do: " + std::string(argv[0]) + " \"1 1 1 + +\" \n");
		RPN::calculate(argv[1]);
	} catch (std::exception &e)
	{ std::cerr << e.what(); return (1); }
}
