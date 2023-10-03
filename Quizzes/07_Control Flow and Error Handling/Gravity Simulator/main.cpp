#include <iostream>
#include "constants.h"


double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}


int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;

    double currentHeight { calculateHeight(initialHeight, 0) };
    int time {};

    while (currentHeight != 0) // the ball hasn't reached the ground
    {
        std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << '\n';
        ++time;        
        currentHeight = calculateHeight(initialHeight, time);
    }
    std::cout << "At " << time << " seconds, the ball is on the ground\n";
    
    return 0;
}
