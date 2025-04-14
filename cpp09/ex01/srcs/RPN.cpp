/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:33:55 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/21 16:18:44 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/RPN.hpp"

std::stack<int>	RPN::_stack;

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &copy) { _stack = copy._stack; }
RPN		&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

int		operate(std::string operate, int b, int a)
{
	if (operate == "+")
		return (a + b);
	if (operate == "-")
		return (a - b);
	if (operate == "*")
		return (a * b);
	if (operate == "/")
		return (a / b);
	return (0);
}

bool	isNum(std::string word)
{
	size_t	i;
	for (i = 0; i < word.size(); i++)
	{
		if (!std::isdigit(word[i]))
			break;
	}
	if (i == word.size() && word.size() != 0)
		return (true);
	return (false);
}

void	RPN::calculate(char *input)
{
	std::stringstream	ss(input);
	std::string			word;
	std::string			operators = "+-/*";
	int					res = 0;

	while (std::getline(ss, word, ' '))
	{
		if (word == "+" || word == "-" || word == "*" || word == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("couldn't perform operation [" + word + "] : RPN:65\n");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			res = operate(word, b, a);
			_stack.push(res);
		}
		else if (isNum(word) && atoi(word.c_str()) >= 0 && atoi(word.c_str()) < 10)
		{
			_stack.push(atoi(word.c_str()));
		}
		else
			throw std::runtime_error("wrong argument [" + word + "] : RPN:78\n");
	}
	if (_stack.size() == 1)
		std::cout << "result is : " << _stack.top();
	else
	{
		if (_stack.empty())
			throw std::runtime_error("nothing to do");
		std::cout << "there are still unused values remaining in stack: ";
		while (!_stack.empty())
		{
			std::cout << _stack.top();
			_stack.pop();
			if (!_stack.empty())
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
}
