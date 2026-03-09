#include "ebay.h"

using namespace ebay;

User::User()
{
    // interest has a constructor
    username = "";
    isSeller = false;
    selling = nullptr;

    for(int i = 0; i < 30; i++)
        history[i] = nullptr;

}

User::~User()
{
    // Deallocates everything
    delete selling;
    for(int i = 0; i < 30; i++)
    {
        delete history[i];
    }
}

void User::addHistory(const Items& add)
{
    // precondition: history has space left, if not then we delete the oldest and place the newest

    // Goes through array to insert add
    for(int i = 0; i < 30; i++)
    {
        if(history[i] == nullptr)
        {
            history[i] = new Items(add);
            return;
        }
    }

    // If no space, then delete oldest then insert add to the newest
    delete history[0];
    for(int i = 0; i < 29; i++)
    {
        history[i] = history[i+1];
    }
    history[29] = new Items(add);
}

bool User::interested(const std::string& name) const
{
    // precondition: name should be valid and interest should be pointing to an Items or nullptr
    size_t i = 0;
    while(i < interest.size())
    {
        if(interest[i] != nullptr && interest[i]->getItem() == name)
            return true;
        i++;
    }
    return false;
}
