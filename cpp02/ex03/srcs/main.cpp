/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:29 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/08 13:45:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	std::cout << "calculus triangle ints\n";
	Point	p1(0, 0);
	Point	p2(10,0);
	Point	p3(0, 10);
	Point	t(1, 1);
	Point	t2(0, 8);
	Point	t3(0, 8);
	std::cout << std::setw(2) <<"p1: " << p1 << "p2: " << p2 << "p3: " << p3 << std::endl;
	std::cout << std::setw(2) <<"t:  " << t << "t2: " << t2 << "t3: " << t3 << std::endl;
	std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
	if (bsp(p1, p2, p3, t))
		std::cout << std::setw(20) << "t is inside" << std::setfill(' ') << "|" << std::endl;
	else
		std::cout << std::setw(20) << "t is outside" << std::setfill(' ') << "->" << std::endl;


	std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
	if (bsp(p1, p2, p3, t2))
		std::cout << std::setw(20) << "t2 is inside" << "|" << std::endl;
	else
		std::cout << std::setw(20) << "t2 is outside" << std::setfill(' ') << "->" << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << ""  << std::setfill(' ') << std::endl;
	if (bsp(p1, p2, p3, t3))
		std::cout << std::setw(20) << "t3 is inside" << std::setfill(' ') << "|" << std::endl;
	else
		std::cout << std::setw(20) << "t3 is outside" << std::setfill(' ') << "->" << std::endl;


	std::cout << std::endl;
	std::cout << "calculus triangle floats\n";
	Point	a(0.1, 1.1);
	Point	b(20.1, 1.1);
	Point	c(2.1, 26.1);
	Point	s(3.1, 3.1);
	Point	s2(10.1,5.1);
	Point	s3(-13.1 , 2.1);
	std::cout << std::setw(2) << "a:  " << a << "b:  " << b << "c:  " << c << std::endl;
	std::cout << std::setw(2) <<"s:  " << s << "s2: " << s2 << "s3: " << s3 << std::endl;
	std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
	if (bsp(a, b, c, s))
		std::cout << std::setw(20) << "s is inside" << std::setfill(' ') << "|" << std::endl;
	else
		std::cout << std::setw(20) << "s is outside" << std::setfill(' ') << "->" << std::endl;


	std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
	if (bsp(a, b, c, s2))
		std::cout << std::setw(20) << "s2 is inside" << "|" << std::endl;
	else
		std::cout << std::setw(20) << "s2 is outside" << std::setfill(' ') << "->" << std::endl;

	std::cout << std::setw(20) << std::setfill('-') << ""  << std::setfill(' ') << std::endl;
	if (bsp(a, b, c, s3))
		std::cout << std::setw(20) << "s3 is inside" << std::setfill(' ') << "|" << std::endl;
	else
		std::cout << std::setw(20) << "s3 is outside" << std::setfill(' ') << "->" << std::endl;
}
