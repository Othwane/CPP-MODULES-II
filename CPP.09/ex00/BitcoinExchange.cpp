#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    std::ifstream dbFile(databaseFile.c_str());
    if (!dbFile.is_open()) {
        throw FileOpenException();
    }

    std::string line;
    // Skip header line
    std::getline(dbFile, line);

    while (std::getline(dbFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string rateStr;
        
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            float rate = std::strtof(rateStr.c_str(), NULL);
            _exchangeRates[date] = rate;
        }
    }

    if (_exchangeRates.empty()) {
        throw BadDatabaseException();
    }
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream inFile(inputFile.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    // Skip header line
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;
        
        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim whitespace
        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        // Validate date format (YYYY-MM-DD)
        if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Validate value
        char* endptr;
        float value = std::strtof(valueStr.c_str(), &endptr);
        if (*endptr != '\0' || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find exchange rate
        std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
        if (it == _exchangeRates.end() || it->first != date) {
            if (it != _exchangeRates.begin()) {
                --it;
            } else {
                std::cerr << "Error: no data available for date " << date << std::endl;
                continue;
            }
        }

        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
    return "Error: could not open database file";
}

const char* BitcoinExchange::BadDatabaseException::what() const throw() {
    return "Error: database file is empty or corrupted";
}