/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:52:53 by thiew             #+#    #+#             */
/*   Updated: 2025/02/24 00:07:49 by thiew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::vector<int>					PmergeMe::_input;
std::vector<pair>					PmergeMe::_pairs;
std::deque<int>						PmergeMe::_input_deque;
std::deque<pair>					PmergeMe::_deques;

std::deque<int>		PmergeMe::MergeDeque(std::string &input)
{
		parseDeque(input);
		if (_input_deque.size() == 2)
		{
			if (intMin(_input_deque[1], _input_deque[0]) == _input_deque[1])
				std::swap(_input_deque[0], _input_deque[1]);
			return (_input_deque);
		}
		_input_deque.clear();
		MergeInsertDeque(_deques);
		return (_input_deque);
}


std::vector<int>	PmergeMe::MergeVector(std::string &input)
{
		parseVector(input);
		if (_input.size() == 2)
		{
			if (intMin(_input[1], _input[0]) == _input[1])
				std::swap(_input[0], _input[1]);
			return (_input);
		}
		_input.clear();
		MergeInsertVector(_pairs);
		return (_input);
}


void	PmergeMe::MergeInsertVector(std::vector<pair> &container)
{
	if (container.size() <= 1)
		return ;
	//sort the container by winners, lowest first
	mergeSort(container);
	if (container.size() % 2)
		container.back().lonely = true;

	//create new container of just the winner values
	std::vector<pair> winners;
	insertValues(winners, container);

	//recursive call with new container
	MergeInsertVector(winners);

	
	//sort values and put them in result
	sortResult(winners, container, _input);
}

void	PmergeMe::MergeInsertDeque(std::deque<pair> &container)
{
	if (container.size() <= 1)
		return ;
	//sort the container by winners, lowest first
	mergeSort(container);
	if (container.size() % 2)
		container.back().lonely = true;

	//create new container of just the winner values
	std::deque<pair> winners;
	insertValuesDeque(winners, container);

	//recursive call with new container
	MergeInsertDeque(winners);

	
	//sort values and put them in result
	sortResultDeque(winners, container, _input_deque);
}

std::vector<pair>	PmergeMe::parseVector(std::string &input)
{
	std::istringstream	iss(input);
	std::string			buff;
	std::string			number_string;
	pair				init_pair;

	//parsing
	while (std::getline(iss, buff))
	{
		std::istringstream	word_iss(buff);
		while (std::getline( word_iss, number_string, ' '))
		{
			if (number_string.empty())
				continue ;
			if (!isValidNum(number_string))
				throw std::runtime_error("wrong input at [" + number_string + "]\n");
			_input.push_back(atoi(number_string.c_str()));
			//TODO another container
		}
	}
	if (_input.size() < 2)
		throw std::runtime_error("pass at least 2 numbers");

	//passing to pairs container and first in pair sort
	for (std::vector<int>::iterator	it = _input.begin(); it != _input.end(); it++)
	{
		if (!(std::distance(_input.begin(), it) % 2) && it + 1 != _input.end())
		{
			init_pair.winner = intMax(*it, *(it + 1));
			init_pair.looser = intMin(*it, *(it + 1));
			init_pair.lonely = false;
			_pairs.push_back(init_pair);
		}
		if (it + 1 == _input.end() && _input.size() % 2)
		{
			init_pair.winner = *it;
			init_pair.looser = -1;
			init_pair.lonely = false;
			_pairs.push_back(init_pair);
			break ;
		}
	}
	return (_pairs);
}

std::deque<pair>	PmergeMe::parseDeque(std::string &input)
{
	std::istringstream	iss(input);
	std::string			buff;
	std::string			number_string;
	pair				init_pair;

	//parsing
	while (std::getline(iss, buff))
	{
		std::istringstream	word_iss(buff);
		while (std::getline( word_iss, number_string, ' '))
		{
			if (number_string.empty())
				continue ;
			if (!isValidNum(number_string))
				throw std::runtime_error("wrong input at [" + number_string + "]\n");
			_input_deque.push_back(atoi(number_string.c_str()));
			//TODO another container
		}
	}

	if (_input_deque.size() < 2)
		throw std::runtime_error("pass at least 2 numbers");
	//passing to pairs container and first in pair sort
	for (std::deque<int>::iterator	it = _input_deque.begin(); it != _input_deque.end(); it++)
	{
		if (!(std::distance(_input_deque.begin(), it) % 2) && it + 1 != _input_deque.end())
		{
			init_pair.winner = intMax(*it, *(it + 1));
			init_pair.looser = intMin(*it, *(it + 1));
			init_pair.lonely = false;
			_deques.push_back(init_pair);
		}
		if (it + 1 == _input_deque.end() && _input_deque.size() % 2)
		{
			init_pair.winner = *it;
			init_pair.looser = -1;
			init_pair.lonely = false;
			_deques.push_back(init_pair);
			break ;
		}
	}
	return (_deques);

}

//constructors
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &copy)
{
	_input = copy._input;
	_pairs = copy._pairs;
}
PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{ 
	if (this != &other)
	{
		_input = other._input;
		_pairs = other._pairs;
	}
	return (*this);
}
PmergeMe::~PmergeMe() {}



/* void	PmergeMe::MergeInsertVector(std::vector<pair> &container) */
/* { */
/* 	if (container.size() <= 1) */
/* 		return ; */
/* 	//sort the container by winners, lowest first */
/* 	mergeSort(container); */
/* 	if (container.size() % 2) */
/* 		container.back().lonely = true; */

/* 	//create new container of just the winner values */
/* 	std::vector<pair> winners; */
/* 	insertValues(winners, container); */
/* 	/1* for (size_t i = 0; i < container.size(); i++) *1/ */
/* 	/1* { *1/ */
/* 	/1* 	std::cout << "[ " << container[i].winner << " " *1/ */
/* 	/1* 		<< container[i].looser << " ] "; *1/ */
/* 	/1* } *1/ */
/* 	/1* std::cout << "\n winners:  "; *1/ */


/* 	/1* for (size_t i = 0; i < winners.size(); i++) *1/ */
/* 	/1* { *1/ */
/* 	/1* 	std::cout << "[ " << winners[i].winner << " " *1/ */
/* 	/1* 		<< winners[i].looser << " ] "; *1/ */
/* 	/1* } *1/ */
/* 	/1* std::cout << "\n"; *1/ */
/* 	/1* std::cout << "\n"; *1/ */

/* 	//recursive call with new container */
/* 	MergeInsert(winners); */

	
/* 	//sort values and put them in result */
/* 	/1* std::vector<int> 	result; *1/ */
/* 	sortResult(winners, container, _input); */
/* 	/1* std::cout << "\n recursive result: "; *1/ */
/* 	/1* for (size_t i = 0; i < _input.size(); i++) *1/ */
/* 	/1* 	std::cout << _input[i] << "  "; *1/ */
/* 	/1* std::cout << "\n"; *1/ */
/* 	/1* std::cout << "\n"; *1/ */

/* } */
