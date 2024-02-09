#include "header.h"

//function Declaration
void login();
void registeration();
void forgot();
void update();

int main()
{
	int c;
	cout << "\t\t\t________________________________________" << endl << endl << endl;
	cout << "\t\t\t_______ WELCOME  TO  LOGIN  PAGE _______" << endl << endl << endl;
	cout << "\t\t\t__________    MAIN  MENU       _________" << endl << endl;
	cout << "                                                               " << endl << endl;
	cout << "                                                               " << endl << endl;
	cout << "\t| Press 1 to LOGIN                |" << endl;
	cout << "\t| Press 2 to SIGN_UP              |" << endl;
	cout << "\t| Press 3 if YOU FORGOT PASSWORD  |" << endl;
	cout << "\t| Press 4 to CHANGE  PASSWORD     |" << endl;
	cout << "\t| Press 5 to EXIT                 |" << endl;
	cout << "\n\t\t\t Please Enter your choice : ";
	cin >> c;
	switch (c)
	{

	case 1:
		login();
		break;

	case 2:
		registeration();
		break;

	case 3:
		forgot();
		break;
	case 4:
		update();
		break;
	case 5:
		cout << "\n\t\t\t\t  THANKS YOU!   " << endl << endl;
		break;

	default:
		system("cls");

		cout << "\t\t\t Please select from the options given above  " << endl << endl;
		main();
	}
}

//LOGIN FUNCTION
void login()
{
	int count = 0, ch;
	string user_id, id, pass, pet;
	char password[20];
	system("cls");
	cout << "\t\t\t   * PLEASE ENTER YOUR USERNAME AND PASSWORD *   " << endl;

	cout << "\t\t\t   USERNAME : ";
	cin >> user_id;

	cout << "\t\t\t   PASSWORD : ";

	for (int i = 0; i >= 0;)
	{
		ch = getch();

		if (ch != 8 && ch != 13)//13 is ascii of carriage return mean press enter or start of line
		{
			cout << "*";
			password[i] = ch;//is a function used to push back the value in password as a parameter
			i++;
		}
		else if (ch == 8) // if backspace is presssed
		{
			cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
			i--;
		}

		else if (ch == 13)
		{
			password[i] = '\0'; // if enter is pressed, last character in Password[] becomes null
			break;         // for end of string
		}
		else
		{
			break;

		}

	}
	// cout<<endl<<password;
	ifstream input("records.txt");
	while (input >> id >> pass >> pet)
	{
		if (id == user_id && pass == password)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << user_id << "\n\n CONGRATULATION! YOUR LOGIN IS SUCCESSFULL.\n THANKS FOR LOGGING IN! " << endl;
		main();

	}
	else
	{
		cout << "\n LOGIN ERROR! \n PLEASE CHECK YOUR USERNAME AND PASSWORD " << endl;
		main();
	}

}

//Registeration FUNCTION
void registeration()
{

	int count = 0, found = 0;
	string ruser_id, rid, rpass, rpet;
	char rpassword[20], ch;
	system("cls");

	cout << "\t\t\t Enter USERNAME : ";
	cin >> ruser_id;
p:
	cout << "\t\t\t Enter PASSWORD : ";

	for (int i = 0; i >= 0;)
	{
		ch = getch();
		if (ch != 8 && ch != 13)
		{
			cout << "*";
			rpassword[i] = ch;//is a function used to push back the value in password as a parameter
			i++;
		}
		else if (ch == 8) // if backspace is presssed
		{
			cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
			i--;
		}
		else if (ch == 13)
		{
			rpassword[i] = '\0'; // if enter is pressed, last character in match[] becomes null
			break;         // for end of string
		}
		else
		{
			break;
		}

	}
	string x = rpassword;
	//cout<<x;
	for (int i = 0; i <= x.size(); i++)
	{
		if (isupper(rpassword[i]) == true)
		{
			count++;
		}

		else if (isdigit(rpassword[i]) == true)
		{
			found++;
		}

	}
	//condition check if true 
	if ((count < 2) || (found < 2))
	{
		cout << "\nPlease Make Sure That Your Password contains an Uppercase letter and Digits! Try again\n";
		count = 0;
		found = 0;
		goto p;
	}

	cout << "\n\t\t\t Enter Favourite Pet : ";
	cin >> rpet;

	//Saving data in records
	ofstream f1("records.txt", ios::app);
	f1 << ruser_id << ' ' << rpassword << ' ' << rpet << endl;
	system("cls");

	//Successfull registeration
	cout << "\n\t\t\t REGISTERATION IS SUCCESSFULL! " << endl;
	main();

}

//Forget password!
void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t FORGOT PASSWORD? NO WORRIES!\n " << endl;
	cout << "Press 1 to search your ID by USERNAME " << endl;
	cout << "Press 2 to go back to the Main Menu\n " << endl;
	cout << "\t\t\t Enter your choice : ";
	cin >> option;

	switch (option)
	{

	case 1:
	{
		int count = 0;
		string suser_id, sid, spass, pet, spet;

		cout << "\n\t\t\t Enter the USERNAME you remembered : ";
		cin >> suser_id;
		cout << "\t\t\t Enter you fav pet : ";
		cin >> pet;
		ifstream f2("records.txt");
		while (f2 >> sid >> spass >> spet)
		{
			if (sid == suser_id && spet == pet)
			{
				count = 1;
				break;
			}
		}
		f2.close();

		if (count == 1)
		{
			cout << "\n\n YOUR ACCOUNT IS FOUND! " << endl;
			cout << "\n\n YOUR PASSWORD IS : " << spass << endl;
			main();
		}
		else
		{
			cout << "\n\t SORRY! YOUR ACCOUNT IS NOT FOUND " << endl;
			main();
		}
		break;
	}

	case 2:
	{
		main();
	}

	default:
		cout << "\t\t\t WRONG CHOICE! PLEASE TRY AGAIN " << endl;
		forgot();

	}
}

// CHANGE PASSWORD FUNCTION
void update()
{
	int count = 0;
	int found = 0, letter = 0;
	string change, c, d, e;
	char change1[20], ch, dh;
	int choice;
	system("cls");
	cout << "\nPress 1 to change your password! " << endl;
	cout << "Press 2 to go back to the Main Menu! " << endl;
	cout << "\t\t\t Enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "\n\t\tENTER YOUR USERNAME: ";
		cin >> change;
		cout << "\t\tENTER YOUR PASSWORD: ";

		for (int i = 0; i >= 0;)
		{
			dh = getch();
			if (dh != 8 && dh != 13)
			{
				cout << "*";
				change1[i] = dh;//is a function used to push back the value in password as a parameter
				i++;
			}
			else if (dh == 8) // if backspace is presssed
			{
				cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
				i--;
			}
			else if (dh == 13)
			{
				change1[i] = '\0'; // if enter is pressed, last character in match[] becomes null
				break;         // for end of string
			}
			else
			{
				break;
			}
			//end of loop  
		}

		ofstream nfile;
		nfile.open("temp.txt");
		ifstream read1;
		read1.open("records.txt");
		read1 >> c >> d >> e;
		while (!read1.eof())
		{
			//cout<<d<<"  "<<change1<<endl;
			if (change == c && change1 == d)
			{
				count++;
				//  	cout<<count;
				cout << "\n\nYOU HAVE SUCCESSFULLY VERIFIED YOUR SELF.";
			p:
				cout << "\n\n\t\tENTER YOUR NEW PASSWORD : ";

				for (int i = 0; i >= 0;)
				{
					dh = getch();
					if (dh != 8 && dh != 13)
					{
						cout << "*";
						change1[i] = dh;//is a function used to push back the value in password as a parameter
						i++;
					}
					else if (dh == 8) // if backspace is presssed
					{
						cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
						i--;
					}
					else if (dh == 13)
					{
						change1[i] = '\0'; // if enter is pressed, last character in match[] becomes null
						break;         // for end of string
					}
					else
					{
						break;
					}

				}
				string y = change1;

				for (int i = 0; i <= y.size(); i++)
				{
					if (isupper(change1[i]) == true)
					{
						letter++;
					}
					if (isdigit(change1[i]) == true)
					{
						found++;
					}
				}
				//condition check if true 
				if ((letter < 2) || (found < 2))
				{
					cout << "\nPlease Make Sure That Your Password contains an Uppercase letter and Digits!try again\n";
					found = 0;
					count = 0;
					goto p;
				}
				nfile << c << ' ' << change1 << ' ' << e << "\n";
				cout << "\n\nYOUR RECORD IS UPDATED!\n";
			}
			//if password do not matched!  
			else
			{
				nfile << c << ' ' << d << ' ' << e << "\n";
			}
			read1 >> c >> d >> e;
		}
		read1.close();//close the read1 file
		nfile.close();

		if (count == 1)
		{
			remove("records.txt");
			cout << "PASSWORD IS CHANGED SUCCESSFULLY\n";
			rename("temp.txt", "records.txt");
			// cout<<"Removed successfully\n";
			cout << "NOW USE NEW PASSWORD FOR ACCESS!\n";
			main();
		}
		else if (count == 0)
		{

			cout << "\n\t\t\t WRONG INPUT! PLEASE CHECK YOUR USERNAME AND PASSWORD!";
			getch();
			update();
		}
		break;
	}

	case 2:
	{
		main();
		break;
	}

	default:
		cout << "\t\t\t Wrong choice! Please try again " << endl;
		update();

	}

}

