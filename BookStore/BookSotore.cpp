#pragma once 
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Manager {
private:
	int id;
	string username;
	string branch;
public:
	Manager() {
		this->username = "";
		this->branch = "";
		this->id = 0;
	}
	Manager(int id, string branch, string username) {
		this->id = id;
		this->username = username;
		this->branch = branch;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
	}
	string getUsername() {
		return username;
	}
	void setUsername(string username) {
		this->username = username;
	}
	virtual void managerMenu() {
		int choice;
		BookFeature bookFT;
		cout << "\t===================== Manager Menu =======================" << endl;
		cout << "\t1. Add Book" << endl;
		cout << "\t2. Remove Book" << endl;
		cout << "\t3. View Storage" << endl;
		cout << "\t4. Edit Book" << endl;
		cout << "\t0. Exit" << endl;
		cout << "\tEnter your choice: " << endl;
		cin >> choice;
		if (choice == 1) {
			bookFT.addBooks();
		}
		else if (choice == 2) {
			bookFT.removeBook();

		}
		else if (choice == 3) {
			bookFT.viewAll();

		}
		else if (choice == 4) {
			bookFT.editBook();
		}
		else {
			cout << "Invalid chocie!!";
			system("cls");
		}
	}

};
class Employee {
private:

	int id;
	string username;
	string role;
public:
	Employee() {
		this->username = "";
		this->role = "";
	}
	Employee(string role, string username) {
		this->username = username;
		this->role = role;
	}
	virtual void EmployeeMenu() {
		BookFeature bookFT;
		int choice;
		cout << "\t===================== Employee Menu =======================" << endl;
		cout << "\t1. Add Book" << endl;
		cout << "\t2. Remove Book" << endl;
		cout << "\t3. View Storage" << endl;
		cout << "\t4. Edit Book" << endl;
		cout << "\t0. Exit" << endl;
		cout << "\tEnter your choice: " << endl;
		cin >> choice;
		if (choice == 1) {
			bookFT.addBooks();
		}
		else if (choice == 2) {
			bookFT.removeBook();

		}
		else if (choice == 3) {
			bookFT.viewAll();

		}
		else if (choice == 4) {
			bookFT.editBook();
		}
		else {
			cout << "Invalid chocie!!";
			system("cls");
		}
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
	}
	string getUsername() {
		return username;
	}
	void setUsername(string username) {
		this->username = username;
	}
	string getRole() {
		return role;
	}
	void setRole(string role) {
		this->role = role;
	}

};

class Books {
private:
	string name;
	string author;
	string genre;
	int id;
	float price;
public:
	Books() {
		this->name = "";
		this->author = "";
		this->genre = "";
		this->id = 0;
		this->price = 0;
	}
	Books(string name, string author, string genre, int id, float price) {
		this->name = name;
		this->author = author;
		this->genre = genre;
		this->id = id;
		this->price = price;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getAuthor() {
		return author;
	}
	void setAuthor(string author) {
		this->author = author;
	}
	string getGenre() {
		return genre;
	}
	void setGenre(string genre) {
		this->genre = genre;
	}
	float getPrice() {
		return price;
	}
	void setPrice(float price) {
		this->price = price;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		if (id > 0) {
			this->id = id;
		}
	}

	virtual void viewAll() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Author: " << author << endl;
		cout << "Genre: " << genre << endl;
		cout << "Price: " << price << endl;
	}
};

