/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:09:01 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/20 20:36:38 by vicmarti         ###   ########.fr       */
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

		operator double();
		//operator float();
		//operator int();
		//operator char();


	private:
		char const	*_raw;
		int		_type;
		double	_d;
		float	_f;
		int		_i;
		char	_c;

		StringConverter(void);
		int	getType(char const *s);
};
#endif

