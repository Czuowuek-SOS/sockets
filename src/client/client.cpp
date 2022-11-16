#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>

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


    // char sendBuffor[256];
    size_t received;
    char output[2048];
    string sendBuffor;
    while(true)
    {
        // std::cin.getline(sendBuffor, 256);
        // scanf("%s", &sendBuffor);
        std::cout << ">>";
        std::getline(std::cin, sendBuffor);
        if(sendBuffor == "exit")
        {
            break;
        }

        if(socket.send(sendBuffor.c_str(), 256) != sf::Socket::Done)
        {
            std::cout << red << "Error: On sending data\n" << reset;
            return 1;
        }


        if(socket.receive(output, 4096, received) != sf::Socket::Done) 
        {
            std::cout << red << "Error: On receiving command output\n" << reset;
        }
        printf(output);
        putchar('\n');
    }
    socket.disconnect();
    // socket.send("_exit", 6);

    return 0;
}