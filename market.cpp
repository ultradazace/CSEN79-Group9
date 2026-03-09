#include "ebay.h"

using namespace ebay;

Market::~Market()
{
    // std::vector and std::unordered_map manage their own memory
}

void Market::addItem(const Items &i)
{
    active_listings.push_back(i);
}

void Market::addUser(const User &u)
{
    users[u.getUsername()] = u;
}

void Market::addLog(const std::string &l)
{
    logs.push_back(l);
}
