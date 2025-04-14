/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:19:55 by thiew             #+#    #+#             */
/*   Updated: 2025/01/03 19:46:27 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class	RobotomyRequestForm : public AForm
{
	public:
		//constructors
		RobotomyRequestForm( std::string target);
		RobotomyRequestForm( RobotomyRequestForm &copy);
		~RobotomyRequestForm( void );
		//overload
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other);

		void		execute( Bureaucrat &executor) const;


	private:
		std::string _target;

		// private constructor
		RobotomyRequestForm( void );
};
