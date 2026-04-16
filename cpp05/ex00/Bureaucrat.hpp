#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;
public:
	Bureaucrat(std::string name, int grade); // Constructor
	~Bureaucrat() { std::cout << "A Bureaucrat called was destroyed" << std::endl; }; // Destructor
	Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator overload
	Bureaucrat(const Bureaucrat& other); // Copy Constructor

	void		decr_grade();
	void		incr_grade();
	int			get_grade();
	std::string	get_name();
};
#endif