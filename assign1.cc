/*
Manoj Veluru
Z1840907
CSCI689
Assignment - 1
*/

#include<iostream>
#include<cmath>
#include<iomanip>

//Using required libraries
using std :: cout;
using std :: cin;
using std :: setw;
using std :: endl;
using std :: setprecision;
using std :: fixed;

//Fuction prototypes
double calculate(double, double); //calculate function prototype 

void tablePrint(double, double, double, double, double, double); //tablePrint function prototype

//main method
int main()
{	
	/*
	Variable declarations: 
	TL - Low temperature range
	TH - High temperature range
	TI - Temperature increment
	HL - Relative humidity Low value
	HH - Relative humidity high value
	HI - Relative humidity increment 
	*/
	double TL, TH, TI, HL, HH, HI;
	cout<<"This program prints out a table of approximate heat index values"<<endl;
	cout<<endl;
	cout<<"Temperature range low value (degrees F) ? ";
	cin>>TL;
	cout<<"Temperature range high value  (degrees F) ? ";
	cin>>TH;
	/* 
	Loop to check illegal values 
	*/
	if(TL >= TH)
	{
		cout<<endl<<"Check the values entered"<<endl;
		return 0;
	}
	cout<<"Temperature increment (degrees F) ? ";
	cin>>TI;
	/*
	 Loop to check illegal values 
	 */
	if(TI<=0)
	{
		cout<<endl<<"Enter legal values to be incremented"<<endl;
		return 0;
	}
	cout<<endl;
	cout<<"Relative humidity low value (%) ? ";
	cin>>HL;
	cout<<"Relative humidity high value(%) ? ";
	cin>>HH;
	/* 
	Loop to check illegal values 
	*/
	if(HL >= HH)
	{
		cout<<endl<<"Check the values entered"<<endl;
		return 0;
	}
	cout<<"Relative humidity increment (%) ? ";
	cin>>HI;
	/*
	 Loop to check illegal values 
	 */
	if(HI<=0)
	{
		cout<<endl<<"Enter legal values to be incremented"<<endl;
		return 0;
	}
	/*
	tablePrint function call (used to print the table)
	*/ 
	tablePrint(TL,TH,TI,HL,HH,HI);
	return 0;
}

/*
calculate function defenition - function used to calculate heat index value with given formula 
has double as return type and also has parameters with double data type
upon calculation, heat index value is returned 
*/
double calculate(double T, double R)
{
	double HeatIndex;
	HeatIndex = -42.379 + (2.04901523 * T) + (10.1433127 * R) - (0.22475541 *T * R) - (6.83783 * pow(10,-3) * T * T) - (5.481717 * pow(10,-2) * R * R) + (1.22874 * pow(10,-3) * T * T * R) + (8.5282 * pow(10,-4) * T * R * R) - (1.99 * pow(10,-6) * T * T * R * R);
	return HeatIndex;
}

/*
tablePrint function defenition- function used to get calculated results from calculate function and prints the table as expected
has no retun type and has six parameters with double datatype
*/
void tablePrint(double TL,double TH,double TI,double HL,double HH,double HI)
{
	/*
	Variable declaration:
	heatindex - used for fetching calculated value from calculate method
	*/
	double heatindex; 
	cout<<endl<<"Heat Index Table"<<endl;
	cout<<endl<<"Relative Humidity"<<endl;	
	/*
	setw - this is used for maintaing 8 characters space as mentioned in question
	setprecision()- this is used to set the precision value after decimal point with fixed format
	*/
	cout<<setw(8)<<" (%)";
	cout<<fixed<<setprecision(2);
	/*
	For loop to print all humidity from low to high in a given row
	*/
	for(double ColumnHumidity=HL;ColumnHumidity<=HH;ColumnHumidity+=HI)
	{
		cout<<setw(8)<<ColumnHumidity;		
	}
	cout<<endl;
	/*
	For loop to print the lines as expected
	*/
	for(double ColumnHumidity=HL;ColumnHumidity<=HH+HI;ColumnHumidity+=HI)
	{
		for(int line=1;line<=8;line++)
		{
			cout<<"-";
		}		
	}
	cout<<endl;
	cout<<"Air Temperature"<<endl;
	cout<<"(deg. F)"<<endl;
	/*
	For loop to print the heat index values table
	*/
	for(double RowTemperature=TL;RowTemperature<=TH;RowTemperature+=TI)
	{		
		cout<<setw(7)<<RowTemperature<<"|"<<setw(8); // prints initial given temperatures from low to high in every row
		/*
	        For loop for calculating and printing particular row temperature with all humidity values
	        */
		for(int ColumnHumidity=HL;ColumnHumidity<=HH;ColumnHumidity+=HI)
    	{
		heatindex = calculate(RowTemperature,ColumnHumidity); 			
	    cout<<setw(8)<<heatindex;
	    }
	    cout<<endl;
	}
		
}
