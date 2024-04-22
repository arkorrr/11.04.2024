#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 4

class Fraction 
{
    int numerator;
    int denominator;
public:
    Fraction() 
    {

    }
    Fraction(int x, int y) 
    {
        numerator = x;
        denominator = y;
    }
    void Sum(Fraction sum) 
    {

        cout << "First drob: ";
        cout << numerator + sum.numerator << endl;

        cout << "Second drob: ";
        cout << denominator + sum.denominator << endl;
    }
    void SumOfTwoDorbs(Fraction sum) 
    {

        cout << "Summ of 2 drobs: ";
        cout << numerator * sum.denominator + sum.numerator * denominator << endl; //исправлено
        cout << "/: " << denominator * sum.denominator << endl;
    }
    void Minus(Fraction minus) 
    {

        cout << "Minus first drob: ";
        cout << numerator - minus.numerator << endl;

        cout << "Minus second drob: ";
        cout << denominator - minus.denominator << endl;
    }
    void MinusOfTwoDrobs(Fraction minus) 
    {

        cout << "Minus of 2 drobs: ";
        cout << numerator * minus.denominator - minus.numerator * denominator << endl; //исправлено
        cout << "/: " << denominator * minus.denominator << endl;
    }
    void multiplication(Fraction mult) 
    {

        cout << "multiplication first drob: ";
        cout << numerator * mult.numerator << endl;
        cout << "multiplication second drob: ";
        cout << denominator * mult.denominator << endl;

    }

    void delen(Fraction del) 
    {
        if (del.numerator == 0) 
        {
            cout << "Imossible if chesl = 0 " << endl;
            return;
        }
        cout << "first drob " << numerator * del.denominator << endl;
        cout << "Second drob " << denominator * del.numerator << endl;
    }
};
int main()
{
    //Task1
    Fraction arr[SIZE] = { Fraction(5, 1) , Fraction(4 , 3) , Fraction(9, 2), Fraction(4, 4) };
    ofstream file("binarefile.txt", ios::binary);
    for (int i = 0; i < SIZE; i++) 
    {
        file.write((char*)arr, sizeof(Fraction));
    }
    file.close();
    Fraction arr2[SIZE];
    ifstream fil("binarefile.txt", ios::binary);
    for (int i = 0; i < SIZE; i++) {
        fil.read((char*)&arr2[i], sizeof(Fraction));
    }
    fil.close();
    file.close();

    //Task2
    Fraction arr3[SIZE] = { Fraction(5, 1) , Fraction(4 , 3) , Fraction(9, 2), Fraction(4, 4) };
    ofstream filee("binare.txt", ios::binary);
    for (int i = 0; i < SIZE; i++) 
    {
        file.write((char*)arr, sizeof(Fraction));
    }
    file.close();
    ifstream fi("binare.txt", ios::binary);
    fi.seekg(0, ios::end);
    fi.seekg(-2 * 16, ios::end);
    Fraction drob;
    fi.read((char*)&drob, sizeof(Fraction));
    fi.close();
}
