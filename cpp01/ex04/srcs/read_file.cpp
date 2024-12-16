/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:21:56 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/04 20:33:25 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/main.hpp"

void	check_line(t_stream *data, std::string *line)
{
	std::size_t	substr_idx;
	std::size_t	repl_len = data->replacer.length();
	std::size_t	orig_len = data->original.length();
	std::size_t	start_idx = 0;

	while (start_idx < (*line).length())
	{
		substr_idx = ( *line).find(data->original, start_idx);
		if (substr_idx == std::string::npos)
			return ;
		(*line).erase(substr_idx, orig_len);
		(*line).insert(substr_idx, data->replacer);
		start_idx = substr_idx + repl_len;
	}
}

void	read_file(t_stream *data, char **argv)
{
	std::string	line;
	while(std::getline(data->infile, line))
	{
		check_line(data, &line);
		data->outfile << line << std::endl;
	}

	if (data->infile.bad() || data->outfile.bad())
	{
		data->infile.close();
		data->outfile.close();
		err_msg_exit("problem reading and writing from file", argv);
	}


}
