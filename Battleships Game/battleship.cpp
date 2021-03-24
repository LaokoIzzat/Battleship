// Name: Laoko Izzat
// Student ID: 160419328
// Student Email: l.izzat@se16.qmul.ac.uk

#include <iostream>
#include <string>
using namespace std;

const int rows = 8;
const int cols = 8;

char displayMainMenu()
{
    cout << "----------------------------" << endl;
    cout << "         Battleships        " << endl;
    cout << "          Main Menu         " << endl;
    cout << "----------------------------" << endl;
    cout << "        1. Start Game       " << endl;
    cout << "        2. Exit Game        " << endl;

    char startOrExit;

    while (true)
    {
        cout << "Enter menu selection(1-2): ";
        cin >> startOrExit;
        cin.ignore(100, '\n'); // This is needed as I used getline after displaying main menu if the player chooses to start the game with 1.
        if (startOrExit == 49)
        {
            cout << "\x1B[2J\x1B[H"; // This clears console.
            break;
        }
        else if (startOrExit == 50)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
            cout << "Invalid entry! Please try again." << endl;
    }
    return startOrExit;
}

void enterToContinue() // Function which allows user to press enter to continue.
{
    cout << "Press enter to continue!";
    cin.clear();          //clears the stream
    cin.ignore(50, '\n'); //ignores next line(enter)
    cin.get();            //“cin>>” expects at least one char input, just enter doesn’t work
}

void getCoordinates(char *x, char *y) 
{
    while (true)
    {
        cout << "Enter the x coordinate (A-H): ";
        cin >> *x;
        if (*x >= 'A' && *x <= 'H')
            break;
        else
            cout << "Invalid entry! Please try again." << endl;
    }

    while (true)
    {
        cout << "Enter the y coordinate (1-8): ";
        cin >> *y;
        if (*y >= 49 && *y <= 56)
            break;
        else
            cout << "Invalid entry! Please try again." << endl;
    }
}

class Ship
{
private:
    int size;
    int hits;
    string type;

public:
    Ship(int size, string type)
    {
        this->hits = 0;
        this->size = size;
        this->type = type;
    }

    bool isSunk()
    {
        if (hits == size)
            return true;
        else
            return false;
    }

    int getSize()
    {
        return size;
    }

    string getType()
    {
        return type;
    }

    void hit()
    {
        this->hits++;
    }
};

class BattleshipSquare
{
private:
    Ship *ship;
    bool isFired;

public:
    BattleshipSquare()
    {
        this->ship = NULL;
        this->isFired = false;
    }

    void reset()
    {
        this->ship = NULL;
        this->isFired = false;
    }

    void addShip(Ship *ship)
    {
        this->ship = ship;
    }

    char getStatus()
    {
        if (ship == NULL && isFired == true)
            return 'M';
        else if (ship == NULL && isFired == false)
            return 'E';
        else if (ship != NULL && isFired == true)
            return 'H';
        else
            return 'S';
    }

    char forShow()
    {
        if (ship == NULL)
            return ' ';
        else
            return 'S';
    }

    void fire()
    {
        if (ship != NULL && ship->isSunk() == false)
        {
            ship->hit();
            this->isFired = true;
        }
    }
};

