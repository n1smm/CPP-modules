/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:29:38 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 19:10:31 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define RED  "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define RESET  "\033[0m"

typedef struct	s_stream
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		original;
	std::string		replacer;
}				t_stream;

/* error.cpp */
void	err_msg_exit(std::string msg, char **argv);
/* read_file.cpp */
void	read_file(t_stream *data, char **argv);

#endif
