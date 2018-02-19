/*********************************************************************
** Program: Final Project
** File: game.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the Game class
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "game.hpp"
#include "space.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets values and null pointers, gives an option to show
**  the guide, and prints the beginning sequence.
*********************************************************************/
Game::Game()
{
    currentArea = NULL;
    finalArea = NULL;
    gameFinished = false;
    threatLevel = 5;

    char gd = '0';
    cout << "\nPress 'g' to view the guide, or another char to skip.  ";
    cin >> gd;

    if (gd == 'g')
    {
        longScript("guide.txt");
        cout << "\nPress [Enter] to continue.  ";
        std::cin.ignore();
        std::cin.ignore();
        cout << std::endl << std::endl;
    }

    longScript("initialscript.txt");
    cout << "\nPress [Enter] to continue.  ";
    std::cin.ignore();
    cout << std::endl << std::endl;
}

/*********************************************************************
** Destructor; sets pointers to null
*********************************************************************/
Game::~Game()
{
    currentArea = NULL;
    finalArea = NULL;
}

/*********************************************************************
** Runs the game.  Starts by creating areas and connecting them; then
**  creates all items and assigns them to their proper containers.
**  Loops the menu and action sequence while the game is incomplete.
**  Checks for threat and player health, taking actions accordingly
**  (switching the complete bool, spawning a robot, reducing health).
**  Deletes dynamically created areas at the end of the game.
*********************************************************************/
void Game::runGame()
{
    //Create first two areas, connect pointers
    currentArea = new FrontHall;
    finalArea = new WorkArea;
    finalArea->connect('e', currentArea);
    currentArea->connect('w', finalArea);

    //Create supply room and connect
    currentArea = new SupplyRoom;
    finalArea->connect('n', currentArea);
    currentArea->connect('s', finalArea);

    //Create office and connect
    finalArea = new Office;
    finalArea->connect('w', currentArea);
    currentArea->connect('e', finalArea);

    //Create proto chamber; set pointer to Game; connect
    currentArea = new ProtoChamber;
    (*currentArea).setGamePoint(this);
    finalArea->connect('e', currentArea);
    currentArea->connect('w', finalArea);

    //Current area moves back to front hall
    currentArea = finalArea->getDirection('w');
    currentArea = currentArea->getDirection('s');
    currentArea = currentArea->getDirection('e');

    //Office points to locked front hall
    finalArea->pointToLocked(currentArea);

    //Create items and assign to "ground" containers
    createItems();

    //Create last room
    finalArea = new TerminalRoom;

    //Connect west to, but not east from, front hall
    finalArea->connect('w', currentArea);
    currentArea->pointToLocked(finalArea);

    //Start Prokovic in current area (front hall)
    proko = MainChar(currentArea);
    proko.addItem(&wrench);

    while (gameFinished == false)
    {
        menu();
        std::cin.clear();
        char choice = '0';
        cin >> choice;
        int act = action(choice);   //Actions cause threat countdown
        threatLevel -= act;

        if (threatLevel == 1 || (threatLevel == 0 && act == 2))
        {
            spawnRobot();   //Attacked by robot
        }

        if (threatLevel <= 0)   //Wounded by robot
        {
            proko.decHealth();
            cout << "\nYou've been wounded by the attacking robot!\n";
            threatLevel = 0;
        }

        if (proko.getHealth() <= 0)     //Death, game over
        {
            cout << "\n\nYou died.  The human race is doomed, and ";
            cout << "the era of the robot is about to dawn.\n\n";
            gameFinished = true;
        }

        if ((*finalArea).complete())    //Print end sequence
        {
            gameFinished = true;
            longScript("finalscript.txt");
        }
    }

    //Delete all dynamic memory

    currentArea = finalArea->getDirection('w');
    delete finalArea;
    finalArea = currentArea->getDirection('w');
    finalArea = finalArea->getDirection('n');
    finalArea = finalArea->getDirection('e');
    delete finalArea->getDirection('w');
    delete finalArea->getDirection('e');
    delete currentArea->getDirection('w');
    delete currentArea;
    delete finalArea;
}
/*********************************************************************
** Runs the game's menu function for user actions
*********************************************************************/
void Game::menu()
{
    if (threatLevel > 1)
    {
        (*currentArea).showSpace('1');  //Normal Space image
    }
    else
    {
        (*currentArea).showSpace('2');  //Image with attacking robot
    }

    if (proko.getHealth() == 2)     //Show health
    {
        cout << "\nHealth   <3  <3  \n";
    }

    else if (proko.getHealth() == 1)
    {
        cout << "\nHealth   <3  \n";
    }

    cout << "\n[1] Move \n[2] Inventory ";  //Static options

    int lCount = 3;
    if ((*currentArea).beenSearched())
    {
        //Shows option to interact if available
        if (!(*currentArea).complete())
        {
            cout << "\n[" << lCount << "] ";
            cout << (*currentArea).getObjective();
            lCount++;
        }

        //Shows option to pick up items if available
        if ((*currentArea).getItems() > 0)
        {
            cout << "\n[" << lCount << "] ";
            cout << "Pick up item(s)";
            lCount++;
        }
    }

    else    //Search area option if Space not searched
    {
        cout << "\n[3] Search area ";
    }

    cout << std::endl;
}

