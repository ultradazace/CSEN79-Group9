/*
 * Updated with public member functions
 * This should cover the basics needed 
 * We might need to change things if needed
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
            Bid(const std::string& u, double a) : user(u), amount(a) {};
            std::string user;
            double amount;

            bool operator <(const Bid& other) const {return amount < other.amount;}     // This is to check if bid is less than the bid we are checking
    };

    class Items{
        public:
            Items() : item_name(""), win(false), sPrice(0.0), binPrice(0.0), expiration(0.0) {};
            void setItem(const std::string& name) {item_name = name;}
            void setPrices(double& s, double& b);
            void setTime(int& t) {expiration = t;}
            std::string getItem() const {return item_name;}
            double getPrice_S() const {return sPrice;}
            double getPrice_B() const {return binPrice;}
            int getTime() const {return expiration;}

            void addBid(const Bid& b);          // This is to add and check if b is greater than the highest bid
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
            User();
            ~User();
            void setUsername(const std::string& u);
            void addHistory(const Items& add);
            void startSelling() {isSeller = true;}

            std::string getUsername() const {return username;}

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
            // Might need a constructor here but I don't know
            ~Market();
            void addItem(const Items& i);
            void addUser(const User& u);
            void addLog(const std::string& l);

        private:
            std::vector<Items> active_listings;             // Contains all items currently being auctioned
            std::unordered_map<std::string, User> users;    // This is for our collection of users 
            std::vector<std::string> logs;                  // The logs of previous transactions
    };
}

#endif
