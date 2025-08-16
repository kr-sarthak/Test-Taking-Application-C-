//
//
//
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip.h>
void main();    //function prototype for returning back to main_menu
void show_applicant_database();
void edit_applicant();
void enter_questions();
void show_questions_database();
void assign_rank();
void settings();
//global variables
int main_menu_choice;
int dd,dm,dy;
char na[50], fa[50], ma[50];
int no_of_applicants=0;
int apno, get_d, get_m, get_y;
char pass[20];
int admin_menu_choice;
int ed_apno, ed_new_dob_d, ed_new_dob_m, ed_new_dob_y;
char ed_new_name[50], ed_new_faname[50], ed_new_maname[50];
int pos;
int no_of_questions=0;
char add_q[100], add_o1[100], add_o2[100], add_o3[100], add_o4[100];
int add_a;
int t_apno, t_dob_d, t_dob_m, t_dob_y;
int pos2;
int marks[500];
int pos3;
//int max_marks;
int negative_mark=1;
int positive_mark=5;
int no_of_ques_to_ask=20;
char password[30]="password";
char app_file_name[30]="APPS.DAT";
char ques_file_name[30]="QUES.DAT";

int new_negative_mark;
int new_positive_mark;
int new_no_of_ques_to_ask;
char new_password[30];
char new_app_file_name[30];
char new_ques_file_name[30];

class Applicants {

 // static int no_of_applicants;
  int applicant_no;
  char name[50];
  char father_name[50];
  char mother_name[50];
  int dob_day;
  int dob_mon;
  int dob_year;
  int marks;
  int rank;
public:


  int get_applicant_no(){ return applicant_no; }
  int get_dob_d() { return dob_day; }
  int get_dob_m() { return dob_mon; }
  int get_dob_y() { return dob_year; }
  //static int get_no_of_applicants() { return no_of_applicants; }
  void get_name() { cout<<name; }
  void get_faname()  { cout<<father_name; }
  void get_maname()  { cout<<mother_name; }
  int get_marks() {return marks;}
  int get_rank() {return rank;}
  void set_marks(int mk) { marks=mk; }
  void set_name(char na[] );
  void set_maname(char ma[]);
  void set_faname(char fa[]);
  void set_rank(int rn) { rank=rn; }
  void set_applicant_no(int ap) { applicant_no=ap; }
  void set_dob_d(int dd) { dob_day=dd; }
  void set_dob_m(int dm) { dob_mon=dm; }
  void set_dob_y(int dy) { dob_year=dy; }
  //static void set_no_of_applicants(int napp) { no_of_applicants=napp;}

};

//int Applicants::no_of_applicants=0;

void Applicants::set_name(char na[])
{
  strcpy(name,na);   //Copies na to me
}

void Applicants::set_maname(char ma[])
{
  strcpy(mother_name,ma);//Copies ma to mother_name
}


void Applicants::set_faname(char fa[])
{
  strcpy(father_name,fa); //Copies fa to father_name
}

void calc_no_of_applicants(){

ifstream fin4calc;
fin4calc.open(app_file_name,ios::in|ios::binary);
fin4calc.seekg(0,ios::end); //return kar dega
no_of_applicants= fin4calc.tellg()/sizeof(Applicants);
fin4calc.close();

}

class Questions{
int id;
char ques[100];
char opt1[100];
char opt2[100];
char opt3[100];
char opt4[100];
int ans;
//static int no_of_questions;
public:
void set_id(int i) { id=i; }
void set_ques(char q[]) { strcpy(ques,q); }
void set_opt1(char o1[]) { strcpy(opt1,o1); }
void set_opt2(char o2[]) { strcpy(opt2,o2); }
void set_opt3(char o3[]) { strcpy(opt3,o3); }
void set_opt4(char o4[]) { strcpy(opt4,o4); }
void set_ans(int a) { ans=a; }

int get_id() { return id; }
void get_ques() { cout<<ques;}
void get_opt1() { cout<<opt1; }
void get_opt2() { cout<<opt2; }
void get_opt3() { cout<<opt3; }
void get_opt4() { cout<<opt4; }
int get_ans() { return ans; }

//static int get_no_of_questions() { return no_of_questions; }
//static void set_no_of_questions(int noq) { no_of_questions=noq;}

};
//int Questions::no_of_questions=0;

