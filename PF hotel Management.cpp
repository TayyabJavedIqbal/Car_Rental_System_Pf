#include<iostream>
#include<string>  
using namespace std;
struct cars {                //This is a structure for cars.
    string brand, colour;
    int year, cost;
};
struct custom {            //This is for customers
    string name, email, address, ph;
};
void getcustomer(custom &customers) {         //this is a function to get input for customers & symbol is used for directly referencing the original value
    cout << "\t\t~Customer Information~" << endl;
    cin.ignore();
    cout << "\nEnter customer name: ";
    getline(cin, customers.name);
    cout << "Enter customer email: ";
    getline(cin, customers.email);
    cout << "Enter customer address: ";
    getline(cin, customers.address);
    cout << "Enter your phone number: ";
    getline(cin, customers.ph);
}
void printline() {            //this is a function to print a line
    cout << "\n-------------------------------------------------------------\n" << endl;
}
void printcarinfo(cars carsr) {             //this is a function to print car into
    cout << "\tModel: "<< carsr.brand << endl;
    cout << "\tYear: " << carsr.year << endl;
    cout << "\tCost: $" << carsr.cost << endl;
    cout << "\tColour: " << carsr.colour << endl;
}
void printcustom(custom customer) {                //This is a function to print customer info (Before the final loop)
    cout << "\tName: "  << customer.name << endl;
    cout << "\tEmail: " << customer.email << endl;
    cout << "\tAddress: " << customer.address << endl;
    cout << "\tPhone: " << customer.ph << endl;
}
void printcust(custom customers) {                //This is a function to print customer info (Inside the loop)
    cout << "\tName: " << customers.name << endl;
    cout << "\tEmail: " << customers.email << endl;
    cout << "\tAddress: " << customers.address << endl;
    cout << "\tPhone: " << customers.ph << endl;
}
int main() {
    int n; //This is to get the number of cars to input (used in main loop)
    char temp;     //temporary variable used for login page and confirmations
    int days = 0; // This is a variable used to ask customer for how many days they wish to rent the car 
    int sel = 0;     //this variable is used to select the car the customer wanted, by subtracting customer number by 1
    int prices; //This is used to display the final price of the rented car (Prices used as price was used in structure above)
    custom customer; ///using structure
 	cout<< "\n";
	cout<<"Welcome to the Car Rental Management System\n"<<endl;     //Login page
	cout<<"Press X to Start\nPress O to exit"<<endl;
	cin>>temp;
	if(temp=='x'||temp=='X'){	
		printline();		
		cout<<"\t\t\t~Welcome~"<<endl;
	}
	else {
            cout << "\t~Program Ended~" << endl;
        	return 0;
        }
    cout << "\nEnter the number of cars you wish to store in the system: ";
    cin >> n;
    cars carsr[n];  //using array with structure to store multiple entities under one structure
    custom customers[n]; //assigning n to make an array
 	printline();
	cout << "\t\tEnter details of available cars";
	printline();
       for (int i = 0; i < n; i++) {             //using loop to get multiple cars under array
        cin.ignore();
        cout << "Enter the brand and model (Toyota Supra etc) of car #" << i + 1 <<" :" << endl;
        getline(cin, carsr[i].brand);
        cout << "Enter the colour of car #" << i + 1 << " :"<< endl;
        getline(cin, carsr[i].colour);
        cout << "Enter manufacture year of car #" << i + 1 <<" :" << endl;
        cin >> carsr[i].year;
        cout << "Enter the rent per day of car #" << i + 1 << " :"<< endl;
        cin >> carsr[i].cost;
        printline();
     	      if (i == n - 1) {
            break;
        }	   		    
        cout<<"Would you like to continue? Y/N"<<endl;
        cin>>temp;
        if(temp == 'Y' || temp =='y'){
        	cout << endl;
		}
		else{
			n = i + 1;		//if the user chooses to stop the array will update and we will add +1 as the array starts from 0.
			break;
		}
		  printline();
	}
   printline();
    cout << "\t~Result~" << endl;
    for (int i = 0; i < n; i++) {   					 //this loop is used to display the result of above entered detail
        cout << "Car # " << i + 1 << endl;
        printcarinfo(carsr[i]);
        cout << endl;
        printline();
    }
    cout << "Enter the Car # you wish to rent out:" << endl;            //Entering users car
	printline();
	
    for (int i = 0; i < n; i++) {
        cout << "Car # " << i + 1 << endl;      //this loop will provide the user with a choice to chose their car
        printcarinfo(carsr[i]);
        cout << endl;
        printline();
    }
    cin >> sel;  								 //sel short for select
    printline();
    int news = sel - 1; 						  //creating a varble to store users choice 
    cout << "You have selected:" << endl;  			//this will print the users choice 
    printcarinfo(carsr[news]);
    printline();
    getcustomer(customers[0]);  			  //calling fiction to get customer info 
    printline();
    cout << "Customer Information" << endl;
    printcustom(customers[0]);    			 //calling function to print customer info
	printline();
    cout << "How many days will the customer rent the car for?" << endl;
    cin >> days;
    prices = carsr[news].cost * days;     	//formula for price of selected car (this makes use of array)
	printline();
    cout << "\t\t----GENERATE BILL-----" << endl;
    cout << "\nTotal price for " << days << " days is: $" << prices << endl;
//    printline();
    carsr[news].brand = "Rented out";  			//Updating array to show rented out car
    carsr[news].colour = "Rented out";
    carsr[news].cost = 0;
    carsr[news].year = 0;
//    cout <<"Your Updated Inventory is:" << endl;
//    for (int i = 0; i < n; i++) {       		 //displayinh updated inventory 
//        printcarinfo(carsr[i]);
//    }
    for (int j = 1; j < n; j++) {                //using loop to ask if we want to rent out more cars	            
		printline();
        cout << "Would you like to rent out more cars?\nPress A for Yes\nPress B for No" << endl;
        cin >> temp;
        printline();
        if (temp == 'A' || temp == 'a') {
            cout << "Select the car you wish to rent out:" << endl;
            printline();
            for (int i = 0; i < n; i++) {
                cout << "Car #" << i + 1 << endl;
                printcarinfo(carsr[i]);
                cout << endl;
                printline();
            }
            cin >> sel;
            printline();
            news = sel - 1;
            cout << "You have selected:" << endl;
            printcarinfo(carsr[news]);  		//once again displaying the selected user car
            printline();
//            getcustomer(customer); 				//calling function	
//            printcust(customer);
     cout << "How many days will the customer rent the car for?" << endl;
  		     cin >> days;
			 prices=0;
  		     prices = carsr[news].cost * days;
           		printline();          
  	    cout << "Total price for " << days << " days is: $" << prices << endl;
  		     carsr[news].brand = "Rented out";
  		     carsr[news].colour = "Rented out";
  		     carsr[news].cost = 0;
             carsr[news].year = 0;
             cout <<endl;
        }
        else {
            cout << "\t\t~Program Ended~" << endl;
            break;
        }
    }
    return 0;
}