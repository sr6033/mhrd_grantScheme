#include <sstream>

template <typename T>
std::string to_string(T const& value) {
    std::stringstream sstr;
    sstr << value;
    return sstr.str();
}

void grant_edit(double g, std::string c, int f)
{
	std::string fileusername, str_grant, r;
	
	std::fstream fp1;
	std::fstream fp2;
	
	fp1.open("csv files/grant.csv",std::ios::in);
	fp2.open("csv files/temp.csv",std::ios::out);
	
	getline(fp1,fileusername,',');
    getline(fp1,str_grant,',');
    getline(fp1,r,'\n');
	
	while(!fp1.eof())
	{	
		if(f == 0)	//for increasing grant of existing project
		{
        	if( fileusername == c )
    		{
    			std::string s = to_string(g);
				fp2<<fileusername<<","<<s<<","<<r<<std::endl;
			}
        	else
        		fp2<<fileusername<<","<<str_grant<<","<<r<<std::endl;
    	}
    	else		//for new project grant
    	{
    		if( fileusername == c )
    		{
    			double calc = g + atof(str_grant.c_str());
    			std::string s = to_string(calc);
				fp2<<fileusername<<","<<s<<","<<r<<std::endl;
			}
        	else
        		fp2<<fileusername<<","<<str_grant<<","<<r<<std::endl;
		}
        getline(fp1,fileusername,',');
        getline(fp1,str_grant,',');
        getline(fp1,r,'\n');
    }
    fp1.close();
    fp2.close();
    
    std::remove("csv files/grant.csv");
    std::rename("csv files/temp.csv", "csv files/grant.csv");
}

//void grant_edit_new(double g, std::string c, int p)
	
