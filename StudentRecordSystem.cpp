#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include <sstream>
#include <string>
#include <iterator> 
#include <vector>
#include<windows.h>
using namespace std;
//progress report
struct student
{
char name[80];
char id[80];
int roll;
float pro,arc,writing,alg,sum,average;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : GUE/";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.pro;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arc;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg;
    s.sum=s.pro+s.arc+s.writing+s.alg;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}
void mainmenu()

{
    system("color c");
    char cc;
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2. VIEW ALL STUDENTs REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t5. RESULT\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-6> :";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :GUE/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :GUE/"<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll==n)
         {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :GUE/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCHITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : GUE/";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.pro;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arc;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg;
    s.sum=s.pro+s.arc+s.writing+s.alg;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }
//student class
class Student
{
	int admno;
	char name[20];
	int dob;
	char gender;
	int std;
	
	
	
	public:
	 	void getData();
		void showData();
		
		int getAdmno()
		{return admno;}
		
}s;

//get student info
void Student::getData()
{
	cout<<"\n\nEnter Student Details......\n";
	cout<<"Enter Admission No.     : ";
	cin>>admno;
	cout<<"Enter Full Name         : ";
	cin.ignore(); cin.getline(name,20);
	cout<<"Enter Gender (M/F)      : ";
	cin>>gender;
	cout<<"Enter Standard          : ";
	cin>>std;
	
	cout<<endl;
}
//update student info
void addData()
{
	ofstream fout;
	fout.open("Students.dat",ios::binary|ios::out|ios::app);
	s.getData();
	fout.write((char*)&s,sizeof(s));
	fout.close();
	cout<<"\n\nData Successfully Saved to File....\n";
}
//for display of student info
void displayData()
{
	ifstream fin;
	fin.open("Students.dat",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.showData();
	}
	fin.close();
	cout<<"\n\nData Reading from File Successfully Done....\n";
}
void Student::showData()
{
	cout<<"\n\n.......Student Details......\n";
	cout<<"Admission No.     : "<<admno<<endl;
	cout<<"Full Name         : "<<name<<endl;
	cout<<"Gender            : "<<gender<<endl;
	cout<<"Standard          : "<<std<<endl;
	
 	cout<<endl;

}


