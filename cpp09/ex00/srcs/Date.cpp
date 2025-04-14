/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:19:42 by thiew             #+#    #+#             */
/*   Updated: 2025/02/21 15:36:13 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Date.hpp"

//constructors
Date::Date() : _year(0), _month(1), _day(1) 
{}

Date::~Date() {}

Date::Date(const Date &copy) : _year(copy._year), _month(copy._month),
	_day(copy._day) {}

Date::Date( std::string &unparsed)
{
	try
	{
		// basic parsing
		parseDate(unparsed);
		//check for valid date
		if (!isValidDate(*this))
			throw std::runtime_error("date at (" + unparsed +
					") is wrong: incorrect or out of scope date");
	} catch ( const std::invalid_argument &e)
	{ std::cerr << "date " + unparsed + " has a non-numeric value\n"; }
	catch (const std::out_of_range &e)
	{ std::cerr << "date " + unparsed + " is out of range\n"; }
	catch (const std::exception &e)
	{ std::cerr << e.what() << std::endl; }
}

//overload
Date			&Date::operator=( const Date &other)
{
	if (this != &other)
	{
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return (*this);
}
bool	Date::operator<( const Date &other ) const
{
	if (_year != other._year) return (_year < other._year);
	if (_month != other._month) return (_month < other._month);
	return (_day < other._day);
}

bool	Date::operator>( const Date &other ) const
{
	if (_year != other._year) return (_year > other._year);
	if (_month != other._month) return (_month > other._month);
	return (_day > other._day);
}

bool	Date::operator==(const Date &other) const
{
	return (
			_year == other._year &&
			_month == other._month &&
			_day == other._day
		   );
}

//methods

void			Date::parseDate(std::string &unparsed)
{
		//check len, and if dashes are in the right place
		if (unparsed.substr(4, 1) != "-" || unparsed.substr(7, 1) != "-"
				|| unparsed.length() != 10)
			throw std::runtime_error("date at (" + unparsed + 
					") is wrong: length or -");

		// Extract date into container vars
		std::istringstream yearStream(unparsed.substr(0, 4));
		std::istringstream monthStream(unparsed.substr(5, 2));
		std::istringstream dayStream(unparsed.substr(8, 2));

		if (!(yearStream >> _year)) {
			throw std::runtime_error("invalid year in date: " + unparsed);
		}
		if (!(monthStream >> _month)) {
			throw std::runtime_error("invalid month in date: " + unparsed);
		}
		if (!(dayStream >> _day)) {
			throw std::runtime_error("invalid day in date: " + unparsed);
		}

}

bool			Date::isValidDate( const Date &uncheckedDate)
{
	// construct tm struct
	time_t timestamp;
	time_t currentTimestamp;
	std::tm	dateTime = {};

	dateTime.tm_year = uncheckedDate._year - 1900;
	dateTime.tm_mon = uncheckedDate._month - 1;
	dateTime.tm_mday = uncheckedDate._day;

	//check if valid date
	if ((timestamp = mktime(&dateTime)) < 0)
		return (false);
    if (dateTime.tm_year != uncheckedDate._year - 1900 
			|| dateTime.tm_mon != uncheckedDate._month - 1 
			|| dateTime.tm_mday != uncheckedDate._day)
		return (false);
	if ((currentTimestamp = std::time(NULL)) < timestamp)
		return (false);
	return (true);
}

std::string		Date::formatDate() const
{
	std::ostringstream	oss;

	oss << _year << "-" 
		<< std::setw(2) << std::setfill('0') << _month << "-"
		<< std::setw(2) << std::setfill('0') << _day;
	oss << std::setfill(' ') << std::setw(0);
	std::string	str = oss.str();
	return (str);
}

//getters
int				Date::getYear() const { return (_year); };
int				Date::getMonth() const { return (_month); };
int				Date::getDay() const { return (_day); };

std::ostream 	&operator<<(std::ostream &ostr, const Date &obj)
{
	ostr << "year: " << obj.getYear() << ", month: " 
		<< obj.getMonth() << ", day: " << obj.getDay();
	return (ostr);
}
