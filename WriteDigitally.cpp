#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream>
#include<windows.h>

using namespace std;

ofstream ofs;
ifstream ifs;

class Story{
	char title[50];
	string line ;
	public:
		virtual void setIncident()
		{
			Write:
			int i=1;
			gotoxy(55,2);
			cout<<"Enter title of story : ";
			fflush(stdin);
			gotoxy(55,3);
			cin.getline(title,sizeof(title));
			ifs.open(title,ios::in);
			if(ifs.is_open())
			{
				gotoxy(55,5);	
				cout<<"Story with this title already exist.";
				gotoxy(55,6);
				cout<<"Please reconsider the title name.";
				ifs.close();
				getch();
				system("cls");
				goto Write;
			}
			else
			{
				//ifs.close();
				ofs.open(title,ios::out|ios::app);
			}
			gotoxy(55,6);
			cout<<"Write your story : ";
			gotoxy(30,8);
			getline(cin, line);
	        while(line != "Quit")
	        {
	        	ofs<<endl;
	        	ofs.write(line.data(),line.size());
	        	gotoxy(30,8+i);
	        	getline(cin, line);
	        	i = i + 1;
			}
			ofs.close();
		}
		virtual void showIncident()
		{
			show:
			system("cls");
			char fileName[50];
			int i=1;
			//system("md new");
			cout<<"List of files......"<<endl<<endl;
			system("dir /b");
			cout<<endl<<endl<<"Enter file name to be opened : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			ifs.open(fileName,ios::in);
			if(!ifs.is_open())
			{
				system("cls");
				gotoxy(55,4);
				cout<<"File name doesnt exist.";
				cout<<"Please re enter the file name.";
				getch();
				goto show;
			}
			else
			{
				system("cls");
				gotoxy(55,2);
				cout<<"Title : "<<fileName<<endl;
			//	ifs>>text;
				while(getline(ifs,line))
				{
					gotoxy(35,4+i);
					cout<<line;
					i = i + 1 ;
				}
				ifs.close();
			}
			
		}
		virtual void appendIncident()
		{
			append:
			system("cls");
			char fileName[50];
			int i = 1;;
			cout<<"List of files......"<<endl<<endl;
			system("dir /b");
			cout<<endl<<endl<<"Enter file name to be opened : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			ifs.open(fileName,ios::in);
			if(!ifs.is_open())
			{
				system("cls");
				gotoxy(55,4);
				cout<<"File name doesnt exist.";
				cout<<"Please re enter the file name.";
				getch();
				goto append;
			}
			else
			{
				system("cls");
				gotoxy(55,2);
				cout<<"Title : "<<fileName;
				while(getline(ifs,line))
				{
					gotoxy(35,4+i);
					cout<<line;
					i = i + 1;
				}
				ifs.close();
			}
			ifs.close();
			ofs.open(fileName,ios::out|ios::app);
			gotoxy(35,5+i);
			getline(cin, line);
	        while(line != "Quit")
	        {
	        	ofs<<endl;
	        	ofs.write(line.data(),line.size());
	        	gotoxy(35,5+i);
	        	getline(cin, line);
	        	i = i + 1;
			}
			ofs.close();
		}
		virtual void deleteIncident()
		{
			system("cls");
			char fileName[50];
			system("dir /b");
			cout<<endl<<endl<<"Enter file you want to delete : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			remove(fileName);
		}
		virtual void gotoxy(int x, int y)           //definition of gotoxy function//                                               
		{
		 COORD pos ={x,y};
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		
		
};

class Poem:public Story{
	char title[50];
	string line ;
	public:
		void setIncident()
		{
			Write:
			int i=1;	
			gotoxy(55,2);
			cout<<"Enter title of Poem : ";
			fflush(stdin);
			gotoxy(55,3);
			cin.getline(title,sizeof(title));
			ifs.open(title,ios::in);
			if(ifs.is_open())
			{
				gotoxy(55,5);
				cout<<"Poem with this title already exist.";
				gotoxy(55,6);
				cout<<"Please reconsider the title name.";
				ifs.close();
				getch();
				system("cls");
				goto Write;
			}
			else
			{
				//ifs.close();
				ofs.open(title,ios::out|ios::app);
			}
			gotoxy(55,6);
			cout<<"Write your Poem : ";
			gotoxy(45,8);
			getline(cin, line);
	        while(line != "Quit")
	        {
	        	ofs<<endl;
	        	ofs.write(line.data(),line.size());
	        	gotoxy(45,8+i);
	        	getline(cin, line);
	        	i = i + 1 ;
			}
			ofs.close();
		}
		void showIncident()
		{
			system("cls");
			char fileName[50];
			//system("md new");
			cout<<"List of files......"<<endl<<endl;
			system("dir /b");
			cout<<endl<<endl<<"Enter file name to be opened : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			ifs.open(fileName,ios::in);
			//ifs>>title;
			system("cls");
			cout<<"Title : "<<fileName<<endl;
		//	ifs>>text;
			while(getline(ifs,line))
			{
				cout<<line<<endl;
			}
			ifs.close();
		}
		void appendIncident()
		{
			system("cls");
			char fileName[50];
			cout<<"List of files......"<<endl<<endl;
			system("dir /b");
			cout<<"Enter file name to be opened : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			ifs.open(fileName,ios::in);
			system("cls");
			cout<<"Title : "<<fileName<<endl;
			while(getline(ifs,line))
			{
				cout<<line<<endl;
			}
			ifs.close();
			cout<<"\n\t";
			ifs.close();
			ofs.open(fileName,ios::out|ios::app);
			getline(cin, line);
	        while(line != "Quit")
	        {
	        	ofs<<endl;
	        	ofs.write(line.data(),line.size());
	        	getline(cin, line);
			}
			ofs.close();
		}
		void deleteIncident()
		{
			system("cls");
			char fileName[50];
			system("dir /b");
			cout<<endl<<endl<<"Enter file you want to delete : ";
			fflush(stdin);
			cin.getline(fileName,sizeof(fileName));
			remove(fileName);
		}
		void gotoxy(int x, int y)           //definition of gotoxy function//                                               
		{
		 COORD pos ={x,y};
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		
		int wherex()
		{
		  CONSOLE_SCREEN_BUFFER_INFO csbi;
		  COORD                      result;
		  if (!GetConsoleScreenBufferInfo(
		         GetStdHandle( STD_OUTPUT_HANDLE ),
		         &csbi
		         ))
			return -1;
		  return result.X;
		}
		int wherey()
		{
		  CONSOLE_SCREEN_BUFFER_INFO csbi;
		  COORD                      result;
		  if (!GetConsoleScreenBufferInfo(
		         GetStdHandle( STD_OUTPUT_HANDLE ),
		         &csbi
		         ))
		    return -1;
		  return result.Y;
		}
};

class ToDoList{
	int id;
	string toDo;
	int mark;
	string date;
	public:
		void setLists(ToDoList T)
		{
			setList:
			int found=0;
			int ID ;
			string LIST , DATE;
			int MARK;
			char ch;
			date=__DATE__;
			date = "*" + date;
			gotoxy(55,2);
			cout<<date;
			gotoxy(45,4);
			cout<<"ID";
			gotoxy(55,4);
			cout<<"Work to be done ";
			gotoxy(45,5);
			cin>>id;
			gotoxy(55,5);
			fflush(stdin);
			getline(cin,toDo);
			mark = 0;
			ifstream ifs;
			ifs.open("ToDoList.bin",ios::in);
			if(!ifs.is_open())
			{
				ifs.close();
				ofstream ofs;
				
				ofs.open("ToDoList.bin",ios::out|ios::app);
				ofs<<" "<<endl;
				ofs.write(date.data(),date.size());
				ofs<<endl;
				ofs.write(toDo.data(),toDo.size());
				ofs<<endl;
				ofs<<id<<endl;
				ofs<<mark<<endl;
				ofs.close();
			}
			else
			{
				ifs>>ch;
				getline(ifs,DATE);
				getline(ifs,LIST);
				ifs>>ID;
				ifs>>MARK;
				while(ifs)
				{
					if(ID == id)
					{
						found = found + 1;
					}
					ifs>>ch;
					getline(ifs,DATE);
					getline(ifs,LIST);
					ifs>>ID;
					ifs>>MARK;
				}
				ifs.close();
			}
			if(found==0)
			{
				ofstream ofs;
				ofs.open("ToDoList.bin",ios::out|ios::app);
				ofs<<" "<<endl;
				ofs.write(date.data(),date.size());
				ofs<<endl;
				ofs.write(toDo.data(),toDo.size());
				ofs<<endl;
				ofs<<id<<endl;
				ofs<<mark<<endl;
				ofs.close();
			}
			else
			{
				system("cls");
				gotoxy(45,7);
				cout<<"(: List with given id already exist. Please reconsider list id.";
				getch();
				goto setList;
			}
		}
		
