//
// Created by stelc on 11.10.2023.
//

#ifndef BLOCKCHAINCPLUSPLUS_TRANSACTION_H
#define BLOCKCHAINCPLUSPLUS_TRANSACTION_H

#include <string>

class Transaction {

public :
    Transaction(std::string _sender, std::string _receiver, time_t _timestamp, double _amount, std::string _tx_data);
    int calculateWeight() const;

private :
    const std::string sender;
    const std::string receiver;
    const time_t timestamp;
    const double amount;
    const std::string tx_data;
};
#endif //BLOCKCHAINCPLUSPLUS_TRANSACTION_H
