/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/06 12:27:48 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <sys/time.h>
#include <unistd.h>


int	main(void)
{
	long 	long	timeStamp;
	pid_t			pid;
	struct	timeval	tv;

	gettimeofday(&tv, NULL);
	timeStamp = tv.tv_sec + tv.tv_usec;
	pid = getpid();

	//empty array
	std::cout << "empty array\n";
	Array<int> emptyArray;
	std::cout << "empty array size: " << emptyArray.size() << std::endl;
	
	//fixed size array
	std::cout << "string array\n";
	Array<std::string>	stringArray(10);
	std::cout << "string array size: " << stringArray.size() << std::endl;

	std::cout << "copy string array\n";
	Array<std::string>	copyStringArray(stringArray);
	std::cout << "copy string array size: " << stringArray.size() << std::endl;

	std::cout << "= operator after [] operator\n";
	for (int i = 0; i < 10; i++)
		copyStringArray[i] = "hhuuuuhhu";
	stringArray = copyStringArray;
	for (int i = 0; i < 10; i++)
		std::cout << stringArray[i] << std::endl;

	try
	{
		std::cout << "out of bounds error handling \n";
		std::cout << stringArray[10];
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//int array
	std::cout << "\n\n int array test\n";
	Array<int> intArray(10);
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + timeStamp + pid;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;

	









	
	
}
