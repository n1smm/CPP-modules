/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:38:42 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/13 12:22:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iomanip>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "PFFFFT, do better next time! Maybe like this: <" << argv[0] << "> <1 argument>\n";
		return (1);
	}
	Harl	msg;

	/* msg.complain("DEBUG"); */
	/* msg.complain("INFO"); */
	/* msg.complain("WARNING"); */
	/* msg.complain("ERROR"); */
	/* msg.complain("upsidupsi"); */

	std::cout << std::setw(75) << std::setfill('-') << "" << std::endl;

	msg.complain_list(argv[1]);

}