class State{
int max_marks;
int negative_mark;
int positive_mark;
int no_of_ques_to_ask;
char password[30];
char app_file_name[30];
char ques_file_name[30];

public:

int get_negative_mark(){ return negative_mark; }
int get_positive_mark(){ return positive_mark; }
int get_no_of_ques_to_ask(){ return no_of_ques_to_ask; }
char* get_password(){ return password; }
char* get_app_file_name(){ return app_file_name; }
char* get_ques_file_name(){ return ques_file_name; }

void set_negative_mark(int nm){  negative_mark=nm;}
void set_positive_mark(int pm){  positive_mark=pm;}
void set_no_of_ques_to_ask(int nq){ no_of_ques_to_ask=nq;}
void set_password(char pw[]){ strcpy(password, pw); }
void set_app_file_name(char af[]){ strcpy(app_file_name, af); }
void set_ques_file_name(char qf[]){ strcpy(ques_file_name, qf); }

};

void calc_no_of_questions(){

ifstream fin4calc_q;
fin4calc_q.open(ques_file_name,ios::in|ios::binary|ios::ate);
//fin4calc_q.seekg(0,ios::end); //return kar dega
//no_of_questions= Last/sizeof(Questions);
no_of_questions= fin4calc_q.tellg()/sizeof(Questions);
fin4calc_q.close();
}

void apply_now() { //this func registers new applicant to the applicant file
Applicants t_applicant; //creates temp. obj of class Applicant
ofstream fout;  //obj to open open

 t_applicant.set_marks(-500); //default values set so that no other values are saved
 t_applicant.set_rank(-1); //also if values are -500 and -1 the get_result() function
			       //output "RESULT NOT ASSIGNED"

fout.open(app_file_name, ios::app|ios::binary); //links the applicant file to fout
cout<<"::APPLICATION FORM::"<<endl<<endl; //heading
cout<<"NAME:";
gets(na);                       //gets name
t_applicant.set_name(na);        //saves in temp obj
cout<<"FATHER'S NAME:";
gets(fa);                                //gets father name
t_applicant.set_faname(fa);              //saves in temp obj
cout<<"MOTHER'S NAME:";
gets(ma);                                //gets mothers name
t_applicant.set_maname(ma);             //saves in temp obj

cout<<"DATE OF BIRTH"<<endl;              //cout DOB
do{
cout<<"DAY (e.g., 1, 2, 3, 4, ....30, 31 )"<<endl;       //day
cin>>dd;
 }
while(!((dd>0)&&(dd<32)));                           //gets day
t_applicant.set_dob_d(dd);
do{                        //saves in temp obj
cout<<"MONTH (e.g., 1, 2, 3, 4, ....11, 12 )"<<endl;  // month
cin>>dm;                                      //gets month
}
while(!((dm>0)&&(dm<13)));
t_applicant.set_dob_m(dm);       //saves in temp object
do{
cout<<"YEAR (e.g., 1901, ...2015, 2016 )"<<endl;     //YEAR
cin>>dy;
}
while(!((dy>1900)&&(dy<3000)));                 //gets YEAR
t_applicant.set_dob_y(dy);                        //saves in temp obj
calc_no_of_applicants();    /* resync no_of_applicants global variable
			       such that the variable no_of_appliacants
			       has the same value as no of records in the
			       applicant file
			       zero if no record in file */

t_applicant.set_applicant_no(no_of_applicants+1); /*sets ap_no of temp obj
						    one more than current no of
						    records in the file
						    1 if no_of_applicants in zero */
fout.write((char*)&t_applicant, sizeof(t_applicant)); //writes/appends temp obj to file
fout.close();                                         //close
calc_no_of_applicants();                        //syncs no_of_applicants after writing the
						//temp obj to file

//Applicants::set_no_of_applicants(no_of_applicants); //also saves the no of records
						    //in the static variable


clrscr();                                            //clears off junk
cout<<"FORM SUCCESSFULLY SUBMITTED!"<<endl;     //success message
cout<<"::YOUR DETAILS::"<<endl;                     //heading
//int noap=Applicants::get_no_of_applicants();
							  //JUNKS ignore
//Applicants::set_no_of_applicants(noap);
//t_applicant.set_applicant_no(noap);
cout<<"APPLICANT NUMBER:"<<t_applicant.get_applicant_no()<<endl; //shows all details from
								//temp obj
cout<<"APPLICANT'S NAME:";
t_applicant.get_name();
  cout<<endl;  //not t_applicant.name //private mem. not accessible//only through fuunc.
cout<<"FATHER'S NAME:";  //father
t_applicant.get_faname(); //father
  cout<<endl;
cout<<"MOTHER'S NAME:"; //mother
t_applicant.get_maname(); //mother
  cout<<endl;
cout<<"DATE OF BIRTH:"<<t_applicant.get_dob_d()<<"-"<<t_applicant.get_dob_m()<<"-"<<t_applicant.get_dob_y()<<endl; //dob formatted

cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU"; //return to menu message
getch();                                        //waits for an input
main(); //returns back to main menu


}


