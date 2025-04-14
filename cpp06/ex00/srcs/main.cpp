/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/09 19:30:13 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"



int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong nbr arguments\n";
		return (0);
	}
	std::string res = argv[1];
	
	ScalarConverter::convert(res);


	 




}

// void testStrtod(const char* str) {
//     char* end;
//     errno = 0; // Reset errno before the call
//     double num = std::strtod(str, &end);

//     std::cout << "Input: " << str << std::endl;
//     std::cout << "Converted number: " << num << std::endl;
//     if (errno == ERANGE) {
//         std::cerr << "Range error occurred" << std::endl;
//     }
//     if (end == str) {
//         std::cerr << "No conversion could be performed" << std::endl;
//     } else {
//         std::cout << "Remaining string: " << end << std::endl;
//     }
//     std::cout << std::endl;
// }

// int main() {
//     testStrtod("12.3A");
//     testStrtod("aabdl");
//     testStrtod("nan");
//     testStrtod("31877483927489");
// 	testStrtod("a");
// 	testStrtod("-4.2ff");
// 	testStrtod("-inff");
// 	testStrtod("+inff");
//     return 0;
// }
