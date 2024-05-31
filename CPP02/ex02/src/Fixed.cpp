/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 05/31/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 05/31/2024                   */
/* ⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀                                                       */
/* ⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆ ⠀       Email: brunrodr@student.42sp.org.br                 */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀   ⢽⣿⣿⠛⢻⣿⣿⣿⣿⠛⠛⠛⠛⢻⣿⣿⠿⠛⠛⠿⣿⡟⠛⠛⠛⠛⣿⡟⢿⣿⣿⣿⠛⢻⡟⠛⠛⠛⠻⣿⣿⣿ */
/* ⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢿⣿⣿⣿⡿⠁⣴⣶⣶⣾⣿⡇⠀⣿⣿⣿⣿⡏⢀⠙⢿⣿⠀⢸⡇⠀⣷⣷⣆⠈⢿⣿ */
/* ⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢤⣤⣴⣿⣧⠀⢿⣿⣤⠀⣿⡇⠀⣤⣤⣼⣿⡇⠀⣷⣄⠙⠀⢸⡇⠀⣿⣿⡟⠀⣸⣿ */
/*  ⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤  ⢸⣿⣿⣀⣈⣉⣉⣉⣿⣀⣈⣉⣉⣹⣿⣷⣄⣈⣁⣤⣿⣇⣀⣉⣉⣉⣿⣇⣀⣿⣿⣷⣄⣸⣧⣀⣉⣉⣀⣴⣿⣿ */
/*************************************************************************************/

#include "../include/Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int intValue)
{
	rawBits = intValue << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floatValue)
{
	rawBits = roundf((floatValue) * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &toCopy)
		this->rawBits = toCopy.rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

int	Fixed::toInt(void) const
{
	int	fixedToInt = this->rawBits >> fractionalBits;
	return (fixedToInt);
}

float	Fixed::toFloat(void) const
{
	float fixedToFloat = this->rawBits / roundf(1 << fractionalBits);
	return (fixedToFloat);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed		Fixed::operator*(const Fixed& obj)
{
	return (this->toFloat() * obj.toFloat());
}

Fixed		Fixed::operator/(const Fixed& obj)
{
	return (this->toFloat() / obj.toFloat());
}

Fixed		Fixed::operator+(const Fixed& obj)
{
	return (this->toFloat() + obj.toFloat());
}

Fixed		Fixed::operator-(const Fixed& obj)
{
	return (this->toFloat() - obj.toFloat());
}

// Pre-increment
Fixed&		Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}

//Post-increment
Fixed		Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->rawBits++;
	return (temp);
}

Fixed		Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a.toFloat());
	return (b.toFloat());
}

const Fixed		Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed		Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed		Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}