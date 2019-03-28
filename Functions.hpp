#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>

struct Advertising{
    double adsShown;
    double percentageOfAdsClicked;
    double earnedPerClick;
};

void calculateEarnings(Advertising ads);


#endif
