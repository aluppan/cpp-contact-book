#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void addContacts();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();

int main() {
	setlocale(LC_ALL, "ru");
	system("cls");
	bool run = true;
	do {
		int menu;
		cout << "----------------------Контактная книга-----------------------------" << endl;
		cout << "\n";
		cout << "Нажмите 1, чтобы добавить контакт" << endl;
		cout << "Нажмите 2, чтобы отредактировать контакт" << endl;
		cout << "Нажмите 3, чтобы удалить контакт" << endl;
		cout << "Нажмите 4, чтобы увидеть все контакты" << endl;
		cout << "Нажмите 5, для поиска контакта" << endl;
		cout << "Нажмите 6, чтобы выйти" << endl << endl;
		cout << "Выбрать: ";
		cin >> menu;
		cin.ignore();
		switch (menu) {
		case 1:
			addContacts();
			break;
		case 2:
			editContact();
			break;
		case 3:
			deleteContact();
			break;
		case 4:
			viewContacts();
			break;
		case 5:
			searchContact();
			break;
		case 6:
			run = false;
			break;
		default:
			cout << "Введите число от 1 до 6!" << endl;
			int main();
		}
	} while (run);
	cout << "Выход...";
}

void addContacts() {		//Добавление контакта
	system("cls");
	string First__name, Surname, Address, Contact, list, name, First__name2, Surname2, Address2, Contact2;
	double counter = 0, number = 0;
	cout << "----------------------Контактная книга-----------------------------" << endl << endl;
	cout << "Не используйте пробелы" << endl;
	cout << "Введите «exit» в поле «Имя», чтобы выйти" << endl << endl;
	cout << "Введите Имя: ";
	getline(cin, First__name);
	if (First__name == "exit")
		main();
	cout << "Введите Фамилию: ";
	getline(cin, Surname);
	cout << "Введите адрес (без пробелов): ";
	getline(cin, Address);
	cout << "Введите номер телефона (без пробелов): ";
	getline(cin, Contact);

	ifstream asd("contact_book.txt");
	while (asd >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
		if (counter == 100) {
			cout << "Максимальное количество контактов достигнуто (100).";
			main();
		}
		else number = counter;
	}
	ofstream adb("contact_book.txt", ios::app);
	number = number + 1;
	adb << number << " " << First__name << " " << Surname
		<< " " << Address << " " << Contact << endl;
	system("pause");
	system("cls");
}

void viewContacts() {	//Все контакты
	system("cls");
	double counter;
	string First__name, Surname, Address, Contact;
	ifstream addressbook("contact_book.txt");
	cout << "ID #" << setw(17) << "Имя" << setw(23) << "Фамилия" << setw(23) << "Адрес" << setw(29) << "Номер" << endl << endl;
	while (addressbook >> counter >> First__name >> Surname >> Address >> Contact) {
		cout << setw(3) << counter << setw(18) << First__name << setw(25) << Surname << setw(25) << Address << setw(30) << Contact << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void searchContact() {	//Поиск по контактам
	system("cls");
	int choice;
	double counter, number;
	string First__name, Surname, Address, Contact, First__name2, Surname2, Address2, Contact2;

	cout << "----------------------Контактная книга-----------------------------" << endl << endl;
	cout << "---Поиск---" << endl;
	cout << "1.) по Имени" << endl;
	cout << "2.) по Фамилии" << endl;
	cout << "3.) по Адресу" << endl;
	cout << "4.) по Номеру" << endl;
	cout << "Выбрать: ";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите Имя: ";
		cin >> First__name;
		cout << endl;
		break;
	case 2:
		cout << "Введите Фамилию: ";
		cin >> Surname;
		cout << endl;
		break;
	case 3:
		cout << "Введите адрес: ";
		cin >> Address;
		cout << endl;
		break;
	case 4:
		cout << "Введите номер: ";
		cin >> Contact;
		cout << endl;
		break;
	default:
		cout << "Введите число от 1 до 4!";
		searchContact();
	}
	ifstream search("contact_book.txt");
	if (choice == 1) {
		while (search >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
			if (First__name == First__name2) {
				cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			}
		}
	}
	if (choice == 2) {
		while (search >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
			if (Surname == Surname2) {
				cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			}
		}
	}
	if (choice == 3) {
		while (search >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
			if (Address == Address2) {
				cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			}
		}
	}
	if (choice == 4) {
		while (search >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
			if (Contact == Contact2) {
				cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void editContact() {		// Функция для редактирования контактов
	system("cls");
	int choice;
	double counter, number;
	string First__name, Surname, Address, Contact, First__name2, Surname2, Address2, Contact2, choice2, choice3;
	ifstream edit("contact_book.txt");
	ofstream temp("Temp.txt", ios::app);
	cout << "Введите ID контакта, которого хотите изменить: ";
	cin >> choice;
	cout << endl;
	if (choice == 0 || choice > 100) {
		cout << "Ошибка, неправильный ID";
		system("pause>0");
		editContact();
	}
	while (edit >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
		if (counter == choice) {
			cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			cout << "Вы хотите изменить этот контакт? y(да) или n(нет) -> ";
			cin >> choice3;
			cout << endl;
		}

		if (choice3 == "n") {
			main();
		}
		if (choice3 == "y") {
			if (counter < choice) {
				temp << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl;
			}
			if (counter == choice) {
				cout << "Введите новое Имя: ";
				cin >> First__name;
				cout << "Введите новую Фамилию: ";
				cin >> Surname;
				cout << "Введите новый адрес: ";
				cin >> Address;
				cout << "Введите новый номер: ";
				cin >> Contact;

				temp << choice << " " << First__name << " " << Surname << " " << Address << " " << Contact << endl;
			}
			if (counter > choice) {
				temp << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl;
			}
		}
	}


	edit.close();
	temp.close();


	if (remove("contact_book.txt") == 0) {
		cout << "Удален" << endl;
	}
	else {
		cout << "Ошибка" << endl;
	}
	if (rename("Temp.txt", "contact_book.txt") == 0) {
		cout << "Переименован" << endl;
	}
	else {
		cout << "Ошибка" << endl;
	}
	system("pause");
	system("cls");
}

void deleteContact() {	//Функция позволяет удалять записи
	system("cls");
	int choice;
	double counter, number;
	string First__name, Surname, Address, Contact, First__name2, Surname2, Address2, Contact2, choice2, choice3;
	ifstream edit("contact_book.txt");
	ofstream temp("Temp.txt", ios::app);
	cout << "Введите ID контакта, которого хотите удалить: ";
	cin >> choice;
	cout << endl;

	while (edit >> counter >> First__name2 >> Surname2 >> Address2 >> Contact2) {
		if (counter == choice) {
			cout << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl << endl;
			cout << "Вы хотите удалить этот контакт? y(да) или n(нет) -> ";
			cin >> choice3;
			cout << endl;
		}
		if (choice3 == "n") {
			main();
		}
		if (counter < choice) {
			temp << counter << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl;
		}
		if (counter > choice) {
			temp << counter - 1 << " " << First__name2 << " " << Surname2 << " " << Address2 << " " << Contact2 << endl;
		}
	}


	edit.close();
	temp.close();


	if (remove("contact_book.txt") == 0) {
		cout << "Удален" << endl;
	}
	else {
		cout << "Ошибка" << endl;
	}
	if (rename("Temp.txt", "contact_book.txt") == 0) {
		cout << "Переименован" << endl;
	}
	else {
		cout << "Ошибка" << endl;
	}
	system("pause");
	system("cls");
}

