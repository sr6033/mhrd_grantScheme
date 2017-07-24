#include"editdetails.cpp"
#include "grant.cpp"

void useroperationui(std::string collegename){
    int operation;
    grant ob;
    
    while(1){
        system("cls");
        std::cout << "\n\t\t=======================  WELCOME TO "<<collegename<<" PORTAL ==========================\n\n\n" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t1. Grant increasse" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t2. Apply for new research grant" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t3. Edit Details" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------" << std::endl;
        std::cout << "     \t\t\t\t4. Logout" << std::endl;
        std::cout << "     \t\t\t\t---------------------------------\n\n\n\n\n" << std::endl;

        std::cout << "\n\nEnter your choice : ";
        std::cin >> operation;
        switch (operation){
            case (1) : ob.grant_increase(collegename);
                        break;
            case (2) : ob.new_grantfunc(collegename);
                        break;
            case (3) : csvedit(collegename);
                        break;
            case (4) : return;
        }
    }
}