class Board
{
private:
    BattleshipSquare squares[rows][cols];
    char firingBoard[rows][cols];

public:
    void resetBoard() // This function makes the board which player will add ships to.
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                squares[i][j].reset();
            }
        }
    }

    void makeFiringBoard() // This function makes the board which player use when firing and will add hits and misses to.
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                firingBoard[i][j] = 32;
            }
        }
    }

    void displayShipBoard() // This function displays the board which player will see when adding ships i.e. the real board.
    {
        cout << "   A--B--C--D--E--F--G--H" << endl;
        cout << "--------------------------" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (j == 0)
                    cout << j + i + 1 << "| " << squares[i][j].forShow() << "  ";
                else
                    cout << squares[i][j].forShow() << "  ";
            }
            cout << "\n--------------------------" << endl;
        }
    }

    void displayFiringBoard() // This function displays the board which player will see when firing at the ships.
    {
        cout << "   A--B--C--D--E--F--G--H" << endl;
        cout << "--------------------------" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (j == 0)
                    cout << j + i + 1 << "| " << firingBoard[i][j] << "  ";
                else
                    cout << firingBoard[i][j] << "  ";
            }
            cout << "\n--------------------------" << endl;
        }
    }

    char getSquareState(char x, char y) // returns the value at the square of the coordinates provided.
    {
        return squares[y - 49][x - 65].getStatus();
    }

    char placeShip(char x, char y, char dir, Ship *ship)
    {
        char worked = 'y';
        bool found;

        if (dir == 'E' && (y - 49 >= 0) && (y - 49 <= 7) && (x - 65 + ship->getSize() - 1 >= 0) && (x - 65 + ship->getSize() - 1 <= 7)) //First if checks the direction inputted and makes sure the coordinates and direction will be in range of the array (0 to 7)
        {
            for (int a = 0; a < ship->getSize(); a++) // This loop and if statement checks whether or not a ship has already been placed on any of the squares that will be occupied by the ship user is trying to place.
            {
                found = 'S' == (squares[y - 49][x - 65 + a].getStatus());
                if (found == true)
                {
                    cout << "Invalid entry! Please try again." << endl;
                    return worked = 'n';
                    break;
                }
            }
            if (found == false) // If the user has picked valid coordinates and direction and size of a ship, it will be placed onto the board.
            {
                for (int i = 0; i < ship->getSize(); i++)
                {
                    squares[y - 49][x - 65 + i].addShip(ship);
                }
            }
        }
        else if (dir == 'W' && (y - 49 >= 0) && (y - 49 <= 7) && (x - 65 - ship->getSize() + 1 >= 0) && (x - 65 - ship->getSize() + 1 <= 7))
        {
            for (int b = 0; b < ship->getSize(); b++)
            {
                found = 'S' == (squares[y - 49][x - 65 - b].getStatus());
                if (found == true)
                {
                    cout << "Invalid entry! Please try again." << endl;
                    return worked = 'n';
                    break;
                }
            }
            if (found == false)
            {
                for (int j = 0; j < ship->getSize(); j++)
                {
                    squares[y - 49][x - 65 - j].addShip(ship);
                }
            }
        }
        else if (dir == 'N' && (y - 49 - ship->getSize() + 1 >= 0) && (y - 49 - ship->getSize() + 1 <= 7) && (x - 65 >= 0) && (x - 65 <= 7))
        {
            for (int c = 0; c < ship->getSize(); c++)
            {
                found = 'S' == (squares[y - 49 - c][x - 65].getStatus());
                if (found == true)
                {
                    cout << "Invalid entry! Please try again." << endl;
                    return worked = 'n';
                    break;
                }
            }
            if (found == false)
            {
                for (int k = 0; k < ship->getSize(); k++)
                {
                    squares[y - 49 - k][x - 65].addShip(ship);
                }
            }
        }
        else if (dir == 'S' && (y - 49 + ship->getSize() - 1 >= 0) && (y - 49 + ship->getSize() - 1 <= 7) && (x - 65 >= 0) && (x - 65 <= 7))
        {
            for (int d = 0; d < ship->getSize(); d++)
            {
                found = 'S' == (squares[y - 49 + d][x - 65].getStatus());
                if (found == true)
                {
                    cout << "Invalid entry! Please try again." << endl;
                    return worked = 'n';
                    break;
                }
            }
            if (found == false)
            {
                for (int l = 0; l < ship->getSize(); l++)
                {
                    squares[y - 49 + l][x - 65].addShip(ship);
                }
            }
        }
        else
        {
            cout << "Invalid entry! Please try again." << endl;
            return worked = 'n';
        }
        return worked;
    }

    char fireAtSquare(char x, char y)
    {
        if ((squares[y - 49][x - 65].getStatus() == 'S') && (firingBoard[y - 49][x - 65] != 'H') && (firingBoard[y - 49][x - 65] != 'M'))
        {
            cout << "It's a hit!" << endl;
            firingBoard[y - 49][x - 65] = 'H';
            squares[y - 49][x - 65].fire();
            return 'h';
        }
        else if ((squares[y - 49][x - 65].getStatus() != 'S') && (firingBoard[y - 49][x - 65] != 'H') && (firingBoard[y - 49][x - 65] != 'M'))
        {
            cout << "It's a miss!" << endl;
            firingBoard[y - 49][x - 65] = 'M';
            return 'm';
        }
        else
        {
            cout << "Invalid entry! You have already fired at that square. Please try again." << endl;
            return 'f';
        }
    }
};

class Player
{
private:
    string name;
    Board board;
    Ship *ships[5];

public:
    // Here the reason I have 2 constructors is because I tried to make global ships of each type and had one constructor, then I realised in the firing function that the players were using the same ships, i.e. they both shared the same 5 ships.
    // Therefore, my quickfire solution to this problem was to just make 2 arrays of 5 ships and then have 2 different constructors so that p1 would call the first constructor and get p1Ships, and p2 would call the second constructor and get p2ships.
    Player(Ship p1Ships[5])
    {
        this->ships[0] = &p1Ships[0];
        this->ships[1] = &p1Ships[1];
        this->ships[2] = &p1Ships[2];
        this->ships[3] = &p1Ships[3];
        this->ships[4] = &p1Ships[4];
        board.resetBoard();
        board.makeFiringBoard();
    }

