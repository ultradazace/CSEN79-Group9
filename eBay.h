/*
 * This is my current progress on the .h file, just making the private members first then doing public later
 * User class is what 3A is on the file on canvas
 * Items class is what 3B is with Market class also being a part of that
 * 
 * Feel free to make changes or add anything new
 * Also leave ideas for public member functions
 */

#ifndef EBAY.H
#define EBAY.H
#include <string>
#include <vector>

namespace ebay{
    class User{
        public:
        // Some getters and setters 
        private:
            std::string username;
            bool isSeller;              // If true, then we initiate selling
            Items* history[30];         // List has about 30 past entries (could make a new class for this)
            Items selling;              // Only one item can be sold for now
            Items* interest[];          // Items that the user wants to keep track of (could be a better way for this)
    };

    class Items{
        public:
        // Same here from line 9
        private:
            std::string item_name;
            bool win;                   // If this item was won in a bid
            double sPrice;              // Starting price
            double binPrice;            // "Buy it now price", if the user wants to skip the whole auction process and get it now
            int expiration;             // When the item goes off sale in hours (There might be another way to do this)
    };

    class Market{
        public:

        private:
            std::vector<Items> active_listings;
    };


}

#endif