#include <SFML/Network.hpp>

#include <iostream>

#include <stdio.h>

#include "parts/ansi.h"
#include "parts/hostname.h"

using std::string;

#define PORT 6090
sf::IpAddress HOST = sf::IpAddress::getLocalAddress();

int main()
{
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(HOST, PORT);

    if(status != sf::Socket::Done)
    {
        std::cout << red << "Not could connect with server\n" << reset;
        return 1;
    }
    std::cout << green << "Connection with server\n\n" << reset;

    char sendBuffor[256];
    while(true)
    {
        // std::cin.getline(sendBuffor, 256);
        scanf("%s", &sendBuffor);

        if(socket.send(sendBuffor, 256) != sf::Socket::Done)
        {
            std::cout << red << "Error: On sending data\n" << reset;
            return 1;
        }
        
    }

    return 0;
}