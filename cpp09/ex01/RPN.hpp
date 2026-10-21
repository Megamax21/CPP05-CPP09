#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstdlib>

class RPN
{
private :
	std::stack<int>	values; // that stack will stock the numeric values
	int				result;
	bool			error_catcher;
public :
	RPN();
	~ RPN();
	void	calculate(std::string expression);
	int		operate(char op); // op -> operator
	bool	get_error() const;
	int		get_result() const;
};

// 3 5 8 * 7 + * => 3*((5*8) + 7) = 141
#endif