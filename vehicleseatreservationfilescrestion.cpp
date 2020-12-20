#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	//FILES ESSENTIAL FOR VEHICLE DETAILS
	ofstream newbus1("busno.txt");
	newbus1<<"This file contains bus numbers";
	newbus1<<endl;
	newbus1.close();
	ofstream newbus2("busdrivername.txt");
	newbus2<<"This file contains bus drivers names";
	newbus2<<endl;
	newbus2.close();
	ofstream newbus3("arrival.txt");
	newbus3<<"This file contains bus arrival times";
	newbus3<<endl;
	newbus3.close();
	ofstream newbus4("departure.txt");
	newbus4<<"This file contains bus departure times";
	newbus4<<endl;
	newbus4.close();
	ofstream newbus5("strtngpnt.txt");
	newbus5<<"This file contains bus starting point";
	newbus5<<endl;
	newbus5.close();
	ofstream newbus6("destination.txt");
	newbus6<<"This file contains bus destinations";
	newbus6<<endl;
	newbus6.close();
	
	//FILES ESSENTIAL FOR RESERVATION DETAILS
	ofstream reservation1("firstname.txt");
	reservation1<<"This file contains first name of the passenger";
	reservation1<<endl;
	reservation1.close();
	ofstream reservation2("lastname.txt");
	reservation2<<"This file contains last name of the passenger";
	reservation2<<endl;
	reservation2.close();
	ofstream reservation3("age.txt");
	reservation3<<"This file contains age of the passenger";
	reservation3<<endl;
	reservation3.close();
	ofstream reservation4("seatnumber.txt");
	reservation4<<"This file contains seat number to be reserved for the passenger";
	reservation4<<endl;
	reservation4.close();
	ofstream reservation5("reservationid.txt");
	reservation5<<"This file contains reservation ID's the passenger";
	reservation5<<endl;
	reservation5.close();
	ofstream reservation6("reservedbusno.txt");
	reservation6<<"This file contains the bus number of bus reserved by passenger";
	reservation6<<endl;
	reservation6.close();
	
	return 0;
}
