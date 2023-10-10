#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <ctime>

using namespace std;

class Block {

public:
    Block(string _timestamp,unsigned long _lasthash,unsigned long _hash, string _data) : timestamp(_timestamp),
    lastHash(_lasthash), hash(_hash), data(_data){};
    string blockString() const{
        return "Block : \nTimestamp : " + timestamp + "\nLast Hash : " + to_string(lastHash) +
        "\nHash : " + to_string(hash) + "\nData : " + data;
    }

    Block static genesis(){
        return Block("date",0, rand() % std::numeric_limits<unsigned long>::max(), "Genesis block");
    }

    string static getCurrentTime(){
        auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string currentTimeStr = ctime(&currentTime);

        if (!currentTimeStr.empty() && currentTimeStr.back() == '\n') {
            currentTimeStr.pop_back();
        }

        return currentTimeStr;
    }

    Block static mineBlock(const Block& lastBlock, const string data){
        const string _timestamp = getCurrentTime();
        const unsigned long _lastHash = lastBlock.hash;
        const unsigned long _hash = 1; //create hash function later

        return Block(_timestamp, _lastHash, _hash, data);
    }

    /*
     * Maybe like this should be better ? Check later
     *Block mineBlock(const string data){
        const string _timestamp = getCurrentTime();
        const unsigned long _lastHash = this->hash;
        const unsigned long _hash = 1; //create hash function later

        return Block(_timestamp, _lastHash, _hash, data);
    } */

private :
    const string timestamp;
    const unsigned long lastHash;
    const unsigned long hash;
    const string data = "";
};

int main() {
    srand(time(0));
    const Block Genesis = Block::mineBlock(Block::genesis(), "first txs on the chain");
    cout << Genesis.blockString() << endl;

//  test2
//    Block test = Block::genesis();

    return 0;
}
