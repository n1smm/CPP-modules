/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:54:41 by thiew             #+#    #+#             */
/*   Updated: 2024/10/18 12:34:05 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class	contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		std::string	format_column(std::string &input);
		void		get_data();
		std::string	get_data(int search_param);
		void		change_data();
		void		change_data(std::string input, int param);
};

