/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:20:39 by thiew             #+#    #+#             */
/*   Updated: 2025/02/21 15:29:35 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

void	calcHoldings(Exchange &exchange)
{
	std::map<Date, double>	db = exchange.getMap();
	const	DateArray		&date_array = exchange.getLedger().getDate();
	const	DoubleArray		&value_array =  exchange.getLedger().getValue();
			int				size = exchange.getLedger().getSize();

	std::map<Date, double>::iterator it = db.begin();
	for (int i = 0; i < size; i++)
	{
		it = db.upper_bound(date_array[i]);
		it--;
		if (it != db.end() && it != db.begin())
		{
			double res = it->second * value_array[i];
			std::cout << "ledger date: " << date_array[i].formatDate() 
				<< "  closest date: " << it->first.formatDate() 
				<< " -> " << " value of btc: " << std::fixed
				<< it->second << ", btc held: " << value_array[i] << " = " << res << " usd\n";
		}
		else 
		{
			std::cout << "ledger date: " << date_array[i].formatDate() 
				<< " \t before the first record of btc\n";
		}

	}
}


int 	main(int argc, char **argv)
{
	if (argc > 100 || !argv[0])
		return 0;

	try
	{

		Exchange  exchange(argv[1]);
		calcHoldings(exchange);

	} catch (std::exception &e)
	{ std::cout << e.what(); }
}
