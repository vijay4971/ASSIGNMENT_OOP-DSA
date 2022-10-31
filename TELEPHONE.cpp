//not completed yet
#include <bits/stdc++.h>

using namespace std;

class hash_table
{
    private:
        struct telephone
        {
            long int no;
            string name;
            string company;
        }tel[10];

    long int hash_fun(long int);
    public: 
        void hash()
        {
            for(int i=0;i<10;i++)
            {
            tel[i].no=-1;
            tel[i].name="_______";
            tel[i].company="_______";
            }
        }
        
        void insert_data();
        void display();
        void collision(long int,long int,string,string);
        void search();
        void del();
        
};
    long int hash_table::hash_fun(long int no)
    {
        return (no % 10);
    }
    void hash_table::insert_data()
    {
     long int telno;
     string n;
     string com;
     long int key;
     
     cout<<"Eneter your telephone number : ";
     cin>>telno;
     
     cout<<"Enter your name :";
     cin>>n;
     
     cout<<"Enter the name of your service provider : ";
     cin>>com;
     
     key = hash_fun(telno);
     
     if(tel[key].no == 0)
     {
        tel[key].no=telno;
        tel[key].name=n;
        tel[key].company=com;
     }
     else
     {
        collision(key,telno,n,com);
     }
    }
    void hash_table::search()
    {
        long int n;
        cout<<"Enter the number to be serached : ";
        cin>>n;
        
        long int k = hash_fun(n);
        
        for(int i=k;i!=k-1;i++)
        {
            if(tel[k].no==n)
            {
                cout<<setw(10)<<tel[k].no;
                cout<<setw(10)<<tel[k].name;
                cout<<setw(10)<<tel[k].company;
                break;
                
            }
            else
            {
                k=(k+1)%10;  
            }
        }
    }
    
    void hash_table::collision(long int hkey,long int sum,string n,string com)
    {
        cout<<"\n\nColission!!!!"<<endl;
        
        for(int i=hkey;i!= (hkey-1);i++)
        {
            if(i==9)
            i=0;
            
            if(tel[i].no==0)
            {
                tel[i].no=sum;
                tel[i].name=n;
                tel[i].company=com;
                break;
            }
        }
    }
    void hash_table::display()
    {
        cout<<endl<<setw(10)<<"Sr.no"<<setw(20)<<"Telephone"<<setw(20)<<"Name"<<setw(20)<<"Company"<<endl;
        
        for(int i=0;i<10;i++)
        {
            cout<<setw(10)<<i<<setw(20);
            cout<<setw(20)<<tel[i].no<<setw(10);
            cout<<setw(20)<<tel[i].name<<setw(10);
            cout<<setw(20)<<tel[i].company<<endl;
        }
    }
    void hash_table::del()
    {
        long int n;
        cout<<"Enter number to be deleted : ";
        cin>>n;
        
        long int k=hash_fun(n);
        
        for(int i=k;i=(k-1);i++)
        {
            if(tel[k].no==n)
            {
                break;
            }
            else 
            {
                k=(k+1)%10;
            }
        }
        tel[k].no=0;
        tel[k].name="-----------";
        tel[k].company="-------------";
    }
int main()
{
    hash_table H;
    int ch;
    cout<<"\n\n************TLEPHONE DIRECTORY***********************"<<endl;
    do
    {
       cout<<"\n1.Insert record"<<endl;
       cout<<"\n2.Displayt hash table"<<endl;
       cout<<"\n3.Search record"<<endl;
       cout<<"\n4.Deletye record"<<endl;
       cout<<"\n5.Exit"<<endl;
       cout<<"Enter your choice :";
       cin>>ch;
       switch(ch)
       {
           case 1:
                H.insert_data();
                break;
            case 2:
                H.display();
                break;
            case 3:
                H.search();
                break;
            case 4:
                H.del();
                break;
            case 5:
                break;
       }
    }while(ch!=5);

    return 0;
}

