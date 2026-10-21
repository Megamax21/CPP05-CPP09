#include "RPN.hpp"

RPN::RPN()
{
	error_catcher = false;
	// std::cout << "Constructor called" << std::endl;
}

RPN::~RPN()
{
	// std::cout << "Destructor called" << std::endl;
}

bool	RPN::get_error() const
{
	return (error_catcher);
}


int	RPN::operate(char op)
{
	int	temp;
	switch (op)
	{
	case '+':
		temp = values.top();
		values.pop();
		values.top() = values.top() + temp;
		break;
	case '-':
		temp = values.top();
		values.pop();
		values.top() = values.top() - temp;
		break;
	case '/':
		temp = values.top();
		values.pop();
		values.top() = values.top() / temp;
		break;
	case '*':
		temp = values.top();
		values.pop();
		values.top() = values.top() * temp;
		break;
	
	default:
		return (-1);
		break;
	}
	return (0);
}

void	RPN::calculate(std::string exp)
{
	int i = 0;

	while (exp[i])
	{
		if (isdigit(exp[i]))
			values.push(exp[i]-'0');
		else if (exp[i] != ' ')
		{
			if (values.size() < 2)
			{
				std::cout << "Expression may be missing a digit" << std::endl;
				error_catcher = true;
				return ;
			}
			if (operate(exp[i]) != 0)
			{
				std::cout << "Expression contains an error at index " << i << " : " << exp[i] << std::endl;
				error_catcher = true;
			}
		}
		i++;
	}
	if (values.size() > 1)
	{
		std::cout << "Expression is missing an operator" << std::endl;
		error_catcher = true;
	}
	result = values.top();
}

int	RPN::get_result(void) const
{
	return (result);
}