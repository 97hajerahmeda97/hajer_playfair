#include <iostream>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;
void array_of_letter(char key1[], char array1[][5],int &l);
void row_col(char array1[][5],char char1,char char2,int &r1,int &c1,int &r2,int &c2);
void search_char(char array1[][5],char &charr1,char &charr2,int x1,int y1,int x2,int y2);
void encryption(int ll,char tex[],char text1[],char array1[][5] );
void decrption(int ll,char tex[],char text1[],char array1[][5] );
void print_array(char array1[][5]);
void plain_text(char text1[],int &ll);
int main()
{int l=0,ll=0,chose,t=0;
    char key1[100], array1[5][5],text[100],text1[100],tex[100];
    cout<<"            please enter a message and keyword in capital letters "<<endl;
   cout<<"enter massage: ";
    cin.getline(text,99);
     t=strlen(text);
    for(int i=0;i<t;i++)
{
   if(isalpha(text[i]))

   {
       text1[ll]=text[i];
       ll++;
   }

}

array_of_letter(key1,array1,l);

    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"array of letter:"<<endl;
    print_array(array1);
    cout<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
cout<<"TO encrypt text click 1"<<endl;
cout<<"TO decrypt the text click 2"<<endl;
cout<<"enter chose:";
cin>>chose;

if(chose==1 ||chose==2)
{
    switch(chose)
    {
    case 1:
        plain_text( text1,ll);
        encryption(ll,tex,text1,array1 );
        if(ll%2!=0)
        {
            ll++;
        }
       cout<<"encryption text:";
       for(int i=0;i<ll;i++)
       {

        cout<<tex[i];
        }break;

        case 2:
            decrption(ll,tex,text1,array1 );
        cout<<"decrption text:" ;
        for(int i=0;i<ll;i++)
       {

        cout<<tex[i];
        }
         break;
    }
}

    cout<<endl;

    return 0;
}
void plain_text(char text1[],int &ll)
{
   char c;

for(int i=0;i<ll;i++)
{
   if(text1[i]==text1[i+1])
   {
       c=text1[i+1];
       text1[i+1]='X';
       for(int j=ll;j>i+2;j--)
       {
           text1[j]=text1[j-1];

       }
       text1[i+2]=c;
ll=ll+1;
   }
   i++;
}
if(ll%2!=0)
{
for(int i=0;i<=ll;i++)

{if(i==ll)
   {


text1[i]='X';
}}

}

}

void print_array(char array1[][5])
{
    for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
    {if(array1[i][j]=='I')
    {
        cout<<"I/J"<<" ";
    }
    else{
        cout<<array1[i][j]<<"   ";}
    }
    cout<<endl;

}

}




void array_of_letter(char key1[], char array1[][5],int &l)
{char key[100] ;
char letter[]="ABCDEFGHIKLMNOPQRSTUVWXYZ";
int z=0,y=0;
    for(int i=0;i<100;i++)
    {
        key[i]=32;
        key1[i]=32;
    }
    cout<<"enter key word:";
    cin.getline(key,99);
    z=strlen(key);
    for(int i=0;i<z;i++)
    {
        if(key[i]=='J')
        {
            key[i]='I';
        }
    }
    for(int i=0;i<z-1;i++)
 {
     for(int j=i+1;j<z;j++)
     {
         if(key[i]==key[j])
         {

          key[j]=32;}
     }
 }

  for(int i=0;i<z;i++)
{
   if(key[i]!=32)

   {
       key1[l]=key[i];
       l++;
   }

}

int m=0;
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
       {
          if(m<l)
          {
            array1[i][j]=key1[m];

            m++;
           }
           else{
        for(int k=0;k<l;k++)
      {
          if(letter[y]==key1[k])
        {
            y=y+1;
            k=-1;

        }


      }
           array1[i][j]=letter[y];
     y++;
     }

}}}

void encryption(int ll,char tex[],char text1[],char array1[][5] )
{
    char char1,char2,charr1,charr2;
    int r1,c1,r2,c2,t;
    for(int i=0;i<ll;i++)
    {
        char1=text1[i];
        char2=text1[i+1];
        row_col(array1,char1,char2,r1,c1,r2,c2);

        if(c1==c2)
        {
            r1=r1+1;
            r2=r2+1;
            if(r2==5)
            {
                r2=0;
            }
            if(r1==5)
            {
                r1=0;
            }
            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }

         if(r1==r2)
        {
            c1=c1+1;
            c2=c2+1;
            if(c2==5)
            {
                c2=0;
            }
            if(c1==5)
            {
                c1=0;
            }
            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }
         else
        {t=c1;
            c1=c2;
            c2=t;

            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }
i++;
    }

}
void decrption(int ll,char tex[],char text1[],char array1[][5] )
{


    char char1,char2,charr1,charr2;
    int r1,c1,r2,c2,t;
    for(int i=0;i<ll;i++)
    {
        char1=text1[i];
        char2=text1[i+1];
        row_col(array1,char1,char2,r1,c1,r2,c2);
        if(c1==c2)
        {
            r1=r1-1;
            r2=r2-1;
            if(r2==-1)
            {
                r2=4;
            }
            if(r1==-1)
            {
                r1=4;
            }
            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }

         if(r1==r2)
        {
            c1=c1-1;
            c2=c2-1;
            if(c2==-1)
            {
                c2=4;
            }
            if(c1==-1)
            {
                c1=4;
            }
            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }
         else
        {t=c1;
            c1=c2;
            c2=t;

            search_char(array1,charr1,charr2,r1,c1,r2,c2);
            tex[i]=charr1;
            tex[i+1]=charr2;
        }
i++;
    }

}
void row_col(char array1[][5],char char1,char char2,int &r1,int &c1,int &r2,int &c2)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(array1[i][j]==char1)
            {
                r1=i;
                c1=j;
            }
             if(array1[i][j]==char2)
            {
                r2=i;
                c2=j;
            }
        }
    }
}
void search_char(char array1[][5],char &charr1,char &charr2,int x1,int y1,int x2,int y2)
{ for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==x1 && j==y1)
            {
               charr1=array1[i][j];
            }
             if(i==x2 && j==y2)
            {
                charr2=array1[i][j];
            }
        }
    }

}
