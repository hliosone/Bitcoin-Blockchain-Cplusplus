//
// Created by stelc on 11.10.2023.
//

#include "Block.h"
#include <string>
#include <vector>
#include <openssl/sha.h>

using namespace std;

Block::Block(uint8_t _lastHash[SHA256_DIGEST_LENGTH], uint8_t _hash[SHA256_DIGEST_LENGTH], int _nonce, int _difficulty,
             time_t _timestamp) : nonce(_nonce), difficulty(_difficulty), timestamp(_timestamp) {
                copy(_lastHash, _lastHash + SHA256_DIGEST_LENGTH, lastHash);
                copy(_hash, _hash + SHA256_DIGEST_LENGTH, hash);
                auto transactions = new vector<Transaction>;
}

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
