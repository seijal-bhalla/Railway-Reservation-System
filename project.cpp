#include<string.h> 
#include<fstream> 
#include<iomanip> 
#include <cstdlib> 
#include<ctime> 
#include<conio.h> 
using namespace std; 
class Train 
{ 
private: 
 int trainid; 
 char trainame[20]; 
 char timing[10]; 
 char duration[20]; 
 char depart[20]; 
 char arrive[20]; 
public: 
 Train() 
 { 
 trainid=0; 
 strncpy(trainame,"no name",20); 
 } 
 int traincheck(int); 
 void gettraindata() 
 { 
 int y; 
 cout<<"\n\n"<<setw(40)<<"INSERTING TRAIN DATA"; 
 cout<<"\n\nEnter Train ID: ";cin>>trainid; 
 y=traincheck(trainid); 
 if(y==0) 
 { 
 cout<<"\n\nThis is an addition of new record"; 
 getch(); 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"INSERTING TRAIN DATA"; 
 cout<<"\n\nEnter Train ID again to confirm: ";cin>>trainid; 
 cout<<"\nEnter Train Name: ";cin>>trainame; 
 cout<<"\nEnter Departing Location: ";cin>>depart; 
 cout<<"\nEnter Arrival Location: ";cin>>arrive; 
 cout<<"\nEnter Timings of Departure: ";cin>>timing; 
 cout<<"\nEnter Journey Time Duration: ";cin>>duration; 
 } 
 else if(y==1) 
 { 
 cout<<"\n\n THIS TRAIN ID ALREADY EXISTS "; 
 getch(); 
 system("cls"); 
 gettraindata(); 
 } 
 } 
 void distraindata() 
 { 
 cout<<" 
"<<trainid<<setw(20)<<trainame<<setw(25)<<depart<<setw(25)<<arrive<<setw(
20)<<timing<<setw(25)<<duration<<endl; 
 } 
 void storetraindata(); 
 void viewtraindata(); 
 void searchtraindata(char *); 
 void searchtraindata1(char *); 
 void searchtraindata2(int); 
 void deletetraindata(char *); 
 void updatetraindata(char *); 
 void trainschedule(); 
}; 
int Train::traincheck(int t) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(t==trainid) 
 { 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==1) 
 { 
 return 1; 
 } 
 else if(flag==0) 
 { 
 return 0; 
 } 
 fin.close(); 
} 
void Train::storetraindata() 
{ 
 ofstream fout; 
 if(trainid==0) 
 { 
 cout<<"\nTrain Schedule not initialized"; 
 } 
 fout.open("Train.dat",ios::app|ios::binary); 
 if(!fout) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout.write((char*)this,sizeof(*this)); 
 fout.close(); 
} 
void Train::viewtraindata() 
{ 
 cout<<"\n\n"<<setw(55)<<"TRAIN SCHEDULE"; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 cout<<"\n\n"<<"Train ID"<<setw(20)<<"Train Name"<<setw(25)<<"Departure 
Location"<<setw(25)<<"Arrival Location"<<setw(25)<<"Timings of 
Departure"<<setw(18)<<"Duration"<<endl; 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 distraindata(); 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
} 
void Train::searchtraindata(char *t) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(!strcmp(t,trainame)) 
 { 
 cout<<"\n\n"<<"Train ID"<<setw(20)<<"Train 
Name"<<setw(25)<<"Departure Location"<<setw(25)<<"Arrival 
Location"<<setw(25)<<"Timings of Departure"<<setw(18)<<"Duration"<<endl; 
 distraindata(); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 fin.close(); 
} 
void Train::searchtraindata1(char *t1) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(!strcmp(t1,trainame)) 
 { 
 cout<<"\n\n"<<"Train ID"<<setw(20)<<"Train 
Name"<<setw(25)<<"Departure Location"<<setw(25)<<"Arrival 
Location"<<setw(25)<<"Timings of Departure"<<setw(18)<<"Duration"<<endl; 
 distraindata(); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 else 
 { 
 deletetraindata(t1); 
 } 
} 
void Train::searchtraindata2(int t) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(t==trainid) 
 { 
 cout<<"\n\n"<<"Train ID"<<setw(20)<<"Train 
Name"<<setw(25)<<"Departure Location"<<setw(25)<<"Arrival 
Location"<<setw(25)<<"Timings of Departure"<<setw(18)<<"Duration"<<endl; 
 distraindata(); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 fin.close(); 
} 
void Train::deletetraindata(char *t) 
{ 
 int flag=0; 
 ofstream fout; 
 ifstream fin; 
 fin.open("Train.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout.open("Temp1.dat",ios::out|ios::binary); 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(strcmp(trainame,t)) 
 { 
 fout.write((char*)this,sizeof(*this)); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 fout.close(); 
 remove("Train.dat"); 
 rename("Temp1.dat","Train.dat"); 
 cout<<"\n\nRECORD DELTED.........."; 
} 
void Train::updatetraindata(char *t) 
{ 
 int flag=0; 
 fstream file; 
 file.open("Train.dat",ios::in|ios::out|ios::ate|ios::binary); 
 file.seekg(0); 
 file.read((char *)this,sizeof(*this)); 
 while(!file.eof()) 
 { 
 if(!strcmp(t,trainame)) 
 { 
 getch(); 
 system("cls"); 
 cout<<"\n\n"<<setw(35)<<"UPDATING TRAIN RECORD"; 
 cout<<"\n\nEnter Train ID: ";cin>>trainid; 
 cout<<"\nEnter Train Name: ";cin>>trainame; 
 cout<<"\nEnter Departing Location: ";cin>>depart; 
 cout<<"\nEnter Arrival Location: ";cin>>arrive; 
 cout<<"\nEnter Timings of Departure: ";cin>>timing; 
 cout<<"\nEnter Journey Time Duration: ";cin>>duration; 
 file.seekp(file.tellp()-sizeof(*this)); 
 file.write((char*)this,sizeof(*this)); 
 flag=1; 
 } 
 file.read((char *)this,sizeof(*this)); 
 } 
 file.close(); 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 else if(flag==1) 
 { 
 cout<<"\n\nRECORD UPDATED......."; 
 } 
} 
void Train::trainschedule() 
{ 
 char name[20]; 
 int x; 
 Train t1; 
 do 
 { 
 system("cls"); 
 cout<<"\n\n"<<setw(30)<<"TRAIN SCHEDULE"<<endl; 
 cout<<"\n\n1.Insert."; 
 cout<<"\n\n2.Display Schedule."; 
 cout<<"\n\n3.Search."; 
 cout<<"\n\n4.Delete"; 
 cout<<"\n\n5.Update."; 
 cout<<"\n\n6.Exit"; 
 cout<<"\n\nEnter your choice: "; 
 cin>>x; 
 switch(x) 
 { 
 case 1: 
 system("cls"); 
 t1.gettraindata(); 
 cout<<"\n\n"<<"Train ID"<<setw(20)<<"Train 
Name"<<setw(25)<<"Departure Location"<<setw(25)<<"Arrival 
Location"<<setw(25)<<"Timings of Departure"<<setw(18)<<"Duration"<<endl; 
 t1.storetraindata(); 
 t1.distraindata(); 
 cout<<"\n\nIt Will be Displayed to the passengers....."<<endl; 
 getch(); 
 break; 
 case 2: 
 system("cls"); 
 cout<<"\n\n"<<setw(60)<<"DISPLAYING TRAIN SCHEDULE"; 
 cout<<"\n\n"; 
 t1.viewtraindata(); 
 getch(); 
 break; 
 case 3: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"SEARCHING FOR A TRAIN"; 
 cout<<"\n\nEnter Train Name to search: "; 
 cin>>name; 
 t1.searchtraindata(name); 
 getch(); 
 break; 
 case 4: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"DELETION FROM A TRAIN SCHEDULE"; 
 cout<<"\n\nEnter Train name to Delete: "; 
 cin>>name; 
 t1.searchtraindata1(name); 
 getch(); 
 break; 
 case 5: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"UPDATION IN A TRAIN SCHEDULE"; 
 cout<<"\n\nEnter Train name to update: "; 
 cin>>name; 
 t1.updatetraindata(name); 
 getch(); 
 break; 
 case 6: 
 cout<<"\n\nEXITING..........."<<endl; 
 getch(); 
 break; 
 default: 
 cout<<"\n\nWrong Option"<<endl; 
 getch(); 
 break; 
 } 
 }while(x!=6); 
} 
class Passenger: public Train 
{ 
private: 
 long int pasid; 
 char pasname[20]; 
 int trainid; 
 char trainseat; 
 char mob[12]; 
 char trainname[25]; 
 char from[20]; 
 char to[20]; 
 char date[15]; 
public: 
 Passenger() 
 { 
 pasid=0; 
 strncpy(pasname,"no name",20); 
 trainid=0; 
 } 
 int pascheck(long int); 
 void pasdetails(); 
 void getpasdata() 
 { 
 int y,z; 
 cout<<"\n\n"<<setw(40)<<"INSERTING PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger ID: ";cin>>pasid; 
 y=pascheck(pasid); 
 if(y==0) 
 { 
 cout<<"\n\nThere is an addition of new record"; 
 getch(); 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"INSERTING PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger ID again to confirm: ";cin>>pasid; 
 cout<<"\nEnter Name: ";cin.ignore();cin.getline(pasname,19); 
 cout<<"\nEnter Mobile Number: ";cin>>mob; 
 cout<<"\nEnter Train ID: ";cin>>trainid; 
 cout<<"\nEnter Train Reservation Status: ";cin>>trainseat; 
 z=traincheck(trainid); 
 if(z==1) 
 { 
 cout<<"\n\nNew Passenger Record Added..........."; 
 getch(); 
 system("cls"); 
 cout<<"\n\n THE RECORD ADDED IS"; 
 } 
 else if(z==0) 
 { 
 cout<<"\n\n This Train ID does not exist."; 
 cout<<"\n\n Try Next time."; 
 cout<<"\n\n ENTER VALID DETAILS"; 
 getch(); 
 system("cls"); 
 getpasdata(); 
 } 
 } 
 else if(y==1) 
 { 
 cout<<"\n\n THIS PASSENGER ID ALREADY EXISTS"; 
 getch(); 
 system("cls"); 
 getpasdata(); 
 } 
 } 
 void dispasdata() 
 { 
 cout<<" 
"<<pasid<<setw(20)<<pasname<<setw(25)<<mob<<setw(20)<<trainid<<setw(20)
<<trainseat<<endl; 
 } 
 void storepasdata(); 
 void viewpasdata(); 
 void searchpasdata(char *); 
 void searchpasdata1(char *); 
 void deletepasdata(char *); 
 void updatepasdata(char *); 
 int seatnum(int); 
 void getbooking(int); 
 void disbooking(); 
 void cancellation(long int); 
 void ticket(long int); 
 void booking(); 
}; 
int Passenger::pascheck(long int p) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\n\nFile not Found."; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(p==pasid) 
 { 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==1) 
 { 
 return 1; 
 } 
 else if(flag==0) 
 { 
 return 0; 
 } 
 fin.close(); 
} 
void Passenger::getbooking(int tr) //BOOKING 
{ 
 int z; 
 z=traincheck(tr); 
 if(z==1) 
 { 
 float Rs=450; 
 int y,n; 
 y = seatnum(trainid); 
 if (y>0) 
 { 
 cout<<"\n\nHow many tickets you want to book: ";cin>>n; 
 if(n<=y) 
 { 
 for(int i=1;i<=n;i++) 
 { 
 srand(time(0)); 
 pasid = rand(); 
 cout<<"\n\nPassenger ID Opted is: "<<pasid; 
 cout<<"\n\nEnter Passenger's name: ";cin>>pasname; 
 cout<<"\nEnter Contact Details: ";cin>>mob; 
 cout<<"\nEnter Train ID again to confirm: ";cin>>trainid; 
 trainseat='R'; 
 cout<<"\nTrain seat Status: "<<trainseat; 
 ofstream fout; 
 fout.open("Passenger.dat",ios::app|ios::binary); 
 fout.write((char*)this,sizeof(*this)); 
 fout.close(); 
 searchtraindata2(trainid); 
 cout<<"\n\nEnter the following details to confirm:- "; 
 cout<<"\n\nEnter Train name: ";cin>>trainname; 
 cout<<"\nDeparture Location: ";cin>>from; 
 cout<<"\nArrival Location: ";cin>>to; 
 cout<<"\nDate of the Journey: ";cin>>date; 
 ofstream fout1; 
 fout1.open("Ticket.dat",ios::app|ios::binary); 
 fout1.write((char*)this,sizeof(*this)); 
 fout1.close(); 
 cout<<"\n\nTicket Booked"<<endl; 
 } 
 Rs=Rs*n; 
 cout<<"\n\nTotal Amount to Pay: Rs."<<Rs; 
 } 
 else 
 { 
 cout<<"\n\nThis much seats are not available.Look for some other option."; 
 } 
 } 
 else if(y==0) 
 { 
 char userchoice; 
 cout<<"\n\nSeats not Available yet.Your names will be on the waiting list."; 
 cout<<"\nDo you want to continue ? (y/n): ";cin>>userchoice; 
 userchoice = tolower(userchoice); 
 if(userchoice=='y') 
 { 
 cout<<"\n\nHow many tickets you want to book: ";cin>>n; 
 for(int i=1;i<=n;i++) 
 { 
 srand(time(0)); 
 pasid = rand(); 
 cout<<"\n\nPassenger ID Opted is: "<<pasid; 
 cout<<"\n\nEnter Passenger's name: ";cin>>pasname; 
 cout<<"\nEnter Contact Details: ";cin>>mob; 
 cout<<"\nTrain ID: ";cin>>trainid; 
 trainseat='W'; 
 cout<<"\nTrain seat Status: "<<trainseat; 
 ofstream fout; 
 fout.open("Passenger.dat",ios::app|ios::binary); 
 fout.write((char*)this,sizeof(*this)); 
 fout.close(); 
 cout<<"\n\nEnter Train name: ";cin>>trainname; 
 cout<<"\nDeparture Location: ";cin>>from; 
 cout<<"\nArrival Location: ";cin>>to; 
 cout<<"\nDate of the Journey: ";cin>>date; 
 ofstream fout1; 
 fout1.open("Ticket.dat",ios::app|ios::binary); 
 if(!fout1) 
 { 
 cout<<"\n\nFile Not Found"; 
 } 
 fout1.write((char*)this,sizeof(*this)); 
 fout1.close(); 
 cout<<"\n\nTicket Booked"; 
 } 
 Rs=Rs*n; 
 cout<<"\n\nTotal Amount to Pay: Rs."<<Rs; 
 } 
 else if(userchoice=='n') 
 { 
 cout<<"\n\nTHANKS FOR VISITING !"; 
 } 
 } 
 } 
 else if(z==0) 
 { 
 cout<<"\n\nThis Train ID does not exist."; 
 getch(); 
 system("cls"); 
 booking(); 
 } 
} 
void Passenger::ticket(long int pi) //TICKET 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Ticket.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\n\nFile Not Found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(pi==pasid) 
 { 
 cout<<"\n\n"<<"Pas.ID"<<setw(10)<<"Pas.Name"<<setw(15)<<"Contact 
No."<<setw(10)<<"Train.ID"<<setw(10)<<"Status"<<setw(10)<<"T.Name"<<set
w(10)<<"From"<<setw(10)<<"To"<<setw(10)<<"Date"; 
 
cout<<"\n\n"<<pasid<<setw(10)<<pasname<<setw(15)<<mob<<setw(10)<<traini
d<<setw(10)<<trainseat<<setw(10)<<trainname<<setw(15)<<from<<setw(10)<<t
o<<setw(15)<<date; 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 fin.close(); 
} 
void Passenger::cancellation(long int pi) //CANCELLATION 
{ 
 int y; 
 y=pascheck(pi); 
 if(y==1) 
 { 
 ticket(pi); 
 long int account; 
 ofstream fout; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout.open("Temp.dat",ios::out|ios::binary); 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(!(pi==pasid)) 
 { 
 fout.write((char*)this,sizeof(*this)); 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 fout.close(); 
 remove("Passenger.dat"); 
 rename("Temp.dat","Passenger.dat"); 
 ofstream fout1; 
 ifstream fin1; 
 fin1.open("Ticket.dat",ios::in|ios::binary); 
 if(!fin1) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout1.open("Temp1.dat",ios::out|ios::binary); 
 fin1.read((char*)this,sizeof(*this)); 
 while(!fin1.eof()) 
 { 
 if(!(pi==pasid)) 
 { 
 fout1.write((char*)this,sizeof(*this)); 
 } 
 fin1.read((char*)this,sizeof(*this)); 
 } 
 fin1.close(); 
 fout1.close(); 
 remove("Ticket.dat"); 
 rename("Temp1.dat","Ticket.dat"); 
 cout<<"\n\n Ticket Cancelled"; 
 cout<<"\n\nYour Account Number: ";cin>>account; 
 cout<<"\n\nRs.225 will be refunded back within 5 working days to your Bank 
Account "<<account; 
 } 
 else if(y==0) 
 { 
 cout<<"\n\nThis Passenger ID does not exist."; 
 } 
} 
int Passenger::seatnum(int t) //BOOKING 
{ 
 int x; 
 int counter=0; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(t==trainid) 
 { 
 counter=counter+1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 x = 5-counter; 
 if(x>0) 
 { 
 cout<<"\n\nTotal number of seats Available: "<<x; 
 return x; 
 } 
 else if (x<0) 
 { 
 return 0; 
 } 
} 
void Passenger::storepasdata() 
{ 
 ofstream fout; 
 if(pasid==0 && trainid==0) 
 { 
 cout<<"\nPassenger data not initialized"; 
 } 
 fout.open("Passenger.dat",ios::app|ios::binary); 
 if(!fout) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout.write((char*)this,sizeof(*this)); 
 fout.close(); 
} 
void Passenger::viewpasdata() 
{ 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 cout<<"\nData of Passenger is......"; 
 cout<<"\n\n"<<"Passenger ID"<<setw(20)<<"Passenger 
Name"<<setw(21)<<"Contact Details"<<setw(20)<<"Train 
ID"<<setw(30)<<"Reservation Status"<<endl; 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 dispasdata(); 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
} 
void Passenger::searchpasdata(char *p) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(!strcmp(p,pasname)) 
 { 
 cout<<"\n\n"<<"Passenger ID"<<setw(20)<<"Passenger 
Name"<<setw(20)<<"Contact Details"<<setw(20)<<"Train 
ID"<<setw(30)<<"Reservation Status"<<endl; 
 dispasdata(); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 fin.close(); 
} 
void Passenger::searchpasdata1(char *p1) 
{ 
 int flag=0; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(!strcmp(p1,pasname)) 
 { 
 cout<<"\n\n"<<"Passenger ID"<<setw(20)<<"Passenger 
Name"<<setw(20)<<"Contact Details"<<setw(20)<<"Train 
ID"<<setw(30)<<"Reservation Status"<<endl; 
 dispasdata(); 
 flag=1; 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 else 
 { 
 deletepasdata(p1); 
 } 
} 
void Passenger::deletepasdata(char *p) 
{ 
 ofstream fout; 
 ifstream fin; 
 fin.open("Passenger.dat",ios::in|ios::binary); 
 if(!fin) 
 { 
 cout<<"\nFile not found"; 
 } 
 fout.open("Temp.dat",ios::out|ios::binary); 
 fin.read((char*)this,sizeof(*this)); 
 while(!fin.eof()) 
 { 
 if(strcmp(pasname,p)) 
 { 
 fout.write((char*)this,sizeof(*this)); 
 } 
 fin.read((char*)this,sizeof(*this)); 
 } 
 fin.close(); 
 fout.close(); 
 remove("Passenger.dat"); 
 rename("Temp.dat","Passenger.dat"); 
 cout<<"\n\nRECORD DELETED............."; 
} 
void Passenger::updatepasdata(char *p) 
{ 
 int flag=0; 
 fstream file; 
 file.open("Passenger.dat",ios::in|ios::out|ios::ate|ios::binary); 
 file.seekg(0); 
 file.read((char *)this,sizeof(*this)); 
 while(!file.eof()) 
 { 
 if(!strcmp(p,pasname)) 
 { 
 getch(); 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"UPDATING PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger ID: ";cin>>pasid; 
 cout<<"\nEnter Name: ";cin.ignore();cin.getline(pasname,19); 
 cout<<"\nEnter Mobile Number: ";cin>>mob; 
 cout<<"\nEnter Train ID: ";cin>>trainid; 
 cout<<"\nEnter Train Reservation Status: ";cin>>trainseat; 
 file.seekp(file.tellp()-sizeof(*this)); 
 file.write((char*)this,sizeof(*this)); 
 flag=1; 
 } 
 file.read((char *)this,sizeof(*this)); 
 } 
 file.close(); 
 if(flag==0) 
 { 
 cout<<"\nRecord not found"<<endl; 
 } 
 else if(flag==1) 
 { 
 cout<<"\n\nRECORD UPDATED......."; 
 } 
} 
void Passenger::pasdetails() 
{ 
 char name[20]; 
 int x; 
 Passenger r1; 
 do 
 { 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"PASSENGER DETAILS"<<endl; 
 cout<<"\n\n1.Insert Passenger Details"; 
 cout<<"\n\n2.Display Passenger Details"; 
 cout<<"\n\n3.Search Passenger Detail"; 
 cout<<"\n\n4.Delete Passenger Detail"; 
 cout<<"\n\n5.Update Passenger Detail"; 
 cout<<"\n\n6.Exit"; 
 cout<<"\n\nEnter your choice: "; 
 cin>>x; 
 switch(x) 
 { 
 case 1: 
 system("cls"); 
 cout<<"\n\n INSERTION OF PASSENGER DATA"; 
 cout<<"\n\n"; 
 r1.getpasdata(); 
 cout<<"\n\n"<<"Passenger ID"<<setw(20)<<"Passenger 
Name"<<setw(20)<<"Contact Details"<<setw(20)<<"Train 
ID"<<setw(30)<<"Reservation Status"<<endl; 
 r1.dispasdata(); 
 r1.storepasdata(); 
 cout<<"\n\nRecord Inserted....."<<endl; 
 getch(); 
 break; 
 case 2: 
 system("cls"); 
 cout<<"\n\n"<<setw(35)<<"DISPLAYING PASSENGER DATA"; 
 cout<<"\n\n"; 
 r1.viewpasdata(); 
 getch(); 
 break; 
 case 3: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"SEARCHING PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger Name to search: "; 
 cin>>name; 
 r1.searchpasdata(name); 
 getch(); 
 break; 
 case 4: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"DELETION OF PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger name to Delete: "; 
 cin>>name; 
 r1.searchpasdata1(name); 
 getch(); 
 break; 
 case 5: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"UPDATION OF PASSENGER DATA"; 
 cout<<"\n\nEnter Passenger name to update: "; 
 cin>>name; 
 r1.updatepasdata(name); 
 getch(); 
 break; 
 case 6: 
 cout<<"\n\nEXITING..........."<<endl; 
 getch(); 
 break; 
 default: 
 cout<<"\n\nWrong Option"<<endl; 
 getch(); 
 break; 
 } 
 }while(x!=6); 
} 
void Passenger::booking() 
{ 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"BOOKING"; 
 int id; 
 cout<<"\n\nEnter the TrainID: "; 
 cin>>id; 
 getbooking(id); 
 getch(); 
} 
int main() 
{ 
 Passenger r1; 
 Train t1; 
 long int id,pid; 
 int choice; 
 do 
 { 
 system("cls"); 
 cout<<"\n\n"<<setw(35)<<"WELCOME TO RAILWAY 
ENQUIRY"<<setw(35); 
 cout<<"\n\n1.Administrator"<<setw(30)<<"2.Passenger."; 
 cout<<"\n\n3.Exit."; 
 cout<<"\n\nLogin as: "; 
 cin>>choice; 
 switch(choice) 
 { 
 case 1: 
 long int logid,password; 
 cout<<"\n\nEnter LoginID: ";cin>>logid; 
 cout<<"\nEnter Password: ";cin>>password; 
 if(logid==8888 && password==24680) 
 { 
 int ch; 
 do 
 { 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"ADMINISTRATION MENU"; 
 cout<<"\n\n1.Trains Schedule."; 
 cout<<"\n\n2.Passenger Data."; 
 cout<<"\n\n3.Booking."; 
 cout<<"\n\n4.Cancellation."; 
 cout<<"\n\n5.Logout."; 
 cout<<"\n\nEnter Your Choice: "; 
 cin>>ch; 
 switch(ch) 
 { 
 case 1: 
 system("cls"); 
 t1.trainschedule(); 
 break; 
 case 2: 
 system("cls"); 
 r1.pasdetails(); 
 break; 
 case 3: 
 r1.booking(); 
 break; 
 case 4: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"CANCELLATION"; 
 cout<<"\n\nEnter your Passenger ID: "; 
 cin>>pid; 
 r1.cancellation(pid); 
 getch(); 
 break; 
 case 5: 
 cout<<"\nLOGGING OUT......"<<endl; 
 getch(); 
 break; 
 default: 
 cout<<"\nWrong Option."<<endl; 
 getch(); 
 break; 
 } 
 }while(ch!=5); 
 } 
 else 
 { 
 cout<<"\n\n"<<setw(20)<<"WRONG ID OR PASSWORD"; 
 cout<<"\n\n"<<setw(20)<<"CONTACT ADMINISTRATION 
OFFICE."<<endl; 
 getch(); 
 } 
 break; 
 case 2: 
 int ch; 
 do 
 { 
 system("cls"); 
 cout<<"\n\n"<<setw(35)<<"PASSENGER MENU"; 
 cout<<"\n\n1.View Train Schedule."; 
 cout<<"\n\n2.View Ticket."; 
 cout<<"\n\n3.Book a Ticket."; 
 cout<<"\n\n4.Cancel a Ticket."; 
 cout<<"\n\n5.Logout."; 
 cout<<"\n\nEnter Your Choice: ";cin>>ch; 
 switch(ch) 
 { 
 case 1: 
 system("cls"); 
 t1.viewtraindata(); 
 getch(); 
 break; 
 case 2: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"YOUR TICKET"; 
 cout<<"\n\nEnter Your Passenger ID: ";cin>>pid; 
 r1.ticket(pid); 
 getch(); 
 break; 
 case 3: 
 r1.booking(); 
 break; 
 case 4: 
 system("cls"); 
 cout<<"\n\n"<<setw(40)<<"CANCELLATION"; 
 cout<<"\n\nEnter your Passenger ID: "; 
 cin>>pid; 
 r1.cancellation(pid); 
 getch(); 
 break; 
 case 5: 
 cout<<"\n\nTHANKS FOR VISITING !"<<endl; 
 getch(); 
 break; 
 default: 
 cout<<"\n\nWrong Option."<<endl; 
 getch(); 
 break; 
 } 
 }while(ch!=5); 
 break; 
 case 3: 
 cout<<"\n\nTHANKS FOR VISITING........."<<endl; 
 getch(); 
 break; 
 } 
 }while(choice!=3); 
 return 0; 
}
