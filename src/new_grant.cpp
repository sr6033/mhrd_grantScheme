
void grant::new_grantfunc(std::string college_name)
{
	grant ob;
	int p;
	double calc_grant;
	std::string input_grant;
	
	system("cls");
    std::cout<< "\n **********************************  Welcome to College/University Portal  *********************************"<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
    std::cout<< "                                 ------------------------"<< std::endl;
    std::cout<< "                                 Enter number of Projects : "<< std::endl;
    std::cout<< "                                 ------------------------"<< std::endl;
    std::cout<< "                                   Enter new Grant amount : ";
    std::cout<< "\n                                 ------------------------"<< std::endl;
    gotoxy(60,7);
    std::cin>>p;
    gotoxy(60,9);
    
    std::cin>>input_grant;
    
	double old_grant = atof(input_grant.c_str());
	ob.rate_calc(college_name);

	calc_grant = old_grant * p * ob.rate;

	if(calc_grant > old_grant) 
	{
		std::cout<<"\n\n\t\t\t\tAccepted extra grant ammount = Rs."<<old_grant<<std::endl;
		grant_edit(old_grant, ob.college_name, 1);
	}
	else
	{
		std::cout<<"\n\n\t\t\t\tAccepted extra grant ammount = Rs."<<calc_grant<<" as per criterias set."<<std::endl;
		grant_edit(calc_grant, ob.college_name, 1);
	}
	std::cout<<std::endl<<std::endl;
	system("pause");

}
