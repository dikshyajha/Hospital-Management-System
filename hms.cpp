#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;
int pass2()
 {char password[15]="Admin@12",pass[15];
   pass1:   cout<<endl<<setw(100)<<"Enter your password first=";cin>>pass;
    if(strcmp(password,pass)==0)
    {   cout<<endl<<setw(97)<<"Welcome to the system.\n"<<endl;
        cout<<endl<<setw(106)<<"Press any key to continue......\n"<<endl;
        getch();
    }
    else
    {   cout<<endl<<setw(110)<<"Your entered password is incorrect.\n"<<endl;
        goto pass1;
    }
    return 0;
 };
 int pass1()
 {char password[15]="Staff@12",pass[15];
   pass1:   cout<<endl<<setw(90)<<"Enter your password first=";cin>>pass;
    if(strcmp(password,pass)==0)
    {   cout<<endl<<setw(87)<<"Welcome to the system.\n"<<endl;
        cout<<endl<<setw(90)<<"Press any key to continue......\n"<<endl;
        getch();
    }
    else
    {   cout<<setw(10)<<"\t\tYour entered password is incorrect.\n"<<endl;
        goto pass1;
    }
    return 0;
 };
  int pass3()
 {char password[15]="Doctor@12",pass[15];
   pass1:   cout<<endl<<setw(89)<<"Enter your password first=";cin>>pass;
    if(strcmp(password,pass)==0)
    {   cout<<endl<<setw(86)<<"Welcome to the system.\n"<<endl;
        cout<<endl<<setw(90)<<"Press any key to continue......\n"<<endl;
        getch();
    }
    else
    {   cout<<setw(10)<<"\t\tYour entered password is incorrect.\n"<<endl;
        goto pass1;
    }
    return 0;
};
class DOCTOR
{ public: char  dname[50],daddress[50],dqualification[50],dpost[50],specilist[50];
         int dage,dexperience,did;
         unsigned long long int dcontact;
         void get_doctor_info();
         void display_doctor_info();
         void doctor_list();
         int get_doctor_id()
         {return did;}
};
class PATIENT:public DOCTOR
{public: char pname[50],problem[50],paddress[50];
         int page,pid;
         unsigned long long int pcontact;
         void get_patient_info();
         void display_patient_info();
         int get_patient_id()
         {return pid;}
};
class STAFF:public DOCTOR,public PATIENT
{public: char sname[50],squalification[50],spost[50],saddress[50];
         int sage,experience,sid;
         unsigned long long int scontact;
         void get_staff_info();
         void display_staff_info();
         int get_staff_id()
         {return sid;}
};
class ASSIGNMENT: public DOCTOR, public PATIENT
{ public: char assign_d[20];
        void get_assign_doctor();
        void show_assign_doctor();
};
class REPORT: public DOCTOR, public PATIENT
{public: char prescription[50],labtest[20];
          int room;
    void get_prescription();
    void show_prescription();
};
class BILL:public DOCTOR, public PATIENT, public REPORT
{public: int bill_id,no,day_stayed,rcost,total_cost,medicine,paid;
         void get_bill();
         void show_bill();
         int get_bill_id()
         { return bill_id;}
};
fstream dfile;
fstream pfile;
fstream sfile;
fstream afile;
fstream rfile;
fstream bfile;
DOCTOR d; STAFF s; PATIENT p; ASSIGNMENT a; REPORT r; BILL b;
void DOCTOR::get_doctor_info()
{cout<<"Enter doctor Id                     : ";cin>>did;
            fflush(stdin); cout<<"Enter doctors name                  : ";cin.getline(dname,50);
            cout<<"Enter the contact number            : ";cin>>dcontact;
             fflush(stdin);cout<<"Enter the address of doctor         : ";cin.getline(daddress,50);
            cout<<"Enter the age of doctor             : ";cin>>dage;
            fflush(stdin);cout<<"Enter the qualification of doctor   : ";cin.getline(dqualification,50);
            fflush(stdin);cout<<"Enter the specialization of doctor  : ";cin.getline(specilist,50);
            cout<<"Enter the experience(in years)      : ";cin>>dexperience;
            fflush(stdin);cout<<"Enter the post of doctor            : ";cin.getline(dpost,50);
}
void DOCTOR::display_doctor_info()
{ cout<<endl<<"Doctor ID        : "<<did;
  cout<<endl<<"Name             : "<<dname;
  cout<<endl<<"Contact No       : "<<dcontact;
  cout<<endl<<"Address          : "<<daddress;
  cout<<endl<<"Age              : "<<dage;
  cout<<endl<<"Qualification    : "<<dqualification;
  cout<<endl<<"Specilist        : "<<specilist;
  cout<<endl<<"Experience       : "<<dexperience;
  cout<<endl<<"Post             :"<<dpost;
}
void DOCTOR::doctor_list()
{
    cout<<setw(5)<<did<<setw(20)<<dname<<setw(20)<<specilist<<setw(20)<<dpost;
}
void add_doctor()
{   char ch='y';
    dfile.open("doctor.txt",ios::app|ios::binary);
    while(ch=='y'||ch=='Y')
    {   d.get_doctor_info();
        dfile.write((char*)&d,sizeof(d));
        cout<<"Do you want to add more records(y/Y)?=";
        cin>>ch;
    }dfile.close();
}
void display_all_doctor()
{dfile.open("doctor.txt",ios::in|ios::binary);
  if(! dfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {dfile.read((char*)&d,sizeof(d));
     while(!dfile.eof())
     {d.doctor_list();
     cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
      dfile.read((char*)&d,sizeof(d));
     }}dfile.close();
}
void search_doctor()
{int n1,flag=0;
    dfile.open("doctor.txt",ios::in|ios::binary);
    if(! dfile)
  {      cout<<"File not found.";
      exit(0);}
  else
  {cout<<"Enter ID=";
    cin>>n1;
    dfile.read((char*)&d,sizeof(d));
        while(!dfile.eof())
        {if(n1==d.get_doctor_id())
        {flag=1;
        d.display_doctor_info();
        break;}
    dfile.read((char*)&d,sizeof(d));
      }
      if(flag==0)
      {cout<<"Record do not exist...";
      }}dfile.close();
}
void delete_doctor()
{   int n;
    cout<<"Enter the ID=";
    cin>>n;
    ofstream dfile2;
    dfile2.open("new.txt",ios::out|ios::binary);
    dfile.open("doctor.txt",ios::in|ios::binary);
    if(! dfile)
  {cout<<"File not found.";
    exit(0);}
  else
  {dfile.read((char*)&d,sizeof(d));
     while(!dfile.eof())
     {if(n!=d.get_doctor_id())
         {dfile2.write((char*)&d,sizeof(d));}
          dfile.read((char*)&d,sizeof(d));}
  }dfile2.close();  dfile.close();
  remove("doctor.txt");
  rename("new.txt","doctor.txt");
}
void PATIENT::get_patient_info()
{cout<<endl<<"Enter a Patient ID : ";cin>>pid;
  fflush(stdin);cout<<endl<<"Patient Name       : ";cin.getline(pname,50);
  cout<<endl<<"Patient age        : ";cin>>page;
  fflush(stdin);cout<<endl<<"Address            : ";cin.getline(paddress,50);
  cout<<endl<<"Contact Number     : ";cin>>pcontact;
  fflush(stdin);cout<<endl<<"State Problem      : ";cin.getline(problem,50);
}
void PATIENT::display_patient_info()
{cout<<endl<<"Patient ID      : "<<pid;
  cout<<endl<<"Patient Name    : "<<pname;
  cout<<endl<<"Patient age     : "<<page;
  cout<<endl<<"Address         : "<<paddress;
  cout<<endl<<"Contact Number  : "<<pcontact;
  cout<<endl<<"Problem         : "<<problem;
}
void add_patient()
{char ch='y';
 pfile.open("patient.txt",ios::app|ios::binary);
  while(ch=='y'||ch=='Y')
    {   p.get_patient_info();
        pfile.write((char*)&p,sizeof(p));
        fflush(stdin);
        cout<<"Do you want to add more records(y/Y)?="; cin>>ch;
    }pfile.close();
}
void display_all_patient()
{pfile.open("patient.txt",ios::in|ios::binary);
  if(! pfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {pfile.read((char*)&p,sizeof(p));
     while(!pfile.eof())
     {p.display_patient_info();
     cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
      pfile.read((char*)&p,sizeof(p));
     }}pfile.close();
}
void display_patient()
{int n1,flag=0;
    pfile.open("patient.txt",ios::in|ios::binary);
    if(! pfile)
  {      cout<<"File not found.";
      exit(0);}
  else
  {PAT:  cout<<"Enter patient ID=";
         cin>>n1;
         pfile.read((char*)&p,sizeof(p));
        while(! pfile.eof())
        {if(n1==p.get_patient_id())
        {flag=1;
        p.display_patient_info();
        break;}
    pfile.read((char*)&p,sizeof(p));
      }
      if(flag==0)
      {cout<<"Record do not exist..."<<endl;
        goto PAT;
      }}pfile.close();
}
void delete_patient()
{int n2;
    cout<<"Enter the ID=";
    cin>>n2;
    ofstream pfile2;
    pfile2.open("new1.txt",ios::out|ios::binary);
    pfile.open("patient.txt",ios::in|ios::binary);
    if(! pfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {pfile.read((char*)&p,sizeof(p));
     while(! pfile.eof())
     {if(n2!=p.get_patient_id())
         {pfile2.write((char*)&p,sizeof(p));}
           pfile.read((char*)&p,sizeof(p));
     }
     cout<<"The record was deleted."<<endl;
  }pfile2.close(); pfile.close();
  remove("patient.txt");
  rename("new1.txt","patient.txt");
}
void STAFF::get_staff_info()
{   cout<<"Enter the staff ID                      : ";cin>>sid;
    fflush(stdin);cout<<"Enter staff name                        : ";cin.getline(sname,50);
    cout<<"Enter contact number                    : ";cin>>scontact;
    fflush(stdin);cout<<"Enter staff address                     : ";cin.getline(saddress,50);
    cout<<"Enter the age of staff                  : ";cin>>sage;
    fflush(stdin);cout<<"Enter the qualification                 : ";cin.getline(squalification,50);
    fflush(stdin);cout<<"Enter the post                          : ";cin.getline(spost,30);
    fflush(stdin);cout<<"Enter the experience(in years)          : ";cin>>experience;
}
void STAFF::display_staff_info()
{ cout<<endl<<"Staff ID     : "<<sid;
  cout<<endl<<"Name         : "<<sname;
  cout<<endl<<"Contact No   : "<<scontact;
  cout<<endl<<"Address      : "<<saddress;
  cout<<endl<<"Qualification: "<<squalification;
  cout<<endl<<"Post         : "<<spost;
  cout<<endl<<"Experience   : "<<experience;
}
void add_staff()
{char ch='y';
 sfile.open("staff.txt",ios::app|ios::binary);
  while(ch=='y'||ch=='Y')
    {   s.get_staff_info();
        sfile.write((char*)&s,sizeof(s));
        fflush(stdin);
        cout<<"Do you want to add more records(y/Y)?="; cin>>ch;
    }sfile.close();}
void display_all_staff()
{sfile.open("staff.txt",ios::in|ios::binary);
  if(! sfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {sfile.read((char*)&s,sizeof(s));
     while(!sfile.eof())
     {s.display_staff_info();
     cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
        sfile.read((char*)&s,sizeof(s));
     }}sfile.close();}
void search_staff()
{int n1,flag=0;
    sfile.open("staff.txt",ios::in|ios::binary);
    if(! sfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {cout<<"Enter the ID=";cin>>n1;
      sfile.read((char*)&s,sizeof(s));
        while(!sfile.eof())
        {if(n1==s.get_staff_id())
        {flag=1;
            s.display_staff_info();
        break;
        }sfile.read((char*)&s,sizeof(s));}
      if(flag==0)
      {cout<<"Record do not exist...";}
  }sfile.close();}
  void delete_staff()
{int n2;
cout<<"Enter the ID=";    cin>>n2;
    ofstream sfile2;
    sfile2.open("new.txt",ios::out|ios::binary);
    sfile.open("staff.txt",ios::in|ios::binary);
    if(! sfile)
  {cout<<"File not found.";
      exit(0);}
  else
  {sfile.read((char*)&s,sizeof(s));
     while(!sfile.eof())
     {if(n2!=s.get_staff_id())
         {sfile2.write((char*)&s,sizeof(s));}
            sfile.read((char*)&s,sizeof(s));}
    cout<<"The record was deleted."<<endl;
  }
  sfile2.close();  sfile.close();
  remove("staff.txt");
  rename("new.txt","staff.txt");
}
void ASSIGNMENT::get_assign_doctor()
{ display_patient();
    cout<<endl;
  display_all_doctor();
  cout<<endl<<"Assign Doctor Name From the list=";fflush(stdin);cin.getline(assign_d,50);
  cout<<"Doctor has been assigned"<<endl;
}
void ASSIGNMENT::show_assign_doctor()
{
   cout<<endl<<"Assigned Doctor : "<<assign_d;
}
void add_assign_doctor()
{  char ch='y';
    afile.open("assign.txt",ios::app|ios::binary);
    while(ch=='y'||ch=='Y')
    {   a.get_assign_doctor();
        afile.write((char*)&a,sizeof(a));
        cout<<"Do you want to add more records(y/Y)?=";
        cin>>ch;
    }afile.close();
}
void search_assign()
{int n1,flag=0;
    pfile.open("patient.txt",ios::in|ios::binary);
    afile.open("assign.txt",ios::in|ios::binary);
    if(! pfile&& !afile)
  {      cout<<"File not found.";
      exit(0);}
  else
  {PAT:  cout<<"Enter patient ID=";
         cin>>n1;
         pfile.read((char*)&p,sizeof(p));
         afile.read((char*)&a,sizeof(a));
        while(! pfile.eof()&& !afile.eof())
        {if(n1==p.get_patient_id())
        {flag=1;
        p.display_patient_info();
        a.show_assign_doctor();
        break;}
        afile.read((char*)&a,sizeof(a));
    pfile.read((char*)&p,sizeof(p));
      }
      if(flag==0)
      {cout<<"Record do not exist..."<<endl;
        goto PAT;
      }}afile.close();
      pfile.close();
}
void REPORT::get_prescription()
{search_assign();
   fflush(stdin);cout<<endl<<"Prescription : "; cin.getline(prescription,50);
   fflush(stdin); cout<<"Lab test (if required) : ";cin.getline(labtest,20);
  cout<<endl<<"Emergency room no(410-430)"<<endl;
  cout<<"General Ward(501-530)"<<endl;
  cout<<"Special Ward(601-620)"<<endl;
  cout<<"VIP Ward(710-720)"<<endl;
  cout<<endl<<"Enter the room no : ";cin>>room;
}
void REPORT::show_prescription()
{   cout<<endl<<"Prescrition(Medicines) : "<<prescription;
    cout<<endl<<"Lab test (if required) : "<<labtest;
    cout<<endl<<"Room no      : "<<room;
}
void add_prescription()
{char ch='y';
    rfile.open("report.txt",ios::app|ios::binary);
    while(ch=='y'||ch=='Y')
    {   r.get_prescription();
        rfile.write((char*)&r,sizeof(r));
        cout<<"Do you want to add more records(y/Y)?=";
        cin>>ch;
    }rfile.close();
}
void search_prescription()
{int n1,flag=0;
    pfile.open("patient.txt",ios::in|ios::binary);
    rfile.open("report.txt",ios::in|ios::binary);
    if(! pfile&& !rfile)
  {      cout<<"File not found.";
      exit(0);}
  else
  {PAT:  cout<<"Enter patient ID=";
         cin>>n1;
         pfile.read((char*)&p,sizeof(p));
         rfile.read((char*)&r,sizeof(r));
        while(! pfile.eof()&& !rfile.eof())
        {if(n1==p.get_patient_id())
        {flag=1;
        p.display_patient_info();
         r.show_prescription();
        break;}
        rfile.read((char*)&r,sizeof(r));
    pfile.read((char*)&p,sizeof(p));
      }
      if(flag==0)
      {cout<<"Record do not exist..."<<endl;
       exit(0);
      }}rfile.close();
      pfile.close();
}
void BILL::get_bill()
{ search_prescription();
  cout<<endl<<"Bill id          : "; cin>>bill_id;
  cout<<endl<<"Lab Test : 500 per tests"<<endl;
  cout<<"No of tests : "; cin>>no;
  cout<<endl<<"Emergency room no(410-430) :500 per night"<<endl;
  cout<<"General Ward(501-530)      :1000 per night"<<endl;
  cout<<"Special Ward(601-620)      :2000 per night"<<endl;
  cout<<"VIP Ward(710-720)          :5000 per night"<<endl;
  cout<<"Days Stayed    : ";cin>>day_stayed;
  cout<<"Cost of room   : ";cin>>rcost;
  cout<<"Appointment fee(1000 per appointment)"<<endl;
  cout<<"Medicine charge : ";cin>>medicine;
  total_cost=((no*500)+(day_stayed*rcost)+1000+medicine);
  cout<<"Total cost  :"<<total_cost<<endl;
  cout<<"Paid amount :"; cin>>paid;
  if(total_cost==paid)
  {cout<<endl<<"Bill is cleared.Can be discharged."<<endl;}
  else
  {cout<<endl<<"Bill is due. Cannot be discharged."<<endl;}
}
void BILL::show_bill()
{ search_prescription();
  cout<<endl<<"---------------------------------------"<<endl;
  cout<<"Bill section"<<endl;
  cout<<endl<<"Bill id        : "<<bill_id;
  cout<<endl<<"Days stayed    : "<<day_stayed;
  cout<<endl<<"Total cost     : "<<total_cost;
  cout<<endl<<"Paid amount    : "<<paid;
  if(total_cost==paid)
  {cout<<endl<<"Bill is cleared.Can be discharged."<<endl;}
  else
  {cout<<endl<<"Bill is due. Cannot be discharged."<<endl;}
}
void add_bill()
{char ch='y';
    bfile.open("bill.txt",ios::app|ios::binary);
    while(ch=='y'||ch=='Y')
    {   b.get_bill();
        bfile.write((char*)&b,sizeof(b));
        cout<<"Do you want to add more records(y/Y)?=";
        cin>>ch;
    }bfile.close();
}
void display_bill() {
    int n1, flag = 0;

    // Open the files only once
    ifstream pfile("patient.txt", ios::in | ios::binary);
    ifstream bfile("bill.txt", ios::in | ios::binary);

    // Check if both files opened successfully
    if (!pfile) {
        cout << "Patient file not found." << endl;
        exit(0);
    }

    if (!bfile) {
        cout << "Bill file not found." << endl;
        exit(0);
    }

    // Prompt the user for the bill ID
    cout << "Enter bill ID = ";
    cin >> n1;

    // Read records from both files
    pfile.read((char*)&p, sizeof(p));
    bfile.read((char*)&b, sizeof(b));

    // Search for the bill ID in the files
    while (!pfile.eof() && !bfile.eof()) {
        if (n1 == b.get_bill_id()) {
            flag = 1; // Bill found
            b.show_bill(); // Display the bill details
            break; // Exit the loop since we've found the bill
        }
        bfile.read((char*)&b, sizeof(b)); // Continue reading the next record
        pfile.read((char*)&p, sizeof(p)); // Continue reading the next record
    }

    // If the bill ID was not found in the file
    if (flag == 0) {
        cout << "Record does not exist..." << endl;
    }

    // Close the files
    bfile.close();
    pfile.close();
}

void delete_bill()
{int n;
    cout<<"Enter bill ID=";
    cin>>n;
    ofstream bfile2;
    bfile2.open("new.txt",ios::out|ios::binary);
    bfile.open("bill.txt",ios::in|ios::binary);
    if(! bfile)
  {cout<<"File not found.";
    exit(0);}
  else
  {bfile.read((char*)&b,sizeof(b));
     while(!bfile.eof())
     {if(n!=b.get_bill_id())
         {bfile2.write((char*)&b,sizeof(b));}
          bfile.read((char*)&b,sizeof(b));}
  }bfile2.close();  bfile.close();
  remove("bill.txt");
  rename("new.txt","bill.txt");
}

int main()
{
    int ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,ch12,ch13;
    HMS1:  system("cls");
    cout<<endl<<setw(100)<<"*****WELCOME TO HOSPITAL MANAGEMENT SYSTEM*****"<<endl;
    cout<<endl<<setw(105)<<"Do you want to login as admin,staff or patient/family?"<<endl;
    cout<<endl<<setw(87)<<"1. Hospital Administration(admin)"<<endl;
    cout<<endl<<setw(82)<<"2. Staff(For emergency only)"<<endl;
    cout<<endl<<setw(93)<<"3. Patient/Family(For Pre booking only)"<<endl;
    cout<<endl<<setw(63)<<"4. Doctor"<<endl;
    cout<<endl<<setw(61)<<"5. Exit"<<endl;
    cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch1;
    switch(ch1)
    { case 1:
        { system("cls");
                cout<<endl<<setw(100)<<"****WELCOME TO ADMIN PANEL****"<<endl;
                cout<<endl<<setw(95)<<"You entered as admin."<<endl;
                pass2();
           HMS2:system("cls");
                cout<<endl<<setw(90)<<"1. Doctor Details."<<endl;
                cout<<endl<<setw(91)<<"2. Patient Details."<<endl;
                cout<<endl<<setw(95)<<"3. Other Staff Details."<<endl;
                cout<<endl<<setw(92)<<"4. Doctor Assignment"<<endl;
                cout<<endl<<setw(90)<<"5. Generate bills."<<endl;
                cout<<endl<<setw(94)<<"6. Search Report card."<<endl;
                cout<<endl<<setw(79)<<"7. Exit"<<endl;
                cout<<endl<<setw(82)<<"Enter your choice=";cin>>ch2;
                switch(ch2)
                {case 1:
                    {
                HMS3: system("cls");
                      cout<<endl<<setw(90)<<"****WELCOME TO DOCTOR DATABASE****"<<endl;
                      cout<<endl<<setw(90)<<"1. Add new doctor information. "<<endl;
                      cout<<endl<<setw(91)<<"2. View all doctor information. "<<endl;
                      cout<<endl<<setw(89)<<"3. Search doctor information. "<<endl;
                      cout<<endl<<setw(89)<<"4. Delete doctor information. "<<endl;
                      cout<<endl<<setw(66)<<"5. Exit"<<endl;
                      cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch3;
                      switch(ch3)
                      {case 1:
                          { system("cls");
                            add_doctor();
                            cout<<"New Doctor Added Successfully.....";
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS3;
                            break;}
                        case 2:
                            {system("cls");
                             cout<<"\t\t\t\t\t"<<"DISPLAYING ALL DOCTORS"<<endl;
                             display_all_doctor();
                             cout<<"\n\tPress any key to continue...";
                             getch();
                             goto HMS3;
                             break;}
                        case 3:
                            {system("cls");
                             cout<<"\t\t\t\t\t"<<"SEARCHING DOCTORS"<<endl;
                             search_doctor();
                             cout<<"\n\tPress any key to continue...";
                             getch();
                             goto HMS3;
                             break;}
                        case 4:
                            {system("cls");
                             delete_doctor();
                             cout<<"The Record was deleted...."<<endl;
                             cout<<"\n\tPress any key to continue...";
                             getch();
                             goto HMS3;
                             break;}
                        case 5:
                            {goto HMS2;
                             break;}
                        default:
                            {cout<<"\n\tInvalid.Try again.";
                                cout<<"\n\tPress any key to continue...";
                                getch();
                                goto HMS3;
                                break;}
                      break;}
                  case 2:
                    {
                HMS4: system("cls");
                      cout<<endl<<setw(90)<<"****WELCOME TO PATIENT DATABASE****"<<endl;
                      cout<<endl<<setw(90)<<"1. Add new patient information. "<<endl;
                      cout<<endl<<setw(90)<<"2. Display patient information. "<<endl;
                      cout<<endl<<setw(89)<<"3. Search patient information. "<<endl;
                      cout<<endl<<setw(89)<<"4. Delete patient information. "<<endl;
                      cout<<endl<<setw(65)<<"5. Exit"<<endl;
                      cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch4;
                      switch(ch4)
                      {case 1:
                          {system("cls");
                            add_patient();
                            cout<<"New patient Added Successfully.....";
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS4;
                            break;}
                        case 2:
                            {system("cls");
                            cout<<"\t\t\t\t\t"<<"DISPLAYING ALL PATIENTS"<<endl;
                              display_all_patient();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS4;
                            break;}
                        case 3:
                            {system("cls");
                            cout<<"\t\t\t\t\t"<<"SEARCHING PATIENTS"<<endl;
                              display_patient();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS4;
                            break;}
                        case 4:
                            {system("cls");
                              delete_patient();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS4;
                            break;}
                        case 5:
                            {goto HMS2;
                             break;}
                        default:
                            {cout<<"\n\tInvalid.Try again.";
                                cout<<"\n\tPress any key to continue...";
                                getch();
                                goto HMS2;
                                break;}
            } break; }
                  case 3:
                    {
                HMS5: system("cls");
                      cout<<endl<<setw(90)<<"****WELCOME TO STAFF DATABASE****"<<endl;
                      cout<<endl<<setw(90)<<"1. Add new staff information. "<<endl;
                      cout<<endl<<setw(90)<<"2. Display staff information. "<<endl;
                      cout<<endl<<setw(89)<<"3. Search staff information. "<<endl;
                      cout<<endl<<setw(89)<<"4. Delete staff information. "<<endl;
                      cout<<endl<<setw(67)<<"5. Exit"<<endl;
                      cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch5;
                      switch(ch5)
                      {case 1:
                          {system("cls");
                            add_staff();
                            cout<<"New staff Added Successfully.....";
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS5;
                            break;}
                        case 2:
                            {system("cls");
                            cout<<"\t\t\t\t\t"<<"DISPLAYING ALL STAFFS"<<endl;
                              display_all_staff();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS5;
                            break;}
                        case 3:
                            {system("cls");
                            cout<<"\t\t\t\t\t"<<"SEARCHING STAFFS"<<endl;
                              search_staff();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS5;
                            break;}
                        case 4:
                            {system("cls");
                              delete_staff();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS5;
                            break;}
                        case 5:
                            {goto HMS2;
                                break;}
                        default:
                            {cout<<"Invalid.Try again.";
                            cout<<"\n\tPress any key to continue...";
                                getch();
                                goto HMS5;
                                break;}
          }break;}
                  case 4:
                    {
                HMS6: system("cls");
                       cout<<endl<<setw(93)<<"1. View Patient And assign doctors."<<endl;
                       cout<<endl<<setw(86)<<"2. View assigned doctor list"<<endl;
                       cout<<endl<<setw(66)<<"3. Exit."<<endl;
                       cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch6;
                       switch(ch6)
                       {case 1:
                           {system("cls");
                            add_assign_doctor();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS6;
                            break;}
                       case 2:
                        {system("cls");
                        search_assign();
                         cout<<"\n\tPress any key to continue...";
                         getch();
                         goto HMS6;
                         break;}
                       case 3:
                        {goto HMS2;
                        break;}
                       default:
                        {cout<<"Invalid.Try again.";
                         cout<<"\n\tPress any key to continue...";
                         getch();
                         goto HMS6;
                         break;}
                       }
               break;     }
                  case 5:
                    {
                HMS7: system("cls");
                       cout<<endl<<setw(90)<<"1. Generate Bills."<<endl;
                       cout<<endl<<setw(96)<<"2. Display Bill History."<<endl;
                       cout<<endl<<setw(95)<<"3. Delete Bill History."<<endl;
                       cout<<endl<<setw(80)<<"4. Exit."<<endl;
                       cout<<endl<<setw(80)<<"Enter your choice=";cin>>ch7;
                       switch(ch7)
                       {case 1:
                           {system("cls");
                            add_bill();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS7;
                            break;}
                       case 2:
                        {   system("cls");
                            display_bill();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS7;
                            break;}
                       case 3:
                        {   system("cls");
                            delete_bill();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS7;
                            break;}
                       case 4:
                        {goto HMS2;
                        break;}
                       default:
                        {cout<<"Invalid.Try again.";
                         cout<<"\n\tPress any key to continue...";
                         getch();
                         goto HMS7;
                         break;}
                       }
                    break;}
                 case 6:
                        {system("cls");
                            display_bill();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS2;
                            break; }
                  case 7:
                    exit(0);
                  default:
                    {cout<<"Invalid.Try again.";
                    cout<<"\n\tPress any key to continue...";
                    getch();
                    break;}

                   } break; }

    case 2:
        {system("cls");
               cout<<endl<<setw(100)<<"****WELCOME TO EMERGENCY REGISTRATION****"<<endl;
               cout<<endl<<setw(90)<<"You have entered as Staff."<<endl;
               pass1();
         HMS8: system("cls");
               cout<<endl<<setw(100)<<"***WELCOME TO STAFF ADMINISTRATION***"<<endl;
               cout<<endl<<setw(101)<<"1. Add/Display Patient Records."<<endl;
               cout<<endl<<setw(99)<<"2. Add/Display Staff Records."<<endl;
               cout<<endl<<setw(78)<<"3. Exit."<<endl;
               cout<<endl<<setw(85)<<"Enter your choice=";cin>>ch8;
               switch(ch8)
               {case 1:
                   {
                    HMS9: system("cls");
                          cout<<endl<<setw(90)<<"\t\t1. Add new patient records."<<endl;
                          cout<<endl<<setw(90)<<"\t\t2. Display all Patient Records."<<endl;
                          cout<<endl<<setw(72)<<"\t\t3. Exit."<<endl;
                          cout<<endl<<setw(90)<<"\t\tEnter your choice=";cin>>ch9;
                          switch(ch9)
                          {case 1:
                              {system("cls");
                            add_patient();
                            cout<<"New patient Added Successfully.....";
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS9;
                            break;}
                        case 2:
                            {system("cls");
                            cout<<"\t\t\t\t\t"<<"DISPLAYING ALL PATIENT"<<endl;
                              display_patient();
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS9;
                            break;}
                        case 3:
                            goto HMS8;
                            break;
                        default:
                            {cout<<"Invalid.Try again.";
                            cout<<"\n\tPress any key to continue...";
                            getch();
                            goto HMS9;
                            break;}
                    } break;}
                   case 2:
                    {
                     HMS10:  system("cls");
                            cout<<endl<<setw(90)<<"\t\t1. Add new staff records."<<endl;
                            cout<<endl<<setw(90)<<"\t\t2. Display all staff Records."<<endl;
                            cout<<endl<<setw(72)<<"\t\t3. Exit."<<endl;
                            cout<<endl<<setw(90)<<"\t\tEnter your choice=";cin>>ch10;
                            switch(ch10)
                            {case 1:
                                {   system("cls");
                                    add_staff();
                                    cout<<"New staff Added Successfully.....";
                                    cout<<"\n\tPress any key to continue...";
                                    getch();
                                    goto HMS10;
                                    break;}
                            case 2:
                                {   system("cls");
                                    cout<<"\t\t\t\t\t"<<"DISPLAYING ALL STAFFS"<<endl;
                                    display_all_staff();
                                    cout<<"\n\tPress any key to continue...";
                                    getch();
                                    goto HMS10;
                                    break;}
                            case 3:
                                {goto HMS8;
                                 break;
                                }
                            default:
                                {   cout<<"Invalid.Try again.";
                                    cout<<"\n\tPress any key to continue...";
                                    getch();
                                    goto HMS10;
                                    break;
                                }}
                            break;}
                   case 3:
                    exit(0);
                   default:
                    {cout<<"Invalid.Try again.";
                    cout<<"\n\tPress any key to continue...";
                    getch();
                    goto HMS8;
                    break;}
               }break;}
    case 3:
        {
    HMS11:system("cls");
          cout<<endl<<setw(100)<<"****PATIENT APPOINTMENT****"<<endl;
          cout<<endl<<setw(95)<<"1. Request Booking"<<endl;
          cout<<endl<<setw(95)<<"2. Display Booking"<<endl;
          cout<<endl<<setw(93)<<"3. Display Bill."<<endl;
          cout<<endl<<setw(84)<<"4. Exit"<<endl;
          cout<<endl<<setw(82)<<"Enter your choice=";cin>>ch11;
          switch(ch11)
          {case 1:
              { system("cls");
                add_patient();
                cout<<"New patient Added Successfully.....";
                cout<<"\n\tPress any key to continue...";
                getch();
                goto HMS11;
                break;}
          case 2:
            {   system("cls");
                cout<<"\t\t\t\t\t"<<"SEARCHING PATIENTS"<<endl;
                display_patient();
                cout<<"\n\tPress any key to continue...";
                getch();
                goto HMS11;
                break;}
          case 3:
            {system("cls");
                display_bill();
                cout<<"\n\tPress any key to continue...";
                getch();
                goto HMS11;
                break;
            }
          case 4:
            exit(0);
          default:
            {cout<<"Invalid.Try again.";
             cout<<"\n\tPress any key to continue...";
             getch();
             goto HMS11;
             break;
            }}
          break;
        }
    case 4:
        {system("cls");
         cout<<endl<<setw(100)<<"****WELCOME TO HOSPITAL MANAGEMENT SYSTEM****"<<endl;
         cout<<endl<<setw(90)<<"You have entered as doctor."<<endl;
         pass3();
 HMS12:  system("cls");
         cout<<endl<<setw(95)<<"1. Display Doctor List."<<endl;
         cout<<endl<<setw(96)<<"2. Display Patient list."<<endl;
         cout<<endl<<setw(124)<<"3. Write Prescription and assign room(if necessary)."<<endl;
         cout<<endl<<setw(95)<<"4. Search Precriptions."<<endl;
         cout<<endl<<setw(90)<<"5. Add new doctor."<<endl;
         cout<<endl<<setw(80)<<"6. Exit."<<endl;
         cout<<endl<<setw(85)<<"Enter your choice=";cin>>ch12;
         switch(ch12)
         {case 1:
             {system("cls");
              cout<<"\t\t\t\t\t"<<"DISPLAYING ALL DOCTORS"<<endl;
              display_all_doctor();
              cout<<"\n\tPress any key to continue...";
              getch();
              goto HMS12;
              break;}
          case 2:
            {system("cls");
             cout<<"\t\t\t\t\t"<<"DISPLAYING ALL PATIENTS"<<endl;
             display_all_patient();
             cout<<"\n\tPress any key to continue...";
             getch();
             goto HMS12;
             break;}
          case 3:
            {system("cls");
             add_prescription();
             cout<<"\n\tPress any key to continue...";
             getch();
             goto HMS12;
             break;}
          case 4:
            {system("cls");
             search_prescription();
             cout<<"\n\tPress any key to continue...";
             getch();
             goto HMS12;
             break;
            }
          case 5:
            {   system("cls");
                add_doctor();
                cout<<"New Doctor Added Successfully.....";
                cout<<"\n\tPress any key to continue...";
                getch();
                goto HMS12;
                break;}
          case 6:
            exit(0);
          default:
            {cout<<"Invalid.Try again.";
             cout<<"\n\tPress any key to continue...";
             getch();
             goto HMS12;
             break;}

         }
         break;
        }
    case 5:
            exit(0);
    default:
        {cout<<"\n\tInvalid.Try again.";
                cout<<"\n\tPress any key to continue...";
                getch();
                break;
        }

    }

    return 0;
}}
