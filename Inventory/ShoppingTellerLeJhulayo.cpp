#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define Enter 13
#define TAB 9
#define Backspace 8

using namespace std;

class Purchase{
	string Date;
	string productName;
	string productId;
	int noOfProd;
	float price;
	float totalPrice;
	
	public:
		virtual void setItemDetails()
		{
			cout<<"Enter product name : ";
			fflush(stdin);
			getline(cin,productName);
			cout<<"Enter product id : ";
			fflush(stdin);
			getline(cin,productId);
			cout<<"No of products : ";
			cin>>noOfProd;
			cout<<"Price per "<<productName<<" : ";
			cin>>price;
			totalPrice = price * noOfProd;
		}
		virtual void displayItemDetails(int i)
		{
			gotoxy(1,6+i);
			cout<<Date;
			gotoxy(19,6+i);
			cout<<productName;
			gotoxy(39,6+i);
			cout<<productId;
			gotoxy(59,6+i);
			cout<<noOfProd;
			gotoxy(79,6+i);
			cout<<price;
			gotoxy(99,6+i);
			cout<<totalPrice;
		}
		virtual void gotoxy(int x, int y)           //definition of gotoxy function//                                               
		{
		 COORD pos ={x,y};
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		virtual void setDate(string date)
		{
			Date = date;
		}
		virtual string getDate()
		{
			return Date;
		}
		virtual void setProductName(string name)
		{
			productName = name;
		}
		virtual void updateNoOfProd(int n)
		{
			noOfProd = noOfProd - n;
		}
		virtual string getProductName()
		{
			return productName;
		}
		virtual void setProdId(string id)
		{
			productId = id;
		}
		virtual string getProductId()
		{
			return productId;
		}
		virtual void setNoOfProd(int no)
		{
			noOfProd = no;
		}
		virtual int getNoOfproduct()
		{
			return noOfProd;
		}
		virtual void setPrice(double p)
		{
			price = p;
		}
		virtual double getPerPrice()
		{
			return price;
		}
		virtual void setTotalPrice(double total)
		{
			totalPrice = total;
		}
		virtual double getTotalPrice()
		{
			return totalPrice;
		}
		friend ofstream &operator<<(ofstream &ofs , Purchase *P);
		friend ifstream &operator>>(ifstream &ifs , Purchase *P);
};

ofstream &operator<<(ofstream &ofs , Purchase *P)
{
	string date , name , id , temp; 
	int no ; 
	double Price , total;
	date = P->getDate();
	name = P->getProductName();
	id = P->getProductId();
	no = P->getNoOfproduct();
	Price = P->getPerPrice();
	total = P->getTotalPrice();
	ofs<<" "<<endl;
	ofs.write(date.data(),date.size());
	ofs<<endl; 
	ofs.write(name.data(),name.size());
	ofs<<endl;
	ofs.write(id.data(),id.size());
	ofs<<endl;
	ofs<<no<<endl;
	ofs<<Price<<endl;
	ofs<<total<<endl;
	return ofs;
}

ifstream &operator>>(ifstream &ifs , Purchase *P)
{
	string date , name , id , temp; 
	int no ; 
	double Price , total;
	char s;
	ifs>>s;
	getline(ifs,date);	
	getline(ifs,name);
	getline(ifs,id);
	ifs>>no;
	ifs>>Price;
	ifs>>total;
	P->setDate(date);
	P->setProductName(name);
	P->setProdId(id);
	P->setNoOfProd(no);
	P->setPrice(Price);
	P->setTotalPrice(total);
	return ifs;
}

class Stock:public Purchase{
	string Date;
	string productName;
	string productId;
	int noOfProd;
	double price;
	double totalPrice;
	
