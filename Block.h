//
// Created by stelc on 11.10.2023.
//

#ifndef BLOCKCHAINCPLUSPLUS_BLOCK_H
#define BLOCKCHAINCPLUSPLUS_BLOCK_H

#include "Transaction.h"

#include <string>
#include <vector>
#include <array>
#include <openssl/sha.h>

class Block {

public:
    Block(uint32_t _blockHeight, const uint8_t _prevBlockHash[SHA256_DIGEST_LENGTH],
          const uint8_t _hash[SHA256_DIGEST_LENGTH], int _difficulty);
    std::string blockString() const;

    // Getters
    time_t getTimestamp() const;
    const uint8_t* getLastBlockHash() const;
    int getNonce() const;
    uint32_t getBlockHeight() const;

    //Block functions
    Block static genesis();
    Block static mineBlock(const Block& lastBlock, const std::string data);

    // Cryptographic functions
    std::string hashToString(const uint8_t hash[SHA256_DIGEST_LENGTH]) const;
    std::string static getInputToHash(const Block& block);

private :
    time_t timestamp;
    uint8_t lastHash[SHA256_DIGEST_LENGTH];
    uint8_t hash[SHA256_DIGEST_LENGTH];
    uint8_t hashRoot[SHA256_DIGEST_LENGTH];
    uint32_t blockHeight;
    const int nonce;
    const int difficulty;
    std::vector<Transaction> transactions;
};

#endif //BLOCKCHAINCPLUSPLUS_BLOCK_H
