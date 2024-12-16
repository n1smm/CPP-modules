/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:25:47 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 18:59:43 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

void	err_msg_exit(std::string msg, char **argv)
{

		std::cerr << RED << msg << std::endl;
		std::cerr << "Correct syntax: " << argv[0] << " <input file> <str to replace> <replacer str>" << RESET << std::endl;
		throw std::runtime_error(msg);
}