    Player(Ship p2Ships[5], int num)
    {
        this->ships[0] = &p2Ships[0];
        this->ships[1] = &p2Ships[1];
        this->ships[2] = &p2Ships[2];
        this->ships[3] = &p2Ships[3];
        this->ships[4] = &p2Ships[4];
        board.resetBoard();
        board.makeFiringBoard();
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void displayShipBoard()
    {
        board.displayShipBoard();
    }

    void displayFiringBoard()
    {
        board.displayFiringBoard();
    }

    // I used addships to call placeships in the board class.
    void addShips() // This function will loop and ask user to add each type of ship with the size it occupies on the board.
    {
        cout << "----------------------------------" << endl;
        cout << "             Add Ship             " << endl;
        cout << "----------------------------------" << endl;
        cout << "    No   Name            Squares  " << endl;
        cout << "----------------------------------" << endl;
        cout << "     1  Carrier             5     " << endl;
        cout << "     1  Battleship          4     " << endl;
        cout << "     1  Cruiser             3     " << endl;
        cout << "     1  Submarine           3     " << endl;
        cout << "     1  Destroyer           2     " << endl;
        cout << "----------------------------------" << endl;

        char x = 'a', y = 49; // Here I am just initialising the variables x and y however, they will change to whatever the user inputs once getCoordinates is called.
        char direction;
        string name = getName();

        for (int i = 0; i < 5; i++)
        {
            while (true)
            {
                cout << name << " add a " << ships[i]->getType() << " size: " << ships[i]->getSize() << endl;
                ::getCoordinates(&x, &y);
                while (true)
                {
                    cout << "Enter the direction (N/E/S/W): ";
                    cin >> direction;
                    if (direction == 'N' || direction == 'E' || direction == 'S' || direction == 'W')
                        break;
                    else
                        cout << "Invalid entry! Please try again." << endl;
                }
                char worked = board.placeShip(x, y, direction, *(ships + i)); // worked takes the return value of the placeShip function which will be 'y' if the ship was able to be placed and 'n' if it was not i.e. the ships were placed off of the board or the ships were placed on top of a pre-existing ship.
                if (worked == 'y')
                    break;
            }
            displayShipBoard();
        }
        cout << "All ships are added!" << endl;
        ::enterToContinue();
    }

    char fire(char x, char y)
    {
        char hit_or_miss = board.fireAtSquare(x, y);
        return hit_or_miss;
    }

    bool checkLost() 
    {
        bool lost = false;
        if ((ships[0]->isSunk()) && (ships[1]->isSunk()) && (ships[2]->isSunk()) && (ships[3]->isSunk()) && (ships[4]->isSunk()))
            lost = true;
        return lost;
    }
};

void firingFunc(Player *att, Player *def) // firing function takes 2 pointers to class Player.
{
    int turn = 1;
    while (true)
    {
        cout << "Turn: " << turn << endl; // Here the input parameter turn will be the variable turn I set in the for loop in main function.
        cout << "Player " << att->getName() << " enter coordinates to fire" << endl;
        def->displayFiringBoard(); // This doesn't make sense logically as it should show the attacking players board obviously however, that is indeed what it does when you run the program.
        char x = 'a', y = 49;      // Here I am just initialising the variables x and y however, they will change to whatever the user inputs once getCoordinates is called.
        while (true)
        {
            ::getCoordinates(&x, &y);
            char fired = def->fire(x, y);     // Defending player is fired at.
            if (fired == 'h' || fired == 'm') // If hit or miss i.e. not an invalid fire i.e. haven't fired at that square before.
                break;
        }
        ::enterToContinue();
        bool def_lost = def->checkLost();
        if (def_lost == true) // Checks if player has won and breaks out of while loop.
        {
            def->displayFiringBoard();
            cout << "Player " << att->getName() << " you win!" << endl;
            break;
        }
        swap(*att, *def); // Swaps the pointers to the attacking and defending player.
        turn++;
    }
}

int main()
{
    char started = displayMainMenu();

    if (started == 49) // If user enters 1 to start game, will execute.
    {
        // p1Ships is to be used in the first constructor in player class.
        Ship p1destroyer(2, "Destroyer");
        Ship p1submarine(3, "Submarine");
        Ship p1cruiser(3, "Cruiser");
        Ship p1battleship(4, "Battleship");
        Ship p1carrier(5, "Carrier");
        Ship p1Ships[5] = {p1destroyer, p1submarine, p1cruiser, p1battleship, p1carrier};

        // p2Ships is to be used in the second constructor in player class.
        Ship p2destroyer(2, "Destroyer");
        Ship p2submarine(3, "Submarine");
        Ship p2cruiser(3, "Cruiser");
        Ship p2battleship(4, "Battleship");
        Ship p2carrier(5, "Carrier");
        Ship p2Ships[5] = {p2destroyer, p2submarine, p2cruiser, p2battleship, p2carrier};

        string name;
        Player p1(p1Ships);
        cout << "**Enter player 1 name: ";
        getline(cin, name);
        p1.setName(name);
        Player p2(p2Ships, 2); //Here I have added a 2 as an argument when creating a p2 object so that I could use a different constructor and use p2Ships.
        cout << "**Enter player 2 name: ";
        getline(cin, name);
        p2.setName(name);

        p1.addShips();
        p2.addShips();

        Player *att = &p1; // Pointer to attacking player which is p1 on turn 1.
        Player *def = &p2; // Pointer to defending player which is p2 on turn 1.
        firingFunc(att, def);
    }

    return 0;
}