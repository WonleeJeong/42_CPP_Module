#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

class RPN
{
	private:
		std::stack<double> num_stack;
		std::vector<std::string> parsed_av;
	public:
		RPN();
		RPN(const RPN &obj);
		RPN &operator =(const RPN &obj);
		~RPN();
		void	SplitArgs(std::string line, char sep);
		void	ValidTest(std::string line);
		void	MakeResult();
		int	FindOperator(std::string line);
};

# endif