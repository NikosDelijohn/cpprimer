#pragma once

#include <iostream>
#include <string>
#include <set>
#include "message.hpp"

class Message;

class Folder
{
public:
    
    Folder(std::string name=""): 
        folder_name(name),
        messages(std::set<Message*>())
    {};
    
    ~Folder() = default;

    void add_to_folder(Message *msg)
    {
        messages.insert(msg);
    };

    void remove_from_folder(Message *msg)
    {
        messages.erase(msg);
    }

    void print_folder()
    {
        std::cout << "Folder: " << folder_name << std::endl;
        for(auto &msg: messages)
        {
            std::cout << "\t- " << msg->contents << std::endl;
        }
        std::cout << std::endl;
    }

private:
    std::string folder_name;
    std::set<Message *> messages;

};
