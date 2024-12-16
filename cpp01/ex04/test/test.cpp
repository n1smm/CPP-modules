/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:07:43 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 21:32:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	err_msg_exit(std::string msg, char **argv)
{

		std::cerr << RED << msg << std::endl;
		std::cerr << "Correct syntax: " << argv[0] << 
			" <input file> <str to replace> <replacer str>" << RESET << std::endl;
		exit(1);
}

void	print_results(int i, int j, char **argv, std::string files[],
		std::string originals[], std::string replacers[])
{
	std::string	line;
	std::string	line2;
	std::string	file_name2;
	std::ifstream	infile;
	std::ifstream	infile2;
	int	status;

	pid_t	pid = fork();
	if (pid == -1) 
	{
		std::cerr << "Error forking process: " << strerror(errno) << std::endl;
		exit(1);
	}
	else if (pid == 0)
	{
		if (execl(argv[1], argv[1], files[i].c_str(),
					originals[j].c_str(), replacers[j].c_str(), NULL) == -1)
		{
			std::cerr << "Error executing program: " << strerror(errno) << std::endl;
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			std::cout << GREEN << "printing out: <" << files[i] 
				<< "> original: <" << originals[j] << "> replacer: <" << replacers[j] 
				<< ">" << RESET << std::endl;
			infile.open(files[i].c_str());
			file_name2 = files[i];
			file_name2.append(".replace");
			infile2.open(file_name2.c_str());
			while (std::getline(infile, line) && std::getline(infile2, line2))
			{
				if (line != line2)
				{
					std::cout << BLUE << "original line: " << std::endl
						<< line << RESET << std::endl;
					std::cout << RED << "replacer line: " << std::endl
						<< line2 << RESET << std::endl;
				}

			}
			std::cout << std::endl;
			infile.close();	
			infile2.close();
			file_name2.clear();
		}
	}
}

int	main (int argc, char **argv)
{
	if (argc != 2)
		err_msg_exit("wrong number of arguments", argv);
	std::string files[] = { "file1", "file2", "file3", "file4" };
	std::string originals[] = { "it", "us", "a", "z", "gooo", "no", "kkkkkkkkkkk", " " };
	std::string replacers[] = { "ipsum", "lorem", "m", "g", "shhh", "yes", "abrakadabra", "*" };
	std::size_t	f_len = sizeof(files) / sizeof(files[0]);
	std::size_t	o_len = sizeof(originals) / sizeof(originals[0]);

	for (std::size_t i=0; i < f_len; i++)
	{
		for (std::size_t j=0; j < o_len; j++)
		{
			print_results(i, j, argv, files, originals, replacers);
		}
	}
	std::cout << "EOF EOF EOF\n";
}
