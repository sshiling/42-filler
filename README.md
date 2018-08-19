# 42-filler
## Algorithmic project 

Filler is the second project of algorithm branch in the study program at School 42 (UNIT Factory). <br>

All functions are created in accordance with Norm - the bunch of rules how code should be formatted.

**!NOTE** <br />
Because of 42 School norm requirements: <br />
* All variables are declared and aligned at the top of each function <br />
* Each function can't have more then 25 lines of code <br />
* C++ style code commenting is forbidden <br />
* Project should be created just with allowed functions otherwise it's cheating. <br />

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

### For example:
```
Start of the game:                       End of the game:
........................................ XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................ XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................ XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
...O.................................... XXXOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................ XXXXOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................ XXXXOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
........................................ XXXXOOOXXXXXXXXXXXXXXXXXXXXXXOOOOXXXXXXX
........................................ XXXXX.OXXXXXXXXXXXXXXOOXOOOXXOOOOX.XXXXX
........................................ XX.XXXOXXXXXXXXOOOOOOOOOOOOOOOOOOOOOOXXX
........................................ .XXXXXOOXXXXXXXXOOOOOOOOOOOOOOOOOOOOXXOO
........................................ ..XXXXOOXOOOOOOXXOOOOOOOOOOOOOOOOOOOOOOO
........................................ .XXXoooOOOOOOOOOXOOXOOOOOOOOOOOOOOOOOOO.
........................................ .XXXOOOOOOOOOOOOXXXXOOOOOOOOOOOOOOOOOOOO
........................................ ...OOOOOOOOOOOOOOOOXXOOOOOOOOOOOOOOOOOOO
........................................ ..OOOOOOOOOOOOOOOOOOXXOOOOOOOOOOOOOOOOOO
........................................ ....OOOOOOOOOOOOOOOOXXXOOOOOOOOOOOOOOOOO
........................................ ....OOOOOOOOOOOOOOOOOOXXXXXXXOOOOOOOOOOO
........................................ ..OOOOOOOOOOOOOOOOOOOOOOOOOXXOOOOOOOOOOO
........................................ ..OOOOOOOOOOOOOOOOOOOOOOOOOOXXOOOOOOOOOO
................................X....... ..OOOOOOOOOOOOOOOOOOOOOOOOOOXXXXXOOOOOOO
........................................ ..OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
........................................ ..OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
........................................ ...OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
........................................ ....OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.
```
Each turn, the active player receives the grid status and must maximize his points while trying to minimize
those of the opponent by eliminating it as quickly as possible.

#### More about School 42 you can find here: https://en.wikipedia.org/wiki/42_(school)
