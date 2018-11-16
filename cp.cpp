#include <iostream>
#include <conio.h>
#include<cstring>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <windows.h>
#include<vector>
using namespace std; //needed for cout and etc
class Person;
string getLetters()
{
    std::string input;
    int valid;
    do
    {
        getline(cin,input);      
        valid = 1;       
		for(int i=0;i<input.length();i++)        
        {
            if(!(isalpha(input[i])||isspace(input[i])))       
            {
                valid = 0;             
                cout << "Invalid input.  Please input only alphabetical characters." << std::endl;
                break;             
            }
        }
    }while(!valid);     

    return input;      
}
class Result{
	string grade;
	int percentage;
	public:
		void setgrade(){
			string a;
			cout<<"Enter Grade"<<endl;
			grade=getLetters();
		}
		string getgrade(){
			return grade;
		}
		void setpercentage(){
			int a;
		 string line;
    double d;
			
			cout<<"Enter Percentage"<<endl;
		start1:
			//cin>>a;
			//cin.ignore();
	
    while (getline(cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error! Percentage should be a Number" << std::endl;
    }
	if(d>=0&&d<=100){
	percentage=d;
}
else {
	cout<<"Percentage must be between 0 and 100"<<endl;
	goto start1;
}
		}
		int getpercentage(){
			return percentage;
		}
		~Result(){
		}
};
class Person
{
	int BOD;
	string name;
	string father_name;
	int age;
	public:
	string ID;
	void setname()
	{
		cout<<"enter name"<<endl;
		name=getLetters();
	}
	string getname()
	{
		return name;
	}
	void virtual display()
	{
		cout<<"Person Name is: "<<name<<endl;
	}
	void virtual setID()=0;
};
class Student:public Person
{
	int fees;
	Result result_;
	int Class;
	public:	
	void setID()
	{
		string a;
		cout<<"enter student id";
		start:
		getline(cin,a);
		if(a[0]=='1'){
			if(a[1]=='7'){
			if(a[2]=='K'){
				ID=a;
			}
				else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start;
		}
	}
	string getID()
	{
		return ID;
	}
	void setfees()
	{
		int a;
		cout<<"enter student fees";
		//cin>>a;
		//	cin.ignore();
		   std::string line;
    double d;
    while (getline(cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error! Fees should be in number" << std::endl;
    }
    fees=a;
	}
	int getfees()
	{
		return fees;
	}
	void setclass()
	{
		int a;
		cout<<"enter student class";
		start:
		//cin>>a;
		   std::string line;
    double d;
    while (getline(cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error! Class should be a number" << std::endl;
    }
    a=d;
		if(a>0&&a<13){
			Class=a;
		}
		else{
			cout<<"Wrong Class Only 1-12 Classes are allowed"<<endl;
			goto start;
		}
		//	cin.ignore();
	}
	int getclass()
	{
		return Class;
	}
	void Addresult(){
	string a;
	string getcontent;
	start1:
	cout<<"Enter Student ID to Add Result OR If you want to go back enter cancel"<<endl;
	getline(cin,a);
		if(a[0]=='1'){
			if(a[1]=='7'){
			if(a[2]=='K'){
				ID=a;
			}
				else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
   ofstream myfile;
   if(a=="cancel"){
		goto start;
	}
			myfile.open ("Result.txt",ios::app );
			result_.setgrade();
			result_.setpercentage();
			myfile<< a;
			myfile <<endl<< result_.getgrade();
			myfile <<endl<< result_.getpercentage()<<endl;
         start:
  myfile.close(); 
   }
   void Searchresult(){
   	int flag=0;
   	int b=0;
   	int c=0;
   	string a;
   	int h=0;
   	int d=0;
   	cout<<"Enter Student ID to Search OR If you want to go back enter cancel"<<endl;
   	start1:
	getline(cin,a);
   	if(a[0]=='1'){
			if(a[1]=='7'){
			if(a[2]=='K'){
				ID=a;
			}
				else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
   	if(a=="cancel"){
   		goto start;
	   }
   {
   
   	int getcontent;
   		string getcontent1;
   		 ifstream openfile ("Result.txt");
    if(openfile.is_open())
    {
    	getline(openfile,getcontent1);
    	//cout<<getcontent<<"ASdas";
        while(openfile.eof()=='\0')
        {
			if(getcontent1==a)
			{
			d=1;
				cout<<"Student ID: "<<getcontent1<<endl;
			while(1){
		if(c==1){
		cout<<"Grade: "<<getcontent1<<endl;
    }
    if(c==2){
		cout<<"Percentage: "<<getcontent1<<endl;
    }
			c++;
			flag=1;
			getline(openfile,getcontent1);
		//	cout<<getcontent1<<"Asad"<<endl;
			if(c==3){
				break;
			}
			}
			if(c==3){
				break;
			}
		}
				getline(openfile,getcontent1);
        }
        if(d==0){
        	cout<<"No Result Found"<<endl;
		}
        }
    }
        start:
    cout<<" ";
	}
	void display()
		{
			int a=0;
			int b=0;
			cout << "Name" << "                  "<<"ID"<<"                    "<<"Fees"<<"                  "<<"Class"<<endl;
			string getcontent;
    ifstream openfile ("studentname.txt");
    if(openfile.is_open())
    {
        while(openfile.eof()=='\0')
        {
        	if(a==4)
			{
        		cout<<endl;
        		a=0;
			}
			getline(openfile,getcontent);
			//openfile >> noskipws>> getcontent;
            cout << getcontent;
            b=getcontent.length();
            for(int i=0;b!=22;i++)
			{
            	b++;
            	cout<<" ";
			}
            a++;
        }
    }
		}
   ~Student(){
   }
};
class Teacher:public Person{
	int salary;
	string degree;
	public:
		void display()
		{
			int a=0;
			int b=0;
			cout << "Name" << "                  "<<"ID"<<"                    "<<"Salary"<<"                "<<"Degree"<<endl;
			string getcontent;
    ifstream openfile ("teachername.txt");
    if(openfile.is_open())
    {
        while(openfile.eof()=='\0')
        {
        	if(a==4)
			{
        		cout<<endl;
        		a=0;
			}
			getline(openfile,getcontent);
			//openfile >> noskipws>> getcontent;
            cout << getcontent;
            b=getcontent.length();
            for(int i=0;b!=22;i++)
			{
            	b++;
            	cout<<" ";
			}
            a++;
        }
    }
		}
		void setsalary()
		{
			int a;
			cout<<"Enter Salary of Teacher"<<endl;
			//cin>>a;
		//	salary=a;
		   std::string line;
    double d;
    while (getline(cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error! Salary should be a number" << std::endl;
    }
    salary=d;
		}
		int getsalary()
		{
			return salary;
		}
		void setdegree()
		{
			string a;
			cout<<"Enter Degree of Teacher"<<endl;
			//getline(cin,a);
			//cin.ignore();
			degree=getLetters();
		}
		string getdegree()
		{
			return degree;
		}
		void setID()
		{
			string a;
			a:
			cout<<"Enter ID of Teacher"<<endl;
			getline(cin,a);
				if(a[0]!='T'){
cout<<"ID must starts with T e.g T123";
goto a;
				}
				ID=a;
		}
		string getID()
		{
			return ID;
		}
		~Teacher()
		{
		}
};
class Management:public Person{
	Student *ptr;
	Teacher *ptr1;
	Person *ptr2;
	char pass[32];
	string username;
	public:
	int login()
	{
		char a;
		int i=0;
		int c;
		start1:
	system("cls");
		cout<<"Enter username"<<endl;
		username=getLetters();
		if(username=="admin")
		{
    cout<<"Enter Password  : ";
    for(i=0;;i++)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
        //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    if(strcmp(pass,"admin"))
    {
	cout<<"\nWrong Password\nEnter Again";
    cout<<"Press any key"<<endl;
        getch();//It is for pausing :p
        goto start1;
}
	else
	{
    	cout<<"\nWelcome to school management system "<<endl;	
	return 1;
	}
		}
		else
		{
			cout<<"Wrong username"<<endl;
    cout<<"Press any key"<<endl;
			getch();
			goto start1;
		}
		
}
void deletestudent(Student &obj)
{
string deleteline;
string line;
int i=0;
int z;
int j=0;
ifstream fin;
fin.open("studentname.txt");
ofstream temp;
temp.open("temp.txt");
cout << "Enter Student ID you want to remove ";
start1:
cin >> deleteline;
		if(deleteline[0]=='1'){
			if(deleteline[1]=='7'){
			if(deleteline[2]=='K'){
				ID=deleteline;
			}
				else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}
		}
		else{
			cout<<"ID must have 17K in starting e.g 17K4018"<<endl;
			goto start1;
		}


 while( getline(fin,line) )
    {
    	i++;
        if(line == deleteline){
        	        	cout<<"Record Deleted!"<<endl;
getline(fin,line);
getline(fin,line);
z=i;
z--;
}
else{
	temp << line << "\n";
}
	}
	

temp.close();
fin.close();
remove("studentname.txt");
rename("temp.txt","studentname.txt");


ifstream fin1;
fin1.open("studentname.txt");
ofstream temp1;
temp1.open("temp.txt");
 while( getline(fin1,line) )
    {
    	j++;
      if(z!=j)
      temp1 << line << "\n";
	}
	
temp1.close();
fin1.close();
remove("studentname.txt");
rename("temp.txt","studentname.txt");


}
void display(Student &obj)
{
ptr2=&obj;
ptr2->display();
}
void display(Teacher &obj)
{
ptr1=&obj;
ptr1->display();
}
void addstudent(Student &obj)
{          
            
            ptr=&obj;
			ofstream myfile;
			myfile.open ("studentname.txt",ios::app );
			cout<<"If you want to go on menu please enter cancel"<<endl;
			ptr->setname();
			if(ptr->getname()=="cancel")
			{
				goto start;
			}
			ptr->setID();
			ptr->setfees();
			ptr->setclass();
			myfile<< ptr->getname();
			myfile<<endl << ptr->getID();
			myfile<<endl << ptr->getfees();
			myfile <<endl<< ptr->getclass()<<endl;
			start:
  myfile.close();
		}
		void setID(){
			ID="";
		}
		void deleteteacher(Teacher &obj)
{
string deleteline;
string line;
int i=0;
int z;
int j=0;
ifstream fin;
fin.open("teachername.txt");
ofstream temp;
temp.open("temp.txt");
a:
cout << "Enter ID of Teacher you want to remove? "<<endl;
cin >> deleteline;
	if(deleteline[0]!='T'){
cout<<"ID must starts with T e.g T123"<<endl;
goto a;
}
 while( getline(fin,line) )
    {
    	i++;
        if(line == deleteline){
        	cout<<"Record Deleted!"<<endl;
getline(fin,line);
getline(fin,line);
z=i;
z--;
}
else{
	temp << line << "\n";
}
	}
	

temp.close();
fin.close();
remove("teachername.txt");
rename("temp.txt","teachername.txt");


ifstream fin1;
fin1.open("teachername.txt");
ofstream temp1;
temp1.open("temp.txt");
 while( getline(fin1,line) )
    {
    	j++;
      if(z!=j)
      temp1 << line << "\n";
	}
	
temp1.close();
fin1.close();
remove("teachername.txt");
rename("temp.txt","teachername.txt");


}
		void addteacher(Teacher &obj)
{          
            
            ptr1=&obj;
			ofstream myfile;
			myfile.open ("teachername.txt",ios::app );
			cout<<"If you want to go on menu please enter cancel"<<endl;
			ptr1->setname();
			if(ptr1->getname()=="cancel")
			{
				goto start;
			}
			ptr1->setID();
			//cin.ignore();
			ptr1->setsalary();
			ptr1->setdegree();
			myfile<< ptr1->getname();
			myfile<<endl << ptr1->getID();
			myfile<<endl << ptr1->getsalary();
			myfile <<endl<< ptr1->getdegree()<<endl;
			start:
  myfile.close();
		}
void searchteacher()
		{
			
			string a;
			int c=0;
			int b=0;
			int d=0;
			int e=0;
			int g=0;
			int j=0;
			string getcontent;
			cout<<"enter name you want to search OR If you want to go on menu please enter cancel"<<endl;
			a=getLetters();
	
			if(a=="cancel")
			{
				e=1;
				g=1;
				j=1;
			}
				if(j==0)
				cout << "Name" << "                  "<<"ID"<<"                    "<<"Salary"<<"                "<<"Degree"<<endl;
			 ifstream openfile ("teachername.txt");
    if(openfile.is_open())
    {
    	getline(openfile,getcontent);
    	//cin.ignore();
        while(openfile.eof()=='\0')
        {
        	if(e==1)
			{
        		break;
			}
        //	cout<<"asd";
        	d=0;
            
            if(getcontent==a)
			{
				g=1;
				d=1;
            	//cout<<endl<<getcontent<<"ASdasdasd"<<endl;
            	if(c==4){
        		cout<<endl;
        		c=0;
			}
			while(d!=5)
			{
            cout << getcontent;
            
            b=getcontent.length();
            for(int i=0;b!=22;i++)
			{
            	b++;
            	cout<<" ";
			}
            c++;
            d++;
            getline(openfile,getcontent);
		//cin.ignore();
			}

        }
        else{
		getline(openfile,getcontent);
		//cin.ignore();
		}

        }
    }
    if(g==0){
        	cout<<"No Result Found"<<endl;
		}
		}
		void searchstudent()
		{
			
			string a;
			int c=0;
			int b=0;
			int d=0;
			int e=0;
			int g=0;
			int j=0;
			string getcontent;
			cout<<"enter name you want to search OR If you want to go on menu please enter cancel"<<endl;
			a=getLetters();
			if(a=="cancel")
			{
				e=1;
				g=1;
				j=1;
			}
				if(j==0)
				cout << "Name" << "                  "<<"ID"<<"                    "<<"Fees"<<"                  "<<"Class"<<endl;
			 ifstream openfile ("studentname.txt");
    if(openfile.is_open())
    {
    	getline(openfile,getcontent);
    	//cin.ignore();
        while(openfile.eof()=='\0')
        {
        	if(e==1)
			{
        		break;
			}
        //	cout<<"asd";
        	d=0;
            
            if(getcontent==a)
			{
				g=1;
				d=1;
            	//cout<<endl<<getcontent<<"ASdasdasd"<<endl;
            	if(c==4){
        		cout<<endl;
        		c=0;
			}
			while(d!=5)
			{
            cout << getcontent;
            
            b=getcontent.length();
            for(int i=0;b!=22;i++)
			{
            	b++;
            	cout<<" ";
			}
            c++;
            d++;
            getline(openfile,getcontent);
		//cin.ignore();
			}

        }
        else{
		getline(openfile,getcontent);
		//cin.ignore();
		}

        }
    }
    if(g==0){
        	cout<<"No Result Found"<<endl;
		}
		}
		void addresult(Student &obj){
			ptr=&obj;
			ptr->Addresult();
		}
		void searchresult(Student &obj){
			ptr=&obj;
			ptr->Searchresult();
		}
	~Management(){
	}	
};
int main()
{
system("color 9");
		int c=0;
	int b;

//    cout<<"\t                     \tLoading"<<endl;
//	cout<<"\t                     \t*";
//	Sleep(500);
//	cout<<"*";
//	Sleep(500);
//	cout<<"*";
//	Sleep(500);
//	cout<<"*";
//	Sleep(500);
//	cout<<"*";
//	Sleep(500);
//	cout<<"*";
//	Sleep(500);
//	cout<<"*";
//    Sleep(500);  
    Student student1;
    Teacher teacher1;
	Management a;
	start:
	if(c==0)
	{
c=a.login();
system("cls");	
goto start;
}
else
{
	
cout<<"Welcome To School Management System"<<endl;
cout<<endl<<"1-add student"<<endl;
cout<<"2-display all student"<<endl;
cout<<"3-search studnet"<<endl;
cout<<"4-To delete student"<<endl;
cout<<"5-To add student's result"<<endl;
cout<<"6-To search student's result"<<endl;
cout<<"7-To add teacher"<<endl;
cout<<"8-To display all teacher"<<endl;
cout<<"9-Search Teacher"<<endl;
cout<<"10-To delete Teacher"<<endl;
cout<<"11-logout"<<endl;
cout<<"12-exit"<<endl;
start3:
std::string line;
    double d;
    while (getline(cin, line))
    {
        std::stringstream ss(line);
        if (ss >> d)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Error! Input should be anubmer" << std::endl;
    }
    b=(int)d;
if(b>0&&b<13){

//acin.ignore();
if(b==11)
{
	system("cls");
	c=0;
	goto start;
}
if(b==1)
{
	system("cls");
	a.addstudent(student1);
	system("cls");	
	goto start;
}
if(b==2)
{
	system("cls");	
    a.display(student1);
    cout<<"Press any key"<<endl;
    getch();
    system("cls");	
	goto start;
	
}
if(b==3)
{
	system("cls");	
	a.searchstudent();
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
	goto start;
}
if(b==5)
{
	system("cls");	
	a.addresult(student1);
	system("cls");	
		goto start;
}
if(b==6)
{
	system("cls");	
	a.searchresult(student1);
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
		goto start;
}
if(b==7)
{
	system("cls");	
	a.addteacher(teacher1);
	system("cls");	
		goto start;
}
if(b==8)
{
	system("cls");	
	a.display(teacher1);
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
		goto start;
}
if(b==9)
{
	system("cls");	
	a.searchteacher();
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
		goto start;
}
if(b==4)
{
	system("cls");	
	a.deletestudent(student1);
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
		goto start;
}
if(b==10)
{
	system("cls");	
	a.deleteteacher(teacher1);
    cout<<"Press any key"<<endl;
	getch();
	system("cls");	
		goto start;
}
}
else{
	cout<<"Invalid Value Enter value from 1 to 12"<<endl;
	goto start3;
}
}

    return 0;
}
