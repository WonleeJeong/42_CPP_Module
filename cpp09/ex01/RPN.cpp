#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &obj)
{
	this->num_stack = obj.num_stack;
	this->parsed_av = obj.parsed_av;
}

RPN &RPN::operator=(const RPN &obj)
{
	if (this == &obj)
		return (*this);
	this->num_stack = obj.num_stack;
	this->parsed_av = obj.parsed_av;
	return (*this);
}

RPN::~RPN()
{
}

void	RPN::SplitArgs(std::string line, char sep)
{
	std::stringstream ss;
	std::string buf;

	ss.str(line);
	while (getline(ss, buf, sep))
		this->parsed_av.push_back(buf);
}

void RPN::ValidTest(std::string line)
{
	if (line.size() != 1)
	{
		throw std::logic_error("Error");
	}
	if (!(line[0] >= 48 && line[0] <= 57))
	{
		if (line[0] != '-' && line[0] != '+' && line[0] != '*' && line[0] != '/')
		{
			throw std::logic_error("Error");
		}
	}
}

int RPN::FindOperator(std::string line)
{
	if (line[0] == '+')
		return (1);
	else if (line[0] == '-')
		return (2);
	else if (line[0] == '*')
		return (3);
	else if (line[0] == '/')
		return (4);
	return (0);
}

void	RPN::MakeResult()
{
	double	data;
	char	*temp;

	for (size_t i = 0; i < this->parsed_av.size(); i++)
	{
		ValidTest(this->parsed_av[i]);
		if (this->parsed_av[i][0] >= 48 && this->parsed_av[i][0] <= 57)
		{
			data = strtod(parsed_av[i].c_str(), &temp);
			this->num_stack.push(data);
		}
		else
		{
			if (!(this->num_stack.size() >= 2))
				throw std::logic_error("Error");
			double second = num_stack.top();
			num_stack.pop();
			double first = num_stack.top();
			num_stack.pop();
			int opt = this->FindOperator(this->parsed_av[i]);
			if (opt == 1)
				num_stack.push(first + second);
			else if (opt == 2)
				num_stack.push(first - second);
			else if (opt == 3)
				num_stack.push(first * second);
			else if (opt == 4)
				num_stack.push(first / second);
		}
	}
	if (this->num_stack.size() != 1)
		std::logic_error("Error");
	if (this->num_stack.top() >= 2147483647 || this->num_stack.top() <= -2147483648)
	{
		std::cout << "Over INT_MAX or under INT_MIN" << std::endl;
		return ;
	}
	std::cout << static_cast<long long>(this->num_stack.top()) << std::endl;
}