/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:23:54 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/10 20:30:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <unistd.h>
#include <sys/time.h>
#include <cmath>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

				Base::~Base( void ) {};

Base			*generate()
{
	long 	long	timeStamp;
	pid_t			pid;
	struct	timeval	tv;
	int				random;

	gettimeofday(&tv, NULL);
	timeStamp = tv.tv_sec + tv.tv_usec;
	pid = getpid();

	random = static_cast<int>((timeStamp * pid) % 3);
	switch (random)
	{
		case 0:
			std::cout << "A()\n";
			return new A();
		case 1:
			std::cout << "B()\n";
			return new B();
		case 2:
			std::cout << "C()\n";
			return new C();
		default:
			std::cout << "no return\n";
			return (NULL);

	}

}

void			identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "it's A\n";
	if (dynamic_cast<B *>(p))
		std::cout << "it's B\n";
	if (dynamic_cast<C *>(p))
		std::cout << "it's C\n";


}

void			identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "-> A\n";
		return;
	} catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "-> B\n";
		return;
	} catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "-> C\n";
		return;
	} catch (std::exception &e) {}
}

//overload
std::ostream		&operator<<(std::ostream &ostr, const Base &obj)
{
	static_cast<void>(obj);
	return (ostr);
}
