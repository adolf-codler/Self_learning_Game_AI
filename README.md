# Self_learning_Tic_Tac_Toe_AI
Tic Tac Toe AI in C based on reinforcement learning. After every game learns from its mistakes and improve it's AI. 

# How it works?
It is based on Q-learning, which uses a Q-table with dimension 19683 X 9 (why this? explained later) to store the Q-values of each and every move in possible state of the game. The Q-table will stored in the form of a binary to avoid training the AI every time you play.

## How to calculate every state of te game?
A Tic Tac Toe board consist of 9 grids each can be a empty grid, played on O or played on X. So consider this from top left to bottom right we will write whole 9 grids in a 9 digit number with base 3, where 0 means empty grid, 1 means O, 2 means X and convert it into a base 10 digit or decimal system so there will be total of 3^9 = 19683 games possible. Every no. from 0 to 19683 represent a different state of game which can be decoded by converting the no. again in base 3.

## How to train?
Millions of game will be simulated on random and for every game every state of the game and every move played in that state will be saved in a array after the games end, the programm will see who won O or X and according to that Q-table will be updated. Faster win more reward slower win less reward, faster loss more punishment slower loss less punisment.

### Flaw in randomly simulating games?
Suppose at some point X plays a bad move and O plays a good move but later played a bad move and eventually lose to X that will cause increment in the Q-value of the X's bad move and decrement in the O's good move.





