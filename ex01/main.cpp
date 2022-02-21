/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:24:00 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/21 21:20:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	char	x;
	char	y;
	char	z;
};

uintptr_t	serialize(Data *dataptr)
{
	return (reinterpret_cast<uintptr_t>(dataptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	struct Data	my_struct;
	struct Data	*dest;
	uintptr_t	garbage;

	my_struct.x = 'l';
	my_struct.y = 'o';
	my_struct.z = 'l';
	std::cout << &my_struct << ">"
		<< my_struct.x << "|"
		<< my_struct.y << "|"
		<< my_struct.z << std::endl;
	garbage = serialize(&my_struct);
	std::cout << garbage << std::endl;
	dest = deserialize(garbage);
	std::cout << dest << ">"
		<< dest->x << "|"
		<< dest->y << "|"
		<< dest->z << std::endl;
	return (71);
}
