/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:27:04 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 19:01:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"


int	main( int argc, char **argv)
{
	try
	{
		if (argc != 4)
			err_msg_exit("wrong number of arguments", argv);

		t_stream		data; 
		std::string		new_file_name = argv[1];
		data.original = argv[2];
		data.replacer = argv[3];


		data.infile.open(argv[1]);
		if (data.infile.fail())
			err_msg_exit("Error opening file. You sure it exists and has read perimissions?", argv);
		new_file_name.append(".replace");
		data.outfile.open(new_file_name.c_str(), std::ios::trunc);
		if (data.outfile.fail())
		{
			data.infile.close();
			err_msg_exit("Something wrong with the outfile", argv);
		}
		read_file(&data, argv);
		data.infile.close();
		data.outfile.close();
		return (0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return (1);
	}
	
	
}
