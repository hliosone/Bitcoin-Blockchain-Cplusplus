//
// Created by stelc on 11.10.2023.
//

#include "Block.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <openssl/sha.h>

using namespace std;

Block::Block(const uint8_t _prevBlockHash[SHA256_DIGEST_LENGTH], const uint8_t _hash[SHA256_DIGEST_LENGTH], int _nonce,
             int _difficulty, time_t _timestamp) : nonce(_nonce), difficulty(_difficulty), timestamp(_timestamp) {
                copy(_prevBlockHash, _prevBlockHash + SHA256_DIGEST_LENGTH, lastHash);
                copy(_hash, _hash + SHA256_DIGEST_LENGTH, hash);
                auto transactions = new vector<Transaction>;
}

// Cryptographic functions
string hashToString(const uint8_t hash[SHA256_DIGEST_LENGTH]){
    string hashStr;
    for(size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i){
        hashStr += hash[i];
    }

    return hashStr;
}

string Block::blockString() const{
 return "Block : \nPrevious Hash : " + hashToString(lastHash);
 //+  " \nTimestamp : " +  "\nLast Hash : " + lastHash +
//           "\nHash : " + hash + "\nData : " + data;

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
