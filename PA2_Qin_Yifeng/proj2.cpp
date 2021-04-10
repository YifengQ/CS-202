//Yifeng Qin
//CS202
//9/13/17
//Section 1104
//Project2

#include <iostream>
#include <fstream> 
using namespace std;

const int maxsize=10;

void myStringCopy (const char *destination, const char *source);
int myStringCompare (const char *str1, const char *str2);

struct car{
      	
		int year;
      	char make[maxsize];
      	char model[maxsize];
      	float price;
      	bool available;

         };


int main()
{
	
	int i=0;
	int j=0;
	int rent;
	int length;
	int days;
	float cost;
	float total;
	char filename[maxsize];
	char input[maxsize];
	char output[maxsize];
	int count=0;
   	car everything[5];
	car temp;
	int menu;
	
	cout << "=====================================" << endl;
	cout << "                Menu"<< endl;
	cout << "=====================================" << endl;
	cout << "1) Open File / Store Data" << endl;
	cout << "2) Print Out Data / Name Output File" << endl;
	cout << "3) Save to Seperate File" << endl;
	cout << "4) Sort Cars By Price" << endl;
	cout << "5) Length of Rent / Estimated Cost" << endl;
	cout << "6) Rent A Car / Estimated Price" << endl;
	cout << "7) Exit File" << endl;
	cout << "Enter Option: ";
	
	cin >> menu;
	
	while(menu != 7)
	{
	
		switch(menu)
		{
		
		case(1):
		{	

			// Enter file name
			cout << endl;
			cout << "Enter the input file name: ";
	  		cin >> filename;	
			//Opens file to read using entered name
			ifstream file;
	  		file.open(filename);
			//reads till end of file
			while(!file.eof())
			{

				// sorts the data of the file into an array
				for(i= 0 ; i < 5 ; i++)
				{
				file >> everything[i].year;
				file >> everything[i].make;
				file >> everything[i].model;
				file >> everything[i].price;
				file >> everything[i].available;

				}
	
			}
			//close file
			cout << "File name was entered" << endl;
			file.close();
			break;
			}


		case(2):
		{
		cout << endl;

			//Prints out the vaules in the file and declares if it is avaiable or not
			for(i= 0 ; i < 5 ; i++)
				{
				cout << everything[i].year << " ";
				cout << everything[i].make << " ";
				cout << everything[i].model;
				cout << ", $" << everything[i].price << " per day,";
				cout << " Available: " << boolalpha << everything[i].available << endl;

				}
		cout << endl;
		cout << "Enter an output file name: ";
		cin >> output;
		break;
		}
		
		case(3):
		{
			//opnes file to write too
			ofstream ofile;
	  		ofile.open(output);
			//write to the fi;e pf whatst in the array
			for(i= 0 ; i < 5 ; i++)
				{
					ofile << everything[i].year << " ";
					ofile << everything[i].make << " ";
					ofile << everything[i].model << " ";
					ofile << everything[i].price << " ";
					ofile << everything[i].available << endl;

				}
			ofile.close();
			cout << "Data was stored into a seperate file" << endl;
		break;
		}
	
		case(4):
		{
		//sorts the prices
		for(i = 0; i  < 5; i++)
		{
			for(j = 0 ; j < 5; j++)
			{
				if(everything[j].price > everything[i].price)
				{
					// if one price is less than the other they will swithc places by using these functions and a temp storage.
					temp = everything[i];

					everything[i] = everything[j];

					everything[j] = temp;
				}

			}

		}
		cout << "Cars have been sorted" << endl;
		 break; 
		}
	
	case(5):
	{
	
	cout << "How many days would you like to rent a car: ";
	cin >> days;  
	//prints out the type of car/only avaialbe cars along with the estimated prices of the total cost
	for(i= 0 ; i < 5 ; i++)
				{

				if(everything[i].available == true)
				{
					cout << everything[i].year << " ";
					cout << everything[i].make << " ";
					cout << everything[i].model << " ";
					total = everything[i].price * days;
					cout << ", Total Cost: $" << total << " ";
					cout << endl;
				}
				}

	}

	case(6):
	{
	
		cout << "Which car do you want to rent? : " ;
		cin >> rent;
		cout << "How long do you want to rent it? : ";
		cin >> length;
		//user enters which car they want and how long they want it
		//total is the price of the car every day mulitpied by the length of the rent
		if(everything[rent].available == true)
		{
			cout << "Sucessful Rent" <<  endl ;
			cost = everything[rent].price * length;
			cout << "Total cost = $" << cost << endl ;
			everything[rent].available = false;
			
	
		}
		else
		{
		// if the car is not avaiable there is an error message
			cout << "Car is not available for rent. Sorry!!!" << endl;
		}


	}

			
	}
		
	cout << endl;
	cout << "Enter Menu Option: ";
	cin >> menu;
	}
	
	  return 0;
}

//copies the calues from the source to a temp destination
void myStringCopy (const char *destination, const char *source)
{
	while( *source!= '\0')
	{
	*source == *destination;
	source++;
	destination++;
	
	}
	destination = '\0';

}
// retruns 0 when strings match
// when value is less than one the srt1 has lower value and when value is more than one str1 is bigger
int myStringCompare (const char *str1, const char *str2)
{
	for( ; *str1 == *str2; str1++, str2++)
		{
		return 0;
		if(*str1 == '\0')
		{
		return str1 - str2;
	
		}
	
		}

}

