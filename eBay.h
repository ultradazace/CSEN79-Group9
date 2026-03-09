/*
 * Updated and working on public member functions 
 * This should cover the basics needed 
 * 
 * 
 * Feel free to make changes or add anything new
 * Also leave ideas for public member functions
 */

#ifndef EBAY_H
#define EBAY_H
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

namespace ebay{
    class Bid{
        public:
            std::string user;
            double amount;
            bool operator <(const Bid& other) const {return amount < other.amount;}
    };

    class Items{
        public:
        // Same here from line 9
        private:
            std::string item_name;
            bool win;                           // If this item was won in a bid
            double sPrice;                      // Starting price
            double binPrice;                    // "Buy it now price", if the user wants to skip the whole auction process and get it now
            int expiration;                     // When the item goes off sale in hours (There might be another way to do this)
            std::priority_queue<Bid> bids;      // The current bids for the item
    };

    class User{
        public:
        // Some getters and setters 
        private:
            std::string username;
            bool isSeller;                         // If true, then we initiate selling
            Items* history[30];                    // List has about 30 past entries. I don't think we need to care about having all past entries
            Items* selling;                        // Only one item can be sold for now
            std::vector<Items*> interest;          // Items that the user wants to keep track of
    };

    // This is basically the main class
    class Market{
        public:

        private:
            std::vector<Items> active_listings;             // Contains all items currently being auctioned
            std::unordered_map<std::string, User> users;    // This is for our collection of users 
            std::vector<std::string> logs;                  // The logs of previous transactions
    };
}

#endif