void give_test(){
Applicants test_applicant;
  fstream fin;
  fin.open(app_file_name,ios::in|ios::out|ios::binary);
  clrscr();
  calc_no_of_questions();
  if(no_of_questions<no_of_ques_to_ask)
  {
    cout<<"INSUFFICIENT QUESTION IN DATABASE. CONTACT ADMINISTRATOR"<<endl;
    cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
    getch();
    main();
  }
  cout<<"ENTER YOUR APPLICANT NUMBER:"<<endl;
  cin>>t_apno;
  cout<<"ENTER DATE OF BIRTH"<<endl;
  cout<<"ENTER DAY:";
  cin>>t_dob_d;
  cout<<"ENTER MONTH:";
  cin>>t_dob_m;
  cout<<"ENTER YEAR:";
  cin>>t_dob_y;

  int flag=0;
  while (!fin.eof())
  {
    pos2=fin.tellg();
    fin.read((char*)&test_applicant,sizeof(test_applicant));
if(test_applicant.get_applicant_no()==t_apno&&test_applicant.get_dob_d()==t_dob_d&&test_applicant.get_dob_m()==t_dob_m&&test_applicant.get_dob_y()==t_dob_y)
  {

    flag=1;
    cout<<"WELCOME";
    test_applicant.get_name();
    cout<<endl;
    break;
  }

  }
  if(flag==1)
  {
    Questions t_obj;
    ifstream t_ques;
    t_ques.open(ques_file_name,ios::in|ios::binary);
    time_t t;
      int seedval= (unsigned) time (&t);
       srand(seedval);

    int marks=0;
    int qno;
    int ans;

    for(int i=0; i<no_of_ques_to_ask;i++)
    {
      qno=rand()%no_of_questions+1;
	    while(t_ques.read((char*)&t_obj, sizeof(t_obj)))
	    {
	      if(t_obj.get_id()==qno)
	      {
		 clrscr();
		cout<<"Q"<<i+1<<". ";
		t_obj.get_ques();
		cout<<endl;
		cout<<"OPTIONS"<<endl<<"1. ";
		t_obj.get_opt1();
		cout<<endl;
		cout<<"2. ";
		t_obj.get_opt2();
		cout<<endl;
		cout<<"3. ";
		t_obj.get_opt3();
		cout<<endl;
		cout<<"4. ";
		t_obj.get_opt4();
		cout<<endl;
		cout<<"ENTER ANSWER: ( 1, 2, 3, 4 ) OR 0(ZERO TO SKIP THIS QUESTION:";
		cin>>ans;
		if (ans==0)
		{
		  ;
		}
		else if(t_obj.get_ans()==ans)
		{ marks = marks + positive_mark;}
		else{ marks = marks - negative_mark;}

		break;

	      }

	    }
      t_ques.seekg(0);
    }

    test_applicant.set_marks(marks);
    fin.seekg(pos2);
    fin.write((char*)&test_applicant,sizeof(test_applicant));
    t_ques.close();                //closes file
    fin.close();              //closes file

  }
  if(flag==0)
  {
    clrscr();
    cout<<"APPLICANT NOT FOUND!"<<endl;
  }
  assign_rank();
  cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
   getch(); main();
 }

