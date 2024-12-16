/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:16:08 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/03 17:12:16 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


int	main( void )
{
    const std::string magenta = "\033[35m";
    const std::string orange = "\033[38;5;214m";
    const std::string reset = "\033[0m";
	
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;
	std::cout <<
		magenta <<std::right << std::setw(15) << std::setfill('*') <<"addresses" <<
		std::setfill('*') << std::setw(15) << "" << std::setfill(' ') << std::endl << reset <<
		orange <<
		std::left << std::setw(15)	 <<"mem addr str" << stringPTR 			<< std::endl <<
		std::left << std::setw(15)	 <<"mem addr str" << &str 				<< std::endl <<
		std::left << std::setw(15)	 <<"mem addr PTR" << &stringPTR 		<< std::endl <<
		std::left << std::setw(15)	 <<"mem addr REF" << &stringREF			<< std::endl <<
		reset <<
		magenta << std::right << std::setw(15) << std::setfill('*') << "values" <<
		std::setfill('*') << std::setw(15) << "" << std::setfill(' ') << std::endl << reset <<
		orange <<
		std::left << std::setw(15)	 <<"value of str" << str 				<< std::endl <<
		std::left << std::setw(15)	 <<"value of PTR" << *stringPTR 		<< std::endl <<
		std::left << std::setw(15)	 <<"value of REF" << stringREF 			<< std::endl << reset;
}
