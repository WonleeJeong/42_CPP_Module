#include <iostream>
#include <fstream>

int main(int ac, char *av[])
{
	std::ifstream	readfile;
	std::ofstream	outfile;
	std::string replace;
	std::string	line;
	std::string av1;
	std::string av2;
	int	av1_len;
	int	av2_len;

	if (ac != 4)
	{
		std::cout << "argv is wrong" << std::endl;
		return (1);
	}
	av1 = av[2];
	av2 = av[3];
	av1_len = av1.length();
	av2_len = av2.length();
	if (av1_len == 0 || av2_len == 0)
	{
		std::cout << "argv is wrong" << std::endl;
		return (1);
 	}
	readfile.open(av[1]);
	if (!readfile.is_open())
	{
		std::cout << "wrong file name" << std::endl;
		return (1);
	}
	replace = av[1];
	replace = replace + ".replace";	//원래 파일명 + .replace 파일을 만들기 위해
	outfile.open(replace);
	if (!outfile.is_open())
	{
		std::cout << "outfile can't open" << std::endl;
		readfile.close();
		return (1);
	}
	while (1)
	{
		std::getline(readfile, line);		//파일 내용들을 한 줄 씩 읽음

		size_t point = 0;
		while (true)		//한 줄에 같은 내용이 없을때까지 무한 반복
		{
			point = line.find(av1, point);	//같은 내용 찾기, 같은 내용이 없으면 find에서 npos를 리턴함
			if (point == std::string::npos)
				break;			//같은 내용이 없으면 그 줄엔 바꿀 내용이 없으므로 break.
			line.erase(point, av1_len);	//같은 내용이 있으면 그 내용만큼 지우고
			line.insert(point, av2);	//바꿀 내용 삽입.
			point += av2_len;		//바꿀 내용 삽입한 길이만큼 길이 추가
		}
		outfile << line;	//바뀐 한 줄을 outline에 삽입.
		if (readfile.eof())
			break;		//읽어온 줄이 파일 끝이면 break.
		outfile << std::endl;
	}
	outfile.close();
	readfile.close();
	return (0);
}