/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:24:00 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/20 22:06:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base { public: virtual ~Base(void){} };

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base	*generate(void)
{
	int	choose = rand() % 3;

	switch (choose)
	{
		case 0 :
			std::cout << "Generated an instance of \033[31mA\033[0m" << std::endl;
			return (new A());
		case 1 :
			std::cout << "Generated an instance of \033[32mB\033[0m" << std::endl;
			return (new B());
		default:
			std::cout << "Generated an instance of \033[33mC\033[0m" << std::endl;
			return (new C());
	}
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "Reference Identify: \033[31mA\033[0m" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "Reference Identify: \033[32mB\033[0m" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "Reference Identify: \033[33mC\033[0m" << std::endl;

}

void	identify(Base &ref)
{
	try
	{
		A aux = dynamic_cast<A &>(ref);
		std::cout << "Reference Identify: \033[31mA\033[0m" << std::endl;
	}
	catch (...) {}
	try
	{
		B aux = dynamic_cast<B &>(ref);
		std::cout << "Reference Identify: \033[32mB\033[0m" << std::endl;
	}
	catch (...) {}
	try
	{
		C aux = dynamic_cast<C &>(ref);
		std::cout << "Reference Identify: \033[33mC\033[0m" << std::endl;
	}
	catch (...) {}
}

int	main(void)
{
	Base	*ptr;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		if (ptr)
		{
			identify(ptr);
			identify(*ptr);
			delete ptr;
			std::cout << std::endl;
		}
	}
	system("leaks -q identify");
	return (71);
}
