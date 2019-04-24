#include <iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
using namespace std;
class contact
{   public:
    char name[60];
    int mob1[10];
    int mob2[10];
    char email[100];
    char note[500];
};
    char w;
    int i;
    fstream fin;
void new_rec()
{
    contact c;
    cout<<"Enter the Name:"<<endl;
    cin>>c.name;
    cout<<"Enter the Mobile No:"<<endl;
    fin.open("pro.dat",ios::app);
    for(i=0;i<10;i++)
    {
        cin>>c.mob1[i];
    }
    cout<<"do you want to enter another mobile no?"<<endl;
    cin>>w;
    if (w=='y')
    {
        cout<<"enter another mobile number"<<endl;
        for(i=0;i<10;i++)
            cin>>c.mob2[i];
    }
    else
    {
        for(i=0;i<10;i++)
        {
            c.mob2[i]=0;
        }
    }
    cout<<"Do you want to enter email?";
    cin>>w;

    if (w=='y')
    {
        cout<<"Enter email"<<endl;
        cin>>c.email;
    }
    else
    {

        strcpy(c.email,"not specified");
    }
    cout<<"Do you want to enter a note?";
    cin>>w;
    if(w=='y')
    {
        cout<<"Enter the note"<<endl;
        cin>>c.note;
    }
    fin.write((char*)&c, sizeof(c));
    fin.close();
}
void display_rec()
{
   contact c;
   fin.open("pro.dat",ios::in|ios::binary);
   cout<<"Records"<<endl;
   fin.read((char*)&c, sizeof(c));
   while(!fin.eof())
   {
   cout<<c.name<<endl;
   for(i=0;i<10;i++)
   cout<<c.mob1[i];
   cout<<endl;
   for(i=0;i<10;i++)
   cout<<c.mob2[i];
   cout<<endl;
   cout<<c.email<<endl;
   cout<<c.note<<endl;
   fin.read((char*)&c, sizeof(c));
   }
   fin.close();
}
int main()

{
    int choice;
    char m='y';

while(m=='y')
{   cout <<endl << "ADDRESS BOOK" << endl;
    cout<<" 1. Add a new record" <<endl;
    cout<<" 2. Display the existing records" << endl;
    cout<<" 3. Modify an existing record" << endl;
    cout<<" 4. Search a specific record"<<endl;
    cout<<" 5. Exit" <<endl;
    cout<<"Enter your choice "<<endl;
    cin>>choice;
    if(choice==1)
    {
      new_rec();
    }
    else if(choice==2)
    {
      display_rec();
    }
    cout<<"Do you want to perform more operations?"<<endl;
    cin>>m;
    }

        return 0;
}
