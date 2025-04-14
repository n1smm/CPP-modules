/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:19:58 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/31 13:00:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

//constructors
Intern::Intern() { std::cout << "def constr Intern\n"; }
Intern::Intern( const Intern &copy) { *this = copy; std::cout << "copy constr Intern\n"; }
Intern::~Intern() { std::cout << "Intern deconstructor \n"; }
//overload
Intern		&Intern::operator=( const Intern &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}


static	AForm	*ShrubberyCreation(std::string targetName)
{
	return (new ShrubberyCreationForm(targetName));
}
static	AForm	*RobotomyRequest(std::string targetName)
{
	return (new RobotomyRequestForm(targetName));
}
static	AForm	*PresidentialPardon(std::string targetName)
{
	return (new PresidentialPardonForm(targetName));
}


//method
AForm		*Intern::makeForm(std::string formName, std::string targetName)
{
	struct	formStruct
	{
		std::string _name;
		AForm	*(*fptr)(std::string targetName);
	};

	formStruct	allForms[3] = {
		{	"ShrubberyCreationForm", &ShrubberyCreation		},
		{	"RobotomyRequestForm", &RobotomyRequest			},
		{	"PresidentialPardonForm", &PresidentialPardon 	},
	};
	for (int i = 0; i < 3; i++)
		if (allForms[i]._name == formName)
		{
			std::cout << "intern creates a form: " << formName << "\n";
			return (allForms[i].fptr(targetName));
		}
	std::cout << "Intern error: Wrong form name passed: " << formName << "\n";
	return (NULL);
}

//HELPER METHODS

/* static AForm	*formy(int i, std::string targetName) */
/* { */
/* 	AForm *form = NULL; */
/* 	switch(i) */
/* 	{ */
/* 		case 0: */
/* 			form = new RobotomyRequestForm(targetName); */
/* 			break; */
/* 		case 1: */
/* 			form = new ShrubberyCreationForm(targetName); */
/* 			break; */
/* 		case 2: */
/* 			form = new PresidentialPardonForm(targetName); */
/* 			break; */
/* 		default: */
/* 			std::cout << "Intern error: Wrong form name passed\n"; */
/* 	} */
/* 	return (form); */
/* } */

/* AForm		*Intern::makeForm(std::string formName, std::string targetName) */
/* { */
/* 	AForm *form; */
/* 	std::string	forms[3] = { */ 
/* 		"RobotomyRequestForm", */ 
/* 		"ShrubberyCreationForm", */ 
/* 		"PresidentialPardonForm" */ 
/* 	}; */
/* 	int i; */
/* 	for (i = 0; i < 3; i++) */
/* 	{ */
/* 		if (forms[i] == formName) */
/* 			break; */
/* 	} */
/* 	form = formy(i, targetName); */
/* 	return (form); */
/* } */

