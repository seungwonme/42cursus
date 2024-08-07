#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char* const* av)
{
    if (ac != 2)
    {
        std::cerr << aec::fg::YELLOW << "Usage: " << av[0] << " <input_file>" << aec::RESET << '\n';
        return 1;
    }
    try
    {
        BitcoinExchange be(av[1]);
        be.Exchange();
    }
    catch(const std::exception& e)
    {
        std::cerr << aec::fg::RED << e.what() << aec::RESET << '\n';
    }
    
    return 0;
}
