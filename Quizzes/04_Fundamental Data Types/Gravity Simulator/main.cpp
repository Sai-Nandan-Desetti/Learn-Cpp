/**
 * @file main.cpp
 * @author DSN
 * @brief Simulates the action of a ball being dropped from a tower.
 * @version 0.2
 * @date 2023-06-29
 * 
 */

/**
 * @mainpage
 * <b>Chapter</b> [4.x](https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/)
 * \n
 * Write a short program to simulate a ball being dropped off of a tower.
 *  - To start, the user should be asked for the height of the tower in meters.
 *  - Assume normal gravity (9.8 m/s@sup{2}), and that the ball has no initial velocity (the ball is not moving to start).
 *  - Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
 *  - The ball should not go underneath the ground (height 0).
 * \n
 * Use a function to calculate the height of the ball after \c x seconds.
 *  - The function can calculate how far the ball has fallen after \c x seconds using the following formula:
    @verbatim
    distance_fallen = gravity_constant * x^2 / 2
    @endverbatim 
 * 
 * Desired output:
    @verbatim
    Enter the height of the tower in meters: 100
    At 0 seconds, the ball is at height: 100 meters
    At 1 seconds, the ball is at height: 95.1 meters
    At 2 seconds, the ball is at height: 80.4 meters
    At 3 seconds, the ball is at height: 55.9 meters
    At 4 seconds, the ball is at height: 21.6 meters
    At 5 seconds, the ball is on the ground.
    @endverbatim
 * 
 */


#include "io.h"
#include "simulation.h"


int main()
{
    const double heightOfTower{ getInput("Enter the height of the tower (in meters): ") };

    printResult(0, ballHeight(0, heightOfTower));
    printResult(1, ballHeight(1, heightOfTower));
    printResult(2, ballHeight(2, heightOfTower));
    printResult(3, ballHeight(3, heightOfTower));
    printResult(4, ballHeight(4, heightOfTower));
    printResult(5, ballHeight(5, heightOfTower));    
}
