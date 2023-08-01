/**
 * @file main.cpp
 * @author DSN
 * @brief This program calculates how much money you how much money you make per day from advertising.
 * @version 0.1
 * @date 2023-07-06
 * 
 */

/**
 * @mainpage
 * - You are running a website, and you are trying to keep track of how much money
 * you make per day from advertising.
 * 
 * - Declare an \c Advertising struct that keeps track of how many ads you’ve shown to readers,
 * what percentage of ads were clicked on by users,
 * and how much you earned on average from each ad that was clicked.
 * 
 * - Read in values for each of these fields from the user.
 * Pass the \c Advertising struct to a function that prints each of the values,
 * and then calculates how much you made for that day (multiply all 3 fields together).
 */


#include <iostream>

struct WebAdvertising
{
    long read {};
    double clicked {};
    double commission {};
};

void getDetails(WebAdvertising&);
void print(const WebAdvertising&);
double getEarnings(const WebAdvertising&);


int main()
{    
    WebAdvertising web_ad {};
    getDetails(web_ad);

    std::cout << "\nThis is the information you entered:\n";
    print(web_ad);    

    std::cout << "\nBased on that you've earned $" << getEarnings(web_ad) << ".\n";
}


void getDetails(WebAdvertising& web_ad)
{    
    std::cout << "\nWe calculate for you how much money you've earned today through advertisements on your website.\n";    
    
    std::cout << "\nEnter the number of ads shown to the readers: ";    
    std::cin >> web_ad.read;

    std::cout << "Enter the percentage of ads clicked: ";    
    std::cin >> web_ad.clicked;

    std::cout << "How much do you make per each ad clicked? ";    
    std::cin >> web_ad.commission;    
}


void print(const WebAdvertising& ad)
{
    std::cout << "Number of ads read: " << ad.read << '\n';
    std::cout << "Percentage of ads clicked: " << ad.clicked << '\n';
    std::cout << "Amount earned per ad: " << ad.commission << '\n';
}


double getEarnings(const WebAdvertising& ad)
{
    return ad.read * ad.clicked * ad.commission;
}
