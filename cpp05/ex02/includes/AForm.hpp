/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:00:07 by thiew             #+#    #+#             */
/*   Updated: 2025/01/03 19:50:41 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		//exceptions
		class	GradeTooLowException : public std::exception
		{ virtual	const	char	*what( void ) const throw(); };

		class	GradeTooHighException : public std::exception
		{ virtual	const	char	*what( void ) const throw(); };

		// deconstructor
		AForm( const std::string name, int grade_sign, int grade_execute);
		virtual ~AForm( void );

		// overloand
		AForm	&operator=( const AForm &other );

		// get/set
				std::string		getName( void )					const;
				int				getGradeSign( void )			const;
				int				getGradeExecute( void )			const;
				bool			getSignedvalue( void )			const;
				void			setSignedValue( bool value );	

		// methods
				void			beSigned( Bureaucrat &obj );
		virtual	void			execute( Bureaucrat &executor)	const	=0;



	private:
		const	std::string		_name;
		const	int				_grade_to_sign;
		const	int				_grade_to_execute;
				bool			_signed;

		// private constructors
		AForm( void );
		AForm( const AForm &other);
		



};

std::ostream	&operator<<( std::ostream &ostr, const AForm &obj );
