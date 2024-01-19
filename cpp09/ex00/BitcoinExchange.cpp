#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	this->filename = filename;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	this->filename = obj.filename;
	this->parsed_csv = obj.parsed_csv;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return (*this);
	this->filename = obj.filename;
	this->parsed_csv = obj.parsed_csv;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::vector<std::string>	BitcoinExchange::SplitArgs(std::string line, char sep)
{
	std::vector<std::string> result;
	std::stringstream ss;
	std::string buf;
	ss.str(line);

	while (getline(ss, buf, sep))
		result.push_back(buf);
	return (result);
}

void	BitcoinExchange::GetTxtFileData(char **av)
{
	std::ifstream txt(av[1]);
	std::string file_in;
	int	i = 0;

	if (!txt.is_open())
		throw std::logic_error("Error: could not open file.");
	while (std::getline(txt, file_in))
	{
		if (i != 0)
		{
			std::vector<std::string> split_args = SplitArgs(file_in, '|');
			if (split_args.size() > 2)
				throw std::logic_error("Wrong txt file!");
			std::string key = split_args[0];
			std::string value = split_args[1];
			if (key[key.size() - 1] == ' ')
				key.pop_back();
			if (value[0] == ' ')
				value.erase(0, 1);
			if (value == "")
				value = "0";
			this->txt_date.push_back(key);
			this->txt_exchange.push_back(value);
		}
		i++;
	}
	if (this->txt_date.size() != this->txt_exchange.size())
		throw std::logic_error("Wrong txt file!");
}

void	BitcoinExchange::CheckTxtFile()
{
	for (size_t i = 0; i < txt_date.size(); i++)
	{
		std::vector<std::string> split_data = SplitArgs(this->txt_date[i], '-');
		if (split_data.size() != 3)
			throw std::logic_error("Wrong txt file!");
		if (split_data[0].size() != 4)
			throw std::logic_error("Wrong txt file!");
		if (split_data[1].size() != 2 || split_data[2].size() != 2)
			throw std::logic_error("Wrong txt file!");
		for (size_t j = 0; j < split_data.size(); j++)
		{
			for (size_t k = 0; k < split_data[j].size(); k++)
			{
				if (split_data[j][k] >= 58 || split_data[j][k] <= 47)
					throw std::logic_error("Wrong txt file!");
			}
		}
		for (size_t j = 0; j < this->txt_exchange.size(); j++)
		{
			if (this->txt_exchange[j] == "bad input")
				continue ;
			for (size_t k = 0; k < this->txt_exchange[j].size(); k++)
			{
				if (this->txt_exchange[j][k] >= 58 || this->txt_exchange[j][k] <= 47)
				{
					if (this->txt_exchange[j][k] != '.' && this->txt_exchange[j][k] != '+' && this->txt_exchange[j][k] != '-')
						throw std::logic_error("Wrong txt file!");
				}
			}
		}
	}
}

void	BitcoinExchange::GetCsvFileData()
{
	std::ifstream csv("data.csv");
	std::string	file_in;
	int	i = 0;

	if (!csv.is_open())
		throw	std::logic_error("File doesn't exist");
	while (std::getline(csv, file_in))
	{
		if (i != 0)
		{
			std::vector<std::string> split_args = SplitArgs(file_in, ',');
			std::string key = split_args[0];
			std::string value = split_args[1];
			this->parsed_csv.insert(std::make_pair(key, value));
		}
		i++;
	}
}

int	BitcoinExchange::DateValueCheck(int count)
{
	int	year_d;
	int	month_d;
	int	day_d;
	char *temp = NULL;

	std::vector<std::string>	split_args = SplitArgs(this->txt_date[count], '-');
	year_d = static_cast<int>(strtod(split_args[0].c_str(), &temp));
	month_d = static_cast<int>(strtod(split_args[1].c_str(), &temp));
	day_d = static_cast<int>(strtod(split_args[2].c_str(), &temp));
	if (month_d < 1 || month_d > 12)
	{
		std::cout << "Error: bad input => " << this->txt_date[count] << std::endl;
		return (1);
	}
	if (month_d == 1 || month_d == 3 || month_d == 5 || month_d == 7 || month_d == 8 || month_d == 10 || month_d == 12)
	{
		if (day_d > 31 || day_d < 1)
		{
			std::cout << "Error: bad input => " << this->txt_date[count] << std::endl;
			return (1);
		}
	}
	else if (month_d == 2)
	{
		if ((year_d % 4 == 0 && year_d % 100 != 0) || year_d % 400 == 0)
		{
			if (day_d > 29 || day_d < 1)
			{
				std::cout << "Error: bad input => " << this->txt_date[count] << std::endl;
				return (1);
			}
		}
		else
		{
			if (day_d > 28 || day_d < 1)
			{
				std::cout << "Error: bad input => " << this->txt_date[count] << std::endl;
				return (1);
			}
		}
	}
	else if (month_d == 4 || month_d == 6 || month_d == 9 || month_d == 11)
	{
		if (day_d > 30 || day_d < 1)
		{
			std::cout << "Error: bad input => " << this->txt_date[count] << std::endl;
			return (1);
		}
	}
	if (year_d < 2009)
	{
		std::cout << "Invalid period!" << std::endl;
		return (1);
	}
	return (0);
}

int		BitcoinExchange::ExchangeValueCheck(int count)
{
	char *temp = NULL;
	double	exchange = strtod(this->txt_exchange[count].c_str(), &temp);
	std::string	check = temp;
	if (check.size() != 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (exchange <= 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	return (0);
}

void	BitcoinExchange::PrintBitcoin(int count)
{
	std::map<std::string, std::string>::iterator iter;
	iter = this->parsed_csv.find(this->txt_date[count]);
	if (iter != this->parsed_csv.end())
	{
		char *temp;
		double cnt = strtod(this->txt_exchange[count].c_str(), &temp);
		if (cnt > 2147483647)
		{
			std::cout << "Error: too large a number." << std::endl;
			return ;
		}
		double rate = strtod(iter->second.c_str(), &temp);
		double value = cnt * rate;
		std::cout << this->txt_date[count] << " => " << this->txt_exchange[count] << " = " << value << std::endl;
	}
	else
	{
		iter = this->parsed_csv.upper_bound(this->txt_date[count]);
		iter--;
		char *temp;
		double cnt = strtod(this->txt_exchange[count].c_str(), &temp);
		if (cnt > 2147483647)
		{
			std::cout << "Error: too large a number." << std::endl;
			return ;
		}
		double rate = strtod(iter->second.c_str(), &temp);
		double value = cnt * rate;
		std::cout << this->txt_date[count] << " => " << this->txt_exchange[count] << " = " << value << std::endl;
	}
}

void	BitcoinExchange::PrintResult()
{
	for (size_t i = 0; i < txt_date.size(); i++)
	{
		if (this->DateValueCheck(i) == 1)
			continue ;
		if (this->ExchangeValueCheck(i) == 1)
			continue ;
		this->PrintBitcoin(i);
	}
}