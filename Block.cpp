//
// Created by stelc on 11.10.2023.
//

#include "Block.h"
#include <string>
#include <vector>
#include <openssl/sha.h>

using namespace std;

Block::Block(uint8_t _lastHash, uint8_t _hash, int _nonce, int _difficulty, time_t _timestamp,
             std::vector<Transaction> _transactions) : lastHash(_lastHash), hash(_hash), nonce(_nonce),
             timestamp(_timestamp), _transactions(new vector<Transaction> transactions){}

string Block::blockString() const{

}

//Block functions
Block static genesis(){

}
Block static mineBlock(const Block& lastBlock, const std::string data){

}

// Time functions
time_t static getCurrentTime(){

}
string Block::getTimeZoneBased(const time_t& timestamp) const{

}

// Cryptographic functions CHECK IF STATIC OR NOT
string static getInputToHash(const Block& block){

}
