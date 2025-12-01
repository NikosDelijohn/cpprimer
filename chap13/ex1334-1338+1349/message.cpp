#include "message.hpp"
#include "folder.hpp"

Message::Message(const Message &other):
    contents(other.contents), folders(other.folders)
{
#ifndef NDEBUG
        std::cout << "[" << __func__ << "]" << " Copy-Constructor invoked!\n";
#endif
    /*
    The newly generated message is aware of all
    the folders. However, it being a copy, must
    also make aware of itself  to  the  other's
    (and now its own) folders. Hence we have to
    add_to_folders to update the  folder to msg
    link. 
    */
    add_to_folders(other);
}

Message::Message(Message &&other):
    contents(std::move(other.contents)),
    folders(std::move(other.folders))
{
#ifndef NDEBUG
        std::cout << "[" << __func__ << "]" << " Move-Constructor invoked!\n";
#endif
    for (auto &folder: folders)
    {
        folder->remove_from_folder(&other);
        folder->add_to_folder(this);
    }

    other.contents.clear();
    other.folders.clear();
}

Message::~Message()
{
    /*
    Message will be deleted. Thus, we must
    update all folders  pointing  to  this
    message. Otherwise, we will have  ptrs
    dangling in the Folder class. 
    */
    remove_from_folders();
}

Message& Message::operator=(const Message &rhs)
{
    if (this != &rhs)
    {
#ifndef NDEBUG
        std::cout << "[" << __func__ << "]"  " Copy-Assignment invoked!\n";
#endif
        remove_from_folders();
        contents = rhs.contents;
        folders = rhs.folders;
        /*
        The folders of lhs, rhs currently have no
        idea about  *this.  The  current  message
        however, has an idea of which of  folders
        contain it. The reverse is not true. Thus
        the folders must be updated and insert  a
        new pointer, namely `this`! 
        */
        add_to_folders(rhs);
    }

    return *this;
}

Message& Message::operator=(Message &&rhs)
{
#ifndef NDEBUG
        std::cout << "[" << __func__ << "]"  " Move-Assignment invoked!\n";
#endif
    if (this != &rhs)
    {
        remove_from_folders();
        contents = std::move(rhs.contents);
        folders = std::move(rhs.folders);

        for (auto &folder: folders) // rhs folders now mine
        {
            folder->add_to_folder(this);
            folder->remove_from_folder(&rhs);
        }

        rhs.contents.clear();
        rhs.folders.clear();
    }
    
    return *this;
}

void Message::remove(Folder &f)
{
    remove_from_my_folders(&f);
    f.remove_from_folder(this);
}

void Message::save(Folder &f)
{
    add_to_my_folders(&f);
    f.add_to_folder(this);
}

void Message::add_to_folders(const Message &msg)
{
    for(auto &folder: msg.folders)
        folder->add_to_folder(this);
}

void Message::remove_from_folders()
{
    for(auto &folder: folders)
        folder->remove_from_folder(this);
}

void Message::add_to_my_folders(Folder *folder)
{
    folders.insert(folder);
}

void Message::remove_from_my_folders(Folder *folder)
{
    folders.erase(folder);
}