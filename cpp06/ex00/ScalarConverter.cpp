#include "ScalarConverter.hpp"

void	ScalarConverter::ConvertChar(std::string data)
{
	char character = data[0];
	std::cout << "char: " << character << std::endl;
	int integer = static_cast<int>(character);
	std::cout << "int: " << integer << std::endl;
	float floaty = static_cast<float>(character);
	std::cout << "float: " << floaty << ".0f" << std::endl;
	double doubly = static_cast<double>(character);
	std::cout << "double: " << doubly << ".0" << std::endl;
}

int	ScalarConverter::IntCheck(std::string data)
{
	unsigned long j = 0;
	if (data[0] == '-')
		j = 1;
	for (unsigned long i = j; i < data.length(); i++)
	{
		if (!(data[i] >= 48 && data[i] <= 57))
			return (-1);
	}
	return (0);
}

void	ScalarConverter::ConvertInt(std::string data)
{
	char *non_change_string;
	double tmp_double = strtod(data.c_str(), &non_change_string);	//strtod 함수를 통해 double로 변환 후 각각의 자료형으로 형변환
	int integer = static_cast<int>(tmp_double);
	if (tmp_double <= 32 || tmp_double >= 127)	//표현 가능 범위 밖이면
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char character = integer;
		std::cout << "char: " << character << std::endl;
	}
	if (tmp_double > INT_MAX || tmp_double < INT_MIN)	//정수 범위 밖인 경우
	{
		std::cout << "int: over int max or min" << std::endl;
	}
	else
	{
		std::cout << "int: " << integer << std::endl;
	}
	float floaty = static_cast<float>(tmp_double);
	std::cout << "float: " << floaty << ".0f" << std::endl;
	std::cout << "double: " << tmp_double << ".0" << std::endl;
}

int	ScalarConverter::FloatCheck(std::string data)
{
	size_t point = data.find(".");
	size_t f_point = data.find("f");
	unsigned long	i = 0;
	unsigned long	point_cnt = 0;
	unsigned long	f_cnt = 0;
	if (data[0] == '-')
		i = 1;
	for (unsigned long j = i; j < data.length(); j++)
	{
		if ((data[j] >= 48 && data[j] <= 57))	//숫자인 경우 f의 갯수가 0개거나 1개이면 continue ; 아니면 -1 리턴
		{
			if (f_cnt >= 1)
				return (-1);
			continue ;
		}
		if (data[j] == '.')	//. 갯수 카운트
		{
			point_cnt++;
			continue ;
		}
		if (data[j] == 'f')	//f갯수 카운트
		{
			f_cnt++;
			continue ;
		}
	}
	if (point_cnt != 1)	//포인트가 1개가 아니면
		return (-1);
	if (!(f_cnt == 0 || f_cnt == 1))	//f의 갯수가 0개거나 1개가 아니면
		return (-1);
	if (f_cnt == 1 && f_point < point)	//f가 1개 있고 f의 위치가 point보다 앞이면
		return (-1);
	return (0);
}

void	ScalarConverter::ConvertFloat(std::string data)
{
	char *stopstr;
	std::string temp;
	stopstr = NULL;
	double tmp_double = strtod(data.c_str(), &stopstr);
	temp = stopstr;
	float floaty = static_cast<float>(tmp_double);
	if (data == "-inff" || floaty == -INFINITY)	//-inff 일 경우
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (data == "+inff" || floaty == +INFINITY) //+inff 일 경우
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}
	else if (data == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if ((!(temp.length() == 1 && temp[0] == 'f')))	//정상적 float 뒤에 뭔가 더 온 경우 예외처리
		throw ScalarConverter::non_title_err();
	int	integer = static_cast<int>(tmp_double);
	if (tmp_double <= 32 || tmp_double >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char character = integer;
		std::cout << "char: " << character << std::endl;
	}
	if (tmp_double > INT_MAX || tmp_double < INT_MIN)
	{
		std::cout << "int: over int max or min" << std::endl;
	}
	else
	{
		std::cout << "int: " << integer << std::endl;
	}
	size_t point = data.find(".");
	size_t f_position = data.find("f");
	if (tmp_double == 0.0 || tmp_double == -0.0)	//0 or -0일 경우
	{
		std::cout << "float: " << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
		return ;
	}
	if (!(point + 1 == f_position))	//f가 .바로 뒤에 있는게 아니면
	{
		int d = 0;
		for (size_t k = point + 1; k < data.length() - 1; k++)
		{
			if (data[k] != '0')
				d = -1;
		}
		if (d == -1)	//.과 f 사이에 0이 아닌게 있으면
		{
			std::cout << "float: " << floaty << "f" << std::endl;
			std::cout << "double: " << tmp_double << std::endl;
		}
		else	//.과 f사이에 모두 0이면
		{
			std::cout << "float: " << floaty << ".0f" << std::endl;
			std::cout << "double: " << tmp_double << ".0" << std::endl;
		}
	}
	else	//f가 .바로 뒤에 있으면
	{
		std::cout << "float: " << floaty << ".0f" << std::endl;
		std::cout << "double: " << tmp_double << ".0" << std::endl;
	}
 }

