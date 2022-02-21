/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:13:06 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/21 23:23:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringConverter.hpp"
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include <iostream>

StringConverter::StringConverter(char const *s)
{
	long	ovf_aux;

	this->_overflows = 0;
	if (!isLiteral(s))
	{
		this->_c = s[0];
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
	}
	else
	{//TODO overflow checks
		this->_d = strtod(s, NULL);
		this->_f = strtof(s, NULL);
		ovf_aux = strtol(s, NULL, 10);
		errno = 0;
		this->_i = static_cast<int>(ovf_aux);
		if (ovf_aux < INT_MIN || ovf_aux > INT_MAX || errno == ERANGE)
		{
			this->_i = 1337;
			this->_overflows |= 0b11;
		}
		else if (ovf_aux < CHAR_MIN || ovf_aux > CHAR_MAX)
			this->_overflows |= 0b01;
		errno = 0;
		this->_c = static_cast<char>(this->_i);
	}
}

StringConverter::StringConverter(StringConverter const &stringconverter)
{
	*this = stringconverter;
}

StringConverter::~StringConverter(void)
{}

StringConverter	&StringConverter::operator=(StringConverter const &stringconverter)
{
	this->_overflows = stringconverter._overflows;
	this->_c = stringconverter._c;
	this->_i = stringconverter._i;
	this->_f = stringconverter._f;
	this->_d = stringconverter._d;
	return (*this);
}

bool	StringConverter::charOvfl(void)
{
	return (this->_overflows & 0b1);
}

bool	StringConverter::intOvfl(void)
{
	return (this->_overflows & 0b10);
}

bool	StringConverter::isLiteral(char const *s) const
{
	if (strcmp(s, "nan") == 0 || strcmp(s, "nanf") == 0)
		return (true);
	if (s[0] == '+' || s[0] == '-')
		s++;
	if (strcmp(s, "inf") == 0 || strcmp(s, "inff") == 0)
		return (true);
	while (isdigit(s[0]))
		s++;
	if (s[0] == '.')
	{
		s++;
		while (isdigit(s[0]))
			s++;
		if (tolower(s[0]) == 'f' || tolower(s[0]) == 'd')
			s++;
	}
	return (s[0] == 0);
}

StringConverter::operator char()
{
	return (this->_c);
}

StringConverter::operator int()
{
	return (this->_i);
}

StringConverter::operator float()
{
	return (this->_f);
}

StringConverter::operator double()
{
	return (this->_d);
}

