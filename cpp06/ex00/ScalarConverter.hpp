#ifndef	SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <math.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator =(const ScalarConverter& obj);
	public:
		static void	Convert(std::string data);
		static void	ConvertChar(std::string data);	//char 들어왔을 때 변환해주는 함수
		static int	IntCheck(std::string data);	//int인지 확인하는 함수
		static void	ConvertInt(std::string data);	//int 들어왔을 때 변환해주는 함수
		static int	FloatCheck(std::string data);	//float나 double인지 확인하는 함수
		static void	ConvertFloat(std::string data);	//float 들어왔을 때 변환해주는 함수
		static void	ConvertDouble(std::string data);	//double 들어왔을 때 변환해주는 함수
		class	non_title_err: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
						return ("Please input valid char, int, float or double");
				}
		};
};

#endif