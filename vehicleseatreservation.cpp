#include<iostream>
#include<sstream>
#include<fstream>
#include<ctime>
#include<string>
#include<vector>

using namespace std;

void mainmenu();
void registernewbus();
int reservationprocess(int );
void previewbus();
void busdiagram(vector<int> );
void previewreservation();
void allvehicles();
void exitmsg();

void mainmenu()
{
	cout<<string(20,' ')<<"Press[1] --> To Register New Bus"<<endl;
	cout<<string(20,' ')<<"Press[2] --> To Perform The Reservation Process"<<endl;
	cout<<string(20,' ')<<"Press[3] --> To Preview Any Bus' Booking Status"<<endl;
	cout<<string(20,' ')<<"Press[4] --> To See All The Available Vehicles In Our SYSTEM"<<endl;
	cout<<string(20,' ')<<"Press[5] --> To Preview Your Reservation Details"<<endl;
	cout<<string(20,' ')<<"Press[0] --> To Exit The SYSTEM"<<endl<<endl;
	cout<<string(16,' ')<<"PRESS THE SELECTION KEY AND THEN PRESS ENTER TO PROCEED"<<endl<<endl;
}

void registernewbus()
{
	cout<<string(80,'-')<<endl;
	cout<<string(15,' ')<<"Kindly fill following information to REGISTER NEW BUS"<<endl<<endl;
	string arr,dep,bsno,drvrnme,strt,end;
	cout<<string(20,' ')<<"Fill in the bus number : ";
	cin>>bsno;
	ofstream fillin;
	fillin.open("busno.txt",ios::app);
	fillin<<bsno;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the bus driver's number : ";
	cin>>drvrnme;
	fillin.open("busdrivername.txt",ios::app);
	fillin<<drvrnme;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the starting point of bus : ";
	cin>>strt;
	fillin.open("strtngpnt.txt",ios::app);
	fillin<<strt;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the destination of bus : ";
	cin>>end;
	fillin.open("destination.txt",ios::app);
	fillin<<end;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the arrival time of bus at starting point[PLEASE MENTION THE TIME IN 24 HOURS FORMAT]: ";
	cin>>arr;
	fillin.open("arrival.txt",ios::app);
	fillin<<arr;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the departure time of bus at starting point[PLEASE MENTION THE TIME IN 24 HOURS FORMAT]: ";
	cin>>dep;
	cout<<endl;
	fillin.open("departure.txt",ios::app);
	fillin<<dep;
	fillin<<endl;
	fillin.close();
	cout<<endl;
	cout<<string(15,' ')<<"Your New Bus, numbered "<<bsno<<", from "<<strt<<" to "<<end<<" is succesfully registered in the system"<<endl<<endl;
	cout<<string(80,'-')<<endl<<endl;
}

int reservationprocess(int Rid)
{
	cout<<string(80,'-')<<endl;
	cout<<string(15,' ')<<"Kindly fill following information for the RESERVATION PROCESS"<<endl<<endl;
	string firstnm,lastnm,age,seatno,Ridstr,busno;
	ofstream fillin;
	cout<<string(20,' ')<<"Fill in the bus number in which you want the reservation to be done : ";
	cin>>busno;
	fillin.open("reservedbusno.txt",ios::app);
	fillin<<busno;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the first name of passenger[ALL BLOCK LETTERS] : ";
	cin>>firstnm;
	fillin.open("firstname.txt",ios::app);
	fillin<<firstnm;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the last name of passenger[ALL BLOCK LETTERS] : ";
	cin>>lastnm;
	fillin.open("lastname.txt",ios::app);
	fillin<<lastnm;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the age of passenger : ";
	cin>>age;
	fillin.open("age.txt",ios::app);
	fillin<<age;
	fillin<<endl;
	fillin.close();
	cout<<string(20,' ')<<"Fill in the seat number to be reserved : ";
	cin>>seatno;
	fillin.open("seatnumber.txt",ios::app);
	fillin<<seatno;
	fillin<<endl;
	fillin.close();
	cout<<endl;
	
	ostringstream str1;
	str1<<Rid;
	Ridstr=str1.str();
	
	fillin.open("reservationid.txt",ios::app);
	fillin<<Ridstr;
	fillin<<endl;
	fillin.close();
	
	Rid++;
	
	cout<<string(15,' ')<<"Dear Mr/Mrs. "<<firstnm<<' '<<lastnm<<", your reservation in bus number - "<<busno<<endl;
	cout<<string(15,' ')<<"is done succesfully. Yous Reservation ID is "<<Rid<<endl;
	cout<<string(80,'-')<<endl<<endl;
	
	return Rid;
}

