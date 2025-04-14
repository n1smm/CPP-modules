/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:35:37 by thiew             #+#    #+#             */
/*   Updated: 2025/01/31 12:37:24 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <cmath>
#include <sstream>

// constructors
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) { std::cout << "def constr Bureaucrat\n"; }

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) 
{ 
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

	std::cout << "arg constr Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) { std::cout << "copy constr Bureaucrat\n"; }

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat deconstruct\n"; }

// overload
Bureaucrat				&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

//exceptions
const	char			*Bureaucrat::GradeTooLowException::what() const throw() 
{ 
	return ("\033[31mgrade too low\033[0m");
}
const	char			*Bureaucrat::GradeTooHighException::what() const throw() 
{ 
	return ("\033[31mgrade too high\033[0m"); 
}

// getters
const	std::string		Bureaucrat::getName()	const { return (_name); }
int						Bureaucrat::getGrade()	const { return (_grade); }

// methods
void					Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void					Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}


//ostream overload
std::ostream &operator<<(std::ostream &ostr, const Bureaucrat &obj)
{
	ostr << "Bureaucrat name: " << obj.getName() << " and his grade is: " << obj.getGrade() << "\n";
	return (ostr);
}




