#include <iostream>

#include <SFML/Network.hpp>

#include <time.h>
#include <stdio.h>

#include "parts/ansi.h" 

#define PORT 6090
#define HOST "1"

using std::string;

string exec(const char* cmd);

int main(int argc, const char* argv[1])
{
    sf::TcpListener listener;

    if(listener.listen(PORT) != sf::Socket::Done)
    {
        std::cout << red << "error: on create listerer\n" << reset; 
        return 1;
    }
    

    return 0;
}

string exec(const char* cmd)
{
    char* buff;
    string result;

    FILE* fd = popen(cmd, "r");

    // use buffer to read and add to result
    while(fgets(buff, 128, fd) != NULL)
    {
        result += buff;
    }

    pclose(fd);

    return result;
}