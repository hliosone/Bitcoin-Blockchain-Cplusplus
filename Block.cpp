//
// Created by stelc on 11.10.2023.
//

#include "Block.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <array>
#include <chrono>
#include <openssl/sha.h>

using namespace std;


// Getters

time_t Block::getTimestamp() const{
    return this->timestamp;
}

const uint8_t* Block::getLastHash() const{
    return this->lastHash;
}


// Blocks functions
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
    //return Block(, 0, 1, Block::getCurrentTime(), to_string(0));
}

//mine block referencing to the last one
Block static mineBlock(const Block& lastBlock){
    const time_t _timestamp = Block::getCurrentTime();
    uint8_t _lastHash[SHA256_DIGEST_LENGTH];
    copy(lastBlock.getLastHash(), lastBlock.getLastHash() + SHA256_DIGEST_LENGTH, _lastHash);
    const string _hash = "0"; //create hash function later

    //return Block(_timestamp, _lastHash, _hash, data, new vector<Transaction> transactions);
}

// Time functions
time_t static getCurrentTime(){
    return chrono::system_clock::to_time_t(chrono::system_clock::now());
}

string Block::getTimeZoneBased(const time_t& timestamp) const{
    string currentTimeStr = "null";
    if(timestamp != 0){
        currentTimeStr = ctime(&timestamp);
        if (!currentTimeStr.empty() && currentTimeStr.back() == '\n') {
            currentTimeStr.pop_back();
        }
    }
    return currentTimeStr;
}

string removeSpaces(const string& input){
    string result;
    for (char c : input){
        if(c != ' '){
            result += c;
        }
    }
    return result;
}

// Cryptographic functions CHECK IF STATIC OR NOT
//string static getInputToHash(const Block& block){
//    //string input = block.timestamp + block.lastHash + block.data; REPLACE DATA WITH ENTIRE VALUE OF MERKLE ROOT CHECK
//    //return removeSpaces(input);
//}


/*
 *
 * Block static genesis(){
        return Block("date", to_string(0), to_string(rand() % std::numeric_limits<unsigned long>::max()), "Genesis block");
    }


 */