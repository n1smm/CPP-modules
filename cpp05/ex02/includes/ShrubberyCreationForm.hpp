/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:19:55 by thiew             #+#    #+#             */
/*   Updated: 2025/01/03 20:22:22 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class	ShrubberyCreationForm : public AForm
{
	public:
		//constructors
		ShrubberyCreationForm( std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm &copy);
		~ShrubberyCreationForm( void );
		//overload
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other);


		void		execute( Bureaucrat &executor) const;


	private:
		const		std::string _target;

		// private constructor
		ShrubberyCreationForm( void );
};
