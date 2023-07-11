// Name: Isaac Abella
/*
  Program Description: Takes the command line files and creates rooms using our rooms class and pointers to allocate memory.
  The program will have functions to exit the program and to move between rooms in a text based game format. :3
 */

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cassert>

using namespace std;

class Room
{
public:
    int north = -1;
    int south = -1;
    int east = -1;
    int west = -1;
    string title;
    string description;

    Room(){};
    Room(string t, string d, string e)
    {
        title = t;
        description = d;
        istringstream ss(e);

        while (ss)
        {
            char Dir = 0;
            ss >> Dir;
            int index = -1;

            ss >> index;
            switch (Dir)
            {
            case 'n':
                north = index;
                break;
            case 's':
                south = index;
                break;
            case 'e':
                east = index;
                break;
            case 'w':
                west = index;
                break;
            }
        }
    }
    void look();
};

void Room::look()
{
    cout << title << "\n";
    cout << description << "\n";

    cout << "\nExits: ";
    if (north != -1)
    {
        cout << " n";
    }
    if (east != -1)
    {
        cout << " e";
    }
    if (south != -1)
    {
        cout << " s";
    }
    if (west != -1)
    {
        cout << " w";
    }
    cout << "\n";
};

int main(int argc, char **argv)
{
    string filename = argv[1];
    fstream fin(filename);

    if (argc != 2)
    {
        cerr << "Usage: ./mud.cpp \"room file\" " << endl;
        return 1;
    }
    if (fin.fail())
    {
      cerr << "File failed to open." << endl;
    }

    int RoomCount = 0;
    string ignoreLine;
    string dum;
    while (getline(fin, dum, '~'))
    {
        RoomCount++;
        getline(fin, ignoreLine);
    }
    RoomCount /= 3;
    fin.clear();
    fin.seekg(0); // bring back to new line to read in file

    Room *rooms = new Room[RoomCount + 1];
    string line;
    string ignorenewline;
    for (int i = 0; i < RoomCount; i++)
    {
        string title, description, exit;
        getline(fin, title, '~');
        while (fin.peek() == '\n')
        {
            fin.ignore(1);
        }
        if (title.size() && title.back() == '\n')
        {
            title.pop_back();
        }
        getline(fin, description, '~');
        while (fin.peek() == '\n')
        {
            fin.ignore(1);
        }
        if (description.size() && description.back() == '\n')
        {
            description.pop_back();
        }
        getline(fin, exit, '~');
        while (fin.peek() == '\n')
        {
            fin.ignore(1);
        }

        rooms[i] = Room(title, description, exit);
    }
    fin.close();
    // delete and destroy the rooms to save memory.

    // Start loop
    string input;
    int CurrentRoom = 0;

    do
    {
        cout << "> ";
        if (!(cin >> input) || (input == "q"))
        {
            break;
        }
        if (input == "l")
        {
            rooms[CurrentRoom].look();
        }
        if (input == "n")
        {
            if (rooms[CurrentRoom].north != -1)
            {
                cout << "You moved NORTH. \n";
                CurrentRoom = rooms[CurrentRoom].north;
            }
            else
            {
                cout << "You can't go NORTH!";
            }
        }
        if (input == "s")
        {
            if (rooms[CurrentRoom].south != -1)
            {
                cout << "You moved SOUTH. \n";
                CurrentRoom = rooms[CurrentRoom].south;
            }
            else
            {
                cout << "You can't go SOUTH!";
            }
        }
        if (input == "e")
        {
            if (rooms[CurrentRoom].east != -1)
            {
                cout << "You moved EAST. \n";
                CurrentRoom = rooms[CurrentRoom].east;
            }
            else
            {
                cout << "You can't go EAST!";
            }
        }
        if (input == "w")
        {
            if (rooms[CurrentRoom].west != -1)
            {
                cout << "You moved WEST. \n";
                CurrentRoom = rooms[CurrentRoom].west;
            }
            else
            {
                cout << "You can't go WEST!";
            }
        }

    } while (true);

    return 0;
}
