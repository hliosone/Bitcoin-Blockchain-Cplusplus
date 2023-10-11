//
// Created by stelc on 11.10.2023.
//

#include "Transaction.h"
#include "common.h"
#include <string>

using namespace std;

Transaction::Transaction(std::string _sender, std::string _receiver,double _amount, std::string _tx_data) : sender(_sender),
receiver(_receiver), timestamp(getCurrentTime()), amount(_amount), tx_data(_tx_data){}

int Transaction::calculateWeight() const{
    return (this->sender.size() + this->receiver.size() + sizeof(this->timestamp) + this->tx_data.size()
            + sizeof(this->amount));
}


/*
 * 1. Receive data as a string
 * 2. Convert this data to UTF-8
 * 3. create a vector of uint8 and add each UTF8 character to the vector
 * 4. one it's done, we can calculate the weight of this vector and if tx > 1mo, rejected by the network
 * have to implement the verification in block class not transaction. transaction should be build out it want but
 * after its up to the network to decide if it respects standards to arrive on the ledger or not */
