/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:19:47 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/21 23:29:26 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
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
	std::cout << std::fixed;
	if (conv.charOvfl())
		std::cout << "Character: " << "immpossible" << std::endl;
	else if (!isprint(static_cast<char>(conv)))
		std::cout << "Character: " << "Non printable" << std::endl;
	else
		std::cout << "Character: '" << static_cast<char>(conv) << "'" << std::endl;
	if (conv.intOvfl())
		std::cout << "Integer:   " << "immpossible" << std::endl;
	else
		std::cout << "Integer:   " << static_cast<int>(conv) << std::endl;
	if (static_cast<float>(conv) == static_cast<int>(conv))
		std::cout << "Float:     " << static_cast<float>(conv) << ".0f" << std::endl;
	else
		std::cout << "Float:     " << static_cast<float>(conv) << "f" << std::endl;
	if (static_cast<double>(conv) == static_cast<int>(conv))
		std::cout << "Double:    " << static_cast<double>(conv) << ".0" << std::endl;
	else
		std::cout << "Double:    " << static_cast<double>(conv) << std::endl;
	return (0);
}
