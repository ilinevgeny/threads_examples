#include <iostream>
#include <thread>
#include <chrono>

void wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds{seconds});
    //boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread()
{

    for (int i = 0; i < 5; ++i)
    {
        wait(1);
        std::cout << "This is thread output " << i << '\n';
    }
}

int main()
{
    std::cout << "Concurrency of threads are " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "Hello, std world!" << std::endl;
    std::thread t_join {thread};
    if(t_join.joinable())
    {
        t_join.join();
    }
    std::thread t_detach {thread};
    t_detach.detach();
    wait(6);
    return 0;
}