	public:
		void setItemDetails()
		{
			cout<<"Enter product name : ";
			fflush(stdin);
			getline(cin,productName);
			cout<<"Enter product id : ";
			fflush(stdin);
			getline(cin,productId);
			cout<<"No of products : ";
			cin>>noOfProd;
			cout<<"Price per "<<productName<<" ";
			cin>>price;
			totalPrice = price * noOfProd;
		}
		void displayItemDetails(int i)
		{
			gotoxy(1,7+i);
			cout<<productName;
			gotoxy(19,7+i);
			cout<<productId;
			gotoxy(39,7+i);
			cout<<noOfProd;
			gotoxy(59,7+i);
			cout<<price;
			/*cout<<"Product Name : "<<productName<<endl;
			cout<<"Product id : "<<productId<<endl;
			cout<<"No of products : "<<noOfProd<<endl;*/
			//cout<<"Per price : "<<price<<endl;
			//cout<<"Total price : "<<totalPrice<<endl;
		}
		void gotoxy(int x, int y)           //definition of gotoxy function//                                               
		{
		 COORD pos ={x,y};
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		string getDate()
		{
			return Date;
		}
		void setDate(string date)
		{
			Date = date;
		}
		string getProductName()
		{
			return productName;
		}
		void setProductName(string name)
		{
			productName = name;
		}
		string getProductId()
		{
			return productId;
		}
		void setProdId(string id)
		{
			productId = id;
		}
		int getNoOfproduct()
		{
			return noOfProd;
		}
		void setNoOfProd(int no)
		{
			noOfProd = no;
		}
		void updateNoOfProd(int n)
		{
			noOfProd = noOfProd - n;
		}
		double getPerPrice()
		{
			return price;
		}
		void setPrice(double p)
		{
			price = p;
		}
		double getTotalPrice()
		{
			return totalPrice;
		}
		void setTotalPrice(double total)
		{
			totalPrice = total;
		}
		
};
class Sales:public Purchase{
	string Date;
	string productName;
	string productId;
	int noOfProd;
	double price;
	double tax , discount;
	double totalPrice;
	