void get_result(){ //this func takes ap_no and DOB and shows all info including marks and rank
  Applicants t2_applicant;  //creates temp obj
  ifstream fin;            //opens file in input mode
  fin.open(app_file_name,ios::in|ios::binary);  //links applicant file
  clrscr();                               //clears off
  cout<<"ENTER YOUR APPLICANT NUMBER:"<<endl;
  cin>>apno;                                 //get ap_no in temp variable
  cout<<"ENTER DATE OF BIRTH"<<endl;
  cout<<"ENTER DAY:";
  cin>>get_d;                         //get dob day in temp variable
  cout<<"ENTER MONTH:";
  cin>>get_m;                         //month
  cout<<"ENTER YEAR:";
  cin>>get_y;                          //year


  int flag=0;                    //changes to 1 if applicant found
				//remains 0 if no applicant found
while(fin.read((char *)&t2_applicant,sizeof(t2_applicant))){ //reads every record in file one by one

if(t2_applicant.get_applicant_no()==apno&&t2_applicant.get_dob_d()==get_d&&t2_applicant.get_dob_m()==get_m&&t2_applicant.get_dob_y()==get_y)
{                                       //compares apno and DOB
  clrscr();
  cout<<"::YOUR RESULT::"<<endl<<endl;        //heading
  cout<<"APPLICANT NUMBER:"<<t2_applicant.get_applicant_no()<<endl; //shows every value in the temp obj
  cout<<"APPLICANT'S NAME:";
  t2_applicant.get_name();                                     //gets sname
    cout<<endl;
  cout<<"FATHER'S NAME:";
  t2_applicant.get_faname();                               // gets Fathers name
    cout<<endl;
  cout<<"MOTHER'S NAME:";
  t2_applicant.get_maname();                                  //gets mothers name
  cout<<endl;

  cout<<"DATE OF BIRTH:"<<t2_applicant.get_dob_d()<<"-"<<t2_applicant.get_dob_m()<<"-"<<t2_applicant.get_dob_y()<<endl;
			      //shows DOB in proper format
  if(t2_applicant.get_rank()!=-1)           //prints NOT ASSIGNED
  {  calc_no_of_applicants();
  cout<<"RANK:"<<t2_applicant.get_rank()<<" OUT OF "<<no_of_applicants<<endl;  }
  else  {  cout<<"RANK NOT ASSIGNED"<<endl;  }   //prints NOT ASSIGNED if rank is -1 (default)
  if(t2_applicant.get_marks()!=-500)
    {  cout<<"MARKS:"<<t2_applicant.get_marks()<<" OUT OF "<<no_of_ques_to_ask*positive_mark<<endl;  }
  else  {  cout<<"MARKS NOT ASSIGNED"<<endl;  } //prints NOT ASSIGNED if marks is -500 (default)
    flag=1;                         //changes to 1 as record is found
 break;                 //breaks from while as no more reading is needed

}

}

if(!flag){                        //if applicant is not in the record file
  clrscr();
  cout<<"APPLICANT NOT FOUND!"<<endl; //shows no applcant found
}

fin.close();                        //closes file
cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";    //return to main menu
 getch(); main();                 //waits for user input

}

void admin_login(){
clrscr();
  cout<<"::ADMIN PANEL::"<<endl;

  cout<<"ENTER ADMIN PASSWORD:";
  gets(pass);
  if(strcmp(pass,password)==0)
  {
    clrscr();
    cout<<"********************************************************************"<<endl;
    cout<<"::WELCOME TO THE ADMIN PANEL::"<<endl;
    cout<<"********************************************************************"<<endl;

    cout<<"1. SHOW APPLICANT DATABASE"<<endl;
    cout<<"2. GET APPLICANT RESULT"<<endl;
    cout<<"3. EDIT APPLICANT DETAILS"<<endl;
    cout<<"4. ENTER QUESTIONS"<<endl;
    cout<<"5. SHOW QUESTIONS DATABASE"<<endl;
    cout<<"6. SETTINGS"<<endl;
    cout<<"7. GO BACK TO MAIN MENU"<<endl<<endl;
    cout<<"********************************************************************"<<endl;
    cout<<"ENTER YOUR CHOICE:";
    cin>>admin_menu_choice;
    switch(admin_menu_choice){

      case 1 : show_applicant_database();
	      break;
      case 2 : get_result();
	      break;
      case 3: edit_applicant();
	      break;
      case 4: enter_questions();
	    break;
      case 5 : show_questions_database();
	      break;
      case 6 : settings();
	      break;
      case 7 : main();
	      break;
      default: cout<<"WRONG CHOICE!";
      cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
	getch();
	 main();
    }
  }
  else
  {
	clrscr();
	cout<<"ACCESS DENIED!"<<endl;
	cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
	  getch();
	   main();
  }
  getch();
  main();
  }

  void show_applicant_database(){

    Applicants t3_applicant;
    ifstream fin;
    fin.open(app_file_name, ios::binary|ios::in);
    calc_no_of_applicants();
    clrscr();
  cout<<"TOTAL:"<<no_of_applicants<<endl;
  cout<<"NO"<<setw(10)<<"NAME"<<setw(10)<<"F_NAME"<<setw(10)<<"M_NAME"<<setw(10)<<"DOB"<<setw(3)<<"RANK"<<setw(3)<<"MARKS"<<endl;

    while(fin.read((char*)&t3_applicant,sizeof(t3_applicant)))
    {

      cout<<setw(3)<<t3_applicant.get_applicant_no()<<setw(15);
      t3_applicant.get_name();
      cout<<setw(15);
      t3_applicant.get_faname();
	 cout<<setw(15);
      t3_applicant.get_maname();
      //   cout<<setw(10);
      cout<<' '<<setw(2)<<setfill('0')<<t3_applicant.get_dob_d()<<"-"<<setw(2)<<setfill('0')<<t3_applicant.get_dob_m()<<"-"<<setw(4)<<setfill('0')<<t3_applicant.get_dob_y()<<setfill(' ');
      if(t3_applicant.get_rank()!=-1)
      {   cout<<setw(4)<<t3_applicant.get_rank();  }
      else  {  cout<<setw(4)<<"N/A"<<setw(3);  }
      if(t3_applicant.get_marks()!=-500)
	{  cout<<setw(4)<<t3_applicant.get_marks()<<endl;  }
      else  {  cout<<setw(4)<<"N/A"<<endl;  }


    }
    fin.close();

    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    getch();
    admin_login();
  }

