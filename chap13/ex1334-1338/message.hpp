#pragma once

#include <iostream>
#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;

public: 
    // default ctor since the parameter is default
    explicit Message(const std::string &str = ""): contents(str){}

    Message(const Message &);
    Message& operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_folders(const Message &);
    void remove_from_folders();

    void add_to_my_folders(Folder *);
    void remove_from_my_folders(Folder *);
};