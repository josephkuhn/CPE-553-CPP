/*
    HW3b - Game of Life
    Author: Joseph Kuhn
    Cite: Worked with John Brescia
    I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <fstream>
using namespace std;

class GOL{
private:
    int size, gens, iterations;
public:
    GOL(int size) : size(size){
        int oldBoard[size][size];
        int newBoard[size][size];
        fstream myfile;
        myfile.open("hw3b.dat");
        if (myfile.fail())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        myfile >> gens;
        myfile >> iterations;
        char c;
        int count = 0;
        int temp = 0;

        cout << "Generation 0:" << endl;
        for (int i = 1; i <= size - 2; i++)
        {
            for (int j = 1; j <= size - 2; j++)
            {
                myfile >> c;
                cout << c;
                if (c == '*')
                {
                    oldBoard[i][j] = 1;
                }
                else if (c == '.')
                {
                    oldBoard[i][j] = 0;
                }
            }
            cout << "\n";
        }
        cout << "\n";

        for (int n = 1; n <= gens; n++)
        {
            for (int i = 1; i <= size - 2; i++)
            {
                for (int j = 1; j <= size - 2; j++)
                {
                    if (oldBoard[i-1][j-1] == 1)
                        temp++;
                    if (oldBoard[i-1][j] == 1)
                        temp++;
                    if (oldBoard[i-1][j+1] == 1)
                        temp++;
                    if (oldBoard[i][j-1] == 1)
                        temp++;
                    if (oldBoard[i][j+1] == 1)
                        temp++;
                    if (oldBoard[i+1][j-1] == 1)
                        temp++;
                    if (oldBoard[i+1][j] == 1)
                        temp++;
                    if (oldBoard[i+1][j+1] == 1)
                        temp++;

                    if (oldBoard[i][j] == 1)
                    {
                        if (temp == 2 || temp == 3)
                        {
                            newBoard[i][j] = 1;
                        }
                        else
                        {
                            newBoard[i][j] = 0;
                        }
                    }

                    else if (oldBoard[i][j] == 0)
                    {
                        if (temp == 3)
                        {
                            newBoard[i][j] = 1;
                        }
                        else
                        {
                            newBoard[i][j] = 0;
                        }
                    }

                    temp = 0;

                }
            }

            for (int i = 1; i <= size - 2; i++)
            {
                for (int j = 1; j <= size - 2; j++)
                {
                    oldBoard[i][j] = newBoard[i][j];
                }
            }

            if (n % iterations == 0)
            {
                cout << "Generation " << n << ":" << endl;
                for (int i = 1; i <= size - 2; i++)
                {
                    for (int j = 1; j <= size - 2; j++)
                    {
                        if (newBoard[i][j] == 1)
                        {
                            cout << "*";
                        }
                        else if (newBoard[i][j] == 0)
                        {
                            cout << ".";
                        }
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }
    }
};


int main() {
    GOL(12);
    return 0;
}