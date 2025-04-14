/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:20:16 by thiew             #+#    #+#             */
/*   Updated: 2025/01/04 12:37:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/AForm.hpp"
#include	"../includes/Bureaucrat.hpp"

// constructors
AForm::AForm() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{ std::cout << "def constr AForm\n"; }

AForm::AForm(std::string name, int grade_sign, int grade_execute) : 
	_name(name), _grade_to_sign(grade_sign),
	_grade_to_execute(grade_execute)
{
	_signed = false;
	std::cout << "arg constr AForm\n";
}

AForm::AForm( const AForm &other) :
	_name(other._name), _grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute), _signed(other._signed)
{ std::cout << "copy constr AForm\n"; }

AForm::~AForm() { std::cout << "deconstr AForm\n"; }

//overload
AForm					&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
} //TODO

//Exceptions
const	char			*AForm::GradeTooLowException::what() const throw() 
{ return ("\033[31m form: grade to low\033[0m"); }

const	char			*AForm::GradeTooHighException::what() const throw() 
{ return ("\033[31m form: grade to high\033[0m"); }

//get/set
std::string				AForm::getName( void )			const 	{ return (_name); }
int						AForm::getGradeSign( void )		const	{ return (_grade_to_sign); }	
int						AForm::getGradeExecute( void )	const	{ return (_grade_to_execute); }
bool					AForm::getSignedvalue( void )	const	{ return (_signed); }
void					AForm::setSignedValue( bool value )		{ _signed = value; }

//methods
void					AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	if (_signed == false)
	{
		std::cout << obj.getName() << " signed the form: " << _name << std::endl; 
		_signed = true;
	}
	else
	{
		std::cout << obj.getName() << " Couldn't sign the form " << _name << " because it's already signed\n";
		_signed = false;
	}
}

std::ostream	&operator<<(std::ostream &ostr, const AForm &obj)
{
	ostr << "form : " << obj.getName() << ", grade to sign: " << obj.getGradeSign() <<
		", grade to execute : " << obj.getGradeExecute() <<
		(obj.getSignedvalue() ? ", is signed\n" : ", is not yet signed\n");
	return (ostr);
}
