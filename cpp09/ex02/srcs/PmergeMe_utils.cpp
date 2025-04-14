/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:22:01 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/24 12:08:42 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool	isValidNum(std::string &input)
{
	char *end;
	if (input[0] == '0' && input.size() > 1)
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
				return (false);
	}
	if (atoi(input.c_str()) < 0)
		return (false);
	if (strtol(input.c_str(), &end, 10) > INT_MAX)
		return (false);


	return (true);
}

bool	cmpPairs(const pair &a, const pair &b)
{
	return (a.winner > b.winner);
}

int		intMax(const int &a, const int &b)
{
	return (a >= b ? a : b);
}

int		intMin(const int &a, const int &b)
{
	return (a <= b ? a : b);
}

void	insertValues(std::vector<pair> &winners, std::vector<pair> container)
{
	pair	insert_pair;

	for (std::vector<pair>::iterator it = container.begin(); it != container.end(); it++)
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


size_t* generateJacobsthalSequence(size_t n) {
    if (n == 0) return NULL;

    size_t* sequence = new size_t[n];

    sequence[0] = 0;
    if (n == 1) return sequence;

    sequence[1] = 1;
    if (n == 2) return sequence;

    for (size_t i = 2; i < n; ++i)
        sequence[i] = sequence[i - 1] + 2 * sequence[i - 2];

    return sequence;
}

 void	sortResult(std::vector<pair> &winners, std::vector<pair> &container, std::vector<int> &result) 
 { 
 	size_t	size = container.size(); 
	// size_t	sequence[11] = {0,1,1,3,5,11,21,43,85,171,341};
	size_t	*sequence = generateJacobsthalSequence(17);
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
		if (i < 3)
		{
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
		else if (std::find(sequence, sequence + 16, i) != sequence + 16)
		{
			size_t idx = std::distance(sequence, std::find(sequence, sequence + 16, i));
			size_t higher = sequence[idx + 1] > size - 1 ? size - 1 : sequence[idx + 1];

			for (size_t it = higher; it > sequence[idx]; it--)
			{
				size_t jacobs_i = it; 
				pos = findIndex(result, container[jacobs_i].winner); 
				pos = binary_search(result, container[jacobs_i].looser, 0, static_cast<int> (pos)); 
				if (container[jacobs_i].looser != -1) 
					result.insert(result.begin() + pos, container[jacobs_i].looser); 

				if (container[it].lonely == true) 
				{ 
					pos = binary_search(result, container[jacobs_i].winner, 0, static_cast<int> (result.size())); 
					result.insert(result.begin() + pos, container[jacobs_i].winner);
				} 
			}
			if (sequence[idx] == 3)
			{
				size_t jacobs_i = 3; 
				pos = findIndex(result, container[jacobs_i].winner); 
				pos = binary_search(result, container[jacobs_i].looser, 0, static_cast<int> (pos)); 
				if (container[jacobs_i].looser != -1) 
					result.insert(result.begin() + pos, container[jacobs_i].looser); 

				if (container[jacobs_i].lonely == true) 
				{ 
					pos = binary_search(result, container[jacobs_i].winner, 0, static_cast<int> (result.size())); 
					result.insert(result.begin() + pos, container[jacobs_i].winner);
				} 
			}
			if (higher == size -1)
				break ;
		}
 	} 
	delete[] sequence;
 }

// void	sortResult(std::vector<pair> &winners, std::vector<pair> &container, std::vector<int> &result)
// {
	
// 	if (winners.size() == 1)
// 	{
// 		if (!winners[0].lonely)
// 			result.push_back(winners[0].looser);
// 		result.push_back(winners[0].winner);
// 	}

// 	if (container[0].looser != -1)
// 		result.insert(result.begin(), container[0].looser);
// 	for (size_t	i = 1; i < container.size(); i++)
// 	{
// 		size_t pos;
// 		pos = findIndex(result, container[i].winner);
// 		pos = binary_search(result, container[i].looser, 0, static_cast<int> (pos));
// 		if (container[i].looser != -1)
// 			result.insert(result.begin() + pos, container[i].looser);

// 		if (container[i].lonely == true)
// 		{
// 			pos = binary_search(result, container[i].winner, 0, static_cast<int> (result.size()));
// 			result.insert(result.begin() + pos, container[i].winner); 
// 		}
// 	}
// }

 //std::vector<size_t>	groupSize(size_t &size) 
 //{ 
 //	std::vector<size_t> sizes; 

 //	//checks for small sizes 
 //	if (size < 2) 
 //	{ 
 //		sizes.push_back(1); 
 //		return (sizes); 
 //	} 
 //	sizes.push_back(2); 
 //	if (size == 2) 
 //		return (sizes); 
 //	if (size == 3) 
 //	{ 
 //		sizes.push_back(1); 
 //		return (sizes); 
 //	} 
 //	else if (size > 3) 
 //		sizes.push_back(2); 
 //	if (size < 6 && size > 4) 
 //	{ 
 //		sizes.push_back(size - 4); 
 //		return (sizes); 
 //	} 

 //	size_t	power = 8; 
 //	size_t	last = 2; 
 //	size_t	sum = 4; 
 //	size_t	curr = 0; 

 //	//larger numbers insertion */
 //	while (sum < size) 
 //	{ 
 //		curr = power - last; 
 //		sum += curr; 
 //		last = curr; 
 //		power *= 2; 
 //		sizes.push_back(curr); 
 //	} 

 //	if (sum > size) 
 //	{ 
 //		sizes.pop_back(); 
 //		sizes.push_back(size - (sum - last)); 
 //	} 
 //	return (sizes); 
 //}

 //size_t jacobsthal(size_t &it, std::vector<size_t> &sizes) 
 //{ 
 //	size_t	sum = 0; 
 //	for (size_t i = 0; i < sizes.size(); i++) 
 //	{ 
 //		size_t	group_start = sum; 
 //		if (sum + sizes[i] > it) 
 //		{ 
 //			size_t	ingroup_i = it - group_start; 
 //			size_t	reverse_ingroup = (sizes[i] - 1) - ingroup_i; 
 //			return (sum + reverse_ingroup); 
 //		} 
 //		sum += sizes[i]; 
 //	} 
 //	return (-1); 
 //}

// size_t jacobsthal(size_t &it, size_t &size)
// {
// 	size_t	sequence[9] = {1,3,5,11,21,43,85,171,341};
// 	size_t	i = 0;

// 	while (i < 9)
// 	{
// 		if (i > sequence[i])
// 		{
// 			size_t lower = sequence[i];
// 			break ;
// 		}
// 		if (i == sequence[i])
// 			return (sequence[i]);
// 		i++;
// 	}
// 	size_t higher =  sequence[i + 1] > size ? size : sequence[i + 1];
	
// }
