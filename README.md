# TikTakToe
The objective of this task was to implement a Tic-Tac-Toe game using the MinMax algorithm with alpha-beta pruning. Additionally, a graphical user interface (GUI) was created for the game using the SFML library. The player had the ability to define the board size and the number of consecutive symbols required to win, as well as the option to reset the board. <br>

The MinMax algorithm with alpha-beta pruning has been previously described and is commonly used for generating optimal moves in strategic games. Additionally, as part of this project, the SFML library was employed to create a graphical user interface for the game. SFML (Simple and Fast Multimedia Library) is a programming library that enables easy development of multimedia applications, such as games, using the C++ language.

To optimize the performance of the MinMax algorithm, the technique of alpha-beta pruning was applied. It involves eliminating unnecessary searches in the state tree by introducing two additional parameters: alpha and beta. The alpha parameter represents the best value that the maximizing player can achieve, while the beta parameter represents the worst value that the minimizing player can achieve. During the tree traversal, if the value for a particular node is worse than alpha or better than beta, the search can be terminated as it will not affect the final outcome.

![image](https://github.com/MateuszAmbrozy/TikTakToe_SFML/assets/127397482/45c427a0-14c5-4312-9253-233a335ba635)

![image](https://github.com/MateuszAmbrozy/TikTakToe_SFML/assets/127397482/b2204529-6a4b-44f7-b6f5-fab268d979e3)