void previewbus()
{
	cout<<string(80,'-')<<endl;
	cout<<string(20,' ')<<"Provide the bus number you want to preview : ";
	char bsno[100],check[100],drvrnm[100],from[100],to[100],arr[100],dep[100];
	cin>>bsno;
	cout<<endl;
	int checkcounter=0,counter=0;
	ifstream tocheck;
	tocheck.open("busno.txt");
	do
	{
		tocheck.getline(check,100);
		if(bsno[0]==check[0] && bsno[2]==check[2])
		{
			checkcounter+=1;
		}
		counter+=1;
	}while(bsno[0]!=check[0] && !tocheck.eof());
	tocheck.close();
	if(checkcounter==1)
	{
		cout<<endl;
		cout<<string(120,'*')<<endl;
		tocheck.open("busdrivername.txt");
		int line=0;
		while(line!=counter)
		{
			tocheck.getline(drvrnm,100);
			line++;
		}
		tocheck.close();
		line=0;
		tocheck.open("strtngpnt.txt");
		while(line!=counter)
		{
			tocheck.getline(from,100);
			line++;
		}
		tocheck.close();
		line=0;
		tocheck.open("destination.txt");
		while(line!=counter)
		{
			tocheck.getline(to,100);
			line++;
		}
		tocheck.close();
		line=0;
		tocheck.open("arrival.txt");
		while(line!=counter)
		{
			tocheck.getline(arr,100);
			line++;
		}
		tocheck.close();
		line=0;
		tocheck.open("departure.txt");
		while(line!=counter)
		{
			tocheck.getline(dep,100);
			line++;
		}
		tocheck.close();
		cout<<string(20,' ')<<"Bus number-"<<bsno<<string(15,' ')<<"Bus driver's name-"<<drvrnm<<endl;
		cout<<string(120,'+')<<endl;
		cout<<string(20,' ')<<"From-"<<from<<string(15,' ')<<"Arrival time-"<<arr<<endl;
		cout<<string(20,' ')<<"To  -"<<to<<string(15,' ')<<"Departure time-"<<dep<<endl;
	}
	else
	{
		cout<<endl;
		cout<<string(20,' ')<<"This bus number is not registered in our System! Sorry!"<<endl<<endl;
	}
	cout<<string(80,'-')<<endl;
}

/*void busdiagram(vector<int> occst)
{
	int n=occst.size();
	cout<<endl;
	cout<<string(20,' ')<<"In this bus, seat number ";
	for(int i=0;i<n,i++)
	{
		cout<<occst[i]<<"-";
	}
	cout<<" are already reserved."<<endl;
	cout<<string(20,' ')<<"You can reserve the seats other than these."<<endl;
	cout<<string(20,' ')<<"We still have "<<(30-n)<<" seats empty in this bus"<<endl;
	cout<<string(120,'*')<<endl;
}*/

void previewreservation()
{
	cout<<string(80,'-')<<endl;
	cout<<string(15,' ')<<"Kindly fill following information for previewing your Reservation details"<<endl<<endl;
	char Ridstr[100],check[100];
	int checkcounter=0,counter=0;
	char frstnm[100],lastnm[100],age[100],seatno[100],busno[100];
	cout<<string(20,' ')<<"TYPE YOUR RESERVATION ID : ";
	cin>>Ridstr;
	ifstream tocheck;
	tocheck.open("reservationid.txt");
	do
	{
		tocheck.getline(check,100);
		if(Ridstr[7]==check[7])
		{
			checkcounter+=1;
		}
		counter+=1;
	}while(Ridstr[7]!=check[7] && !tocheck.eof());
	tocheck.close();
	if(checkcounter==1)
	{
		cout<<string(20,' ')<<"Following are your reservation details - "<<endl;
		tocheck.open("firstname.txt");
		int line=0;
		while(line!=counter)
		{
			tocheck.getline(frstnm,100);
			line++;
		}
		tocheck.close();
		line=0;
		tocheck.open("lastname.txt");
		while(line!=counter)
		{
			tocheck.getline(lastnm,100);
			line++;
		}
		tocheck.close();
		cout<<string(20,' ')<<"Name of passenger is :- "<<frstnm<<' '<<lastnm<<endl;
		line=0;
		tocheck.open("reservedbusno.txt");
		while(line!=counter)
		{
			tocheck.getline(busno,100);
			line++;
		}
		tocheck.close();
		cout<<string(20,' ')<<"Your seat is reserved in bus number :- "<<busno<<endl;
		line=0;
		tocheck.open("age.txt");
		while(line!=counter)
		{
			tocheck.getline(age,100);
			line++;
		}
		tocheck.close();
		cout<<string(20,' ')<<"Age of passenger is "<<age<<endl;
		line=0;
		tocheck.open("seatnumber.txt");
		while(line!=counter)
		{
			tocheck.getline(seatno,100);
			line++;
		}
		tocheck.close();
		cout<<string(20,' ')<<"Reserved seat number of passenger is "<<seatno<<endl;
	}
	else
	{
		cout<<endl;
		cout<<string(20,' ')<<"Your Reservation ID is INVALID! Kindly validate it!"<<endl<<endl;
	}
	cout<<string(80,'-')<<endl;
}

