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
        auto currentTime = ::chrono::system_clock::to_time_t(chrono::system_clock::now());
        return (string) std::ctime(&currentTime);
    }

private :
    const string timestamp;
    const unsigned long lastHash;
    const unsigned long hash;
    const string data = "";
};

int main() {
    srand(time(0));
    Block one("test",321, 213, "mes txs");
    cout << one.blockString() << endl;
//  test2
//    Block test = Block::genesis();

    return 0;
}
