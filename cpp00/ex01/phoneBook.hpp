/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:49:46 by thiew             #+#    #+#             */
/*   Updated: 2024/10/09 16:58:54 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "contact.hpp"


class	phoneBook
{
	private:
		contact			_contacts[8];
		int				_index;

	public:
		phoneBook() :	_index(0) {};
		void			add(contact &first);
		void			search(contact &first);
		void			get_data();
		void			get_data(int i);
		std::string		get_data(int i, int search_param);
		std::string		get_index();
		int				size() const { return 8; };
};

