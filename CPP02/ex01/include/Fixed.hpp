/***************************************************************************************/
/* ⠀⠀⠀⠀⠀⠀⠀⢀⣠⣄⣶⢟⣶⣵⣲⢠⡀⣀⠀⠀⠀⠀⠀⠀⠀                                                      */
/* ⠀⠀⠀⠀⢀⣠⣾⣿⣿⡻⡿⣿⣿⣷⣿⣿⣷⣾⣾⣦⡀⠀⠀⠀⠀                                                      */
/* ⠀⠀⠀⣴⣿⡿⠿⠟⠿⠿⠿⢿⣿⢿⣽⣿⣿⣽⣿⣾⣓⡄⠀⠀⠀                                                      */
/* ⠀⢀⣼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⢿⣟⣿⡄⠀⠀                                                      */
/* ⠀⣸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣷⡀⠀  Created by: brunrodr - 05/30/2024                   */
/* ⠀⢹⡿⠃⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⢻⣿⣿⣿⡇⠀  Updated by: brunrodr - 05/30/2024                   */
/* ⠀⢸⠁⠜⠉⣠⣭⣿⣿⡆⠀⠀⢠⣿⣿⣉⣉⡉⢢⠀⠙⣿⣿⡇⠀                                                      */
/* ⣠⢼⡇⠀⠚⠁⠉⠁⠉⠀⠀⢠⠛⠉⠈⠛⠘⠿⠚⡄⠀⣿⣿⡇⡀  Email: brunrodr@student.42sp.org.br                 */
/* ⡙⠁⡇⠀⠀⠀⠀⠀⠀⠀⠀⠘⢃⠀⠀⠀⠀⠀⠀⠀⠀⢻⡡⠚⣿                                                      */
/* ⢇⠀⡇⠀⠀⠀⠀⠀⢀⡤⣤⣤⣄⣁⠀⠀⠀⠀⠀⡠⢀⡇⠁⠀⡜                                                      */
/* ⠘⢄⡃⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⢀⣬⠃⠨⠖⡠⠖⠀                                                      */
/* ⠀⠀⠀⠀⠀⠀⠀⢤⣖⣛⣛⢛⣓⣶⣴⠂⢀⠎⠀⠀⠘⡇⠀⠀⠀  ⢽⣿⣿⠛⢻⣿⣿⣿⣿⠛⠛⠛⠛⢻⣿⣿⠿⠛⠛⠿⣿⡟⠛⠛⠛⠛⣿⡟⢿⣿⣿⣿⠛⢻⡟⠛⠛⠛⠻⣿⣿⣿ */
/* ⠀⠀⢰⠀⠀⢃⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⡞⠀⠀⡇⠀⡇⠀⠀⠀  ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢿⣿⣿⣿⡿⠁⣴⣶⣶⣾⣿⡇⠀⣿⣿⣿⣿⡏⢀⠙⢿⣿⠀⢸⡇⠀⣷⣷⣆⠈⢿⣿ */
/* ⠀⠀⠀⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⣰⠃⡆⢡⡀⠀⠀  ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢤⣤⣴⣿⣧⠀⢿⣿⣤⠀⣿⡇⠀⣤⣤⣼⣿⡇⠀⣷⣄⠙⠀⢸⡇⠀⣿⣿⡟⠀⣸⣿ */
/* ⠀⠀⡀⣴⡏⢠⡀⠀⠀⠀⠀⠀⠀⠀⠊⣀⣤⡾⠋⠁⠀⢸⣿⠦⠀  ⢸⣿⣿⣀⣈⣉⣉⣉⣿⣀⣈⣉⣉⣹⣿⣷⣄⣈⣁⣤⣿⣇⣀⣉⣉⣉⣿⣇⣀⣿⣿⣷⣄⣸⣧⣀⣉⣉⣀⣴⣿⣿ */
/***************************************************************************************/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
	int					rawBits;
	static const int	fractionalBits;

	public:
	Fixed();
	Fixed(const int value);
	Fixed(const float vValue);
	~Fixed();
	Fixed(const Fixed& toCopy);
	Fixed& operator=(const Fixed& toCopy);

	float		toFloat(void)const;
	int			toInt(void)const;
	int			getRawBits(void) const;
	void		setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif