/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:55:52 by thiew             #+#    #+#             */
/*   Updated: 2024/10/18 12:21:40 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

#define RESET       "\033[0m"
/* colors */
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

/* Bold Macros */
#define BOLD        "\033[1m"

/* Bold and Color Macros */
#define BOLD_BLACK  "\033[1;30m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD_WHITE  "\033[1;37m"


/* text macros */
#define INTRO "this phonebook has 3 options and can store up to 8 contacts.\n" \
		"Upon exiting all the contatcs will be lost.\n" \
		"Kind of stupid if you ask me, but hey I'm just a program, ...\n" \
		"anyway here are the three options, and don't try any funny bussinesss, you here me?!\n\n"

#define MAIN_QUESTION "use keyword ADD, to add a contact and SEARCH to search." \
			" If you find the program useless, write EXIT: \n > "

#define	SEARCH_PARAMS "search by 1:<index>, 2:<first_name>, 3:<last_name>," \
			" 4:<phone_number>, 5:<darkest_secret>? 6:<print_all>: "