void allvehicles()
{
	cout<<string(120,'*')<<endl;
	cout<<string(15,' ')<<"Below are all the vehicles available in our SYSTEM"<<endl<<endl;
	cout<<"BUS NO   BUS DRIVER'S NAME   STARTING POINT   ARRIVAL(Starting point)   DEPARTURE(Starting Point)   DESTINATION"<<endl;
	char arr[100],dep[100],bsno[100],drvrnme[100],strt[100],end[100];
	int line=0,i=2;
	ifstream takeout1;
	ifstream takeout2;
	ifstream takeout3;
	ifstream takeout4;
	ifstream takeout5;
	ifstream takeout6;
	takeout1.open("busno.txt");
	takeout2.open("busdrivername.txt");
	takeout3.open("strtngpnt.txt");
	takeout4.open("arrival.txt");
	takeout5.open("departure.txt");
	takeout6.open("destination.txt");
	do
	{
		while(line!=i)
		{
			takeout1.getline(bsno,100);
			takeout2.getline(drvrnme,100);
			takeout3.getline(strt,100);
			takeout4.getline(arr,100);
			takeout5.getline(dep,100);
			takeout6.getline(end,100);
			line++;
		}
		cout<<" "<<bsno<<string(5,' ')<<drvrnme<<string(14,' ')<<strt<<string(12,' ')<<arr<<string(25,' ')<<dep<<string(25,' ')<<end<<endl;
		i++;
	}while(!takeout1.eof());
	takeout1.close();
	takeout2.close();
	takeout3.close();
	takeout4.close();
	takeout5.close();
	takeout6.close();
	cout<<string(120,'*')<<endl<<endl;
}

void exitmsg()
{
	cout<<endl;
	cout<<string(80,'^')<<endl<<endl;
	cout<<string(16,'!')<<"   THANK YOU FOR USING OUR RESERVATION SERVICE   "<<string(16,'!')<<endl<<endl;
	cout<<string(82,'=')<<endl<<endl;
}

int main()
{
	cout<<endl;
	cout<<string(17,'!')<<"   WELCOME TO BUS SEAT RESERVATION SYSTEM   "<<string(17,'!')<<endl<<endl;
	time_t now=time(0);
	char* date=ctime(&now);
	cout<<string(78,'-')<<endl<<endl;
	cout<<string(19,' ')<<"Current time : "<<date<<endl;
	cout<<string(78,'-')<<endl<<endl;
	mainmenu();
	int rid=18115000,seat;
	vector<int> seatsoccupied;
	char option;
	do
	{
		cin>>option;
		switch(option)
		{
			case '1':
				{
					registernewbus();
					mainmenu();
					break;
				}
			case '2':
				{
					rid=reservationprocess(rid);
				//	seatsoccupied.push_back(seat);
					mainmenu();
					break;
				}
			case '3':
				{
					previewbus();
				//	busdiagram(seatsoccupied);
					mainmenu();
					break;
				}
			case '4':
				{
					allvehicles();
					mainmenu();
					break;
				}
			case '5':
				{
					previewreservation();
					mainmenu();
					break;
				}
			case '0':
				{
					exitmsg();
					break;
				}
			default:
				{
					cout<<string(100,'-')<<endl<<endl;
					cout<<string(30,' ')<<"INVALID SELECTION KEY!!!"<<endl;
					cout<<string(25,' ')<<"Please enter valid selection key..."<<endl<<endl;
					cout<<string(20,' ')<<endl<<endl;
					cout<<string(100,'-')<<endl<<endl;
					mainmenu();
					break;
				}
		}
	}while(int(option)-48);
}
