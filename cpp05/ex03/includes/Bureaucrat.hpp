/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:24:27 by thiew             #+#    #+#             */
/*   Updated: 2025/01/04 12:35:40 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	public:

		//exceptions
		class	GradeTooLowException : public std::exception
		{
			virtual	const	char	*what( void ) const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			virtual	const	char	*what( void ) const throw();
		};

		// methods
				void			incrementGrade( void );
				void			decrementGrade( void );
				void			signForm( AForm &obj );
				void			executeForm( AForm const &obj );

		// get/set
		const	std::string		getName( void )		const;
				int				getGrade( void )	const;


		// constructors
		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade);
		Bureaucrat( const Bureaucrat &other);
		~Bureaucrat( void );
		// overloand
		Bureaucrat	&operator=( const Bureaucrat &other );


	private:
		const	std::string		_name;
				int				_grade;

};

std::ostream	&operator<<( std::ostream &ostr, const Bureaucrat &obj );
