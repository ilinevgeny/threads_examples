#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(int seconds)
{
    boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread()
{
    for (int i = 0; i < 5; ++i) {
        wait(1);
        std::cout << "This is thread output " << i  << std::endl;
    }
}

int main ()
{
    std::cout << "Concurrency of threads are " << boost::thread::hardware_concurrency() << std::endl;
    boost::thread t{thread};
    t.detach();
    wait(6);
    return 0;
};