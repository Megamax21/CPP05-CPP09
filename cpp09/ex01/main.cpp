#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN myRPN;
	if (ac > 2)
	{
		std::cout << "Must use program this way : ./RPN `expression`" << std::endl;
		return (-1);
	}
	myRPN.calculate(av[1]);
	if (!myRPN.get_error())
		std::cout << myRPN.get_result() << std::endl;
	return (0);
}