//search in student info
void searchData()
{
	int n, flag=0;
	ifstream fin;
	fin.open("Students.dat",ios::in|ios::binary);
	cout<<"Enter Admission Number you want to search : ";
	cin>>n;
 
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(n==s.getAdmno())
		{
			cout<<"The Details of Admission No. "<<n<<" shown herewith:\n";
			s.showData();
			flag++;
		}
	}
	fin.close();	
	if(flag==0)
	cout<<"The Admission No. "<<n<<" not found....\n\n";
	cout<<"\n\nData Reading from File Successfully Done....\n";
}
//deletion of student record
void deleteData()
{
	int n, flag=0;
	ifstream fin;
	ofstream fout,tout;

	fin.open("Students.dat",ios::in|ios::binary);
	fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
	tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);
	cout<<"Enter Admission Number you want to move to Trash : ";
	cin>>n;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(n==s.getAdmno())
		{
			cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
			s.showData();
			tout.write((char*)&s,sizeof(s));
			flag++;
		}
		else
		{
			fout.write((char*)&s,sizeof(s));
 		}
	}
	fout.close();
	tout.close();
	fin.close();
	if(flag==0)
		cout<<"The Admission No. "<<n<<" not found....\n\n";
	remove("Students.dat");
	rename("tempStud.dat","Students.dat");
}
//retreive student record from trash
void getTrash()
{
	ifstream fin;
	fin.open("TrashStud.dat",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.showData();
	}
	fin.close();
	cout<<"\n\nData Reading from Trash File Successfully Done....\n";
}
//modify student record
void modifyData()
{
	int n, flag=0, pos;
	fstream fio;

	fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
	cout<<"Enter Admission Number you want to Modify : ";
	cin>>n;
 
	while(fio.read((char*)&s,sizeof(s)))
	{
		pos=fio.tellg();
		if(n==s.getAdmno())
		{
			cout<<"The Following Admission No. "<<n<<" will be modified with new data:\n";
			s.showData();
			cout<<"\n\nNow Enter the New Details....\n";
		    s.getData();
		    fio.seekg(pos-sizeof(s));
			fio.write((char*)&s,sizeof(s));
			flag++;
		}
	}
	fio.close();
 
	if(flag==0)
		cout<<"The Admission No. "<<n<<" not found....\n\n";
}
//fee status
struct fee
{
	string classes;
	string year;
	float tuitionFee;	
	float sportsFee;
	float uniformFee;
	float total;
};
//add fee values
void addFee()
{
    fee s1;
    fstream outfile ("feeInfo.txt",ios::app);
    cout<<"Class(Standard):";
    cin>>s1.classes;
    cout<<"Year:";
    cin>>s1.year;
    cout<<"SportsFee:";
    cin>>s1.sportsFee;
    cout<<"TuitionFee:";
    cin>>s1.tuitionFee;
    cout<<"UniformFee:";
    cin>>s1.uniformFee;
    s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
    outfile<<s1.classes<<" "<<s1.year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
    cout<<"\n*Successfully Added*\n";
    outfile.close();
    return;
}
//update fee values
void updateFee()
{
    string classes,year;
    cout<<"\n Enter class(STANDARD):\n";
    cin>>classes;

    cout<<"\n Enter Year:\n";
    cin>>year;

    fee s1;
    fstream infile ("feeInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;
    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end);
		vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && classes==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"SportsFee:";
            cin>>s1.sportsFee;
            cout<<"TuitionFee:";
            cin>>s1.tuitionFee;
            cout<<"UniformFee:";
            cin>>s1.uniformFee;
            s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
            tempfile<<classes<<" "<<year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
            cout<<"\n*Successfully updated*\n";

        }
        else
        {
                tempfile<<line<<endl;
        }

    }
    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");

}
//display fees
void listAllFees()
{
    ifstream file("feeInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !* FEES LIST *!\t\t\n\n\n";
    cout << setw(15) <<"CLASS" << setw(15) << "YEAR" << setw(15) << "S.FEE" <<setw(15) <<"T.FEE"<<setw(15)<<"U.FEE"<<setw(15)<<"TOTAL"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);
        vector<string>::iterator it;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;

        }
        std::cout << '\n';
	}
}
//other activities
struct Activity
{
	string Name;
	string Activity;
	string mNumber;
 	string duration ;
};
//new activity record
void newActivityRegistration()
{
    fstream outfile ("ActivityInfo.txt",ios::app);
    Activity a1;
    cout<<"Name:";
    cin>>a1.Name;
    cout<<"Activity:";
    cin>>a1.Activity;
     cout<<"Activity:";
    cout<<"Number:";
    cin>>a1.mNumber;
    cout<<"duration:";
    cin>>a1.duration;
    outfile<<a1.Name<<" "<<a1.Activity<<" "<<a1.mNumber<<" "<<a1.duration<<endl;
    cout<<"\n*Successfully Added*\n";
    outfile.close();
    return;
}
//update activity record
void updateActivityInform()
{
    string Name;
    cout<<"\n Enter Activity Name:\n";
    cin>>Name;

    Activity a1;
    fstream infile ("ActivityInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && Name==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"Name:";
            cin>>a1.Name;
            cout<<"Activity:";
            cin>>a1.Activity;
            cout<<"Number:";
            cin>>a1.mNumber;
            cout<<"duration:";
            cin>>a1.duration;
            tempfile<<a1.Name<<" "<<a1.Activity<<" "<<a1.mNumber<<" "<<a1.duration<<endl;
            cout<<"\n*Successfully updated*\n";

        }
        else
        {

            tempfile<<line<<endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("ActivityInfo.txt");
    rename("tempInfo.txt","ActivityInfo.txt");

}
//delete activity record
void deleteActivityInform()
{
        string Name;
    cout<<"\n Enter Activity Name:\n";
    cin>>Name;

    Activity a1;
    fstream infile ("ActivityInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && Name==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n\n * deleted successfully*\n";

        }
    }
    infile.close();
    tempfile.close();
    remove("ActivityInfo.txt");
    rename("tempInfo.txt","ActivityInfo.txt");

}
//display list of activities
void listOfActivity()
{

    fstream file ("ActivityInfo.txt");
    Activity a1;
cout<<endl<<"\t\t\t\t !* ACTIVITY LIST *!\t\t\n\n\n";
    cout<<setw(15)<<"NAME:"<<setw(15)<<"ACTIVITY"<<setw(15)<<"M.NUMBER"<<setw(15)<<"DURATION"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
	    std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;

        }
        cout<<endl;
    }
        cout<<endl;

}

