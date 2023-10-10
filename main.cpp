#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <ctime>
#include <openssl/sha.h>



using namespace std;

class Block {

public:
    Block( string _timestamp, string _lasthash,string _hash, string _data) : timestamp(_timestamp),
    lastHash(_lasthash), hash(_hash), data(_data){};
    string blockString() const{
        return "Block : \nTimestamp : " + timestamp + "\nLast Hash : " + lastHash +
        "\nHash : " + hash + "\nData : " + data;
    }

    Block static genesis(){
        return Block("date", to_string(0), to_string(rand() % std::numeric_limits<unsigned long>::max()), "Genesis block");
    }

    string static getCurrentTime(){
        auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string currentTimeStr = ctime(&currentTime);

        if (!currentTimeStr.empty() && currentTimeStr.back() == '\n') {
            currentTimeStr.pop_back();
        }

        return currentTimeStr;
    }

    //mine block referencing to the last one
    Block static mineBlock(const Block& lastBlock, const string data){
        const string _timestamp = getCurrentTime();
        const string _lastHash = lastBlock.hash;
        const string _hash = "0"; //create hash function later

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
    const string lastHash;
    const string hash;
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
