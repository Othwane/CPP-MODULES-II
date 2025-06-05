#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    void processInputFile(const std::string& inputFile) const;

    class FileOpenException : public std::exception {
        virtual const char* what() const throw();
    };

    class BadDatabaseException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif