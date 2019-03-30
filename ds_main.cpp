#ifndef __CLASSES_CPP__
#define __CLASSES_CPP__

//Daniel Pintor
//H346N927

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
#include "classes.cpp"
#define CAR_NUM 15

using namespace std;

int searchid(int id_to_find, ArrayList a, int car_num){ //function to return id
	for (int i = 0; i < car_num; i++){ //scans through 'a'
		if (a.get(i).getid() == id_to_find){				
				cout << "Array index found:	"; //returns index
				return i;
		}
	}
}

void searchmake (string make_to_find, ArrayList a, int car_num){ //function to find make
	for (int i = 0; i < car_num; i++){	//scans through 'a'		
		if ((a.get(i).getmake()).compare(make_to_find) != 0)
			cout << a.get(i).getmake() << endl; //returns make
	}
}

void searchcat (string cat_to_find, ArrayList a, int car_num){ //function to find category
	for (int i = 0; i < car_num; i++){ //scans through 'a'
		if ((a.get(i).getcat()).compare(cat_to_find) != 0)
			cout << a.get(i).getcat(); //returns category
	}
}

void addcar (Car c, ArrayList a, int car_num){

	int new_id; //holds new id
	string new_make, new_model, new_cat; //holds new traits
	
	cout << "Enter new ID:	";
	cin >> new_id;
	c.setid(new_id); //in first run, holds id in car #16
	
	cout << "Enter new make:	";
	cin >> new_make;
	c.setmake(new_make); //in first run, holds make in car #16
	
	cout << "Enter new model:	";
	cin >> new_model;
	c.setmodel(new_model); //in first run, holds model in car #16
	
	cout << "Enter new category:	";
	cin >> new_cat;
	c.setcat(new_cat); //in first run, holds category in car #16
			
	car_num++;
	a.add(c);
}


int main(){

	Car c;
	ArrayList a;
	int id; //to hold car's id
	string make, model, category; //to hold car traits

	int car_num = CAR_NUM; //holds defined number of cars
	
	ifstream in; //to read files
	in.open("cars.data");
	if (in.fail())
	{
		cout << "No such file exists" << endl; //to see if file exists
	}
	else
	{
		// bookcount is inputted from the file, along with all the information of all books...
		cout << "File found" << endl;
		for(int m = 0; m <= car_num; m++) //reading in from file
		{
			in >> id;
			c.setid(id); //sets car id
			getline (in, make);
			c.setmake(make); //sets car make
			getline (in, model);
			c.setmodel(model); //sets car model
			getline (in, category);
			c.setcat(category); //sets car category
			a.add(c); //adds car to a's next available slot
		};
	}
	
	int option; //holds menu choice
	
	do{ //operations menu
		cout << "What would you like to do with your array list?" << endl;
		cout << "1. Search by ID" << endl;
		cout << "2. Search by make" << endl;
		cout << "3. Search by category" << endl;
		cout << "4. Add a new car" << endl;
		cout << "5. Delete a car by ID" << endl;
		cout << "6. List all cars" << endl;
		cout << "7. Exit program" << endl;
		
		if (option == 1){
			int id_to_find;
			cout << "Enter ID:	";
			cin >> id_to_find;
			cout << searchid(id_to_find, a, car_num) << endl;

					
		}
		if(option == 2){
			string make_to_find;
			cout << "Enter make:	";
			cin >> make_to_find;
			searchmake(make_to_find, a, car_num);
		}
		if(option == 3){
			string cat_to_find;
			cout << "Enter category:	";
			cin >> cat_to_find;
			searchcat(cat_to_find, a, car_num);
		}
		if(option == 4){
			addcar(c, a, car_num);
		}
		if (option == 5){
			int id_to_be_deleted;
			cout << "Input ID of car to be deleted:	";
			cin >> id_to_be_deleted;
			a.del(a.search(c)); //deletes arr[i] such that i is the index of the car
								//	whose id is marked for deletion
		}
		if(option == 6){
		
			a.traverse();
			
		}	
	}while(option != 7);
	
	ofstream out;
	out.open("cars.data");
	int l;
	l = 0;
	while(l <= car_num - 1)
	{
		out << (a.get(l)).getid() << endl; //writing out a's contents to file
		out << (a.get(l)).getmake() << endl;
		out << (a.get(l)).getmodel() << endl;
		out << (a.get(l)).getcat() << endl;
		l++;
	}
	out.close();
	
	
	return 0;
}
#endif
