#include <SFML/Network.hpp>

#include <iostream>

#include "parts/ansi.h"
#include "parts/hostname.h"

using std::string;

#define PORT 6090
sf::IpAddress HOST = ;

int main()
{
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(HOST, PORT);

    if(status != sf::Socket::Done)
    {
        std::cout << red << "Not could connect with server\n" << reset;
    }

    char sendBuffor[256];
    while(true)
    {
        std::cin.getline(sendBuffor, 256);


    }

    return 0;
}