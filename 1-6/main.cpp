//  Exercise 1 - 6: Modify the AirlineTicket class from Exercise 1 - 5 to include an optional
//  frequent - flyer number.What is the best way to represent this optional data member ? Add a
//  setter and a getter to set and retrieve the frequent - flyer number.Modify the main() function
//  to test your implementation.

#include <iostream>
#include <format>

class AirlineTicket
{
public:
    AirlineTicket()
        : m_passengerName{ "Unknown Passenger" },
        m_numberOfMiles{ 0 },
        m_hasEliteSuperRewardsStatus{ false },
        m_frequentFlierNumber(0)
    {
    }
    ~AirlineTicket()
    {
        // Nothing to do in terms of cleanup
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

    std::string getPassengerName() const { return m_passengerName; }
    void setPassengerName(std::string name) { m_passengerName = name; }

    int getNumberOfMiles() const { return m_numberOfMiles; }
    void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

    bool hasEliteSuperRewardsStatus() const { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status) { m_hasEliteSuperRewardsStatus = status; }

    int getFrequentFlierNumber() const { return m_frequentFlierNumber; }

    void setFrequentFlierNumber(int number) { m_frequentFlierNumber = number; }

private:
    std::string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
    int m_frequentFlierNumber;
};

int main()
{
    AirlineTicket myTicket;

    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    myTicket.setFrequentFlierNumber(100);
    double cost{ myTicket.calculatePriceInDollars() };

    std::cout << std::format("This ticket will cost ${}", cost) << std::endl;
    std::cout << std::format("Frequent Flier Number: {}", myTicket.getFrequentFlierNumber()) << std::endl;

    return 0;
}
