//
// Created by stelc on 11.10.2023.
//

#include "Transaction.h"
#include <string>

using namespace std;

Transaction::Transaction(std::string _sender, std::string _receiver, time_t _timestamp, double _amount, std::string _tx_data) : sender(_sender),
receiver(_receiver), timestamp(_timestamp), amount(_amount), tx_data(_tx_data){}

int Transaction::calculateWeight() const{
    return (this->sender.size() + this->receiver.size() + sizeof(this->timestamp) + this->tx_data.size()
            + sizeof(this->amount));
}
