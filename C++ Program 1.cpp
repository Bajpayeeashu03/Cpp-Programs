#include <iostream>
#include<cstdarg>
#include<vector>
#include<algorithm>
using namespace std;
int calculate(int n,...) 
{
    va_list a;
    va_start(a,n);
    vector<int>v;
    int i,y;
    for (i = 0; i < n; i++) 
    {
       y=va_arg(a,int);
       v.push_back(y); 
    }
    sort(v.begin(),v.end(),greater<int>());
    int ts=0;
    for (int i = 0; i < 3 && i < n; i++)
    {
        ts += v[i];
    }
    return ts;
}

int main() 
{
    int n;
    cout << "Enter the number of questions (min 3, max 5): ";
    cin >> n;
    if (n < 3 || n > 5) 
    {
        cout << "Number of questions must be between 3 and 5." << endl;
        return 1;
    }
    int score[n],m;
    for (int i = 0; i < n; i++) 
    {
        cout << "Enter score for question " << i + 1 << " (max 15): ";
        cin >> score[i];
        if (score[i] > 15) {
            cout << "Score cannot be more than 15." << endl;
            return 1;
        }
    }
    if(n==3)
    {
        m=calculate(n,score[0],score[1],score[2]);
    }
    else if(n==4)
    {
        m=calculate(n,score[0],score[1],score[2],score[3]);
    }
    else
    {
        m=calculate(n,score[0],score[1],score[2],score[3],score[4]);
    }
    cout<<"Best Of 3 Score Is:-"<<m<<endl;
    return 0;
}