void	ScalarConverter::ConvertDouble(std::string data)
{
	char *stopstr;
	std::string temp;
	stopstr = NULL;
	double tmp_double = strtod(data.c_str(), &stopstr);
	temp = stopstr;
	float floaty = static_cast<float>(tmp_double);
	if (data == "+inf" || tmp_double >= +INFINITY)	//+inf일 경우
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}
	else if (data == "-inf" || tmp_double <= -INFINITY)	//-inf일 경우
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (data == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (temp.length() != 0)	//정상적 숫자 뒤에 뭔가 더 온 경우 예외처리
		throw ScalarConverter::non_title_err();
	int	integer = static_cast<int>(tmp_double);
	if (tmp_double <= 32 || tmp_double >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char character = integer;
		std::cout << "char: " << character << std::endl;
	}
	if (tmp_double > INT_MAX || tmp_double < INT_MIN)
	{
		std::cout << "int: over int max or min" << std::endl;
	}
	else
	{
		std::cout << "int: " << integer << std::endl;
	}
	size_t point = data.find(".");
	if (tmp_double == 0.0 || tmp_double == -0.0)	//0 or -0일 경우
	{
		std::cout << "float: " << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
		return ;
	}
	if (point == data.length() - 1)	//.이 맨 뒤에 ㅅ있으면
	{
		std::cout << "float: " <<floaty << ".0f" << std::endl;
		std::cout << "double: " << tmp_double << ".0" << std::endl;
	}
	else	//.뒤에 뭔가 더 있으면
	{
		for (unsigned long i = point + 1; i < data.length(); i++)
		{
			if (data[i] != '0')	//.뒤가 0이 아닌 뭔가가 있으면
			{
				std::cout << "float: " << floaty << "f" << std::endl;
				std::cout << "double: " << tmp_double << std::endl;
				return ;
			}
		}
		//. 뒤가 다 0이면
		std::cout << "float: " << floaty << ".0f" << std::endl;
		std::cout << "double: " << tmp_double << ".0" << std::endl;
	}
}

void	ScalarConverter::Convert(std::string data)
{
	if (data.size() == 1 && ((data[0] >= 33 && data[0] <= 47) || (data[0] >= 58 && data[0] <= 126)))	//char인 경우
	{
		ScalarConverter::ConvertChar(data);
		return ;
	}
	else if (ScalarConverter::IntCheck(data) == 0)	//int인 경우
	{
		ScalarConverter::ConvertInt(data);
		return ;
	}
	else if (ScalarConverter::FloatCheck(data) == 0 || data == "+inff" || data == "-inff" || data == "nanf" || data == "+inf" || data == "-inf" || data == "nan")	//float나 double인 경우
	{
		if (data.find("f") != std::string::npos || data == "-inff" || data == "+inff" || data == "nanf")	//float인 경우
			ScalarConverter::ConvertFloat(data);
		else	//double인 경우
			ScalarConverter::ConvertDouble(data);
	}
	else
		throw ScalarConverter::non_title_err();
}