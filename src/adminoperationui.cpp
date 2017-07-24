
void edit_password(){
    std::string username,password;
    std::string new_password;
    system("cls");
    gotoxy(36,7);
    std::cout << "Enter new password : " ;
    std ::cin >> new_password;
    std::fstream fpold,fpnew;
    fpold.open("csv files/admincredentials.csv",std::ios::in);
    fpnew.open("csv files/temp.csv",std::ios::out);
    getline(fpold,username,',');
    fpnew<<username<<","<<new_password<<std::endl;
    fpnew.close();
    fpold.close();
    remove("csv files/admincredentials.csv");
    rename("csv files/temp.csv","csv files/admincredentials.csv");

}

void list(){
    system("cls");
    std::cout << "\n\t\t***********************  College List **************************\n\n\n" << std::endl;
    std::string college_name,temp;
    int i = 1;
    std::fstream fp;
    fp.open("csv files/usercredential.csv",std::ios::in);
    getline(fp,college_name,',');
    getline(fp,temp,'\n');
    while(!fp.eof()){
        gotoxy(36,3+i);
        std::cout <<i<< ". " << college_name << std::endl;
        i++;
        getline(fp,college_name,',');
        getline(fp,temp,'\n');
    }
    system("pause");
}

void adminoperation(){
    int operation;
    while(1){
        system("cls");
        std::cout << "\n\t\t***********************  WELCOME TO Administrator PORTAL **************************\n\n\n" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t1. List of colleges" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t2. Edit college Details" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t3. change Administrator password" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t4. Logout" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------\n\n\n\n\n" << std::endl;

        std::cout << "\n\nEnter your choice : ";
        std::cin >> operation;
        std::cout<<operation;
        switch (operation){
            case (1) : list();
                       break;
            case (2) : {std::string s;
            		   std::cout<<"\t\t\t\tEnter College name: ";
            		   std::cin>>s;
					   csvedit(s);
                       break;}
            case (3) : edit_password();
                       break;
            case (4) : return;
        }
    }
}