void project()
{
	
		cout<<"...............STUDENT MANAGEMENT SYSTEM..............\n";
		cout<<"======================================================\n";
		int u;
 
	while(u<5)
	{
  		cout<<"1.Student Profile \n 2.Progress Report Card \n 3.Fee Status \n 4.Other Activities \n 5.Exit \n"<<endl;
		cin>>u;
		switch(u)
		{
		  	case 1: cout<<"STUDENT PROFILE";
		  	int ch;
			do
			{
				system("cls");
			  	cout<<"0. Exit from Program\n";
 				cout<<"1. Write Data to File\n";
				cout<<"2. Read Data From File\n";
				cout<<"3. Search Data From File\n";
				cout<<"4. Delete Data From File\n";
				cout<<"5. Get Deleted Records from Trash file\n";
				cout<<"6. Modify Data in File\n";
				cout<<"Enter your choice  : ";
				cin>>ch;
				system("cls");
  				switch(ch)
  				{
  					case 1: addData(); break;
    				case 2: displayData(); break;
					case 3: searchData(); break;
					case 4: deleteData(); break;
					case 5: getTrash(); break;
					case 6: modifyData(); break;
				}
				system("pause");
			}
			while(ch);
			break;

			case 2:
				cout<<"PROGRESS REPORT CARD \n ";
			    system("color a");
			    char c;
			    system("cls");
			    

			    do
				{
				   system("cls");
   					system("color e");
				   cout<<"\n\n";
				   cout<<"\t====================STUDENT REPORT CARD MANEGEMENT SYSTEM===================="<<endl;
				   cout<<endl;
				   cout<<"\t\t\t\t1. MAIN MENU\n\n";
					   cout<<"\t\t\t\t2. EXIT\n\n";
				   cout<<"ENTER YOUR CHOICE :";
				   cin>>c;
   				system("cls");
   					switch(c)
  					 {
   							case '1':
 							   {
    							    mainmenu();
  									      break;
							   }
					   case '2':
					    {    cout << "\n\n THANK YOU";
        			      cout << "\n\n";
  						  }
  					 }
   				 }while(c!='2');
				break;
			case 3:
			    cout<<"FEE SYSTEM \n ";
				int coi;
				do
				{
					cout<<"Enter your choice : 1. Addfee 2.UpdateFEE 3.listAllFees \n";
					cin>>coi;
					switch(coi)
					{ 
						case 1:
							addFee();
							break;
						case 2:
							updateFee();
							break;
						case 3:
						listAllFees();
						break;
						default :
							coi=0;
					}
				}
				while(coi);
				break;
			case 4:
		  		cout<<"OTHER ACTIVITIES ";
				int choi;
				do
				{
					cout<<"ENTER YOUR CHOICE 1.NEW ACTIVITY 2.UPDATE 3.DELETE 4. DISPLAY\n";				
					cin>>choi;
					switch(choi)		
					{
						case 1:
							newActivityRegistration();
							break;
						case 2:
							updateActivityInform();
							break;
						case 3:	
							deleteActivityInform();
							break;
						case 4 :
							void listOfActivity();
						default:
							choi=0;
					}
				}
				while(choi);
				break;			
		}
	}
}
int main()
{
 project();
}

