/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:09:01 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/21 23:08:10 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGCONVERTER_HPP
# define STRINGCONVERTER_HPP
# include <string>

class StringConverter
{
	public:
		StringConverter(char const *s);
		StringConverter(StringConverter const &stringconverter);
		virtual ~StringConverter(void);
		StringConverter	&operator=(StringConverter const &stringconverter);

		bool	charOvfl(void);
		bool	intOvfl(void);
		operator double();
		operator float();
		operator int();
		operator char();


	private:
		double	_d;
		float	_f;
		int		_i;
		char	_c;
		char	_overflows;

		StringConverter(void);
		bool	isLiteral(char const *s) const;
};
#endif

