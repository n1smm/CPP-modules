/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:08:01 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 20:25:58 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

#define RED  "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define RESET  "\033[0m"

void	err_msg_exit(std::string msg, char **argv);

#endif
