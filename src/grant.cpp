#include<string>
#include <fstream>
#include "grant_edit.cpp"

class grant
{
	public:
			std::string new_grant, college_name;
			int rate, total_projects, completed_projects;
			double old_grant;
			void get_grant()
			{
				std::cin>>new_grant;
			}
			
			void rate_calc(std::string);
			void grant_increase(std::string);
			void found(grant);
			void new_grantfunc(std::string);
};

#include "new_grant.cpp"

void grant::rate_calc(std::string college_name)
{
	std::fstream fp1;
	
	std::string file_college_name, temp_projects, temp_completed, str_grant, r;
	int projects;
	double completed;
	
	std::fstream fp2;
	std::fstream fpnew;

	fp1.open("csv files/project.csv",std::ios::in);
	fpnew.open("csv files/temp.csv",std::ios::out);
	
	fp2.open("csv files/grant.csv",std::ios::in);
	getline(fp2,file_college_name,',');
	getline(fp2,str_grant,',');
	getline(fp2,r,'\n');
	while(!fp2.eof())
	{
		getline(fp1,file_college_name,',');
		getline(fp1,temp_projects,',');
		getline(fp1,temp_completed,'\n');
	
		projects = atoi(temp_projects.c_str());
		completed = atoi(temp_completed.c_str());
	
		double rr = (completed / projects) * 10;
	
        fpnew<<file_college_name<<","<<str_grant<<","<<rr<<std::endl;
        
        if(file_college_name == college_name)
        {
        	this->college_name = college_name;
        	this->new_grant = atof(str_grant.c_str());
        	this->rate = rr;
		}
        
        getline(fp2,file_college_name,',');
		getline(fp2,str_grant,',');
		getline(fp2,r,'\n');
    }
    
    fp1.close();
    fp2.close();
    fpnew.close();
    
	std::remove("csv files/grant.csv");
    std::rename("csv files/temp.csv", "csv files/grant.csv"); 
}

void grant::grant_increase(std::string college_name)
{
	grant obj;
	
	rate_calc(college_name);
    std::fstream fp1;
    std::fstream fp2;
    std::string fileusername, str_grant, r, projects, completed;
        
    fp1.open("csv files/grant.csv",std::ios::in);
    fp2.open("csv files/project.csv",std::ios::in);
    while(1){
        getline(fp1,fileusername,',');
        getline(fp1,str_grant,',');
        getline(fp1,r,'\n');
        
		getline(fp2,fileusername,',');
        getline(fp2,projects,',');
        getline(fp2,completed,'\n');
        
        if( fileusername == college_name )
		{
			obj.college_name = college_name;
			obj.old_grant = atof(str_grant.c_str());
			obj.rate = atoi(r.c_str());
			
			obj.total_projects = atof(projects.c_str());
			obj.completed_projects = atof(completed.c_str());
			
            fp1.close();
            fp2.close();
            found(obj);
            break;
        }
    }
}
void grant::found(grant obj)
{	
	system("cls");
    std::cout<< "\n **********************************  Welcome to College/University Portal  *********************************"<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
    std::string new_grant;
    std::cout<< "                                 --------------------"<< std::endl;
    std::cout<< "                                 	      College : "<<obj.college_name<< std::endl;
    std::cout<< "                                 --------------------"<< std::endl;
    std::cout<< "                                 Enter New Grant(Rs.) : ";
    std::cout<< "\n                                 --------------------"<< std::endl;
    
	gotoxy(56,9);
	obj.get_grant();
	
	double default_grant = obj.old_grant + (obj.old_grant * obj.rate); 
	double g = atof(obj.new_grant.c_str());
	
	if(obj.completed_projects > (obj.total_projects / 4.0))
	{
		if(default_grant > g)
		{
			grant_edit(g, obj.college_name, 0);
			gotoxy(41,15);
			std::cout<<"New grant amount Accepted!"<<std::endl;
		}
		else
		{
			grant_edit(default_grant, obj.college_name, 0);
			gotoxy(41,15);
			std::cout<<"New grant amount = Rs."<<default_grant<<std::endl;
		}
	}
	else
	{
		gotoxy(21,15);
		std::cout<<"You are not eligible for increasing your grant."<<std::endl;
		gotoxy(21,16);
		std::cout<<obj.completed_projects<<" out of "<<obj.total_projects<<" projects are completed which doesn't suffice the criteria."<<std::endl;
	}
    
    system("pause");
}

