#include <iostream>

int main(int ac, char *av[])
{
    char    c;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    else
    {
        for(int i = 1; i < ac; i++)
            for(int j = 0; av[i][j]; j++)
            {
                c = toupper(av[i][j]);
                std::cout << c;
            }
        std::cout << std::endl;
    }
    return (0);
}

// #include <iostream>

// int main(int ac, char *av[])
// {
//     if (ac == 1)
//     {
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//         return (0);
//     }
//     else
//     {
//         for(int i = 1; i < ac; i++)
//             for(int j = 0; av[i][j]; j++)
//                 std::cout << static_cast<char>(std::toupper(av[i][j]));
//         std::cout << std::endl;
//     }
//     return (0);
// }