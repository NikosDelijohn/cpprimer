#include "folder.hpp"
#include "message.hpp"

int main()
{
    Folder inbox("Inbox");
    Folder outbox("Outbox");

    inbox.print_folder();
    outbox.print_folder();

    Message m1("Call for Papers: OurAwesomeConf2k26");
    m1.save(inbox);
    m1.save(outbox);
    m1.remove(outbox);
    
    Message m2("SubscriptionFlix: Your annual subscription has changed!");
    m2.save(inbox);

    inbox.print_folder();
    outbox.print_folder();

    {
        Message m3;
        m3 = m2;

        Message m4(m3);
        inbox.print_folder();
    }

    inbox.print_folder();

    return EXIT_SUCCESS;
}