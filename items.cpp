#include "eBay.h"

using namespace ebay;

void Items::addBid(const std::string userName, const double bidAmount)
{
    // precondition: item has not already been won/sold, and new bid is higher than previous high bid
    if (win)
    {
        return;
    }
    if (bidAmount >= binPrice) // if the bid is equal to or higher than the buy it now price
    {
        win = true;
        Bid newBid = Bid(userName, binPrice);
        bids.push_back(newBid);
        highestBid = binPrice;
        winner = userName;
    }
    else if (bidAmount >= highestBid)
    {
        highestBid = bidAmount;
        Bid newBid = Bid(userName, bidAmount);
        bids.push_back(newBid);
    }
    else
    {
        return;
    }
}