		void displayList(ToDoList T)
		{
			int i = 1;
			char ch , ch1;
			int ID;
			gotoxy(40,4);
			cout<<"DATE";
			gotoxy(60,4);
			cout<<"ID";
			gotoxy(70,4);
			cout<<"Work to be done ";
			ifstream ifs;
			ifs.open("ToDoList.bin",ios::in);
			ifs>>ch;
			getline(ifs,date);
			getline(ifs,toDo);
			ifs>>id;
			ifs>>mark;
			while(ifs)
			{
				gotoxy(40,5+i);
				cout<<date;
				gotoxy(60,5+i);
				cout<<id;
				gotoxy(70,5+i);
				cout<<toDo;
				
				//cout<<"Marking : "<<mark<<endl<<endl;
				ifs>>ch;
				getline(ifs,date);
				getline(ifs,toDo);
				ifs>>id;
				ifs>>mark;
				i = i + 1;
			}
			ifs.close();
			
			gotoxy(40,6+i);
			cout<<"Enter (Y/y) if you have completed any task, else exit .";
			ch1 = getch();
			if(ch1=='Y' || ch1 == 'y')
			{
				gotoxy(40,7+i);
				cout<<"Enter id no of task you have completed : ";
				cin>>ID;
				ifs.open("ToDoList.bin",ios::in);
				ofstream ofs;
				ofs.open("New.bin",ios::out|ios::app);
				ifs>>ch;
				getline(ifs,date);
				getline(ifs,toDo);
				ifs>>id;
				ifs>>mark;
				while(ifs)
				{
					if(ID!=id)
					{
						ofs<<" "<<endl;
						ofs.write(date.data(),date.size());
						ofs<<endl;
						ofs.write(toDo.data(),toDo.size());
						ofs<<endl;
						ofs<<id<<endl;
						ofs<<mark<<endl;
					}
					ifs>>ch;
					getline(ifs,date);
					getline(ifs,toDo);
					ifs>>id;
					ifs>>mark;
				}
				ifs.close();
				ofs.close();
				remove("ToDoList.bin");
				rename("New.bin","ToDoList.bin");
				gotoxy(40,8+i);
				cout<<"Completed task has been removed successfully.";
			}
		}
		void gotoxy(int x, int y)           //definition of gotoxy function//                                               
		{
		 COORD pos ={x,y};
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
};

int main()
{
	system("cls");
	char mainMenuOption;
	Story *s , S;
	Poem p;
	ToDoList T;
	p.gotoxy(55,10);
	cout<<"==============================";
	p.gotoxy(63,9);
	cout<<"DIGITAL WRITER";
	p.gotoxy(55,8);
	cout<<"==============================";
	p.gotoxy(60,12);
	cout<<"1. Story";
	p.gotoxy(60,13);
	cout<<"2. Poem";
	p.gotoxy(60,14);
	cout<<"3. To do list";
	p.gotoxy(60,15);
	cout<<"4. Exit";
	p.gotoxy(60,17);
	cout<<"Enter your option : ";
	cin>>mainMenuOption;
	if(mainMenuOption=='1')
	{
		StoryMenu:
		system("cls");
		char storyMenuOption;
		s = &S;
		s->gotoxy(55,8);
		cout<<"==============================";
		s->gotoxy(63,9);
		cout<<"STORY MENU";
		s->gotoxy(55,10);
		cout<<"==============================";
		s->gotoxy(60,12);
		cout<<"1. New story.";
		s->gotoxy(60,13);
		cout<<"2. Display story";
		s->gotoxy(60,14);
		cout<<"3. Append story";
		s->gotoxy(60,15);
		cout<<"4. Delete story";
		s->gotoxy(60,16);
		cout<<"5. Back";
		s->gotoxy(60,17);
		cout<<"6. Exit";
		s->gotoxy(60,19);
		cout<<"Enter your option : ";
		cin>>storyMenuOption;
		if(storyMenuOption=='1')
		{
			system("cls");
			s->setIncident();
			cout<<"Press any key to continue .";
			getch();
			goto StoryMenu;
		}
		else if(storyMenuOption=='2')
		{
			system("cls");
			s->showIncident();
			cout<<endl<<endl<<"Press any key to continue .";
			getch();
			goto StoryMenu;
		}
		else if(storyMenuOption=='3')
		{
			system("cls");
			s->appendIncident();
			cout<<endl<<endl<<"Press any key to continue .";
			getch();
			goto StoryMenu;
		}
		else if(storyMenuOption=='4')
		{
			system("cls");
			s->deleteIncident();
			getch();
			cout<<endl<<"File deleted successfully ."<<endl<<"Press any key to continue .";
			getch();
			goto StoryMenu;
		}
		else if(storyMenuOption=='5')
		{
			system("cls");
			main();
		}
		else if(storyMenuOption=='6')
		{
			system("cls");
			s->gotoxy(55,14);
			cout<<"Thank you for using DIGITAL WRITER.";
			p.gotoxy(55,15);
			cout<<"Press any key to exit.";
			getch();
			system("cls");
			exit(0);
			return 0;
		}
		else
		{
			system("cls");
			s->gotoxy(55,15);
			cout<<"Please enter valid option.";
			s->gotoxy(55,14);
			cout<<"Press any key to continue.";
			getch();
			goto StoryMenu;
		}
	}
	else if(mainMenuOption=='2')
	{
		PoemMenu:
		system("cls");
		s = &p;
		char poemMenuOption;
		s->gotoxy(55,8);
		cout<<"==============================";
		s->gotoxy(63,9);
		cout<<"POEM MENU";
		s->gotoxy(55,10);
		cout<<"==============================";
		s->gotoxy(60,12);
		cout<<"1. New poem.";
		s->gotoxy(60,13);
		cout<<"2. Display poem";
		s->gotoxy(60,14);
		cout<<"3. Append poem";
		s->gotoxy(60,15);
		cout<<"4. Delete poem";
		s->gotoxy(60,16);
		cout<<"5. Back";
		s->gotoxy(60,17);
		cout<<"6. Exit";
		s->gotoxy(60,19);
		cout<<"Enter your option : ";
		cin>>poemMenuOption;
		if(poemMenuOption=='1')
		{
			system("cls");
			s->setIncident();
			cout<<endl<<endl<<"Press any key to continue .";
			getch();
			goto PoemMenu;
		}
		else if(poemMenuOption=='2')
		{
			system("cls");
			s->showIncident();
			cout<<endl<<endl<<"Press any key to continue .";
			getch();
			goto PoemMenu;
		}
		else if(poemMenuOption=='3')
		{
			system("cls");
			s->appendIncident();
			cout<<endl<<endl<<"Press any key to continue .";
			getch();
			goto PoemMenu;
		}
		else if(poemMenuOption=='4')
		{
			system("cls");
			s->deleteIncident();
			getch();
			cout<<endl<<"File deleted successfully ."<<endl<<"Press any key to continue .";
			getch();
			goto PoemMenu;
		}
		else if(poemMenuOption=='5')
		{
			system("cls");
			main();
		}
		else if(poemMenuOption=='6')
		{
			system("cls");
			s->gotoxy(55,14);
			cout<<"Thank you for using DIGITAL WRITER.";
			s->gotoxy(55,15);
			cout<<"Press any key to exit.";
			getch();
			system("cls");
			exit(0);
			return 0;
		}
		else
		{
			system("cls");
			p.gotoxy(55,15);
			cout<<"Please enter valid option.";
			p.gotoxy(55,14);
			cout<<"Press any key to continue.";
			getch();
			goto PoemMenu;
		}
	}
	else if(mainMenuOption=='3')
	{
		system("cls");
		ToDoMenu:
		system("cls");
		char todoMenuOption;
		T.gotoxy(55,8);
		cout<<"==============================";
		T.gotoxy(63,9);
		cout<<"TO DO MENU";
		T.gotoxy(55,10);
		cout<<"==============================";
		T.gotoxy(60,12);
		cout<<"1. Add list.";
		T.gotoxy(60,13);
		cout<<"2. Display list";
		T.gotoxy(60,14);
		cout<<"4. Back";
		T.gotoxy(60,15);
		cout<<"5. Exit";
		T.gotoxy(60,16);
		cout<<"Enter your option : ";
		
		cin>>todoMenuOption;
		
		if(todoMenuOption=='1')
		{
			char add;
			system("cls");
			do
			{
				T.setLists(T);
				T.gotoxy(45,7);
				cout<<"Enter (y/Y) to add another list. Else exit.";
				add = getch();
				system("cls");
			}while(add=='y' || add=='Y');
			T.gotoxy(45,9);
			cout<<"Press any key to continue .";
			getch();
			goto ToDoMenu;
		}
		else if(todoMenuOption=='2')
		{
			system("cls");
			T.displayList(T);
			cout<<"Press any key to continue.";
			getch();
			goto ToDoMenu;
		}
		else if(todoMenuOption=='3')
		{
			system("cls");
			main();
		}
		else if(todoMenuOption=='4')
		{
			system("cls");
			T.gotoxy(55,14);
			cout<<"Thank you for using DIGITAL WRITER.";
			T.gotoxy(55,15);
			cout<<"Press any key to exit.";
			getch();
			system("cls");
			exit(0);
			return 0;
		}
		else
		{
			system("cls");
			T.gotoxy(55,15);
			cout<<"Please enter valid option.";
			T.gotoxy(55,14);
			cout<<"Press any key to continue.";
			getch();
			goto ToDoMenu;
		}
		
	}
	else if(mainMenuOption=='4')
	{
		system("cls");
		p.gotoxy(55,14);
		cout<<"Thank you for using DIGITAL WRITER.";
		p.gotoxy(55,15);
		cout<<"Press any key to exit.";
		getch();
		system("cls");
		exit(0);
		return 0;
	}
	else
	{
		system("cls");
		p.gotoxy(55,15);
		cout<<"Please enter valid option.";
		p.gotoxy(55,14);
		cout<<"Press any key to continue.";
		getch();
		main();
	}
	return 0;
}
