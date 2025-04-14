/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:24:27 by thiew             #+#    #+#             */
/*   Updated: 2025/01/31 12:11:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	public:

		//exceptions - if you don't make what() public it can only be caought by
		//std::exception
		class	GradeTooLowException : public std::exception
		{
			public:
			virtual	const	char	*what( void ) const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			public:
			virtual	const	char	*what( void ) const throw();
		};

		// methods
				void			incrementGrade( void );
				void			decrementGrade( void );

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