/*********************************************************************
** Executes an action based on the user's menu choice; can move, view
**  inventory options, search the area, view and pick up items, and
**  interact with the Space.  Increments an actionTaken variable for
**  the threat count and returns that variable.
*********************************************************************/
int Game::action(char choice)
{
    int actionTaken = 0;

    if (choice == '1')      //Move to a new Space
    {
        actionTaken += proko.move();
        currentArea = proko.getLocation();
    }

    else if (choice == '2')     //Bring up inventory menu
    {
        actionTaken += proko.inventoryMenu(threatLevel);
    }

    //Options after 1 and 2 are dynamic due to menu showing only
    // those that are available

    else if (choice == '3')     //Search area if not searched
    {
        if (!(*currentArea).beenSearched())
        {
            (*currentArea).showScript();
            actionTaken++;
        }

        else if (!(*currentArea).complete())    //Interact
        {
            threatLevel += (*currentArea).interact();
            actionTaken++;
        }
        //Pick up an item
        else if ((*currentArea).getItems() > 0 && !proko.invFull())
        {
            int n = (*currentArea).showItems();
            if (n > 0)
            {
                proko.addItem((*currentArea).popItem(n-1));
                actionTaken++;
            }
        }
        else
        {
            return 0;   //Input not recognized
        }
    }

    else if (choice == '4')     //4th option is dynamic
    {
        if (!(*currentArea).beenSearched())
        {
            return 0;
        }
        else if ((*currentArea).complete())
        {
            return 0;
        }
        else if ((*currentArea).getItems() > 0 && !proko.invFull())
        {
            int n = (*currentArea).showItems();
            if (n > 0)
            {
                proko.addItem((*currentArea).popItem(n - 1));
                actionTaken++;
            }
        }
        else    //Input not recognized
        {
            cout << "\nPlease enter a valid option.\n";
            return 0;
        }
    }

    else    //Input not recognized
    {
        cout << "\nPlease enter a valid option.\n";
    }

    return actionTaken;
}

/*********************************************************************
** Notifies user that a robot has been spawned
*********************************************************************/
void Game::spawnRobot()
{
    cout << "\nA robot has entered the room!  Defend yourself!\n";
}

/*********************************************************************
** Adds to the threat variable to "reduce" threat (delay countdown)
*********************************************************************/
void Game::reduceThreat(int add)
{
    threatLevel += add;
}

/*********************************************************************
** Prints a txt file (used for beginning, guide, and end sequences
*********************************************************************/
void Game::longScript(string fName)
{
    std::ifstream script;
    script.open(fName);

    if (!script)
    {
        cout << "\nScript file cannot be displayed.\n";
    }

    string display;

    while (script)
    {
        display = "";
        std::getline(script, display);
        cout << display << std::endl;
    }
}

/*********************************************************************
** Creates all items at the beginning of the game and assigns them to
**  their relevant containers
*********************************************************************/
void Game::createItems()
{
    char t = 'w';
    string n = "Wrench";
    string i = "A tool.  Maybe a weapon, in desperate situations. \n";
    i += "However, if you use it in close combat, you may not";
    i += " get out unscathed.";
    int ul = 9999;
    Space * s = NULL;
    wrench = Item(n, i, ul, t, s);

    t = 'w';
    n = "Electroshock flux initiationizer";
    i = "Sends an overcharge of energy to a machine's circuits. ";
    i += "\nLow on energy, so it probably has one use left.";
    ul = 1;
    efi = Item(n, i, ul, t, s);

    t = 'w';
    n = "Infinite loop effectuationer";
    i = "Sends an NFC signal that targets and manipulates a computer";
    i += " system's binary bits and \nsends it into an infinite loop.";
    i += "  Unsure how many times it's usable, so use it wisely.";
    ul = 2;
    ild = Item(n, i, ul, t, s);

    t = 'q';
    n = "Terminal room keycard";
    i = "Opens the door to the main terminal room from the front hall.";
    ul = 1;
    s = currentArea;
    key = Item(n, i, ul, t, s);

    t = 'q';
    n = "Power cell";
    i = "Used to power one of your old robot models, the TL7-X.";
    ul = 1;
    s = finalArea->getDirection('e');
    pwrCell = Item(n, i, ul, t, s);

    //Drop items on ground in proper Spaces
    (*finalArea).dropItem(&key);
    finalArea = finalArea->getDirection('w');
    (*finalArea).dropItem(&pwrCell);
    finalArea = finalArea->getDirection('s');
    (*finalArea).dropItem(&efi);
    (*finalArea).setQitem(&ild);
}
