#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int mRawBits;
	static const int mFractionalBits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed(const Fixed& oldFixed);
	const Fixed&		operator=(const Fixed& rhs);
	bool				operator>(const Fixed& rhs);
	bool				operator<(const Fixed& rhs);
	bool				operator>=(const Fixed& rhs);
	bool				operator<=(const Fixed& rhs);
	bool				operator!=(const Fixed& rhs);
	Fixed				operator+(const Fixed& rhs);
	Fixed				operator-(const Fixed& rhs);
	Fixed				operator*(const Fixed& rhs);
	Fixed				operator/(const Fixed& rhs);
	const Fixed&		operator++();
	Fixed				operator++(int);
	const Fixed&		operator--();
	Fixed				operator--(int);
	int					getRawBits(void) const;
	void				setRawBits(const int raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	static const Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	static const Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif