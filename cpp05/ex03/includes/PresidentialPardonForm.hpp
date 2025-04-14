/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:19:55 by thiew             #+#    #+#             */
/*   Updated: 2025/01/03 19:46:20 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class	PresidentialPardonForm : public AForm
{
	public:
		//constructors
		PresidentialPardonForm( std::string target);
		PresidentialPardonForm( PresidentialPardonForm &copy);
		~PresidentialPardonForm( void );
		//overload
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other);

		void		execute( Bureaucrat &executor) const;


	private:
		std::string _target;

		// private constructor
		PresidentialPardonForm( void );
};
