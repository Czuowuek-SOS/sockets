#include <SFML/System.hpp>
#include <iostream>

void func()
{
    // this function is started when thread.launch() is called

    for (int i = 0; i < 10; ++i)
        std::cout << "I'm thread number one" << std::endl;
}
void seks()
{
    for (int i = 0; i < 10; ++i)
        std::cout << "I'm thread of sex" << std::endl;
}

int main()
{
    // create a thread with func() as entry point
    sf::Thread thread1(&func);
    sf::Thread thread2(&seks);

    // run it
    thread1.launch();
    thread2.launch();

    // the main thread continues to run...

    for (int i = 0; i < 10; ++i)
        std::cout << "I'm the main thread" << std::endl;

    return 0;
}