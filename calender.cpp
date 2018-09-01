#include<bits/stdc++.h>
using namespace std;

int leap_year(int year)
{
    int retu=0;
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                retu=1;
        }
        else
            retu=1;
    }
    return retu;
}


class year_month
{
    public:
        int yer,leap,NOD[12],mon_cod,rem,last_digit,total,yer_cod,fin_rem,day,diff,in_da_diff,in_date,ret=0,if_or_set;
    char month[12][12],days[7][10],mon[10],original[12];

    void set_month()
    {
       strcpy(month[0],"january");
       strcpy(month[1],"february");
       strcpy(month[2],"march");
       strcpy(month[3],"april");
       strcpy(month[4],"may");
       strcpy(month[5],"june");
       strcpy(month[6],"july");
       strcpy(month[7],"auguest");
       strcpy(month[8],"september");
       strcpy(month[9],"october");
       strcpy(month[10],"november");
       strcpy(month[11],"december");
    }

void year_code()
{
    if(yer>=2900&&yer<3000)
        yer_cod=4;
    else if(yer>=2800&&yer<2900)
        yer_cod=6;
    else if(yer>=2700&&yer<2800)
        yer_cod=0;
    else if(yer>=2600&&yer<2700)
        yer_cod=2;
    else if(yer>=2500&&yer<2600)
        yer_cod=4;
    else if(yer>=2400&&yer<2500)
        yer_cod=6;
    else if(yer>=2300&&yer<2400)
        yer_cod=0;
    else if(yer>=2200&&yer<2300)
        yer_cod=2;
    else if(yer>=2100&&yer<2200)
        yer_cod=4;
    else if(yer>=2000&&yer<2100)
        yer_cod=6;
    else if(yer>=1900&&yer<2000)
        yer_cod=0;
    else if(yer>=1800&&yer<1900)
        yer_cod=2;
    else if(yer>=1700&&yer<1800)
        yer_cod=4;
    else if(yer>=1600&&yer<1700)
        yer_cod=6;
}

void set_NOD()
    {
        int t;
        leap=leap_year(yer);
        if(leap)
            t=29;
        else
            t=28;
        NOD[0]=31; NOD[1]=t; NOD[2]=31; NOD[3]=30; NOD[4]=31; NOD[5]=30;
        NOD[6]=31; NOD[7]=31; NOD[8]=30; NOD[9]=31; NOD[10]=30; NOD[11]=31;
    }

void compare(char *mon)
    {
        int flag=0;
        for(int i=0;i<12;i++)
        {
            /// cout<<" month "<<mon<<" i "<<i<<endl;
            ret=strcmp(month[i],mon);
            if(!ret)
            {
                ret=i+1;
                flag=1;
                break;
            }
        }
        if(!flag)
            ret=0;
    }

void month_code()
    {
        switch(ret)
            {
                case 1: {mon_cod=0;break;}
                case 2: {mon_cod=3;break;}
                case 3: {mon_cod=3;break;}
                case 4: {mon_cod=6;break;}
                case 5: {mon_cod=1;break;}
                case 6: {mon_cod=4;break;}
                case 7: {mon_cod=6;break;}
                case 8: {mon_cod=2;break;}
                case 9: {mon_cod=5;break;}
                case 10: {mon_cod=0;break;}
                case 11: {mon_cod=3;break;}
                case 12: {mon_cod=5;break;}
            }
    }

 void calculate()
 {
     last_digit=yer%100;
     rem=last_digit/4;
     if(ret==1&&leap || ret== 2&&leap)
        total=last_digit+rem+mon_cod+yer_cod;
     else
        total=last_digit+rem+1+mon_cod+yer_cod;
     /// cout<<" total "<<total<<endl;
     fin_rem=total%7;
 }

void print_month()
    {
        day=NOD[ret-1];
        //cout<<"NOD[ret-1] "<<day<<endl;
        system("CLS");

        cout<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                             "<<original<<" "<<yer<<endl;
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Sun             Mon             Tue             Wed             Thu             Fri             Sat"<<endl<<endl;
        for(int i=0;i<fin_rem;i++)
        {
                cout<<"\t\t";

        }
        int tot_days=day+fin_rem;
        for(int i=fin_rem+1;i<=tot_days;i++)
        {
            cout<<i-fin_rem<<"\t\t";
            if(i%7==0)
            cout<<endl;
        }
        cout<<endl<<endl;
    }

};
int main()
{
    int year,mov,flag=0;
    char month[10],mon1[10],yr[4];
    year_month m;
    m.set_month();
       cout<<"enter either month number or month name -> ";
  while(1)
   {
    cin>>month;
    strcpy(m.original,month);
    strlwr(month);
    m.compare(month);
    if(!m.ret)
    {
        sscanf(month,"%d",&mov);
        if(mov>0 &&mov <13)
        {
            m.ret=mov;
            strcpy(m.original,m.month[mov-1]);
            break;
        }
        else
            cout<<"you enter wrong month "<<endl<<"please renter either month number or month name -> ";
    }
    else
        break;
   }
cout<<"enter year between 1600 and 2999 -> ";
while(1)
  {
    cin>>yr;
    sscanf(yr,"%d",&year);
    if(year>=1600 && year<3000)
      {
       m.yer=year;
       break;
      }
    else
    {
        cout<<"you enter wrong year "<<endl<<"please enter year between 1600 and 2999 -> ";
    }
  }

    m.set_NOD();
    ///m.compare();             /// compare which month entered by user (set ret)
    m.month_code();          /// defines the code for month          (set mon_cod using ret)
    m.year_code();           /// defines the year                    (set yer_cod using yer)
    m.calculate();           /// perform calculation
    m.print_month();         /// print the month
}
