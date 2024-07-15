#include<iostream>
#include<exception>
#include <string>
#include <regex>
#include <bits/stdc++.h>
#include <memory>
#include <vector>
#include <unordered_map>
using namespace std;


//--------------------------------------------------------------------------------------------------------------------------------------------

class Course {
protected:
    std::string name;
    int creditHours;

public:
    Course(const std::string& name, int creditHours)
        : name(name), creditHours(creditHours) {}

    virtual std::string getInfo() const = 0;
    virtual ~Course() {}
};


//--------------------------------------------------------------------------------------------------------------------------------------------

class CoreCourse : public Course {
public:
    CoreCourse(const std::string& name, int creditHours)
        : Course(name, creditHours) {}

    std::string getInfo() const override {
        return "Core Course - Name: " + name + ", Credit Hours: " + std::to_string(creditHours);
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------


class ElectiveCourse : public Course {
public:
    ElectiveCourse(const std::string& name, int creditHours)
        : Course(name, creditHours) {}

    std::string getInfo() const override {
        return "Elective Course - Name: " + name + ", Credit Hours: " + std::to_string(creditHours);
    }
};


//--------------------------------------------------------------------------------------------------------------------------------------------


class CourseFactory {
public:
    enum class CourseType {
        CORE,
        ELECTIVE
    };

    static std::unique_ptr<Course> createCourse(CourseType type, const std::string& name, int creditHours) {
        switch (type) {
            case CourseType::CORE:
                return std::make_unique<CoreCourse>(name, creditHours);
            case CourseType::ELECTIVE:
                return std::make_unique<ElectiveCourse>(name, creditHours);
            default:
                return nullptr;
        }
    }
};


//--------------------------------------------------------------------------------------------------------------------------------------------



class person//declaring a class named person
{
    private://declaring data members in private section
    string name;
    int age;
    string address;
    public://declaring methods in public section
    person()//constructor
    {
        name="";
        age=0;
        address="";
    }
    person(string a,int b,string c)//parametarised constructor
    {
        name=a;
        age=b;
        address=c;
    }
    string rname()//function that returns name of person
    {
        return name;
    }
    int rage()//function that returns age
    {
        return age;
    }
    string raddress()//function that returns address
    {
        return address;
    }
    virtual void printperson()//virtual function which will be overrided in inherited classes
    {
    }


};


//-----------------------------------------------------------------------------------------------------------------------------

class teacher: public person//inheriting class person in public mode
{
    private:
    int salary;
    string branch;
    public:
    teacher():person()//calling base class constructor
    {
        salary=0;
        branch="";
    }
    teacher(string a,int b,string c,int d,string e):person(a,b,c)//calling base class parameterised constructor
    {
        salary=d;
        branch=e;
    }
    void printperson()//overriding base class print function
    {
        string a=this->rname();
        int b=this->rage();
        string c=this->raddress();
        cout<<"\nNAME :"<<a<<endl<<"AGE :"<<b<<endl<<"ADDRESS :"<<c<<endl<<"SALARY :"<<salary<<endl<<"BRANCH :"<<branch<<endl<<endl;
    }
    string rbranch()//returns branch name of student
    {
        return this->branch;
    }
    string tname()
    {
        return this->rname();
    }


};

//--------------------------------------------------------------------------------------------------------------------------------------------

class UserManager {
private:
    std::unordered_map<std::string, std::pair<std::string, int>> users;

public:
    // Constructor to initialize some sample user data
    UserManager() {
        // Sample user data: {username, {password, userType}}
        users["admin123"] = {"adminpass", 1}; // Admin
        users["faculty456"] = {"facultypass", 2}; // Faculty
        users["student789"] = {"studentpass", 3}; // Student
    }

    // Function to get the user type based on the username
    int getUserType(const std::string& username) {
        if (users.find(username) != users.end()) {
            return users[username].second;
        }
        return 0; // 0 indicates an invalid user type (user not found)
    }
    string getUserPass(const std::string& username,const std::string& password) {
        if (users.find(username) != users.end()) {
            return users[username].first;
        }
    }
};


//----------------------------------------------------------------------------------------------------------------------------------------


class student: public person//inheriting class person in public mode
{
    private:
    string usn;
    string branch;
    string guide;
    int c[3]={-1,-1,-1};
    public:
    student():person()//calling base class constructor
    {
        usn="";
        branch="";
        guide="";
    }
    student(string a,int b,string c,string d,string e,string f):person(a,b,c)//calling base class parameterised constructor
    {
        usn=d;
        branch=e;
        guide=f;
    }
    void printperson()//overriding base class print function
    {
        string a=this->rname();
        int b=this->rage();
        string c=this->raddress();
        cout<<"\nNAME :"<<a<<endl<<"AGE :"<<b<<endl<<"ADDRESS :"<<c<<endl<<"USN :"<<usn<<endl<<"BRANCH :"<<branch<<endl<<"GUIDE :"<<guide<<endl<<endl;
    }
    string rbranch()//returns branch name of student
    {
        return this->branch;
    }
    string rusn()//returns usn of student
    {
        return this->usn;
    }
    void assignmarks()
    {
        int a1,b1,c1;
        cout<<"ENTER ISA1(OUT OF 20),ISA2(OUT OF 30) AND ESA(OUT OF 50) MARKS\n";
        cin>>a1>>b1>>c1;
        if(a1>20||b1>20||c1>50)
        {
            cout<<"ENTER MARKS IN SPECIFIED RANGE\n";
            return;
        }
        c[0]=a1;
        c[1]=b1;
        c[2]=c1;
    }

    int gettmarks()
    {
        if(c[0]==-1 && c[1]==-1 && c[2]==-1)
        {
            cout<<"COULD NOT GET TOTAL MARKS AS MARKS OF ISA1 ISA2 ESA WERE NOT ASSIGNED\n";
            return 0;
        }
        return(c[0]+c[1]+c[2]);
    }
    string rguide()
    {
        return(guide);
    }

    string sname()
    {
        return this->rname();
    }



};

//----------------------------------------------------------------------------------------------------------------------------------------


class nonteachstaff: public person//inheriting class person in public mode
{
    private:
    int salary;
    string department;
    public:
    nonteachstaff():person()//calling base class constructor
    {
        salary=0;
        department="";
    }
    nonteachstaff(string a,int b,string c,int d,string e):person(a,b,c)//calling base class parameterised constructor
    {
        salary=d;
        department=e;
    }

    void printperson()//overriding base class print function
    {
        string a=this->rname();
        int b=this->rage();
        string c=this->raddress();
        cout<<"NAME :"<<a<<endl<<"AGE :"<<b<<endl<<"ADDRESS :"<<c<<endl<<"SALARY :"<<salary<<endl<<"DEPARTMENT :"<<department<<endl<<endl;
    }

    string rbranch()//returns department name of worker
    {
        return this->department;
    }

    string stname()
    {
        return this->rname();
    }


};

//-------------------------------------------------------------------------------------------------------------------------------------------------------

class result
{
    public:
    int getresult(student s)
    {
        return(s.gettmarks());
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

class branch:public exception
{
    public:
    const char * what() const throw()
    {
        return"SORRY! NO SUCH BRANCH EXIST\n";
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------


class book
{
    private:
    string title;
    string author;
    int copies,given;
    public:
    book()
    {
        title="";
        author="";
        copies=0;
        given=0;
    }
    book(string t,string a,int c,int g)
    {
        title=t;
        author=a;
        copies=c;
        given=g;
    }
    string rtitle()
    {
        return title;
    }
    string rauthor()
    {
        return author;
    }
    int rcopy()
    {
        return copies;
    }
    int rgiven()
    {
        return given;
    }
    void incgiven()
    {
        given=given+1;
    }
    void print()
    {
        cout<<"TITLE :"<<title<<endl<<"AUTHOR :"<<author<<endl<<"COPIES :"<<copies<<endl<<"GIVEN :"<<given<<endl<<endl;
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------------


class library
{
    private:
    book b[100];

    public:
    int n=0;
    library()
    {}
    void addbooks()
    {
        string t,a;
        int c;
        cout<<"Enter the details of book(title,author,copies) \n";
        cin>>t>>a>>c;
        b[n]=book(t,a,c,0);
        n++;
        cout<<"\nBOOKS SUCCESSFULLY ADDED\n";
    }
    void lendbooks()
    {
        int i;
        if(n==0)
        {
            cout<<"SORRY! NO BOOKS IN LIBRARY TO LEND\n\n";
            return;
        }
        cout<<"ENTER THE NAME OF THE BOOK\n";
        string bookname;
        cin>>bookname;
        int count=0;
        for(i=0;i<n;i++)
        {
            if(b[i].rtitle()==bookname)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<"\nBOOK NOT FOUND IN LIBRARY\n"<<endl;
        }
        else
        {
            if(b[i].rgiven()<b[i].rcopy())
            {
                b[i].incgiven();
                cout<<"\nLENDING SUCCESSFUL!\n";
            }
            else
            {
                cout<<"\nSORRY! NO COPY LEFT, TRY FOR ANOTHER BOOK\n";
            }
        }
    }
    void printbooks()
    {
        if(n==0)
        {
            cout<<"\nNO BOOKS IN LIBRARY\n";
        }
        int i;
        for(i=0;i<n;i++)
        {
            b[i].print();
        }
    }


};

//--------------------------------------------------------------------------------------------------------------------------------------------------


template<typename T>
void countMembersInBranch(T s[100], int n)
{
        string e;
        try
        {
            cout<<"ENTER BRANCH NAME(AS --> CS/EC/MECH/EEE)\n";
            cin>>e;
            if(e!="CS"&& e!="EC"&& e!="MECH"&& e!="EEE")
            {
                branch b1;
                throw b1;
            }
            else
            {
                int count=0,i=0;
                for(i=0;i<n;i++)
                {
                    if(s[i].rbranch()==e)
                    {
                        count++;
                    }
                }
                cout<<endl<<"TOTAL COUNT :"<<count<<endl<<endl;
            }
        }
        catch(exception& e1)
        {
            cout<<e1.what();
        }
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

class Singleton
{
    private:
    teacher t[100];
    student s[100];
    nonteachstaff st[100];
    std::vector<std::unique_ptr<Course>> courses;
    library l1;
    result r1;
    static Singleton* instancePtr;
    Singleton()
    {
    }
    public:
    Singleton(const Singleton& obj)= delete;
    static Singleton* getInstance()
    {
        if (instancePtr == NULL)
	    {
            instancePtr = new Singleton();
	        return instancePtr;
	    }
	    else
	    {
	        return instancePtr;
	    }
    }
    int n=0,n1=0,n2=0;
    void addteacher()
    {
        string a,c,e;
        int b,d;
        try
        {
            cout<<"ENTER NAME,AGE,ADDRESS,SALARY AND BRANCH(AS --> CS/EC/MECH/EEE)\n";
            cin>>a>>b>>c>>d>>e;
            if(e!="CS"&& e!="EC"&& e!="MECH"&& e!="EEE")
            {
                branch b1;
                throw b1;
            }
            else
            {
                cout<<"SUCCESSFULLY HIRED\n";
                t[n]=teacher(a,b,c,d,e);
                n++;
            }
        }
        catch(exception& e1)
        {
            cout<<e1.what();
        }

    }

    void addstudent()   //adds a new student to the university
    {
        if(n==0)
        {
            cout<<"SORRY! CAN'T ADMIT STUDENT WITHOUT A GUIDE\n";
            cout<<"FIRST HIRE TEACHERS \n";
        }
        else
        {
            string a,c,d,e,f;
            int b;
        try
        {
            cout<<"ENTER NAME,AGE,ADDRESS,BRANCH(AS --> CS/EC/MECH/EEE) ,USN(AS --> 01fe21+(branch)+number{3}) AND GUIDE\n";
            cin>>a>>b>>c>>e>>d>>f;
            if(e!="CS"&& e!="EC"&& e!="MECH"&& e!="EEE")
            {
                branch b1;
                throw b1;
            }
            else
            {

                std::regex pattern("01FE21B" + e + "[0-9]{3}");
                if(std::regex_match(d, pattern))
                {
                    cout<<"SUCCESSFULLY ADMITTED\n";
                    s[n1]=student(a,b,c,d,e,f);
                    n1++;
                }
                else
                {
                    cout<<"USN IS NOT IN THE SPECIFIED FORMAT\n\n";
                }
            }
        }
        catch(exception& e1)
        {
            cout<<e1.what();
        }

        }
    }
    void lbooks()
    {
        l1.lendbooks();
    }
    void printteacher()
    {
        if(n==0)
        {
            cout<<"SORRY! NO TEACHERS IN UNIVERSITY\n";
        }
        else
        {
            cout<<"\n-----LECTURES DETAILS-----\n";
            int i;
            for(i=0;i<n;i++)
            {
                t[i].printperson();
            }
            cout<<"\n\n";
        }
    }

    void printstudent()
    {
        if(n1==0)
        {
            cout<<"SORRY! NO STUDENTS IN UNIVERSITY\n";
        }
        else
        {
            cout<<"\n-----STUDENTS DETAILS-----\n";
            int i;
            for(i=0;i<n1;i++)
            {
                s[i].printperson();
            }
            cout<<"\n\n";
        }
    }

    void getresult()
    {
        cout<<"ENTER THE USN OF STUDENT\n";
        string u;
        cin>>u;
        int i,j;
        bool flag=false;
        for(i=0;i<n1;i++)
        {
            if(s[i].rusn()==u)
            {
                flag=true;
                break;
            }

        }
        if(flag==false)
        {
            cout<<"SORRY! COULDN'T FIND THE STUDENT\n";
        }
        else
        {
            s[i].assignmarks();
            j=r1.getresult(s[i]);
            cout<<"RESULT IN PERCENTAGE :"<<j<<" %"<<endl;
        }
    }

    void fireteacher()
    {
        if(n==0)
        {
            cout<<"SORRY! NO TEACHERS IN UNIVERSITY\n";
        }
        else
        {
            teacher m;
            string a;
            int i,count=0;
            cout<<"ENTER NAME OF THE TEACHER TO FIRE\n";
            cin>>a;
            for(i=0;i<n;i++)
            {
                if(t[i].tname()==a)
                {
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                cout<<"SORRY! CAN'T FIND THE TEACHER WITH ENTERED NAME\n";
            }
            else
            {
                m=t[i];
                t[i]=t[n-1];
                t[n-1]=m;
                n--;
                cout<<"FIRED TEACHER SUCCESSFULLY!\n";
            }
        }
    }

    void hirenonteastaff()
    {
        string a,c,e;
        int b,d;
        try
        {
            cout<<"ENTER NAME,AGE,ADDRESS,SALARY AND BRANCH(AS --> CS/EC/MECH/EEE)\n";
            cin>>a>>b>>c>>d>>e;
            if(e!="CS"&& e!="EC"&& e!="MECH"&& e!="EEE")
            {
                branch b1;
                throw b1;
            }
            else
            {
                cout<<"SUCCESSFULLY HIRED\n";
                st[n2]=nonteachstaff(a,b,c,d,e);
                n2++;
            }
        }
        catch(exception& e1)
        {
            cout<<e1.what();
        }
    }
    void fbranchteach()
    {
        countMembersInBranch<teacher>(t,n);
    }
    void fbranchstud()
    {
        countMembersInBranch<student>(s,n1);
    }
    void fbranchnonteach()
    {
        countMembersInBranch<nonteachstaff>(st,n2);
    }
    void fguide()
    {
        string a;
        int i,count=0;
        if(n1==0){cout<<"\nSORRY! NO STUDENTS IN THE UNIVERSITY\n";return;}
        cout<<"ENTER THE NAME OF GUIDE TO DISPLAY STUDENTS UNDER HIS GUIDANCE\n";
        cin>>a;
        for(i=0;i<n;i++)
        {
            if(t[i].tname()==a)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<"SORRY! CAN'T FIND THE TEACHER WITH ENTERED NAME\n";
        }
        else
        {
            int count=0;
            for(i=0;i<n1;i++)
            {
                if(s[i].rguide()==a)
                {
                    s[i].printperson();
                    count++;
                }
            }
            if(count==0)
            {
                cout<<"THERE ARE NO STUDENTS ALLOCATED TO ENTERED GUIDE\n";
            }
        }

    }

    void printnonteastaff()
    {
        int i;
        if(n2==0)
        {
            cout<<"SORRY! NO NON TEACHING STAFF HIRED\n";
        }
        else
        {
            cout<<"\n-----NON TEACHING STAFF DETAILS-----\n\n";
            for(i=0;i<n2;i++)
            {
                st[i].printperson();
            }
        }
    }

    void deletestudent()
    {
        if(n1==0)
        {
            cout<<"SORRY! NO STUDENTS IN UNIVERSITY\n";
        }
        else
        {
            student m;
            string a;
            int i,count=0;
            cout<<"ENTER NAME OF THE USN OF STUDENT TO FIRE\n";
            cin>>a;
            for(i=0;i<n1;i++)
            {
                if(s[i].rusn()==a)
                {
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                cout<<"SORRY! CAN'T FIND THE STUDENT WITH ENTERED USN\n";
            }
            else
            {
                m=s[i];
                s[i]=s[n1-1];
                s[n1-1]=m;
                n1--;
                cout<<"RESTICATED THE STUDENT SUCCESSFULLY!\n";
            }
        }
    }

    void firenonteastaff()
    {
        if(n2==0)
        {
            cout<<"SORRY! NO NON TEACHING STAFF IN UNIVERSITY\n";
        }
        else
        {
            nonteachstaff m;
            string a;
            int i,count=0;
            cout<<"ENTER NAME OF THE NON TEACHING STAFF TO FIRE\n";
            cin>>a;
            for(i=0;i<n2;i++)
            {
                if(st[i].stname()==a)
                {
                    count++;
                    break;
                }
            }
            if(count==0)
            {
                cout<<"SORRY! CAN'T FIND THE STUDENT WITH ENTERED USN\n";
            }
            else
            {
                m=st[i];
                st[i]=st[n2-1];
                st[n2-1]=m;
                n2--;
                cout<<"FIRED THE NON TEACHING STAFF SUCCESSFULLY!\n";
            }
        }
    }
    void addcourse(int choice)
    {
        if (choice == 1) {
            std::string courseName;
            int creditHours;
            std::cout << "Enter the name of the Core Course:\n";
            std::cin.ignore(); // Ignore any leftover newline character from previous input
            std::getline(std::cin, courseName);

            std::cout << "Enter the credit hours of the Core Course:\n";
            std::cin >> creditHours;

            courses.push_back(CourseFactory::createCourse(CourseFactory::CourseType::CORE, courseName, creditHours));
            cout<<"COURSE SUCCESSFULLY ADDED\n";
        } else if (choice == 2) {
            std::string courseName;
            int creditHours;
            std::cout << "Enter the name of the Elective Course:\n";
            std::cin.ignore(); // Ignore any leftover newline character from previous input
            std::getline(std::cin, courseName);

            std::cout << "Enter the credit hours of the Elective Course:\n";
            std::cin >> creditHours;


            courses.push_back(CourseFactory::createCourse(CourseFactory::CourseType::ELECTIVE, courseName, creditHours));
            cout<<"COURSE SUCCESSFULLY ADDED\n";
        }
    }

    void printcourse()
    {
        std::cout << "\n----- Course Information -----\n";
        for (const auto& course : courses)
        {
        if (course)
        {
            std::cout <<endl<<endl<<course->getInfo() <<std::endl<<endl;
        }
        }
    }
    void addbooks()
    {
        l1.addbooks();
    }
    void printbooks()
    {
        l1.printbooks();
    }
};

Singleton* Singleton ::instancePtr = NULL;


bool AuthenticateUser(const std::string& username, const std::string& password, int userType)
{
    UserManager userManager; // Create an instance of the UserManager class (You may have a global instance in your application)

    // Check if the user exists and if the provided password matches the stored password
    if (userManager.getUserType(username) == userType && userManager.getUserPass(username,password) == password)
    {
        return true;
    }

    return false;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    cout<<"\n\n---------------WELCOME TO UNIVERSITY MANAGEMENT SYSTEM-------------------\n\n";
    Singleton* u1= Singleton ::getInstance();//university class u1;
    Singleton* u2= Singleton ::getInstance();


    std::string username, password;
    int userType; // Assuming userType: 1 - Admin, 2 - Faculty, 3 - Student

    bool c=true;
    while(c){
    // Prompt the user for login credentials
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << "Select your user type:\n";
    std::cout << "1. Administrator\n";
    std::cout << "2. Faculty\n";
    std::cout << "3. Student\n";
    std::cout << "Enter your choice: ";
    std::cin >> userType;
    if(userType==1 || userType==2 || userType==3)
    {
        bool isAuthenticated = AuthenticateUser(username, password, userType);
        if(isAuthenticated) {
        std::cout << "Login successful!\n";
        c=false;
        // Add code to redirect the user to their respective dashboard here
        } else{
        std::cout << "Login failed. Invalid username or password.\n";
        }
    }
    else
    {
        cout<<"ENTER APPROPRIATE CHOICE\n";
    }

    }

    int d;
    while(1)
    {
        cout<<"ENTER 1 TO ADMIT STUDENT INTO UNIVERSITY\n";//ADDSTUDENT
        cout<<"ENTER 2 TO HIRE LECTURER FOR UNIVERSITY\n";//ADDTEACHER
        cout<<"ENTER 3 TO DISPLAY RESULTS OF STUDENTS\n";//GETRESULTS
        cout<<"ENTER 4 TO DISPLAY DETAILS OF STUDENTS IN UNIVERSITY\n";//PRINTSTUDENT
        cout<<"ENTER 5 TO DISPLAY DETAILS OF LECTURERS IN UNIVERSITY\n";//PRINTTEACHER
        cout<<"ENTER 6 TO HIRE NON TEACHING STAFF FOR UNIVERSITY\n";//hirenonteastaff
        cout<<"ENTER 7 TO DISPLAY DETAILS OF NON TEACHING STAFF IN UNIVERSITY\n";//printnonteastaff
        cout<<"ENTER 8 TO RESTICATE STUDENT\n";//deletestudent
        cout<<"ENTER 9 TO FIRE LECTURER\n";//FIRETEACHER
        cout<<"ENTER 10 TO FIRE NON TEACHING STAFF MEMBER\n";//firenonteastaff
        cout<<"ENTER 11 TO FIND DETAILS OF STUDENTS UNDER PARTICULAR GUIDE\n";//FGUIDE
        cout<<"ENTER 12 TO ADD BOOK TO LIBRARY\n";
        cout<<"ENTER 13 TO PRINT BOOKS IN LIBRARY\n";
        cout<<"ENTER 14 TO BORROW BOOK FROM LIBRARY\n";//LBOOKS()
        cout<<"ENTER 15 TO ADD COURSE TO UNIVERSIY\n";//addcourse()
        cout<<"ENTER 16 TO PRINT COURSES OF UNIVERSITY\n";//printcourse()
        cout<<"ENTER 17 TO PRINT COUNT OF NO. OF TEACHERS THAT BELONG TO PARTICULAR BRANCH\n";
        cout<<"ENTER 18 TO PRINT COUNT OF NO. OF STUDENTS THAT BELONG TO PARTICULAR BRANCH\n";
        cout<<"ENTER 19 TO PRINT COUNT OF NO. OF NON TEACHING STAFF THAT BELONG TO PARTICULAR BRANCH\n";
        cout<<"ENTER 20 TO EXIT FROM APPLICATION\n";

        cout<<"\nENTER YOUR CHOICE\n";
        cin>>d;
        switch(d)
        {
            case 1:if(userType==1){u1->addstudent();break;}
                   else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 2:if(userType==1){u1->addteacher();break;}
                   else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 3:u1->getresult();
                   break;
            case 4:u1->printstudent();
                   break;
            case 5:u1->printteacher();
                   break;
            case 6:if(userType==1){u1->hirenonteastaff();break;}
                   else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 7:u1->printnonteastaff();
                   break;
            case 8:if(userType==1){u1->deletestudent();break;}
                   else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 9:if(userType==1){u1->fireteacher();break;}
                   else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 10:if(userType==1){u1->firenonteastaff();break;}
                    else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 11:u1->fguide();
                   break;
            case 12:u1->printbooks();
                    break;
            case 13:if(userType==1){u1->addbooks();break;}
                    else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 14:u1->lbooks();
                    break;
            case 15:if(userType==1){std::cout <<"\nEnter 1 to add a Core Course, 2 to add an Elective Course\n";
                    int choice;
                    std::cin >> choice;
                    u1->addcourse(choice);
                    break;}
                    else{cout<<"\nSORRY! YOU CAN'T ACCESS THIS FEATURE\n\n";break;}
            case 16:u1->printcourse();
                    break;
            case 17:u1->fbranchteach();
                    break;
            case 18:u1->fbranchstud();
                    break;
            case 19:u1->fbranchnonteach();
                    break;
            case 20:exit(0);
                    break;
            default:cout<<"INVALID CHOICE!\n\n";
                    break;
        }
    }

}
