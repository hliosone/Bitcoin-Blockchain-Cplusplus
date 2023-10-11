//
// Created by stelc on 11.10.2023.
//

#ifndef BLOCKCHAINCPLUSPLUS_BLOCK_H
#define BLOCKCHAINCPLUSPLUS_BLOCK_H

#include "Transaction.h"

#include <string>
#include <vector>
#include <openssl/sha.h>

class Block {

public:
    Block(uint8_t _lastHash, uint8_t _hash, int _nonce, int _difficulty, time_t _timestamp,
          std::vector<Transaction> _transactions);
    std::string blockString() const;

    //Block functions
    Block static genesis();
    Block static mineBlock(const Block& lastBlock, const std::string data);

    // Time functions
    time_t static getCurrentTime();
    std::string getTimeZoneBased(const time_t& timestamp) const;

    // Cryptographic functions
    std::string static getInputToHash(const Block& block);

private :
    time_t timestamp;
    const uint8_t lastHash[SHA256_DIGEST_LENGTH];
    uint8_t Hash[SHA256_DIGEST_LENGTH];
    const int nonce;
    const int difficulty;
    std::vector<Transaction> transactions;
};

#endif //BLOCKCHAINCPLUSPLUS_BLOCK_H
