/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:46:49 by thiew             #+#    #+#             */
/*   Updated: 2025/01/04 14:04:28 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <unistd.h>
#include <cstdlib>

// constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
	_target("default") { std::cout << "def constr RobotomyRequestForm\n"; }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),
	_target(target) { std::cout << "arg constr RobotomyRequestForm\n"; }

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &copy) :
	AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target)
{ std::cout << "copy constr RobotomyRequestForm\n";	}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "destruct RobotomyRequestForm\n"; }

//overload
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

//methods
void					initializeRandom() 
{
	static bool init = false;
	if (!init)
	{
		srand(static_cast<unsigned int>(time(0)));
		init = true;
	}
}

void					RobotomyRequestForm::execute( Bureaucrat &executor) const
{
	int	min = 0;
	int max = 100;
	initializeRandom();
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	if (this->getSignedvalue() == true)
	{
		std::cout << "bzzzz rgtggzzziiiiippp zzzzzrrrrrrrooooowwwwww fffffffsssshhhhhhh zzzzzpp\n";
		usleep(500000);
		int	rand_numb = min + rand() % (max - min);
		std::cout << "chances of successful robotomization are: " << 100 - rand_numb << "\n";
		if (rand_numb < 50)
			std::cout << _target << " Has been successfully robotomized\n";
		else
			std::cout << " Robotomy on " << _target << " failed due to unforeseen circumstances, sorry!\n";
	}
	else
		std::cout << executor.getName() << " Couldn't execcute the form " << this->getName() << " because it's not signed\n";
}

