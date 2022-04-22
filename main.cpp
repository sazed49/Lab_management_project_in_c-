#include<iostream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int n;

int stoi(string s)
{ 


    int len=s.size();
    int num=0;
    for(int i=len-1; i>=0; i--)
    {
        num+=(s[i]-48);
        num*=10;
    }
    num/=10;
    return num;

}

class student_num
{

    int total_num=0;
    string roll5;
    int count=0,total=0;

public:
    student_num()
    {
        total_num=0;
        roll5="1707030";
    }

    student_num(string roll9)
    {
        roll5=roll9;
        fstream fin;
        fin.open("Lab_marks.csv",ios::in);


        vector<string>row1;
        string word,line;

        while(!fin.eof())
        {
            row1.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row1.push_back(word);

            }
            int row_size=row1.size();
            int num=0;

            if(row1[0]==roll9)
            {

                for(int i=1; i<row_size; i++)
                {

                    num = stoi(row1[i]);
                    total+=num;
                }




            }


            count++;
            if(count==30)break;


        }

        fin.close();
        total_num=total;
    }


    student_num operator+(student_num std2)
    {
        student_num std3;
        if(this->total_num>=std2.total_num)
        {
            std3.total_num=this->total_num;
            std3.roll5=this->roll5;

        }
        else
        {
            std3.total_num=std2.total_num;
            std3.roll5=std2.roll5;
        }
        return std3;
    }
    friend class teacher;







};


class student
{

    int cost,amount;
    string name,day,time,ename,cname,sroll,sname,sphn,sirname,sirdeg,sirphn,roll;

public:
    string pass_new;
    string name_new;

    virtual void file_read()
    {
s:
        cout<<"PLEASE ENTER YOUR ID\n";
        cin>>roll;
t:
        cout<<"PLEASE ENTER YOUR PASSWORD\n";
        string pass;
        cin>>pass;
        cout<<endl;
        ifstream inf("user_pass.txt");
        int flag=0;
        for(int i=0; i<30; i++)
        {
            inf>>name_new;
            inf>>pass_new;
            if(name_new==roll && pass_new==pass)
            {
                cout<<"\t\t********WELCOME "<<roll<<"********"<<endl;
d:
                cout<<"\t1.show routine\n\t2.show equipment\n\t3.show mark\n\t4.show student list\n\t5.show teacher list\n\t6.log out\n";
                cout<<"enter your choice\n";
                int e;
                cin>>e;
                if(e==1)
                {
                    show_routine();
                    cout<<endl;
                    goto d;


                }
                if(e==2)
                {
                    show_equipment();
                    cout<<endl;
                    goto d;
                }
                if(e==3)
                {
                    show_mark(roll);
                    cout<<endl;
                    goto d;
                }
                if(e==4)
                {
                    show_slist();
                    cout<<endl;
                    goto d;
                }
                if(e==5)
                {
                    show_sirlist();
                    cout<<endl;
                    goto d;

                }
                if(e==6)
                {
                    cout<<"\t*******THANK YOU FOR USING THIS APPLICATION*******\n";
                    return ;
                }


                flag=1;

            }
            else if(name_new==roll && pass_new!=pass)
            {
                cout<<"Invalid Pass"<<endl;
                goto t;
                flag=1;
            }

        }
        if(!flag)
        {
            cout<<"Invalid ID"<<endl;
            goto s;
        }


        inf.close();
    }
    void show_mark()
    {
        fstream fin;
        fin.open("Lab_marks.csv",ios::in);

        int number,number2,count=0,total=0;
        vector<string>row1;
        string word,line,roll2;
        cout<<"enter a roll ";
        cin>>roll2;
        while(!fin.eof())
        {
            row1.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row1.push_back(word);

            }
            int row_size=row1.size();
            int num=0;

            if(row1[0]==roll2)
            {
                cout<<"Number of the student:\n";
                for(int i=1; i<row_size; i++)
                {
                    cout<<"Lab "<<i<<": "<<row1[i]<<endl;
                    num = stoi(row1[i]);
                    total+=num;
                }
                cout<<"Total Marks: "<<total<<endl;
                printf("Average Marks: %.2lf\n",(((double)total)/(row_size-1)));
                printf("Rate of Performance: %.2lf",((((double)total)/(10*(row_size-1)))*100));
                cout<<"%\n";

            }


            count++;
            if(count==30)break;


        }

