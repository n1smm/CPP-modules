/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:51:56 by thiew             #+#    #+#             */
/*   Updated: 2025/02/21 14:39:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <algorithm>

#ifndef THRESHOLD
#	define THRESHOLD 500
#endif

struct	pair
{
	int	winner;
	int	looser;
	bool	lonely;
};

class PmergeMe
{
	public:
		//constructors & overloads
		PmergeMe( void );
		PmergeMe( const PmergeMe &copy );
		~PmergeMe( void );
		PmergeMe	&operator=(const PmergeMe &other);

		//methods
		static	std::vector<int>	MergeVector(std::string &input);
		static	std::deque<int>		MergeDeque(std::string &input);
		static	std::vector<pair>	parseVector(std::string &input);
		static	std::deque<pair>	parseDeque(std::string &input);
		static	void				MergeInsertVector(std::vector<pair> &container);
		static	void				MergeInsertDeque(std::deque<pair> &container);


	private:
		static	std::vector<int>	_input;
		static	std::deque<int>		_input_deque;
		static	std::vector<pair>	_pairs;
		static	std::deque<pair>	_deques;


};

//utils
bool	isValidNum(std::string &input);
bool	cmpPairs(const pair &a, const pair &b);
int		intMax(const int &a, const int &b);
int		intMin(const int &a, const int &b);
void	insertValues(std::vector<pair> &winners, std::vector<pair> container);
void	insertValuesDeque(std::deque<pair> &winners, std::deque<pair> container);
void	sortResult(std::vector<pair> &winners, std::vector<pair> &container, std::vector<int> &result);
void	sortResultDeque(std::deque<pair> &winners, std::deque<pair> &container, std::deque<int> &result);

//templates

template<typename Container>
struct ThreadArg
{
	Container *container;
};

template<typename Container>
void	mergeSort(Container	&container);

template <typename Container>
int binary_search(const Container &res, int target, int low, int high)
{
    int mid;

    if (low >= high)
        return low;

    mid = (low + high) / 2;

    if (res[mid] == target)
        return mid + 1;
    else if (res[mid] < target)
        return binary_search(res, target, mid + 1, high);
    else
        return binary_search(res, target, low, mid);
}

template <typename Container>
size_t findIndex(const Container &vec, int value)
{
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == value)
            return i;
    }
    return vec.size();
}

#include "../srcs/mergeSort.tpp"
