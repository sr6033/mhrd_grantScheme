#include"encryption.cpp"

std::string gethiddenpassword();

class credentials{
    std::string username,password;
    //char temp1[100], temp2[100];
public:
    void getusername(){
    	getline(std::cin,username);
    }
    void getpassword(){
    	password = gethiddenpassword();
	}
    friend int usercredential(credentials);
    friend int adminkey(credentials);
};

#include"usercredential.cpp"

void userui(){
    credentials c;
    
    while(1){
    	std::cin.ignore();
        system("cls");
        std::cout<< "\n **********************************  Welcome to College/University Portal  *********************************"<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
        std::string collegename,password;
        std::cout<< "                                 ----------------------"<< std::endl;
        std::cout<< "                                 Enter the college name : "<< std::endl;
        std::cout<< "                                 ----------------------"<< std::endl;
        std::cout<< "                                               Password : ";
        std::cout<< "\n                                 ----------------------"<< std::endl;
        gotoxy(58,7);
        c.getusername();
        std::cout<< "\n                                               Password : ";
        gotoxy(58,9);
        c.getpassword();
        
        if(!usercredential(c)){
        	//std::cout << "Wrong username password combination" << std::endl;
		}
    }
}

std::string gethiddenpassword(){
    int i = 0;
    char c,pass[100];
    while(1){
        c = getch();
        if(c == '\b' and i <= 0){
            continue;
        }
        if(c == 13){
            break;
        } else if(c == '\b'){
            std::cout<< "\b";
            std::cout<< " ";
            std::cout<< "\b";
            i--;
        } else {
            std::cout<< "*";
            pass[i++] = c;
        }
    }
    pass[i] = '\0';
    std::string str = std::string(pass);
    std::cout<< "\n";
    return str;
}