        fin.close();

    }
    void show_mark(string roll2)
    {
        fstream fin;
        fin.open("Lab_marks.csv",ios::in);

        int number,number2,count=0,total=0;
        vector<string>row1;
        string word,line;

        while(!fin.eof())
        {
            row1.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row1.push_back(word);

            }
            int row_size=row1.size();
            int num=0;

            if(row1[0]==roll2)
            {
                cout<<"Number of the student:\n";
                for(int i=1; i<row_size; i++)
                {
                    cout<<"Lab "<<i<<": "<<row1[i]<<endl;
                    num = stoi(row1[i]);
                    total+=num;
                }
                cout<<"Total Marks: "<<total<<endl;
                printf("Average Marks: %.2lf\n",(((double)total)/(row_size-1)));
                printf("Rate of Performance: %.2lf",((((double)total)/(10*(row_size-1)))*100));
                cout<<"%\n";
            }


            count++;
            if(count==30)break;


        }

        fin.close();

    }



    void input_marks()
    {
        fstream fin,fout;
        fin.open("Lab_marks.csv",ios::in);
        fout.open("Lab_marks2.csv",ios::out | ios::app);

        int number,number2,count=0;
        vector<string>row1;
        string word,line;

        while(!fin.eof())
        {
            row1.clear();
            getline(fin,line);
            stringstream s(line);

            while(getline(s,word,','))
            {
                row1.push_back(word);
                fout<<word<<",";
            }
            cout<<"Input Number for roll: "<<row1[0]<<endl;

            cin>>number;
            fout<<number<<"\n";
            count++;
            if(count==30)break;


        }
        fin.close();
        fout.close();
        remove("Lab_marks.csv");
        rename("Lab_marks2.csv","Lab_marks.csv");

    }


    void creat_routine()
    {
        ofstream outf("routine.txt");

        for(int i=0; i<4; i++)
        {
            cout<<"group:";
            cin>>name;


            outf<<name<<" ";

            cout<<"day:";

            cin>>day;
            outf<<day<<" ";
            cout<<"time:";
            cin>>time;
            outf<<time<<endl;
        }
        outf.close();
    }
    void show_routine()
    {
        ifstream inf("routine.txt");
        for(int i=0; i<4; i++)
        {
            inf>>name;
            inf>>day;
            inf>>time;

            cout<<"\t"<<name<< " "<<day<<" "<<time<<endl;
        }
        inf.close();

    }
    void add_equipment()
    {
        fstream outf;
        outf.open("equipment.txt",ios::out | ios::app);
        cout<<"add how many?";

        cin>>n;


        for(int i=0; i<n; i++)
        {
            cout<<"name of equipment:";
            cin>>ename;


            outf<<ename<<"\t ";

            cout<<"company name:";

            cin>>cname;
            outf<<cname<<" \t";
            cout<<"amount:";
            cin>>amount;
            outf<<amount<<"\t ";
            cout<<"price per equipment:";
            cin>>cost;
            cout<<endl;
            outf<<cost<<endl;
        }
        outf.close();
    }
    void show_equipment()

    {
        cout<<"\titem\t company  amount  price\n";
        ifstream inf("equipment.txt");
        string show;
        while(!inf.eof())
        {
            getline(inf,show);
            cout<<"\t"<<show<<" "<<endl;

        }
        inf.close();//system("FB_IMG_1542631341519.jpg");
    }
    void student_list()
    {
        ofstream outf("studentlist.txt");


        for(int i=0; i<30; i++)
        {
            cout<<"roll:";
            cin>>sroll;


            outf<<sroll<<" ";

            cout<<"student name:";

            cin>>sname;
            outf<<sname<<" ";
            cout<<"phone no:";
            cin>>sphn;
            outf<<sphn<<endl;

        }
        outf.close();
    }
    void show_slist()

    {
        cout<<"\tROLL\t NAME\t\t PHONE NUMBER\n";
        cout<<endl;
        ifstream inf("studentlist.txt");
        for(int i=0; i<30; i++)
        {
            inf>>sroll;
            inf>>sname;
            inf>>sphn;

            cout<<"\t"<<sroll<< "  "<<sname<<"  "<<sphn<<endl;
        }
        inf.close();
    }

    void teacher_list()
    {
        ofstream outf("teacherlist.txt");


        for(int i=0; i<2; i++)
        {
            cout<<"name:";
            cin>>sirname;


            outf<<sirname<<" ";

            cout<<"designation:";

            cin>>sirdeg;
            outf<<sirdeg<<" ";
            cout<<"phone no:";
            cin>>sirphn;
            outf<<sirphn<<endl;

        }
        outf.close();
    }
    void show_sirlist()

    {
        cout<<"\tname\t\t designation\t PHONE NUMBER\n";
        cout<<endl;
        ifstream inf("teacherlist.txt");
        for(int i=0; i<2; i++)
        {
            inf>>sirname;
            inf>>sirdeg;
            inf>>sirphn;

            cout<<"\t"<<sirname<< "  "<<sirdeg<<"  "<<sirphn<<endl;
        }
        inf.close();
    }


};
class
    teacher : public student
{
public:
    int n;
    void file_read()
    {
s:
        cout<<"Please Enter your ID Sir\n";
        string roll;
        cin>>roll;
t:
        cout<<"Password Please\n";
        string pass;
        cin>>pass;
        cout<<endl;
        ifstream inf("user_pass.txt");
        int flag=0;
        for(int i=0; i<2; i++)
        {
            inf>>name_new;
            inf>>pass_new;
            if(name_new==roll && pass_new==pass)
            {
                cout<<"\t*********WELCOME "<<" "<<roll<<"***********"<<endl;
d:
                cout<<"\t1.create routine\n\t2.show routine\n\t3.create student list\n\t4.show student list\n\t5.create teacher list\n\t6.show teacher lista\n\t7.add mark\n\t8.show mark \n\t9.add equipment\n\t10.show equipment\n\t11.Compare Student\n\t12.log out\n";
                cout<<"enter your choice\n";
                int e;
                cin>>e;
                if(e==1)
                {
                    creat_routine();
                    goto d;
                }
                if(e==2)
                {
                    show_routine();
                    cout<<endl;
                    goto d;

                }
                if(e==3)
                {
                    student_list();
                    cout<<endl;
                    goto d;

                }
                if(e==4)
                {
                    show_slist();
                    cout<<endl;
                    goto d;

                }
                if(e==5)
                {
                    teacher_list();
                    cout<<endl;
                    goto d;

                }

                if(e==6)
                {
                    show_sirlist();
                    cout<<endl;
                    goto d;

                }
                if(e==7)
                {
                    input_marks();
                    cout<<endl;
                    goto d;
                }

                if(e==8)
                {
                    show_mark();
                    cout<<endl;
                    goto d;
                }
                if(e==9)
                {
                    add_equipment();
                    cout<<endl;

                    goto d;
                }

                if(e==10)
                {
                    show_equipment();
                    cout<<endl;
                    goto d;
                }
                if(e==11)
                {
                    compare();
                    cout<<endl;
                    goto d;
                }
                if(e==12)
                {
                    cout<<"\t******THANK YOU FOR USING THIS APPLICATION******\n";
                    return;
                }
                flag=1;
            }
            else if(name_new==roll && pass_new!=pass)
            {
                cout<<"Invalid Pass"<<endl;
                goto t;
                flag=1;
            }

        }
        if(!flag)
        {
            cout<<"Invalid ID"<<endl;
            goto s;
        }
        inf.close();
    }
    void compare()
    {
        student_num std3;
        string x,y;
        cout<<"\nEnter 1st roll: ";
        cin>>x;
        cout<<"\nEnter 2nd roll: ";
        cin>>y;
        student_num std1(x),std2(y);
        std3=std1+std2;
        cout<<"\nThe Better performing Student is "<<std3.roll5<<" consisting of total marks "<<std3.total_num<<endl;



    }
};

int main()
{
    student b,*bptr;
    teacher a;
    cout<<"\t\t**************************************************************\n";
    cout<<"\t\t\t*************************************************\n";
    cout<<"\t\t\t\t***************************\n";
    cout<<endl;
    cout<<"\t\t\t\tWELCOME TO  CPP LAB MANAGEMENT\t\n";
    cout<<endl;
    cout<<"\t1.LOG IN\n\t2.EXIT";
    int c;
    cout<<endl;
    cout<<"Enter your choice\n";
    cin>>c;
    if(c==1)
    {
        cout<<"1.STUDENT\n2.TEACHER\n";
        int x;
        cin>>x;
        if(x==1)
        {
            bptr=&b;
            bptr->file_read();
        }
        else
        {
            bptr=&a;
            bptr->file_read();
        }
    }
    return 0;
}
