#include<iostream>
using namespace std;
class Fraction
{
    private:
    int numerator;
    int denominator;
    public:
    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;

    }
    void simplify()
    {
        int gcd=1;
        int j=min(this->numerator,this->denominator);
        for(int i=1;i<=j;i++)
        {
            if(numerator%i==0 && denominator%i==0)
            {
                gcd=i;
            }
        }
        this->numerator=numerator/gcd;
        this->denominator=denominator/gcd;
    }
    void add(Fraction f2)
    {
        int lcm=this->denominator*f2.denominator;
        int numerator=(f2.denominator*this->numerator)+(this->denominator*f2.numerator);
        denominator=lcm;
        simplify();

    }
    void multiply(Fraction const &f2)
    {
        numerator=(this->numerator*f2.numerator);
        denominator=(this->denominator*f2.denominator);
        simplify();


    }
    

};
int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();
    cout<<endl;
    f1.add(f2);
    f1.print();
    cout<<endl;
    f1.multiply(f2);
    f1.print();
    f2.print();

}

