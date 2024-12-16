/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:53:00 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/05 14:15:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug()
{
	std::string msg = "debibibibibbi debuubbiibi debugugi debugi debugi";
	std::cout << msg << std::endl;
}

void	Harl::_info()
{
	std::string msg = "info infopinfo minfo finfo info fifno";
	std::cout << msg << std::endl;
}
void	Harl::_warning()
{
	std::string msg = "warrrrrniiiiiiiiiiinnngngnngggiiiiiiii";
	std::cout << msg << std::endl;
}
void	Harl::_error()
{
	std::string msg = " upsiii. My bad! ";
	std::cout << msg << std::endl;
}


void	Harl::complain_list(char *level)
{
	int	i = 0;
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	std::string lvl = level;
	void	(Harl::*fptr)() = NULL;

	while( i < 4 && lvl != levels[i])
		i++;
	switch(i)
	{
		case DEBUG:
			std::cout << "[DEBUG]\n";
			fptr = &Harl::_debug;
			(this->*fptr)();
		case INFO:
			std::cout << "[INFO]\n";
			fptr = &Harl::_info;
			(this->*fptr)();
		case WARNING:
			std::cout << "[WARNING]\n";
			fptr = &Harl::_warning;
			(this->*fptr)();
		case ERROR:
			std::cout << "[ERROR]\n";
			fptr = &Harl::_error;
			(this->*fptr)();
			break;
		default:
			std::cout << "WROOOONG!\n";
			std::cout << "what are you even doing choose one of this: ->";
			for (int i = 0; i < 4; i++) {
				std::cout << levels[i];
				if (i < 3) {
					std::cout << ", ";
				}
			}
			std::cout << "<-\n";
	}


	

}

void Harl::complain( std::string level)
{
	struct	levelFunction
	{
		std::string level;
		void (Harl::*fptr)();
	};
	levelFunction	levelFunctions[4] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}
	};
		
	for (int i = 0; i < 4; i++)
	{
		if (levelFunctions[i].level == level)
		{
			(this->*levelFunctions[i].fptr)();
			return ;
		}
	}


	std::cout << "what are you even doing choose one of this: ->";
	for (int i = 0; i < 4; i++) {
		std::cout << levelFunctions[i].level;
		if (i < 3) {
			std::cout << ", ";
		}
	}
	std::cout << "<-\n";
}

/* void	Harl::complain( std::string level) */
/* { */
/* 	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; */
/* 	void	(Harl::*fptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error}; */
/* 	for (int i = 0; i < 4; i++) */
/* 	{ */
/* 		if (levels[i] == level) */
/* 		{ */
/* 			(this->*fptr[i])(); */
/* 			return ; */
/* 		} */
/* 	} */
/* 	std::cout << "what are you even doing choose one of this: ->"; */
/* 	for (int i = 0; i < 4; i++) { */
/* 		std::cout << levels[i]; */
/* 		if (i < 3) { */
/* 			std::cout << ", "; */
/* 		} */
/* 	} */
/* 	std::cout << "<-\n"; */
/* } */
