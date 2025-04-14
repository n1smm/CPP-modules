/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:20:17 by thiew             #+#    #+#             */
/*   Updated: 2025/02/24 12:05:52 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

//constructors

Exchange::Exchange(const Exchange &copy)
	: _value(copy._value), _DB(copy._DB), _ledger(copy._ledger) {}


//the one we actually use
Exchange::Exchange(char *file_name)
{ 
	std::ifstream	input(file_name);
	std::ifstream	db("data.csv");
	if (!db.is_open() || !input.is_open())
		throw std::runtime_error("error opening one of the input files: data.csv or"  + std::string(file_name) + "\n");
	if (!parseFile(input, _ledger))
		throw std::runtime_error("error parsing input file\n");
	if (!parseDB(db, _DB))
		throw std::runtime_error("error parsing btc database\n");
	
	if (db.bad() || input.bad())
		throw std::runtime_error("error reading from one of the files\n");
	db.close();
	input.close();
}

Exchange::~Exchange(void) {}

// ------------------------------------------------------

//helper to use with std::remove_if
bool	isWhitespace(char c)
{ return (std::isspace(c)); }

void	checkDate(std::string &line)
{
	size_t start = 0;
    while (start < line.length() && !std::isalnum(line[start]))
	{++start;}
	if (start == line.length())
		throw std::runtime_error("learn how to write properly! what is this : " + line);
	size_t end = start;
	while (end < line.length() && !std::isspace(line[end]))
		end++;
	std::string datestr = line.substr(start, end - start);

	//check len, and if dashes are in the right place
	if (datestr.substr(4, 1) != "-" || datestr.substr(7, 1) != "-"
			|| datestr.length() != 10)
		throw std::runtime_error("date at (" + datestr + 
				") is wrong: length or -");
}

//parses the txt file and stores it in the _ledger map
bool	Exchange::parseFile(std::ifstream &input, FakeMap &ledger)
{
	std::string				line;
	std::string				unparsed;
	std::string				date;
	std::string				value;
    std::string				whitespaces = " \t\r\f\v";
	int						i = 1;

	/* std::getline(input, line); // TODO parse the first line */
	checkFirstLine(input, true, whitespaces);
	while (std::getline(input, line))
	{
		i++;
		unparsed = line;
		/* checkDate(line); */
		line.erase(std::remove_if(line.begin(), line.end(), isWhitespace), line.end());
		if (line.find("|") == std::string::npos)
		{
			std::cerr << "unfinished or empty line at: " << i << std::endl;
		}
		else
		{
			std::istringstream	checked_line(line);
			if (!std::getline(checked_line, date, '|') || !std::getline(checked_line, value))
				throw std::runtime_error("error parsing line with date and time: " + line + "\n");
			if (unparsed.find(date) == std::string::npos)
				std::cerr << "wrong formatting of date at line: " << i << std::endl;
			else if (unparsed.find(value) == std::string::npos)
				std::cerr << "wrong formatting of value at line: " << i << std::endl;
			else
			{
				Date	dt(date);
				double	res = parseValue(value);
				if (res > 1000) 
					std::cerr << "value > 1000 at: " << i << "\n";
				if (res == -1)
					std::cerr << ": at: " << i << "\n";
				if (!dt.isValidDate(dt))
					std::cerr << ": at " << i << "\n";
				if (res >= 0 && res <= 1000 && dt.isValidDate(dt))
					ledger.insert(dt, res);

				// else
				// 	std::cerr << "too large number: " << std::fixed << res << "\n";
			}
			if (checked_line.bad())
				throw std::runtime_error("error reading parsed line: " + line + "\n");
		}
	}

	return (true);
}

//parses .csv file and stores it in a _db map
bool	Exchange::parseDB(std::ifstream &input, std::map<Date, double> &db)
{
	std::string				line;
	std::string				date;
	std::string				value;
    std::string				whitespaces = " \t\r\f\v";
	std::map<Date, double>	tmp;

	/* std::getline(input, line); // TODO - parse first line */
	checkFirstLine(input, false, whitespaces);
	while (std::getline(input, line))
	{
		if (line.find_first_of(whitespaces) != std::string::npos)
			throw  std::runtime_error("found whitespace on line: " + line);
		std::istringstream	strstream(line);
		if (!std::getline(strstream, date, ',') || !std::getline(strstream, value))
			throw std::runtime_error("couldn't parse: " + line + "\n");
		Date	dt(date);
		double	res = parseValue(value);
		db.insert(std::make_pair(dt, res));
	}
	return (true);
}

void	Exchange::checkFirstLine(std::ifstream &input, bool is_file, std::string whitespaces)
{
	std::string line;
	std::string	word;

	std::getline(input, line); // TODO - parse first line
	if (is_file)
	{
		line.erase(std::remove_if(line.begin(), line.end(), isWhitespace), line.end());
		std::istringstream oss(line);
		std::getline(oss, word, '|');
		if (word != "date")
			throw std::runtime_error("header " + line + " not setup correctly - "
					" write date | value \n");
		std::getline(oss, word);
		if (word != "value")
			throw std::runtime_error("header " + line + " not setup correctly\n - "
					" write date | value ");
	}
	else
	{
		if (line.find_first_of(whitespaces) != std::string::npos)
			throw  std::runtime_error("found whitespace on line: " + line);
		std::istringstream oss(line);
		std::getline(oss, word, ',');
		if (word != "date")
			throw std::runtime_error("header " + line + "not setup correctly\n");
		std::getline(oss, word);
		if (word != "exchange_rate")
			throw std::runtime_error("header " + line + "not setup correctly\n");
	}
}


//checks if value is valid
double	Exchange::parseValue(std::string &input)
{
	std::istringstream iss(input);
	double value;

	if (!(iss >> value))
	{
		std::cerr << "invalid value: " << input;
		return (-1);
	}
	else if (iss.peek() != std::istringstream::traits_type::eof())
	{
		std::cerr << "invalid value: " << input;
		return (-1);
	}
	else if (value < 0)
	{
		std::cerr << "value < 0 at: " << input;
		return (-1);
	}
	// else if (value > 1000)
	// {
	// 	std::cerr << "value > 1000 at: " << input << "\n";
	// 	return (-1);
	// }
	
	return value;
}

//---------------------------------

//getters
std::map<Date, double>	&Exchange::getMap()
{ return (_DB); }

FakeMap					&Exchange::getLedger()
{ return (_ledger); }


// ----------------------- << overload --------------

std::ostream	&operator<<(std::ostream &ostr, Exchange &obj)
{
	std::map<Date, double>		db = obj.getMap();

	std::map<Date, double>::iterator itdb = db.begin();
	ostr << obj.getLedger() << "\n\n\n";
	ostr << "\n\n\nDB \n ";
		while (itdb != db.end())
		{
			ostr << "[ " << itdb->first << " ], [ " << itdb->second << " ]\n";
			++itdb;
		}

	return (ostr);
}

Exchange::Exchange(const FakeMap &input)
	: _ledger(input)
{
	std::ifstream db("data.csv");
	if (!db.is_open())
		throw std::runtime_error("error opening data.csv\n");
	if (!parseDB(db, _DB))
		throw std::runtime_error("error parsing btc database\n");
	if (db.bad())
		throw std::runtime_error("error reading from data.csv\n");
	db.close();
}
