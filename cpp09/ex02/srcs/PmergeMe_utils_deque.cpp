/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils_deque.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:52:50 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/21 12:24:16 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void	insertValuesDeque(std::deque<pair> &winners, std::deque<pair> container)
{
	pair	insert_pair;

	for (std::deque<pair>::iterator it = container.begin(); it != container.end(); it++)
	{
		if (!(std::distance(container.begin(), it) % 2) && it + 1 != container.end())
		{
			insert_pair.winner = intMax(it->winner, (it + 1)->winner);
			insert_pair.looser = intMin(it->winner, (it + 1)->winner);
			insert_pair.lonely = false;
			winners.push_back(insert_pair);
		}
		else if (!(std::distance(container.begin(), it) % 2) && it == container.end())
		{
			insert_pair.winner = it->winner;
			insert_pair.looser = -1;
			insert_pair.lonely = false;
			winners.push_back(insert_pair);
		}
		if (it + 1 == container.end())
			break ;
	}
}

void	sortResultDeque(std::deque<pair> &winners, std::deque<pair> &container, std::deque<int> &result)
{
	
	if (winners.size() == 1)
	{
		if (!winners[0].lonely)
			result.push_back(winners[0].looser);
		result.push_back(winners[0].winner);
	}

	if (container[0].looser != -1)
		result.insert(result.begin(), container[0].looser);
	for (size_t	i = 1; i < container.size(); i++)
	{
		size_t pos;
		pos = findIndex(result, container[i].winner);
		pos = binary_search(result, container[i].looser, 0, static_cast<int> (pos));
		if (container[i].looser != -1)
			result.insert(result.begin() + pos, container[i].looser);

		if (container[i].lonely == true)
		{
			pos = binary_search(result, container[i].winner, 0, static_cast<int> (result.size()));
			result.insert(result.begin() + pos, container[i].winner); 
		}
	}
}
