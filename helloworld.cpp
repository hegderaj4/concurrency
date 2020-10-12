#include <iostream>
#include <thread>

using namespace std;

/*
 * A simple program to run a function via a thread
 * */
void hello()
{
    cout << "Hello Concurrency\n";
}

int main()
{
    thread t(hello);
    t.join();
    return 0;
}
