#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
: mName("Default")
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name)
: mName(name)
, mGrade(150) {}
Bureaucrat::Bureaucrat(const std::string& name, const int grade)
: mName(name)
, mGrade(grade)
{
	if (mGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	if (mGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
Bureaucrat::~Bureaucrat() {};
Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
: mName(rhs.mName)
, mGrade(rhs.mGrade) {}
const std::string& Bureaucrat::GetName() const
{
	return mName;
}
int Bureaucrat::GetGrade() const
{
	return mGrade;
}
void Bureaucrat::Increment(const unsigned int amount)
{
	int increasedGrade = mGrade - amount;

	if (amount > 149 ||increasedGrade > 150 ||increasedGrade < 1)
	{
		throw GradeTooHighException();
	}
	mGrade = increasedGrade;
}
void Bureaucrat::Decrement(const unsigned int amount)
{
	int decreasedGrade = mGrade + amount;

	if (amount > 149 ||decreasedGrade > 150 ||decreasedGrade < 1)
	{
		throw GradeTooLowException();
	}
	mGrade = decreasedGrade;
}
void Bureaucrat::SignForm(AForm& form) const
{
	try
	{
		form.BeSigned(*this);
		std::cout << mName << " signed " << form.GetName() << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cout << mName << " couldn\'t sign " << form.GetName() << " because " << e.what() << std::endl;
	}
}
void Bureaucrat::ExecuteForm(const AForm& form) const
{
	try
	{
		form.Execute(*this);
		std::cout << GetName() << " executed " << form.GetName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << '.';
	return os;
}
