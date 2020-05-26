#include <iostream>
using namespace std;

class Coordinate
{
public:
    friend ostream &operator<<(ostream &out, Coordinate &coor);
    Coordinate(int x = 0, int y = 0)
    {
        m_iX = x;
        m_iY = y;
    }

    ~Coordinate()
    {
    }

private:
    int m_iX;
    int m_iY;
};
ostream &operator<<(ostream &out, Coordinate &coor)
{
    out << "(" << coor.m_iX << "," << coor.m_iX << ")" << endl;
    return out;
}