	public:
		void displayItems()
		{
			ifstream ifs;
			int i=1;
			ifs.open("Sale.bin",ios::in);
			if(!ifs.is_open())
			{
				gotoxy(1,10);
				cout<<"(: Error opening the file."<<endl;
			}
			ifs.seekg(0,ios::end);
			int length = ifs.tellg();
			if(length==0)
			{
				gotoxy(1,10);
				cout<<"File is empty.";
				gotoxy(1,11);
				cout<<"No records found";
			}
			else
			{
				ifs.seekg(0,ios::beg);
				char c;
				ifs>>c;
				int i = 1;
				//ifs>>Date;
				getline(ifs,Date);
				getline(ifs,productName);
				//ifs>>productName;
				getline(ifs,productId);
				//ifs>>productId;
				ifs>>noOfProd;
				ifs>>price;
				ifs>>totalPrice;
				gotoxy(55,1);
				cout<<"SALES ITEMS";
				gotoxy(1,3);
				cout<<"Date of sale";
				gotoxy(19,3);
				cout<<"Item Name";
				gotoxy(39,3);
				cout<<"Product id";
				gotoxy(59,3);
				cout<<"No of products";
				gotoxy(79,3);
				cout<<"Per Price";
				gotoxy(99,3);
				cout<<"Total price";
				gotoxy(1,5);
				cout<<"------------------------------------------------------------------------------------------------------------------";
				while(ifs)
				{
					/*gotoxy(10,2);
					cout<<"Item ";*/
					i=i+1;
					gotoxy(1,7+i);
					cout<<Date;
					gotoxy(19,7+i);
					cout<<productName;
					gotoxy(39,7+i);
					cout<<productId;
					gotoxy(59,7+i);
					cout<<noOfProd;
					gotoxy(79,7+i);
					cout<<price;
					gotoxy(99,7+i);
					cout<<totalPrice;
					ifs>>c;
					//ifs>>Date;
					getline(ifs,Date);
					getline(ifs,productName);
					//ifs>>productName;
					getline(ifs,productId);
					//ifs>>productId;
					ifs>>noOfProd;
					ifs>>price;
					ifs>>totalPrice;
					i = i + 1;
				}
			}
			ifs.close();
		}
		void SalesRecord()
		{
			ofstream ofs;
			ofs.open("Sale.bin",ios::out|ios::app);
			ofs<<" "<<endl;
			ofs.write(Date.data(),Date.size());
			ofs<<endl; 
			ofs.write(productName.data(),productName.size());
			ofs<<endl;
			ofs.write(productId.data(),productId.size());
			ofs<<endl;
			ofs<<noOfProd<<endl;
			ofs<<price<<endl;
			ofs<<totalPrice<<endl;
		}
		string getDate()
		{
			return Date;
		}
		void setDate(string date)
		{
			Date = date;
		}
		string getProductName()
		{
			return productName;
		}
		void setProductName(string name)
		{
			productName = name;
		}
		string getProductId()
		{
			return productId;
		}
		void setProdId(string id)
		{
			productId = id;
		}
		int getNoOfproduct()
		{
			return noOfProd;
		}
		void setNoOfProd(int no)
		{
			noOfProd = no;
		}
		double getPerPrice()
		{
			return price;
		}
		void setPrice(double p)
		{
			price = p;
		}
		void setTax(double t)
		{
			tax = t;
		}
		double getTax()
		{
			return tax;
		}
		void setTotal(double t)
		{
			totalPrice = t;
		}
		void setTotalPrice(double p , int n , double T)
		{
			double total = p * n;
			double taxAmt = (total * T) / 100;
			totalPrice = total + taxAmt;	
		}
		double getTotalPrice()
		{
			return totalPrice;
		}
};

int Exit()
{
	system("cls");
	cout<<"Thankyou for using shopping teller"<<endl;
	cout<<"Press any key to exit"<<endl;
	getch();
	system("cls");
	exit(0);
	return 0;
}

void setPassword(char pwd[50])
{
	int i=0;
	int j=1;
	char ch;
	while(1)
	{
		//gotoxy(55+j,4);
		ch=getch();
		if(ch==Enter || ch==TAB)
		{
			pwd[i]='\0';
			break;
		}
		else if(ch==Backspace)
	 	{
			if(i>0)
		 	{
				i--;
				cout<<"\b \b";
			}
		
		}
		else 
		{
			pwd[i++]= ch;
			cout<<"* \b";
		}
		j = j + 1;
	}
}

void gotoxy(int x, int y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	fstream file;
	char password[50];
	char checkPassword[50];
	char mainMenuOption;
	int i;
	Purchase P , *p;
	Stock stObj;
	Sales salesObj;
	//p = &P;
	system("cls");
	gotoxy(52,2);
	cout<<"==============================================";
	gotoxy(66,3);
	cout<<"SHOPPING TELLER";
	gotoxy(52,4);
	cout<<"==============================================";
	gotoxy(66,6);
	cout<<"1. Inventory";
	gotoxy(66,7);
	cout<<"2. Cashier";
	gotoxy(66,8);
	cout<<"3. Exit";
	gotoxy(66,10);
	cout<<"Enter your option : ";
	cin>>mainMenuOption;
	if(mainMenuOption=='1')
	{
			AdminPanel:
			system("cls");
			char ch;
			i=0;
			gotoxy(55,4);
			cout<<"Enter password : ";
			setPassword(password);
			file.open("Account.bin",ios::in);
			while(1)
			{
				file.get(ch);
				if(ch=='\n')
				{
					checkPassword[i]='\0';
					break;
				}
				else 
				{
					checkPassword[i++]= ch;	
				}
			}
			file.close();
			if(strcmp(password,checkPassword)==0)
			{
				AdminMenu:
				system("cls");
				char AdminOption;
				gotoxy(60,3);
				cout<<"<--------ADMIN PANEL-------->";
				gotoxy(66,5);
				cout<<"1. Purchase";
				gotoxy(66,6);
				cout<<"2. Stock";
				gotoxy(66,7);
				cout<<"3. Selling";
				gotoxy(66,8);
				cout<<"4. Change password";
				gotoxy(66,9);
				cout<<"5. Back";
				gotoxy(66,10);
				cout<<"6. Exit";
				gotoxy(66,12);
				cout<<"Enter your option : ";
				cin>>AdminOption;
				if(AdminOption=='1')
				{
					PurchaseMenu:
					system("cls");
					char purchaseOption; 
					int i;
					p = &P;
					gotoxy(60,3);
					cout<<"<--------PURCHASE PANEL-------->";
					gotoxy(66,5);
					cout<<"1.Add item";
					gotoxy(66,6);
					cout<<"2.Display Purchased Item";
					gotoxy(66,7);
					cout<<"3.Clear Purchase Record";
					gotoxy(66,8);
					cout<<"4.Update record";
					gotoxy(66,9);							
					cout<<"5.Back";
					gotoxy(66,10);
					cout<<"6.Exit";
					gotoxy(66,12);
					cout<<"Enter your option : ";
					cin>>purchaseOption;	
					if(purchaseOption == '1')
					{
						string date;
						system("cls");
						string name , id;
						int no , Price , total , i=1 ;
						int NoOfProd;
						char ch;
						ifstream ifs;
						ofstream ofs , ofs1;
						date = __DATE__;
						date = "***" + date;
						p->setDate(date);
						do
						{
							gotoxy(67,4);
							cout<<"Date : "<<date;
							gotoxy(60,6);
							cout<<"<----------Add Items------------>";
							back:
							int found=0;
							ofs1.open("Stock.bin",ios::out|ios::app);
							cout<<endl<<endl<<endl<<"Item "<<i<<endl;
							cout<<"----------------------------"<<endl;
							i=i+1;
							p->setItemDetails();
							ifs.open("Purchase.bin",ios::in);
							if(!ifs)
							{
								ifs.close();
								ofs.open("Purchase.bin",ios::out|ios::app);
								ofs<<p;
								ofs1<<p;
								ofs.close();
								ofs1.close();
								cout<<endl<<"Item added successfully.";
							}
							else
							{
								//ifs>>date>>name>>id>>no>>Price>>total;	
								getline(ifs,date);
								getline(ifs,name);
								getline(ifs,id);
								ifs>>no;
								ifs>>Price;
								ifs>>total;
								while(ifs)
								{
									if(id==p->getProductId())
									{
										found++;
										//NoOfProd = p->getNoOfproduct();
									}
									//ifs>>date>>name>>id>>no>>Price>>total;		
									getline(ifs,date);
									getline(ifs,name);
									getline(ifs,id);
									ifs>>no;
									ifs>>Price;
									ifs>>total;				
								}
								ifs.close();
								if(found!=0)
								{
										cout<<endl<<"(: Sorry !";
										cout<<endl<<"Item with similar item id already exists.";
										cout<<"Please re enter item details."<<endl;
										ofs1.close();
										i = i - 1;
										getch();
										system("cls");
										goto back;
								}
								else
								{
									ofs.open("Purchase.bin",ios::out|ios::app);
									ofs<<p;
									ofs1<<p;
									ofs.close();
									ofs1.close();
									cout<<endl<<"Item added successfully.";
								}
							}
							cout<<endl<<endl<<"Press (y/Y) to add another data. Press (n/N) to exit."<<endl;
							cin>>ch;
							system("cls");
						}while(ch=='y'|ch=='Y');
						gotoxy(55,10);
						cout<<"Press any key to continue .";
						getch();
						goto PurchaseMenu;
					}
					else if(purchaseOption == '2')
					{
						system("cls");
						ifstream ifs;
						i=1;
						ifs.open("Purchase.bin",ios::in);
						if(!ifs.is_open())
						{
							cout<<"(: Error opening the file."<<endl;
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							cout<<"File is empty."<<endl<<"No records found"<<endl;
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(55,1);
							cout<<"Purchased Items";
							gotoxy(1,3);
							cout<<"Purchase Date";
							gotoxy(19,3);
							cout<<"Item Name";
							gotoxy(39,3);
							cout<<"Product id";
							gotoxy(59,3);
							cout<<"No of products";
							gotoxy(79,3);
							cout<<"Per price";
							gotoxy(99,3);
							cout<<"Total price";
							gotoxy(1,5);
							cout<<"-------------------------------------------------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								ifs>>p;
								i = i + 1;
							}
						}
						ifs.close();
						cout<<endl<<endl<<"Press any key to continue .";
						getch();
						goto PurchaseMenu;
					}
					else if(purchaseOption == '3')
					{
						system("cls");
						char ch;
						gotoxy(55,10);
						cout<<"Do you really want to delete all record ?";
						gotoxy(55,11);
						cout<<"Enter Y/y to confirm";
						gotoxy(55,12);
						cout<<"Enter N/n to getback";
						cin>>ch;
						if(ch=='y' || ch=='Y')
						{
							ofstream ofs;
							ofs.open("Purchase.bin",ios::trunc);
							gotoxy(55,15);
							cout<<endl<<"File cleared successfully.";
							ofs.close();
							getch();
							goto PurchaseMenu;
						}
						else
						{
							goto PurchaseMenu;
						}	
					}
					else if(purchaseOption == '4')
					{
						system("cls");
						ifstream ifs;
						ofstream ofs;
						i=1;
						int count=10;
						ifs.open("Purchase.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(55,1);
							cout<<"Purchased Items";
							gotoxy(1,3);
							cout<<"Purchase Date";
							gotoxy(19,3);
							cout<<"Item Name";
							gotoxy(39,3);
							cout<<"Product id";
							gotoxy(59,3);
							cout<<"No of products";
							gotoxy(79,3);
							cout<<"Per price";
							gotoxy(99,3);
							cout<<"Total price";
							gotoxy(1,5);
							cout<<"-------------------------------------------------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								count = count+1;
								ifs>>p;
								i = i + 1;
							}
						}
						ifs.close();
						i=1;
						string itemId;
						ifs.open("Purchase.bin",ios::in);
						ofs.open("Newpurchase.bin",ios::app);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file."<<endl;
						}
						ifs.seekg(0,ios::end);
						 length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							gotoxy(1,count+1);
							cout<<"Enter item id : ";
							cin>>itemId;
							ifs>>p;
							while(ifs)
							{
								if(p->getProductId()==itemId)
								{
									gotoxy(1,count+2);
									cout<<"Update Item";
									gotoxy(1,count+4);
									p->setItemDetails();
									ofs<<p;
									goto jump;
								}
								ofs<<p;
								jump:
								ifs>>p;
								i = i + 1;
							}
						}
						ofs.close();
						ifs.close();
						remove("Purchase.bin");
						rename("Newpurchase.bin" , "Purchase.bin");
						gotoxy(1,count+10);
						cout<<"Item updated successfully.";
						gotoxy(1,count+11);
						cout<<"Press any key to continue .";
						getch();
						goto PurchaseMenu;
					}
					else if(purchaseOption == '5')
					{
						goto AdminMenu;
					}
					else if(purchaseOption == '6')
					{
						Exit();
					}
					else
					{
						goto PurchaseMenu;
					}
				}
				else if(AdminOption=='2')
				{
					StockMenu:
					system("cls");
					char stockOption;
					p = &stObj;
					gotoxy(60,3);
					cout<<"<--------PURCHASE PANEL-------->";
					gotoxy(66,5);
					cout<<"1.Display Stock Item";
					gotoxy(66,6);
					cout<<"2.Edit Stock Item";
					gotoxy(66,7);
					cout<<"3.Search Item";
					gotoxy(66,8);
					cout<<"4.Delete Item";
					gotoxy(66,9);
					cout<<"5.Back";
					gotoxy(66,10);
					cout<<"6.Exit";
					gotoxy(66,12);
					cout<<"Enter your option : ";
					cin>>stockOption;
					if(stockOption=='1')
					{
						system("cls");
						ifstream ifs;
						i=0;
						int count = 10;
						ifs.open("Stock.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(25,1);
							cout<<"-----STOCK ITEMS-----";
							gotoxy(1,3);
							cout<<"Item Name";
							gotoxy(19,3);
							cout<<"Product id";
							gotoxy(39,3);
							cout<<"No of products";
							gotoxy(59,3);
							cout<<"Per Price";
							gotoxy(1,5);
							cout<<"---------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								ifs>>p;
								i = i + 1;
								count = count+1;
							}
						}
						ifs.close();
						cout<<endl<<endl<<"Press any key to continue .";
						getch();
						goto StockMenu;
					}
					else if(stockOption=='2')
					{
						system("cls");
						ifstream ifs;
						ofstream ofs;
						i=0;
						int count = 10;
						ifs.open("Stock.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(25,1);
							cout<<"-----STOCK ITEMS-----";
							gotoxy(1,3);
							cout<<"Item Name";
							gotoxy(19,3);
							cout<<"Product id";
							gotoxy(39,3);
							cout<<"No of products";
							gotoxy(59,3);
							cout<<"Per Price";
							gotoxy(1,5);
							cout<<"---------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								ifs>>p;
								i = i + 1;
								count = count+1;
							}
						}
						ifs.close();
						i=0;
						string itemId;
						ifs.open("Stock.bin",ios::in);
						ofs.open("Newstock.bin",ios::app);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						 length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							gotoxy(1,count+1);
							cout<<"Enter item id : ";
							cin>>itemId;
							ifs>>p;
							while(ifs)
							{
								if(p->getProductId()==itemId)
								{
									gotoxy(1,count+2);
									cout<<"Update Item";
									gotoxy(1,count+4);
									p->setItemDetails();
									ofs<<p;
									goto jump1;
								}
								ofs<<p;
								jump1:
								ifs>>p;
								i = i + 1;
							}
						}
						ofs.close();
						ifs.close();
						remove("Stock.bin");
						rename("Newstock.bin" , "Stock.bin");
						gotoxy(1,count+10);
						cout<<"Item updated successfully.";
						gotoxy(1,count+11);
						cout<<"Press any key to continue .";
						getch();
						goto StockMenu;
					}
					else if(stockOption=='3')
					{
						system("cls");
						ifstream ifs;
						string itemId;
						int i=0;
						int count = 10;
						ifs.open("Stock.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(25,1);
							cout<<"-----STOCK ITEMS-----";
							gotoxy(1,3);
							cout<<"Item Name";
							gotoxy(19,3);
							cout<<"Product id";
							gotoxy(39,3);
							cout<<"No of products";
							gotoxy(59,3);
							cout<<"Per Price";
							gotoxy(1,5);
							cout<<"---------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								ifs>>p;
								i = i + 1;
								count = count+1;
							}
						}
						ifs.close();
						i=0;
						ifs.open("Stock.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file."<<endl;
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						 length = ifs.tellg();
						if(length==0)
						{
							gotoxy(65,10);
							cout<<"File is empty.";
							gotoxy(65,11);
							cout<<"No records found";
							getch();
							goto StockMenu;
						}
						else
						{
							ifs.seekg(0,ios::beg);
							gotoxy(1,count+1);
							cout<<"Enter item id : ";
							cin>>itemId;
							ifs>>p;
							while(ifs)
							{
								if(p->getProductId()==itemId)
								{
									cout<<endl<<endl<<"Item detail"<<endl<<endl;
									i=i+1;
									//string date = p->getDate();
									cout<<"Date of purchase : "<<p->getDate()<<endl;
									cout<<"Item name : "<<p->getProductName()<<endl;
									cout<<"Item id : "<<p->getProductId()<<endl;
									cout<<"No of product : "<<p->getNoOfproduct()<<endl;
									cout<<"Per price : "<<p->getPerPrice();
									//p->displayItemDetails(i);
									break;	
								}
								ifs>>p;	
							}
							if(i==0)
							{
								gotoxy(1,count+3);
								cout<<"(: Item not found";
								gotoxy(1,count+4);
								cout<<"Press any key to continue";
								getch();
								goto StockMenu;				
							}
							cout<<endl<<endl<<"Press any  key to continue"<<endl;
							getch();
							goto StockMenu;	
						}	
					}
					else if(stockOption=='4')
					{
						system("cls");
						ifstream ifs;
						ofstream ofs;
						i=0;
						int found = 10;
						ifs.open("Stock.bin",ios::in);
						if(!ifs.is_open())
						{
							gotoxy(1,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						int length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
						}
						else
						{
							ifs.seekg(0,ios::beg);
							ifs>>p;
							gotoxy(55,1);
							cout<<"STOCK ITEMS";
							gotoxy(1,3);
							cout<<"Item Name";
							gotoxy(19,3);
							cout<<"Product id";
							gotoxy(39,3);
							cout<<"No of products";
							gotoxy(59,3);
							cout<<"Per Price";
							gotoxy(1,5);
							cout<<"-------------------------------------------------------------------------";
							while(ifs)
							{
								p->displayItemDetails(i);
								ifs>>p;
								i = i + 1;
								found = found+1;
							}
						}
						ifs.close();
						string itemId;
						 int count=0;
						ifs.open("Stock.bin",ios::in);
						ofs.open("Newstock.bin",ios::out|ios::app);
						
						if(!ifs.is_open())
						{
							gotoxy(55,10);
							cout<<"(: Error opening the file.";
							getch();
							goto StockMenu;
						}
						ifs.seekg(0,ios::end);
						 length = ifs.tellg();
						if(length==0)
						{
							gotoxy(55,10);
							cout<<"File is empty.";
							gotoxy(55,11);
							cout<<"No records found";
							getch();
							goto StockMenu;
						}
						else
						{
							ifs.seekg(0,ios::beg);
							gotoxy(1,found+1);
							cout<<"Enter item id : ";
							cin>>itemId;
							ifs>>p;
							while(ifs)
							{
								if(p->getProductId()==itemId)	
								{
									
									cout<<endl<<endl<<"Item details "<<endl;
									cout<<"Date of purchase : "<<p->getDate()<<endl;
									cout<<"Item name : "<<p->getProductName()<<endl;
									cout<<"Item id : "<<p->getProductId()<<endl;
									cout<<"No of product : "<<p->getNoOfproduct()<<endl;
									cout<<"Per price : "<<p->getPerPrice();
									cout<<endl<<endl<<"Press any key to delete this item "<<endl;
									getch();
									cout<<"Item deleted successfully"<<endl;
									count = count + 1;
								}
								else
								{
									ofs<<p;
								}
								ifs>>p;
							}
							if(count==0)
							{
								gotoxy(55,10);
								cout<<"(:  Item not found"<<endl;	
							}	
						}
						ifs.close();
						ofs.close();
						remove("Stock.bin");	
						rename("Newstock.bin" , "Stock.bin");
						cout<<"Press any key to continue ."<<endl;
						getch();
				        goto StockMenu;
					}
					else if(stockOption=='5')
					{
						goto AdminMenu;
					}
					else if(stockOption=='6')
					{
						Exit();
					}
					else
					{
						goto StockMenu;
					}
				}
				else if(AdminOption=='3')
				{
					SalesMenu:
					system("cls");
					char salesMenuOption;
					Sales sObj;
					gotoxy(60,3);
					cout<<"<--------PURCHASE PANEL-------->";
					gotoxy(66,5);
					cout<<"1. Display sales record .";
					gotoxy(66,6);
					cout<<"2. Back";
					gotoxy(66,7);
					cout<<"3. Exit";
					gotoxy(66,9);
					cout<<"Enter your option : ";
					cin>>salesMenuOption;
					if(salesMenuOption=='1')
					{
						system("cls");
						sObj.displayItems();
						cout<<endl<<endl<<"Press any key to continue."<<endl;
						getch();
						goto SalesMenu;
					}
					else if(salesMenuOption=='2')
					{
						system("cls");
						goto AdminMenu;
					}
					else if(salesMenuOption=='3')
					{
						system("cls");
						Exit();
					}
					else
					{
						goto SalesMenu;
					}
				}
				else if(AdminOption=='4')
				{
					changePassword:
					system("cls");
					file.open("Account.bin",ios::in);
					i=0;
					char ch;
					while(1)
					{
						file.get(ch);
						if(ch=='\n')
						{
							checkPassword[i]='\0';
							break;
						}
						else 
						{
							checkPassword[i++]= ch;	
						}
					}
					file.close();
					gotoxy(60,2);
					cout<<"Enter current password : ";
					setPassword(password);
					if(strcmp(password,checkPassword)==0)
					{
						file.open("Account.bin",ios::out);
						gotoxy(60,4);
						cout<<endl<<"Enter new password : "<<endl;
						//cout<<"(""Password must be 8 characters long"")"<<endl;
						while(1)
						{
							ch=getch();
							if(ch==Enter || ch==TAB)
							{
								file.put('\n');
								break;
							}
							else if(ch==Backspace)
						 	{
								if(i>0)
								{
									i--;
									cout<<"\b \b";
								}
							}
							else 
							{
								file.put(ch);
								cout<<"* \b";
							}	
						}
						file.close();
						gotoxy(65,5);
						cout<<"Password changed successfully .";
						gotoxy(65,6);
						cout<<"Press any key to continue .";
						getch();
						goto AdminMenu;
					}
					else
					{
						system("cls");
						gotoxy(66,2);
						cout<<"Current password doesn't match.";
						gotoxy(66,3);
						cout<<"Press any key to try again.";
						getch();
						goto changePassword;
					}	
				}
				else if(AdminOption=='5')
				{
					system("cls");
					main();
				}
				else if(AdminOption=='6')
				{
					system("cls");
					gotoxy(66,2);
					cout<<"Are you sure you want to exit ?";
					getch();
					exit(0);
				}
				else
				{
					system("cls");
					fflush(stdin);
					cout<<"Please  enter valid option."<<endl<<"Press  any key to continue"<<endl;
					getch();
					goto AdminMenu;
				}
			}
			else
			{
				system("cls");
				cout<<":) Password doesn't match. Please try again"<<endl;
				getch();
				goto AdminPanel;
			}
	}
	else if(mainMenuOption=='2')
	{
			system("cls");
			Cashier:
			string date;
			ifstream ifs;
			date = __DATE__;
			date = "***" + date;
			p = &stObj;
			i=0;
			int count = 10;
			ifs.open("Stock.bin",ios::in);
			if(!ifs.is_open())
			{
				gotoxy(55,10);
				cout<<"(: Error opening the file.";
				getch();
				goto StockMenu;
			}
			ifs.seekg(0,ios::end);
			int length = ifs.tellg();
			if(length==0)
			{
				gotoxy(55,10);
				cout<<"File is empty.";
				gotoxy(55,11);
				cout<<"No records found";
			}
			else
			{
				ifs.seekg(0,ios::beg);
				ifs>>p;
				gotoxy(1,1);
				cout<<date;
				gotoxy(1,3);
				cout<<"Item Name";
				gotoxy(19,3);
				cout<<"Product id";
				gotoxy(39,3);
				cout<<"No of products";
				gotoxy(59,3);
				cout<<"Per Price";
				gotoxy(1,5);
				cout<<"---------------------------------------------------------------------";
				while(ifs)
				{
					p->displayItemDetails(i);
					ifs>>p;
					i = i + 1;
					count = count+1;
				}
			}
			ifs.close();
			
			string itemId;
			p = &stObj;
			Sales salesObj[50];
			int no , noOfProd , price , j=0;
			double tax = 13.0;
			ifstream ifs1;
			ofstream ofs1;
			/*cout<<"Enter Date"<<" (yy-m-d)"<<endl;
			cin>>date;*/
			int found = 0 , i=0;
			char ch;
			do
			{
				ifs1.open("Stock.bin",ios::in);
				gotoxy(1,count+5+j);
				cout<<"Enter item id : ";
				cin>>itemId;
				ifs1>>p;
				while(ifs1)
				{
					ofs1.open("Newstock.bin",ios::out|ios::app);
					if(p->getProductId() == itemId)
					{
						found = found + 1;
						if(p->getNoOfproduct() == 0)
						{
							cout<<"Item is out of stock."<<endl;
							getch();
						}
						else
						{
							gotoxy(1,count+6+j);
							cout<<"Enter no of product : ";
							cin>>noOfProd;
							if(p->getNoOfproduct() < noOfProd)
							{
								cout<<"Not enough item to sell."<<endl;
								getch();
							}
							else
							{
								salesObj[i].setDate(date);
								salesObj[i].setProductName(p->getProductName());
								salesObj[i].setProdId(itemId);
								salesObj[i].setNoOfProd(noOfProd);
								salesObj[i].setPrice(p->getPerPrice());
								salesObj[i].setTax(tax);
								salesObj[i].setTotalPrice(p->getPerPrice() , noOfProd , tax);
								p->updateNoOfProd(noOfProd);	
								salesObj[i].SalesRecord();
								ofs1<<p;
								ofs1.close();
								i = i + 1;
								goto jump2;
							}
						}
					}
					ofs1<<p;
					jump2:
					ifs1>>p;
					ofs1.close();
				}
				if(found==0)
				{
					cout<<"Item not available ."<<endl;
					getch();
				}
				//jump3:
				ifs1.close();
				//ofs1.close();
				remove("Stock.bin");
				rename("Newstock.bin","Stock.bin");
				cout<<"Press (y/Y) to sale another item. Press (n/N) to exit. ";
				cin>>ch;
				cout<<endl<<endl;
				j = j + 4;
			}while(ch=='y' || ch=='Y');
			
			int y = 0;
			system("cls");
			double total=0;
			gotoxy(60,1);
			cout<<"================================";
			gotoxy(66,2);
			cout<<"  INVOICE ";
			gotoxy(60,3);
			cout<<"================================";
			for(int n=0 ; n<i ; n++)
			{
				gotoxy(60,5+y);
				cout<<"Item "<<n+1;
				gotoxy(60,6+y);
				cout<<"<------------------------------>";
				gotoxy(60,8+y);
				cout<<"Name : "<<salesObj[n].getProductName();
				gotoxy(60,9+y);
				cout<<"No of product : "<<salesObj[n].getNoOfproduct();
				gotoxy(60,10+y);
				cout<<"Price per "<<salesObj[n].getProductName()<<" : "<<salesObj[n].getPerPrice();
				gotoxy(60,11+y);
				cout<<"Tax allowed : "<<salesObj[n].getTax();
				gotoxy(60,12+y);
				cout<<"Total : "<<salesObj[n].getTotalPrice();
				total = total + salesObj[n].getTotalPrice();
				y = y + 9;
			}
			gotoxy(60,15+y);
			cout<<"Grand total------------------------------"<<total;
			getch();
			system("cls");
			goto Cashier;
	}
	else if(mainMenuOption=='3')
	{
		Exit();
	}
	else
	{
		gotoxy(66,2);
		cout<<"Please enter valid option.";
		gotoxy(66,3);
		cout<<"Press any key to continue.";
		getch();
		main();
	}
	return 0;
}
