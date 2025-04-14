/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:00:07 by thiew             #+#    #+#             */
/*   Updated: 2025/01/03 17:41:42 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		//exceptions
		class	GradeTooLowException : public std::exception
		{ virtual	const	char	*what( void ) const throw(); };

		class	GradeTooHighException : public std::exception
		{ virtual	const	char	*what( void ) const throw(); };

		// constructors
		Form( void );
		Form( const std::string name, int grade_sign, int grade_execute);
		Form( const Form &other);
		~Form( void );
		// overloand
		Form	&operator=( const Form &other );

		// get/set
				std::string		getName( void )					const;
				int				getGradeSign( void )			const;
				int				getGradeExecute( void )			const;
				bool			getSignedvalue( void )			const;
				void			setSignedValue( bool value );	

		// methods
				void			beSigned( Bureaucrat &obj );



	private:
		const	std::string		_name;
		const	int				_grade_to_sign;
		const	int				_grade_to_execute;
				bool			_signed;
		



};

std::ostream	&operator<<( std::ostream &ostr, const Form &obj );
