#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class DataPoint
{
    short N, M, D;
public:
    DataPoint(void) : N(0), M(0), D(0){}
    DataPoint(short new_n, short new_m, short new_d) : N(new_n), M(new_m), D(new_d){}
    DataPoint(const DataPoint & point) : N(point.N), M(point.M), D(point.D){}

    void set_n(short new_n) {N = new_n;}
    void set_m(short new_m) {M = new_m;}
    void set_d(short new_d) {D = new_d;}

    void print(void) const
    {
        cout << "Steps: " << N << "    Trial #: " << M << "    End Pos: " << D << endl;
        return;
    }
};

void particle_walk(short N, short M)
{
    short D = 0;
    bool rand_value;
    for(short i = 1; i <= M; i++)
    {
        D = 0;
        DataPoint new_point = DataPoint(N, i, 0);
        for(short j = 0; j < N; j++)
        {
            rand_value = static_cast<bool>(rand() % 2);
            if(rand_value)
            {
                D++;
            }
            else
            {
                D--;
            }
        }
        new_point.set_d(D);
        new_point.print();
    }
}

int main(void)
{
    short N, M;

    srand(static_cast<unsigned>(time(nullptr)));

    particle_walk(5, 10);
    particle_walk(10, 10);
    particle_walk(20, 10);
    particle_walk(50, 10);
    particle_walk(100, 10);

    return 0;
}