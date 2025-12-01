#include "folder.hpp"
#include "message.hpp"

Message make_message(const std::string &val)
{
    
    return Message(val);
}

int main()
{
    Folder inbox("Inbox");
    Folder outbox("Outbox");

    inbox.print_folder();
    outbox.print_folder();

    auto m1 = make_message("Submission 46: A new Move-Constructor!");

    auto tmp = Message("Hi");     // Constructor called normally
    Message m2 = std::move(tmp);  // FORCED move constructor

    m1.save(inbox);
    m2.save(inbox);

    inbox.print_folder();
    m1 = std::move(m2); // overwrites m1 and updates folders correctly
    inbox.print_folder();

    return EXIT_SUCCESS;
}