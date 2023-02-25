// Console Alram Clock

#include <iostream>
#include <cctype>
#include <unistd.h>
#include <windows.h>
using namespace std;


class clock{
    int hr,min,sec;     
    char time_status[3];
    int a_hr,a_min;      
    char a_timestatus[3];

    public:
    void set_clock(){

        cout<<"\nEnter Hr:Min:Sec hands (set in 12 hrs formate)\n";
        cout<<"\t hr hand: "; cin>>hr;
        cout<<"\t min hand: "; cin>>min;
        cout<<"\t sec hand: "; cin>>sec;
        cout<<"\t Time Status (AM/PM): ";  cin>>time_status;
        time_status[0]=toupper(time_status[0]);
        time_status[1]=toupper(time_status[1]);
      
        system("cls");
        char choise;
        cout<<"Hay, want to set Alram(y/n): ";  cin>>choise;
        system("cls");
        if(choise=='Y'|| choise=='y'){
            cout<<"Great!\n";
            cout<<"Enter hr hand: "; cin>>a_hr;
            cout<<"Enter min hand: "; cin>>a_min;
            cout<<"Enter Time status (AM/PM): ";  cin>>a_timestatus;
            a_timestatus[0]=toupper(a_timestatus[0]);
            a_timestatus[1]=toupper(a_timestatus[1]);
    

            system("cls"); 

       
        }  

        display_clock();
    }

    void display_clock();
};


    void clock::display_clock(){
        while(1){
            system("cls");
            cout<<"\t\t\t----------- Time ----------\n";
            cout<<"\t\t\t\t  "<<hr<<":"<<min<<":"<<sec<<" "<<time_status<<"\n"; 
            cout<<"\t\t\t--------------------------\n";
            sec++;
            sleep(1);
            
            if(sec==60){
                sec=0;
                min++;
            }
            
            if(min==60){
                min=0;
                hr++;

            }

            if(hr==12 && min==0 && sec==0){
                if(!strncmp(time_status,"AM",1) || !strncmp(time_status,"am",1) ){
                    time_status[0]= 'P' ;
                    time_status[1]= 'M' ;
                  
                }

                else{
                    time_status[0]= 'A' ;
                    time_status[1]= 'M' ;
                }

            if(hr==13){
                hr=1;
     
            }

   }

            if(a_hr==hr && a_min==min && (!strncmp(a_timestatus,time_status,1))){  
                cout<<"Alram Alram !\n";  
                  Beep(230,1000); 
                  sec++;    
                  char alert;
                  cout<<"Enter any key to stop alram: ";
                       

            }      
        }
        display_clock();
    }

int main(){
    clock c;
    c.set_clock();

    return 0;
}