void edit_applicant(){
Applicants ed_obj;
  fstream ed_file;
  ed_file.open(app_file_name,ios::in|ios::out|ios::binary);
  clrscr();
cout<<"ENTER APPLICANT NO:";
cin>>ed_apno;

int flag_ed=0;
while(!ed_file.eof())
{
pos=ed_file.tellg();
ed_file.read((char*)&ed_obj,sizeof(ed_obj));


   if(ed_obj.get_applicant_no()==ed_apno)
{

  cout<<"ENTER NEW APPLICANT NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_name);
  if((strcmp(ed_new_name,"x")!=0)&&(strcmp(ed_new_name,"X")!=0))
  {
    ed_obj.set_name(ed_new_name);
  }
  cout<<"ENTER NEW FATHER'S NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_faname);
  if((strcmp(ed_new_faname,"x")!=0)&&(strcmp(ed_new_faname,"X")!=0))
  {
    ed_obj.set_faname(ed_new_faname);
  }
  cout<<"ENTER NEW MOTHER'S NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_maname);
  if((strcmp(ed_new_maname,"x")!=0)&&(strcmp(ed_new_maname,"X")!=0))
  {
    ed_obj.set_maname(ed_new_maname);
  }
  cout<<"ENTER NEW DATE OF BIRTH OR 0 TO DO NOT CHANGE"<<endl;
  cout<<"DATE:";

  cin>>ed_new_dob_d;
  if(ed_new_dob_d!=0)
  {
    ed_obj.set_dob_d(ed_new_dob_d);
  }
  cout<<"MONTH:";
  cin>>ed_new_dob_m;
  if(ed_new_dob_m!=0)
  {
    ed_obj.set_dob_m(ed_new_dob_m);
  }
  cout<<"YEAR:";
  cin>>ed_new_dob_y;
  if(ed_new_dob_y!=0)
  {
    ed_obj.set_dob_y(ed_new_dob_y);
  }

  ed_file.seekg(pos);
  ed_file.write((char*)&ed_obj, sizeof(ed_obj));
  flag_ed=1;
  clrscr();
  cout<<"APPLICANT DETAILS SUCCESSFULLY CHANGED!"<<endl;
  break;
}


}

if(!flag_ed)
{
clrscr();
cout<<"APPLICANT NOT FOUND!"<<endl;

}
ed_file.close();
clrscr();
cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
getch();
admin_login();
}


