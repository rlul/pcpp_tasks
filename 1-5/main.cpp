//  Exercise 1 - 5: Now that you know about const and references, and what they are used for,
//  modify the AirlineTicket class from earlier in this chapter to use references wherever possible
//  and to be so - called const correct.

#include <iostream>
#include <format>

class AirlineTicket
{
public:
    AirlineTicket()
        : m_passengerName{ "Unknown Passenger" },
        m_numberOfMiles{ 0 },
        m_hasEliteSuperRewardsStatus{ false }
    {
    }

    double calculatePriceInDollars() const
    {
        if (hasEliteSuperRewardsStatus()) {
            // Elite Super Rewards customers fly for free!
            return 0;
        }
        // The cost of the ticket is the number of miles times 0.1.
        // Real airlines probably have a more complicated formula!
        return getNumberOfMiles() * 0.1;
    }

    const std::string& getPassengerName() const { return m_passengerName; }
    void setPassengerName(const std::string& name) { m_passengerName = name; }

    int getNumberOfMiles() const { return m_numberOfMiles; }
    void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

    bool hasEliteSuperRewardsStatus() const { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status) { m_hasEliteSuperRewardsStatus = status; }

private:
    std::string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
};

int main()
{
    AirlineTicket myTicket;
    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    double cost{ myTicket.calculatePriceInDollars() };
    std::cout << std::format("This ticket will cost ${}", cost) << std::endl;

    return 0;
}
