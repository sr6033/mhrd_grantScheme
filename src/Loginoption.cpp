#include"userui.cpp"
#include"adminui.cpp"

int loginoption(){
    while(1){
        system("cls");
        int operation;
        std::cout << "    **********************  Ministry of Human Resource Development About MHRD  ************************\n" << std::endl;
        std::cout << "    The Ministry of Human Resource Development, formerly Ministry of Education (until 25 September 1985),\n    is responsible for the development of human resources in India. The Ministry is divided into two \n    departments: the Department of School Education and Literacy, which deals with primary, secondary and \n    higher secondary education, adult education and literacy, and the Department of Higher Education, which \n  \tdeals with university education, technical education, scholarship etc.\n\n\n" << std::endl;
        std::cout << "     -----------"<< std::endl;
        std::cout << "     *  Login ---------------->       LOGIN AS"<< std::endl;
        std::cout << "     -----------               ----------------------"<< std::endl;
        std::cout << "     *  Register                1. MHRD Administrator"<< std::endl;
        std::cout << "     -----------               ----------------------"<< std::endl;
        std::cout << "                                2. College/university"<< std::endl;
        std::cout << "                               ----------------------"<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> operation;
        switch (operation){
            case (1) : adminui();
                       break;
            case (2) : userui();
                       break;
        }
    }
    return 0;
}
