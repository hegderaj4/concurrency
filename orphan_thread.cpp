#include <iostream>
#include <thread>

/*
 * A simple function to illustrate that a child thread can be detached even before
 * it is completed
 *
 * In orphan state, a child thread cannot access variables of parent thread.
 *
 * Solution1:
 *      If you decide to orphan it, then ensure all required data is passed  to the thread.
 *      For example, passing the entire object to the new thread will do this.
 * Solution2:
 *      Ensure that thread is completed before exiting by using 'join' option
 * */

struct func
{
    int i;
    func (int& i_):i(i_){}
    void operator()()
    {
        for(unsigned j=0; j<1000000;j++) {
            do_something(j);
        }
    }
};

void oops()
{
    int local_val = 0;
    func my_func(local_val);
    std::thread my_thread(my_func);
    my_thread.detach();
}