void enter_questions(){
Questions t_question;
ofstream fout;
char ask='y';
calc_no_of_questions();
fout.open(ques_file_name, ios::app|ios::binary);

cout<<"::ENTER QUESTIONS::"<<endl<<endl;

while(ask!='n'){


cout<<"ENTER QUESTION OR x TO STOP:";
gets(add_q);
if(strcmp(add_q,"X")==0)
{
  ask='n';
  continue;
}
if(strcmp(add_q,"x")==0)
{
  ask='n';
  continue;
}
t_question.set_ques(add_q);
cout<<"OPTION 1:";
gets(add_o1);
t_question.set_opt1(add_o1);
cout<<"OPTION 2:";
gets(add_o2);
t_question.set_opt2(add_o2);
cout<<"OPTION 3:";
gets(add_o3);
t_question.set_opt3(add_o3);
cout<<"OPTION 4:";
gets(add_o4);
t_question.set_opt4(add_o4);
cout<<"ANSWER:";
cin>>add_a;
t_question.set_ans(add_a);
//calc_no_of_questions();
cout<<no_of_questions;  //delete karna hai is line ko yaad rakh na baad me
t_question.set_id(++no_of_questions);
fout.write((char*)&t_question, sizeof(t_question));

//Questions::set_no_of_questions(no_of_questions);
}

fout.close();

clrscr();
cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
getch();
admin_login();


}


void show_questions_database(){

  Questions t3_question;
  ifstream fin;
  fin.open(ques_file_name, ios::binary|ios::in);
  calc_no_of_questions();
  cout<<no_of_questions;
  clrscr();
  cout<<"TOTAL:"<<no_of_questions<<endl;
  cout<<"ID"<<'\t'<<"QUES"<<'\t'<<"OPT1"<<'\t'<<"OPT2"<<'\t'<<"OPT3"<<'\t'<<"OPT4"<<'\t'<<"ANS"<<endl;

  while(fin.read((char*)&t3_question,sizeof(t3_question)))
  {

    cout<<t3_question.get_id()<<'\t';  //Displays ID
    t3_question.get_ques();    //Displays Question
    cout<<'\t';
    t3_question.get_opt1();    //Displays option 1
    cout<<'\t';
    t3_question.get_opt2();    //Displays option 2
    cout<<'\t';
    t3_question.get_opt3();    //Displays option 3
    cout<<'\t';
    t3_question.get_opt4();    //Displays option 4
    cout<<'\t';
    cout<<t3_question.get_ans()<<endl;



  }
fin.close();
  cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
  getch();
  admin_login();

}


void assign_rank(){
int big, pos, temp;
Applicants t_app_obj;
fstream t_app_file;
t_app_file.open(app_file_name, ios::in|ios::out|ios::binary);
int i=0;
int marks_array[100];
while(t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj)))
{
marks_array[i]=t_app_obj.get_marks();
i++;
}



calc_no_of_applicants();
for(i=0;i<no_of_applicants;i++)
{
big = marks_array[i];
pos=i;
	for(int j=i+1;j<no_of_applicants;j++)
	    {
		 if(marks_array[j]>big)
			{ big = marks_array[j];
			  pos=j;
			}
	    }

	    if(i!=pos)
	    { temp = marks_array[i];
	      marks_array[i] = marks_array[pos];
	      marks_array[pos] = temp;
	    }
}



t_app_file.clear();
t_app_file.seekg(0);



while (!t_app_file.eof()) {

pos3=t_app_file.tellg();
t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj));
for(i = no_of_applicants; i>-1;i--)
{

  if(t_app_obj.get_marks()==-500)
  {
     t_app_obj.set_rank(-1);
     break;
  }
   else if(t_app_obj.get_marks()==marks_array[i])
   {
     t_app_obj.set_rank(i+1);

     break;
   }

}

t_app_file.seekg(pos3);
t_app_file.write((char*)&t_app_obj, sizeof(t_app_obj));



}
t_app_file.close();


}

void configure(){
State config_obj;
fstream config_file;
config_file.open("config.dat",ios::in|ios::binary);

cout<<config_file;
if(config_file){

config_file.read((char*)&config_obj,sizeof(config_obj));

strcpy(password, config_obj.get_password());
positive_mark=config_obj.get_positive_mark();
negative_mark=config_obj.get_negative_mark();
no_of_ques_to_ask=config_obj.get_no_of_ques_to_ask();
strcpy(app_file_name,config_obj.get_app_file_name());
strcpy(ques_file_name,config_obj.get_ques_file_name());


}
config_file.close();

}