class BookFeature : public Books {
private:
	vector<Books*> newBook;
public:
	vector<Books*> getBooks() {
		return newBook;
	}
	void addBooks() {
		string name;
		string author;
		int id;
		float price = 0;
		string genre;
		cout << "Enter The Books' Information." << endl;
		cout << "ID: ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		cout << "Author: ";
		cin >> author;
		cout << "Genre: ";
		cin >> genre;
		cout << "Price: ";
		cin >> price;
		Books* book = new Books(name, author, genre, id, price);
		newBook.push_back(book);
		cout << endl;
	}
	void searchBook() {
		int id;
		cout << "Enter teacher ID to search: ";
		cin >> id;
		for (int i = 0; i < newBook.size(); i++) {
			if (newBook[i]->getId() == id) {
				newBook[i]->viewAll();
				return;
			}
		}
		cout << "We don't have this book in storage." << endl;
	}
	void viewAll() {
		for (int i = 0; i < newBook.size(); i++) {
			newBook[i]->viewAll();
		}
	}
	void editBook() {
		int id;
		cout << "Enter teacher ID to search: ";
		cin >> id;
		for (int i = 0; i < newBook.size(); i++) {
			if (newBook[i]->getId() == id) {
				newBook[i]->viewAll();
				int choice = 0;
				cout << "What information do you want to edit??" << endl;
				cout << "1. ID " << endl;
				cout << "2. Name " << endl;
				cout << "3. Author " << endl;
				cout << "4. Genre " << endl;
				cout << "5. Price" << endl;
				cout << "Enter choice: ";
				cin >> choice;
				if (choice == 1) {
					int id;
					cout << "Enter new id: ";
					cin >> id;
					newBook[i]->setId(id);
				}
				else if (choice == 2) {
					string name;
					cout << "Enter new name: ";
					cin >> name;
					newBook[i]->setName(name);
				}
				else if (choice == 3) {
					string author;
					cout << "Enter new author name: ";
					cin >> author;
					newBook[i]->setAuthor(author);
				}
				else if (choice == 4) {
					string genre;
					cout << "Enter new genre: ";
					cin >> genre;
					newBook[i]->setGenre(genre);
				}
				else if (choice == 5) {
					float price;
					cout << "Enter new price: ";
					cin >> price;
					newBook[i]->setPrice(price);
				}
				else {
					cout << "Please Enter from the list." << endl;
				}
				cout << "Information has been updated successfully!!" << endl;
			}
		}

	}
	void removeBook() {
		int id;
		cout << "Enter Book ID to delete: ";
		cin >> id;
		for (int i = 0; i < newBook.size(); i++) {
			if (newBook[i]->getId() == id) {
				char choice;
				newBook[i]->viewAll();
				cout << "Are you sure you want to remove the book?(Y/N)" << endl;
				cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					delete newBook[i];
					newBook.erase(newBook.begin() + i);
					cout << "Book removed successfully!" << endl;
				}
				else {
					cout << "Remove Book unsuccessful!" << endl;
				}
				return;
			}
		}
		cout << "Book not found!" << endl;
	}

};
class Login {
public:
	
	void adminLogin() {
		string username;
		string password;
		cout << "===================== Admin Login =======================" << endl;
		cout << "Please Enter Username and Password." << endl;
		cout << "Enter Username: " << endl;
		cin >> username;
		cout << "Enter Password: " << endl;
		cin >> password;
		if (username == "Admin" && password == "Admin") {
			cout << "\tLogin Successful." << endl;
		}
		else {
			cout << "Invalid user." << endl;
		}

	}

	void employeeLogin() {
		string username;
		string password;
		string user;
		string pass;
		int count = 0;
		cout << "===================== Employee Login =======================" << endl;
		cout << "Please Enter Username and Password." << endl;
		cout << "Enter Username: " << endl;
		cin >> username;
		cout << "Enter Password: " << endl;
		cin >> password;

		ifstream input("employees.txt");

		while (input >> user >> pass) {
			if (user == username && pass == password) {
				count = 1;
			}
		}
		input.close();
		system("cls");
		if (count == 1) {
			cout << username << " is logged in." << endl;
		}
		else {
			cout << "Wrong" << endl;
		}
	}
	void employeeLogin() {
		string username;
		string password;
		string user;
		string pass;
		int count = 0;
		cout << "===================== Employee Login =======================" << endl;
		cout << "Please Enter Username and Password." << endl;
		cout << "Enter Username: " << endl;
		cin >> username;
		cout << "Enter Password: " << endl;
		cin >> password;

		ifstream input("employees.txt");

		while (input >> user >> pass) {
			if (user == username && pass == password) {
				count = 1;
			}
		}
		input.close();
		system("cls");
		if (count == 1) {
			cout << username << " is logged in." << endl;
		}
		else {
			cout << "Wrong" << endl;
		}
	}
	void registration() {

		string rusername;
		string rpassword;
		string ruser;
		string rpass;
		system("cls");
		cout << "Enter username: " << endl;
		cin >> rusername;
		cout << "Enter password: " << endl;
		cin >> rpassword;

		ofstream f1("employees.txt", ios::app);
		f1 << rusername << "   " << rpassword << endl;
		system("cls");
		cout << "Registered successful." << endl;
	}

};

int main() {
	Manager manager;
	Employee emp;
	Login log;
	int give;
	int choice = 0;

	cout<< "===================== Login Menu =======================" << endl;
	cout << "1. Login as Manager" << endl;
	cout << "2. Login as Employee" << endl;
	cout << "3. Register as new Employee" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1) {
		log.adminLogin();
		return give = 1;
	}
	else if (choice == 2) {
		log.employeeLogin();
		return give = 2;
	}
	else if (choice == 3) {
		log.registration();
		main();
	}
	if (give == 1) {
		manager.managerMenu();
		system("cls");
	}
	else if (give == 2) {
		emp.EmployeeMenu();
		system("cls");
	}
	else {
		cout << "Invalid choice!!!" << endl;
	}
}