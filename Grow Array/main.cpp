// Author: Joseph Kuhn
// Cite: Worked with Ethan Jones & Kyle Bernardes

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class point {
public:
    double x, y;
    //point(double x, double y) : x(x), y(y) {}
};

template<typename T>
class growArray {
private:
    int used, capacity;
    T *data;
    /*void checkGrow() {
        if (used < capacity)
        {
            re
        }
    }*/
public:
    growArray() : used(0), capacity(1), data(new T[capacity]) {}
    growArray(int capacity) : used(0), capacity(capacity), data(new T[capacity]) {}
    ~growArray() {
        delete [] data;
    }
    growArray(const growArray& orig) = delete;
    growArray& operator =(const growArray& orig) = delete;

    T get(int i) {
        return data[i];
    }

    void addEnd(T x) // O(n)
    {
        if (used < capacity) {
            data[used++] = x;
        }
        else {
            const T* old = data;
            capacity *= 2;
            data = new T[capacity];
            for (int i = 0; i < used; i++)
            {
                data[i] = old[i];
            }
            data[used++] = x;
            delete [] old;
        }
    }
    void addStart(T x) // O(n^2)
    {
        const T* old = data;
        if (used == capacity)
        {
            capacity *= 2;
        }
        data = new T[capacity];
        data[0] = x;
        for (int i = 0; i < used; i++)
        {
            data[i + 1] = old[i];
        }
        used++;
        delete [] old;
    }
    void insert(int pos, T x) // O(n^2)
    {
        const T* old = data;
        if (used == capacity)
        {
            capacity *= 2;
        }
        data = new T[capacity];
        for (int i = 0; i < pos; i++)
        {
            data[i] = old[i];
        }
        data[pos] = x;
        for (int i = pos; i < used; i++)
        {
            data[i + 1] = old[i];
        }
        used++;
        delete [] old;
    }
    void removeEnd() // O(1)
    {
        used--;
    }
    void removeStart() // O(n^2)
    {
        const T* old = data;
        data = new T[capacity];
        used--;
        for (int i = 0; i < used; i++)
        {
            data[i] = old[i + 1];
        }
        delete [] old;
    }
    void remove(int pos) // O(n^2)
    {
        const T* old = data;
        data = new T[capacity];
        used--;
        for (int i = 0; i < pos; i++)
        {
            data[i] = old[i];
        }
        for (int i = pos; i < used; i++)
        {
            data[i] = old[i + 1];
        }
        delete [] old;
    }

    int size() // O(1)
    {
        return used;
    }
};

int main() {
    int n = 8;
    growArray <point> a;
    growArray <point> rect[n][n];
    /*for (int i = 0; i < 10; i++) {
        a.addEnd(i);
    }*/
    ifstream file("convexhullpoints.dat");
    double x, y;
    file >> x >> y;
    double maxX, minX = x;
    double maxY, minY = y;
    point values;
    while (file >> x >> y)
    {
        values.x = x;
        values.y = y;
        a.addEnd(values);
        if (x > maxX)
        {
            maxX = x;
        }
        if (x < minX)
        {
            minX = x;
        }
        if (y > maxY)
        {
            maxY = y;
        }
        if (y < minY)
        {
            minY = y;
        }
    }

    for (int z = 0; z < a.size(); z++)
    {
        int i = round((a.get(z).y - minY) / (maxY - minY) * (n - 1));
        int j = round((a.get(z).x - minX) / (maxX - minX) * (n - 1));
        rect[i][j].addEnd(a.get(z));
    }

    cout << minX << ", " << maxX << ", " << minY << ", " << maxY << endl;

    for (int f = 0; f < 8; f++)
    {
        cout << "Cell (" << f << ", 0):" << endl;
        for (int g = 0; g < rect[f][0].size(); g++)
        {
            cout << "(" << rect[f][0].get(g).x << ", " << rect[f][0].get(g).y << ") ";
        }
        cout << endl;
    }
    for (int f = 1; f < 8; f++)
    {
        cout << "Cell (7, " << f << "):" << endl;
        for (int g = 0; g < rect[7][f].size(); g++)
        {
            cout << "(" << rect[7][f].get(g).x << ", " << rect[7][f].get(g).y << ") ";
        }
        cout << endl;
    }

    for (int f = 7; f > 0; f--)
    {
        cout << "Cell (" << f - 1 << ", 7):" << endl;
        for (int g = 0; g < rect[f][7].size(); g++)
        {
            cout << "(" << rect[f][7].get(g).x << ", " << rect[f][7].get(g).y << ") ";
        }
        cout << endl;
    }

    for (int f = 7; f > 1; f--)
    {
        cout << "Cell (0, " << f - 1 << "):" << endl;
        for (int g = 0; g < rect[0][f].size(); g++)
        {
            cout << "(" << rect[0][f].get(g).x << ", " << rect[0][f].get(g).y << ") ";
        }
        cout << endl;
    }

        //getline(file, str);
        //size = stoi(str);
        //file >> size;
        //cout << "Size: " << size << endl;

    /*a.insert(4, 100);
    a.removeEnd();
    a.removeStart();
    a.remove(3);*/

    /*for (int i = 0; i < a.size(); i++)
    {
        cout << a.get(i).x << endl;
    }*/
}