void settings(){
  clrscr();
cout<<"::SETTINGS::"<<endl<<endl;
cout<<"CURRENT SETTINGS:"<<endl;
cout<<"ADMIN PASSWORD:"<<password<<endl;
cout<<"APPLICANT DATABASE FILENAME:"<<app_file_name<<endl;        //
cout<<"QUESTIONS DATABASE FILENAME:"<<ques_file_name<<endl<<endl; //
cout<<"MARKS AWARDED FOR RIGHT ANSWER:"<<positive_mark<<endl;        //
cout<<"MARKS DEDUCTED FOR WRONG ANSWER:"<<negative_mark<<endl;        //
cout<<"NUMBER OF QUESTIONS TO BE ASKED IN THE TEST:"<<no_of_ques_to_ask<<endl;


cout<<"DO YOU WANT TO CHANGE THE SETTINGS?: y/n";
char ch;
cin>>ch;
if(ch=='y'||ch=='Y')
{
  State config_obj;
  ofstream config_file;
  config_file.open("config.dat",ios::out|ios::trunc|ios::binary);
  cout<<"ENTER NEW ADMIN PASSWORD OR ENTER X TO DO NOT CHANGE:";
  gets(new_password);
  if((strcmp(new_password,"x")!=0)&&(strcmp(new_password,"X")!=0))
  {
    config_obj.set_password(new_password);
  }
  else
  {
    config_obj.set_password(password);
  }

  cout<<"ENTER NEW FILENAME FOR APPLICANT DATABASE OR ENTER X TO DO NOT CHANGE:";
  gets(new_app_file_name);
  if((strcmp(new_app_file_name,"x")!=0)&&(strcmp(new_app_file_name,"X")!=0))
  {
    config_obj.set_app_file_name(new_app_file_name);
  }
  else
  {
    config_obj.set_app_file_name(app_file_name);
  }

  cout<<"ENTER NEW FILENAME FOR QUESTION DATABASE OR ENTER X TO DO NOT CHANGE:";
  gets(new_ques_file_name);
  if((strcmp(new_ques_file_name,"x")!=0)&&(strcmp(new_ques_file_name,"X")!=0))
  {
    config_obj.set_ques_file_name(new_ques_file_name);
  }
  else
  {
    config_obj.set_ques_file_name(ques_file_name);
  }

  cout<<"ENTER MARKS TO BE AWARDED FOR RIGHT ANSWER OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
  cin>>new_positive_mark;
  if(new_positive_mark!=-1)
  {
    config_obj.set_positive_mark(new_positive_mark);
  }
  else
  {
    config_obj.set_positive_mark(positive_mark);
  }
  cout<<"ENTER MARKS TO BE DEDUCTED FOR WRONG ANSWER OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
  cin>>new_negative_mark;
  if(new_negative_mark!=-1)
  {
    config_obj.set_negative_mark(new_negative_mark);
  }
  else
  {
    config_obj.set_negative_mark(negative_mark);
  }
  cout<<"ENTER NUMBER OF QUESTIONS TO BE ASKED IN TEST OR ENTER -1(MINUS ONE) TO DO NOT CHANGE:";
  cin>>new_no_of_ques_to_ask;
  if(new_no_of_ques_to_ask!=-1)
  {
    config_obj.set_no_of_ques_to_ask(new_no_of_ques_to_ask);
  }
  else
  {
    config_obj.set_no_of_ques_to_ask(no_of_ques_to_ask);
  }

  config_file.write((char*)&config_obj,sizeof(config_obj));
  config_file.close();
  configure();

}
admin_login();
}

void main(){ //void to run on TC++


  clrscr();
  configure();
  clrscr();




cout<<"********************************************************************"<<endl;
cout<<"::WELCOME MESSAGE::"<<endl;
cout<<"********************************************************************"<<endl;

cout<<"1. APPLY NOW"<<endl;
cout<<"2. GIVE TEST"<<endl;
cout<<"3. GET RESULT"<<endl;
cout<<"4. ADMIN LOGIN"<<endl;
cout<<"5. EXIT"<<endl<<endl;
cout<<"********************************************************************"<<endl;

cout<<"ENTER YOUR CHOICE:"<<endl;
cin>>main_menu_choice;

switch(main_menu_choice) //swtich variable(global) for main menu
{

  case 1 :
            apply_now(); // this func registers new applicant to the applicant file
            break;
  case 2 : give_test();  //this func takes test and saves the marks obatined in applicants record file
            break;
  case 3 : get_result(); //this func takes ap_no and DOB and shows all info including marks and rank
           break;
  case 4 : admin_login(); //the admin panel
          //show_applicant_database();
            break;
  case 5 : exit(0);



}




}
