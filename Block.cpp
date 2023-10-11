//
// Created by stelc on 11.10.2023.
//

#include "Block.h"
#include "common.h"
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

const uint8_t* Block::getLastBlockHash() const{
    return this->hash;
}

int Block::getNonce() const{
    return this->nonce;
}

uint32_t Block::getBlockHeight() const{
    return this->blockHeight;
}


// Blocks functions
Block::Block(uint32_t _blockHeight, const uint8_t _prevBlockHash[SHA256_DIGEST_LENGTH], const uint8_t _hash[SHA256_DIGEST_LENGTH],
             int _difficulty) : blockHeight(_blockHeight), nonce(0), difficulty(_difficulty), timestamp(getCurrentTime()) {
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

// Block functions
Block static genesis(){

    const uint8_t genesisPreviousHash[SHA256_DIGEST_LENGTH] = {};
    string genesisHashStr = "000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f";
    uint8_t genesisHash[SHA256_DIGEST_LENGTH] = {};
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i){
        genesisHash[i] = genesisHashStr[i];
    }

    const uint32_t firstBlockHeight = 0;

    return Block(firstBlockHeight, genesisPreviousHash, genesisHash, 1);
}

Block static mineBlock(const Block& lastBlock){

    uint8_t _lastHash[SHA256_DIGEST_LENGTH];
    copy(lastBlock.getLastBlockHash(), lastBlock.getLastBlockHash() + SHA256_DIGEST_LENGTH, _lastHash);
    uint8_t _hash[SHA256_DIGEST_LENGTH] = {}; //create hash function later
    const time_t _timestamp = getCurrentTime();

    return Block((lastBlock.getBlockHeight() + 1),_lastHash, _hash, 0);
}

string Block::blockString() const{
    return "Block : \nPrevious Hash : " + hashToString(lastHash);
    //+  " \nTimestamp : " +  "\nLast Hash : " + lastHash +
//           "\nHash : " + hash + "\nData : " + data;

}

// Time functions
time_t getCurrentTime(){
    return chrono::system_clock::to_time_t(chrono::system_clock::now());
}

string getTimeZoneBased(const time_t& timestamp) {
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