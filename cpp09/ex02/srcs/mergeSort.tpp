/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:05:33 by tjuvan            #+#    #+#             */
/*   Updated: 2025/02/21 12:38:23 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/PmergeMe.hpp"

template <typename Container>
void *mergeSortThread(void *args)
{
    ThreadArg<Container> *thread_args = static_cast<ThreadArg<Container>*>(args);
    mergeSort(*thread_args->container);
    return NULL;
}

template <typename Container>
Container mergeHalves(Container left, Container right)
{
    Container res;
    typename Container::iterator it_left = left.begin();
    typename Container::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (!cmpPairs(*it_left, *it_right))
        {
            res.push_back(*it_left);
            it_left++;
        }
        else
        {
            res.push_back(*it_right);
            it_right++;
        }
    }
    for (; it_left != left.end(); it_left++)
        res.push_back(*it_left);
    for (; it_right != right.end(); it_right++)
        res.push_back(*it_right);
    return res;
}

template <typename Container>
void mergeSort(Container &container)
{
    if (container.size() <= 1)
        return;

    size_t mid = container.size() / 2;
    Container left(container.begin(), container.begin() + mid);
    Container right(container.begin() + mid, container.end());

    if (container.size() > THRESHOLD)
    {
        pthread_t leftThread, rightThread;
        ThreadArg<Container> leftArgs = { &left };
        ThreadArg<Container> rightArgs = { &right };

        pthread_create(&leftThread, NULL, mergeSortThread<Container>, &leftArgs);
        pthread_create(&rightThread, NULL, mergeSortThread<Container>, &rightArgs);

        pthread_join(leftThread, NULL);
        pthread_join(rightThread, NULL);
    }
    else
    {
        mergeSort(left);
        mergeSort(right);
    }
    Container sorted = mergeHalves(left, right);
    container = sorted;
}

/* void	*mergeSortThread(void *args) */
/* { */
/* 	ThreadArg *thread_args = static_cast<ThreadArg*>(args); */
/* 	mergeSort(*thread_args->container); */
/* 	return (NULL); */
/* } */

/* std::vector<pair>	mergeHalves(std::vector<pair> left, std::vector<pair> right) */
/* { */
/* 	std::vector<pair>	res; */
/* 	std::vector<pair>::iterator	it_left = left.begin(); */
/* 	std::vector<pair>::iterator	it_right = right.begin(); */

/* 	while (it_left != left.end() && it_right != right.end()) */
/* 	{ */
/* 		if (!cmpPairs(*it_left, *it_right)) */
/* 		{ */
/* 			res.push_back(*it_left); */
/* 			it_left++; */
/* 		} */
/* 		else */
/* 		{ */
/* 			res.push_back(*it_right); */
/* 			it_right++; */
/* 		} */
/* 	} */
/* 	for (; it_left != left.end(); it_left++) */
/* 		res.push_back(*it_left); */
/* 	for (; it_right != right.end(); it_right++) */
/* 		res.push_back(*it_right); */
/* 	return (res); */
/* } */

/* void	mergeSort(std::vector<pair>	&container) */
/* { */
/* 	if (container.size() <= 1) */
/* 		return ; */

/* 	size_t mid = container.size() / 2; */
/* 	std::vector<pair> left(container.begin(), container.begin() + mid); */
/* 	std::vector<pair> right(container.begin() + mid, container.end()); */

/* 	if (container.size() > THRESHOLD) */
/* 	{ */
/* 		pthread_t	leftThread, rightThread; */
/* 		ThreadArg	leftArgs = { &left }; */
/* 		ThreadArg	rightArgs = { &right }; */

/* 		pthread_create(&leftThread, NULL, mergeSortThread, &leftArgs); */
/* 		pthread_create(&rightThread, NULL, mergeSortThread, &rightArgs); */

/* 		pthread_join(leftThread, NULL); */
/* 		pthread_join(rightThread, NULL); */
/* 	} */
/* 	else */
/* 	{ */
/* 		mergeSort(left); */
/* 		mergeSort(right); */
/* 	} */
/* 	std::vector<pair> sorted = mergeHalves(left, right); */
/* 	container = sorted; */
/* } */
