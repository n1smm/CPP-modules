/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:47:48 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/04 16:52:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	ScalarConverter
{
	public:
	~ScalarConverter( void );	

	static void		convert(std::string &input);


	private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter &copy);
	ScalarConverter		&operator=(const ScalarConverter &other);
	

};
