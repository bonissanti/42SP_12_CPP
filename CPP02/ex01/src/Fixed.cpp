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

#include "../include/Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	rawBits = intValue << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	rawBits = (roundf(floatValue * (1 << fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy){
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
	{
		this->rawBits = toCopy.rawBits;
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	float	fixedToFloat = (this->rawBits / (roundf(1 << fractionalBits)));
	return (fixedToFloat);
}

int		Fixed::toInt(void) const
{
	int	fixedToInt = this->rawBits >> fractionalBits;
	return (fixedToInt);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}