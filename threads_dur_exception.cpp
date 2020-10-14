struct func;
void f()
{
    int local_var = 0;
    func my_func(local_var);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(..)
    {
        t.join();
        throw;
    }
    t.join();
}
