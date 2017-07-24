
class registeration{
    char temp[1000];
    std::string collegename,password,confirmpassword,collegetype,state,researchfield,city;
public:
    registeration(){
        system("cls");
        std::cout << "\n          *******************  Welcome to College/University Registeration Portal  *********************"<< std::endl<< std::endl<< std::endl<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "    Enter the college name : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "                      City : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "                     State : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "              College Type : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "            Research Field : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        std::cout << "                  Passowrd : "<< std::endl << std::endl ;
        std::cout << "    ----------------------"<< std::endl << std::endl ;
        gotoxy(29,8);
        getchar();
        gets(temp);
        collegename = temp;
        gotoxy(29,12);
        gets(temp);
        city = temp;
        gotoxy(29,16);
        gets(temp);
        state = temp;
        gotoxy(29,20);
        gets(temp);
        collegetype = temp;
        gotoxy(29,24);
        gets(temp);
        researchfield = temp;
        gotoxy(29,28);
        std::cin >> password;
        csvinput(*this);
        usercredential(*this);
    }
    friend int usercredential(registeration);
    friend void csvinput(registeration);
};


void csvinput(registeration r){
    std::fstream fp;
    fp.open("csv files/colleges_details.csv",std::ios::app);
    fp<<r.collegename<<",";
    fp<<r.city<<",";
    fp<<r.state<<",";
    fp<<r.collegetype<<",";
    fp<<r.researchfield<<"\n";
    fp.close();
    fp.open("csv files/usercredential.csv",std::ios::app);
    fp<<r.collegename<<","<<r.password<<"\n";
    fp.close();
}
