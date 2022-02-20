/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:19:47 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/20 20:36:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StringConverter.hpp"

int main(int argc, char **argv)
{
	StringConverter	conv("0");

	if (argc != 2)
	{
		std::cout << "Only one argument, please." << std::endl;
		return (-1);
	}
	conv = StringConverter(argv[1]);
//	print_char(s, type);
//	print_int(s, type);
//	print_float(s, type);
//	print_double(s, type);
	std::cout << "Double: " << static_cast<double>(conv) << std::endl;
	return (0);
}
