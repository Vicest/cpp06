/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:13:06 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/20 21:08:54 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringConverter.hpp"
#include <string>
#include <stdlib.h>
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

StringConverter::StringConverter(char const *s)
{
	this->_raw = s;
	this->_type = getType(s);
}

StringConverter::StringConverter(StringConverter const &stringconverter)
{
	*this = stringconverter;
}

StringConverter::~StringConverter(void)
{}

StringConverter	&StringConverter::operator=(StringConverter const &stringconverter)
{
	this->_raw = stringconverter._raw;
	this->_type = getType(this->_raw);
	return (*this);
}

int	StringConverter::getType(char const *s)
{
	size_t	len = strlen(s);

	if (len == 1 && !isdigit(s[0]))
		return (CHAR);
//	else if (s.find('.') == std::string::npos)
//		return (INT);
	else if (tolower(s[len - 1]) == 'f')
		return (FLOAT);
	else
		return (DOUBLE);
}

StringConverter::operator double()
{
	return (strtod(this->_raw, NULL));
}

