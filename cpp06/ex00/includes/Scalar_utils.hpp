/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:47:25 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/31 13:29:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> 
#include <cerrno> 
#include <cmath>
#include <sstream>
#include <limits>
#include <cctype>



void	check_empty( std::string &input	);
bool	check_f( char **end );
void	print_results(double num);
