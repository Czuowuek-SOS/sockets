#include <SFML/Network.hpp>

#include <iostream>

#include "parts/ansi.h"

#define PORT 6090
#define HOST "1"

int main()
{
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(HOST, PORT);

    if(status != sf::Socket::Done)
    {
        std::cout << red << "Not could connect with server\n" << reset;
    }
    return 0;
}