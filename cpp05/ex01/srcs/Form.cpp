/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:20:16 by thiew             #+#    #+#             */
/*   Updated: 2025/01/31 12:30:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/Form.hpp"
#include	"../includes/Bureaucrat.hpp"

// constructors
Form::Form() : _name("default"), _grade_to_sign(150), _grade_to_execute(150), _signed(false)
{ std::cout << "def constr Form\n"; }

Form::Form(std::string name, int grade_sign, int grade_execute) : 
	_name(name), _grade_to_sign(grade_sign),
	_grade_to_execute(grade_execute), _signed(false)
{
	if (grade_sign > 150 || grade_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_sign < 1 || grade_execute < 1)
		throw Form::GradeTooHighException();

	std::cout << "arg constr Form\n";
}

Form::Form( const Form &other) :
	_name(other._name), _grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute), _signed(other._signed)
{ std::cout << "copy constr Form\n"; }

Form::~Form() { std::cout << "deconstr Form\n"; }

//overload
Form					&Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
} //TODO

//Exceptions
const	char			*Form::GradeTooLowException::what() const throw() 
{ return ("\033[31m form: grade to low\033[0m"); }

const	char			*Form::GradeTooHighException::what() const throw() 
{ return ("\033[31m form: grade to high\033[0m"); }

//get/set
std::string				Form::getName( void )			const 	{ return (_name); }
int						Form::getGradeSign( void )		const	{ return (_grade_to_sign); }	
int						Form::getGradeExecute( void )	const	{ return (_grade_to_execute); }
bool					Form::getSignedvalue( void )	const	{ return (_signed); }
void					Form::setSignedValue( bool value )		{ _signed = value; }

//methods
void					Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	if (_signed == false)
	{
		std::cout << obj.getName() << " signed the form: " << _name << std::endl; 
		_signed = true;
	}
	else
		std::cout << obj.getName() << " Couldn't sign the form " << _name << " because it's already signed\n";
}

std::ostream	&operator<<(std::ostream &ostr, const Form &obj)
{
	ostr << "form : " << obj.getName() << ", grade to sign: " << obj.getGradeSign() <<
		", grade to execute : " << obj.getGradeExecute() <<
		(obj.getSignedvalue() ? ", is signed\n" : ", is not yet signed\n");
	return (ostr);
}
