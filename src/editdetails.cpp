void csvedit(std::string);
class CollegeDetailslege_details;
class College_Details{
public:
	std::string collegename,collegename1,password,confirmpassword,collegetype,state,researchfield,city;
	char temp[1000];
	friend void csveditinput(std::string);
    College_Details(std::string collegename){
    		this->collegename = collegename;
            std::fstream fp;
            std::string filecollegename,filepassword;
            fp.open("csv files/colleges_details.csv",std::ios::in);
            while(!fp.eof()){
                getline(fp,filecollegename,',');
                if( filecollegename == collegename ){
                    system("cls");
                    std::cout << "\n          ===================  Overwrite your Details  ====================="<< std::endl<< std::endl<< std::endl<< std::endl << std::endl ;
                    std::cout << "    ----------------------"<< std::endl ;
                    std::cout << "         College name old : "<< filecollegename << std::endl;
					std::cout << "         College name new : "<< std::endl;
                    std::cout << "    ----------------------"<< std::endl ;
                    getline(fp,filecollegename,',');
                    std::cout << "                 City old : "<<filecollegename<< std::endl ;
					std::cout << "                 City new : "<< std::endl ;
                    std::cout << "    ----------------------"<< std::endl ;
                    getline(fp,filecollegename,',');
                    std::cout << "                State old : "<<filecollegename<< std::endl ;
					std::cout << "                State new : "<< std::endl ;
                    std::cout << "    ----------------------"<< std::endl ;
                    getline(fp,filecollegename,',');
                    std::cout << "         College Type old : "<<filecollegename<< std::endl ;
					std::cout << "         College Type new : "<< std::endl ;
                    std::cout << "    ----------------------"<< std::endl ;
                    getline(fp,filecollegename,'\n');
                    std::cout << "       Research Field old : "<<filecollegename<< std::endl;
					std::cout << "       Research Field new : "<< std::endl ;
                    std::cout << "    ----------------------"<< std::endl ;
                    std::cout << "             new Password : "<< std::endl ;
                    std::cout << "    ----------------------"<< std::endl << std::endl ;
					gotoxy(28,8);
					getchar();
					gets(temp);
        			collegename1 = temp;
                    gotoxy(28,11);
					gets(temp);
        			city = temp;
                    gotoxy(28,14);
					gets(temp);
        			state = temp;
                    gotoxy(28,17);
					gets(temp);
        			collegetype = temp;
                    gotoxy(28,20);
					gets(temp);
        			researchfield = temp;
                    gotoxy(28,22);
                    std::cin >> password;
                }
                getline(fp,filepassword,'\n');
            }
        }
};

void csveditinput(College_Details ob){
    std::string collegename,password,confirmpassword,collegetype,state,researchfield,city;
    std::fstream fpold,fpnew;
    fpold.open("csv files/colleges_details.csv",std::ios::in);
    fpnew.open("csv files/temp.csv",std::ios::out);
	getline(fpold,collegename,',');
	getline(fpold,city,',');
	getline(fpold,state,',');
	getline(fpold,collegetype,',');
	getline(fpold,researchfield,'\n');
    while(!fpold.eof()){
        if( collegename == ob.collegename){
            fpnew<<ob.collegename1<<","<<ob.city<<","<<ob.state<<","<<ob.collegetype<<","<<ob.researchfield<<std::endl;
        } else {
            fpnew<<collegename<<","<<city<<","<<state<<","<<collegetype<<","<<researchfield<<std::endl;
        }
		getline(fpold,collegename,',');
        getline(fpold,city,',');
        getline(fpold,state,',');
        getline(fpold,collegetype,',');
        getline(fpold,researchfield,'\n');
    }
	fpold.close();
	fpnew.close();
	remove("csv files/colleges_details.csv");
	rename("csv files/temp.csv","csv files/colleges_details.csv");
	fpold.open("csv files/usercredential.csv",std::ios::in);
    fpnew.open("csv files/temp.csv",std::ios::out);
	getline(fpold,collegename,',');
	getline(fpold,password,'\n');
    while(!fpold.eof()){
        if( collegename == ob.collegename){
            fpnew<<ob.collegename1<<","<<ob.password<<std::endl;
        } else {
            fpnew<<collegename<<","<<password<<std::endl;
        }
		getline(fpold,collegename,',');
        getline(fpold,password,'\n');
    }
	fpold.close();
	fpnew.close();
	remove("csv files/usercredential.csv");
	rename("csv files/temp.csv","csv files/usercredential.csv");

}

void csvedit(std::string collegename){
    system("cls");
	College_Details c(collegename);
    csveditinput(c);
}
