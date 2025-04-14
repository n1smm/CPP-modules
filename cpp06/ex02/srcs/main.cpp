/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:19:30 by tjuvan            #+#    #+#             */
/*   Updated: 2025/01/31 17:01:18 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{
	Base	*foo = generate();
	identify(foo);
	identify(*foo);
	Base	*fuu = generate();
	identify(fuu);
	identify(*fuu);
	Base	*fii = generate();
	identify(fii);
	identify(*fii);
	delete fii;
	delete foo;
	delete fuu;
}
