/**
 * @file simulation.cpp
 * @author DSN
 * @brief Contains the function defining the simulation
 * @version 0.2
 * @date 2023-06-29
 */

/**
 * @brief Use \c constexpr because we know that it has to be a compile-time constant.
 * @details
 *  - See difference between \c const and \c constexpr [here](https://www.learncpp.com/cpp-tutorial/compile-time-constants-constant-expressions-and-constexpr/).
 *  - Although this is used only in \c ballHeight(),
 *    I thought it was better to define it as a global variable in \c simulation.cpp.
 *    Because there's a high chance that tomorrow any other function that's added here
 *    will require the \c gravitationalConstant.
 * 
 */
constexpr double gravitationalConstant = 9.8;


double ballHeight(const double seconds, const double heightOfTower)
{   
    const double distanceTraveled = { (gravitationalConstant * (seconds * seconds)) / 2 };
    const double heightOfBall = { heightOfTower - distanceTraveled };

    if (heightOfBall >= 0)
        return heightOfBall;
    
    return 0; // the ball cannot go below the ground!
}
