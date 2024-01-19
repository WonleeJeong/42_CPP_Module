#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class BitcoinExchange
{
	private:
		std::string get_data;
		std::string filename;
		std::vector <std::string> split_result;
		std::vector <std::string> txt_date;
		std::vector <std::string> txt_exchange;
		std::map<std::string, std::string>	parsed_csv;
		int	DateValueCheck(int count);
		int	ExchangeValueCheck(int count);
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
		std::vector<std::string>	SplitArgs(std::string line, char sep);
		void	GetTxtFileData(char **av);
		void	CheckTxtFile();
		void	GetCsvFileData();
		void	PrintBitcoin(int count);
		void	PrintResult();
};

#endif