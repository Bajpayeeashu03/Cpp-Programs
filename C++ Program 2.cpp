#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    double price;
public:
     Publication(string t="hello",double p=0):title(t),price(p){};
     void inputpub()
     {
        cout << "Enter Book title: ";
        cin >> title;
        cout << "Enter Book price: ";
        cin >> price;
     }
    string gettitle() 
    {
        return title;
    }
    double getprice() 
    {
        return price;
    }
};

class Sales {
protected:
    int cop;
    int cos;
public:
    Sales(int a=0,int c=0):cop(a),cos(c){};  
    void inputsales()
    {
        cout << "Enter number of printed copies: ";
        cin >> cop;
        cout << "Enter number of sold copies: ";
        cin >> cos;
    }
    int getprinted() {
        return cop;
    }
    int getsold()  {
        return cos;
    }
};

class Book : public Publication, public Sales {
private:
    int nop;
public:
    Book(string t="hello",double p=0,int a=0,int c=0,int e=0):Publication(t,p),Sales(a,c),nop(e){};
    void inputbook()
    {
        Publication::inputpub();
        Sales::inputsales();
        cout << "Enter number of pages: ";
         cin >> nop;
    }
    void getbook() {
        cout << "Title : " << Publication::gettitle() << endl;
        cout << "Price : " << Publication::getprice() << endl;
        cout << "Printed Copies : " << Sales::getprinted() << endl;
        cout << "Sold Copies : " << Sales::getsold() << endl;
        cout << "Number of Pages Are : " << nop << endl;
    }
};

int main() 
{
    Book obj1;
    obj1.inputbook();
    obj1.getbook();
    return 0;
}