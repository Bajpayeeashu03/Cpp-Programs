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

class Book {
private:
    int nop;
    Publication obj_pub;
    Sales obj_sales;
public:
    Book(string t="hello",double p=0,int a=0,int c=0,int e=0):obj_pub(t,p),obj_sales(a,c),nop(e){};
    void inputbook()
    {
        obj_pub.inputpub();
        obj_sales.inputsales();
        cout << "Enter number of pages: ";
         cin >> nop;
    }
    void getbook() {
        cout << "Title : " <<   obj_pub.gettitle() << endl;
        cout << "Price : " <<   obj_pub.getprice() << endl;
        cout << "Printed Copies : " <<  obj_sales.getprinted() << endl;
        cout << "Sold Copies : " <<  obj_sales.getsold() << endl;
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