#include "Functions.hpp"
#include <iostream>

void calculateEarnings(Advertising ads){
    std::cout << "You showed " << ads.adsShown << " ads today. \n";
    std::cout << " Of " << ads.adsShown << " ads shown, " << ads.percentageOfAdsClicked << " was clicked. \n";
    std::cout << " on average of each ad clicked you earned " << ads.earnedPerClick << " € \n";
    std::cout << "You made " << ads.adsShown * ads.percentageOfAdsClicked / 100 * ads.earnedPerClick << " € today. \n";
}
