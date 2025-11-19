#include <iostream>
#include <memory>

struct host {
    short ipv4[4];
};

struct connection {
    host src;
    host dst;
};

connection connect(host* dest)
{
    std::cout << "Connecting to "
              << dest->ipv4[0] << "."
              << dest->ipv4[1] << "."
              << dest->ipv4[2] << "."
              << dest->ipv4[3] << "\n";

    return connection{
        {127,0,0,1},
        *dest
    };
}

void disconnect(const connection& conn)
{
    std::cout << "Disconnecting from "
              << conn.dst.ipv4[0] << "."
              << conn.dst.ipv4[1] << "."
              << conn.dst.ipv4[2] << "."
              << conn.dst.ipv4[3] << "\n";
}

void f(host& dst)
{
    connection c = connect(&dst);

    // Shared_ptr that does NOT own the memory
    std::shared_ptr<connection> sp_conn(&c,
        [](connection* conn)
        {
            // custom deleter called when sp_conn is destroyed
            disconnect(*conn); // OK — just logs
            // DO NOT free, new, delete, or free memory!!!
            // We are in the stack, not in the heap!!!
        }
    );

} // disconnect will be invoked when function body completes

int main()
{
    host dst = {192,168,2,2};
    f(dst);
}
