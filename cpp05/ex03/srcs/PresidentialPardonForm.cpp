/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:46:49 by thiew             #+#    #+#             */
/*   Updated: 2025/01/04 12:31:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),
	_target("default") { std::cout << "def constr PresidentialPardonForm\n"; }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5),
	_target(target) { std::cout << "arg constr PresidentialPardonForm\n"; }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &copy) :
	AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target)
{ std::cout << "copy constr Shrub\n";	}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "destruct Shrub\n"; }

//overload
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

//methods
void					PresidentialPardonForm::execute( Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	if (this->getSignedvalue() == true)
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox, rejoice peasants!\n";
	else
		std::cout << executor.getName() << " Couldn't execcute the form " << this->getName() << " because it's not signed\n";
}

