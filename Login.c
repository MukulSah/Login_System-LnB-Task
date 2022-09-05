#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ENTER 13 
#define TAB 9
#define BAKSPC 8

struct user{
	char username[50];
	char fullname[50];
	char email[50];
	char phone[50];
	char password[50];
}user,usr,ffuser;

void takeinput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
}

char generateUsername(char email[50],char username[50]){
	int i;
	for(i=0;i<strlen(email);i++) {
		if(email[i] == '@') 
		break;
		else username[i] = email[i];
	}
}

void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
	     	ch=getch();
		    if(ch == ENTER || ch == TAB){
			pwd[i] ='\0';
			break;
		}else if(ch == BAKSPC){
			if(i>0){
			i--;
			printf("\b \b");
		}
     	}else {
	   		pwd[i++] = ch;
			printf("* \b");
		}

	}
}

int main()
{
	int option,usrFound = 0;
		
 //   struct user user;
    char username[50],pword[50];
    char password2[50];
    FILE *fp;
    re:
	printf("\n\n\t\t\t-----------------Welcome to Login System-----------------");
	printf("\n\n\n");
	printf("\t\t|1. Sign Up\n\n");
	printf("\t\t|2. LogIn \t\t\t |3. Having Trouble While Login !\n\n");
	printf("\t\t|4. Exit\n\n");
    printf("\t\tEnter Your Choice\n");	
	printf("\t\t-->\t");
	scanf("%d",&option);
	fgetc(stdin);
	
	switch(option)
		case 1: 
		{
		printf("Enter Your Full Name :\t");
		takeinput(user.fullname);
		printf("Enter Your Email Id :\t");
		takeinput(user.email);
		printf("Enter Your Phone No :\t");
		takeinput(user.phone);
		printf("Enter Password :\t");
		takepassword(user.password);
		printf("Confirm Your Password :\t");
		takepassword(password2);
		
		if(!strcmp(user.password,password2)){
		 generateUsername(user.email,user.username);
		 fp= fopen("Usersdata.txt","a+");
		 fwrite(&user,sizeof(struct user),1,fp);
		 if(fwrite != 0)
		 printf("\n\nUser Registration Successfully Done, Your username is %s",user.username);
 			else printf("\n\n Sorry ! Something went wrong :( ");
 			fclose(fp);
		}
		else{
			printf("\n\nPassword didn't matched"); 
			Beep(750,300);
		}
	    goto re;
		break;
		
		
		
		case 2:
			
			//struct user usr;
			
			printf("\nEnter username :\t");
			takeinput(username);
			printf("\nEnter Your password :\t");
			takepassword(pword);
			fp = fopen("Usersdata.txt","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){
						printf("\n\t\t\t\t\tWelcome %s",usr.fullname);
						printf("\n\n| Full name :\t%s",usr.fullname);
						printf("\n| Email :\t\t%s",usr.email);
						printf("\n|Username :\t%s",usr.username);
						printf("\n| Phone No: \t%s",usr.phone);
					}else{
						printf("\n\nInvalid Password!");
					    Beep(800,300);
					}
					usrFound = 1;
				}
			}
 			if(!usrFound){
 				printf("\n\nUser is not registered");
 				Beep(800,300);
			 }
			    fclose(fp);
			     goto re;
 				break;	
				
				 
			case 3:
				system("cls");
			int select,ex=1;
				char femail[50],fpassword[50],searchuser,su,sp;
	
				printf("\n\n\n Having Problem in Login ! (Y/N) :\t");
				scanf("%s",&su);
				if (su=='Y' || su=='y')
				{
					printf("Enter the way you want search your account : \n");
					printf("\n\n| 1. Search by EmailID :\t");
					printf("\n\n| 2. Search by password :\t");
					printf("-->\t");
					
					scanf("%d",&select);
					switch(select) {
						case 1: 
						
						printf("\n\nEnter Your EmailID : \t");
						scanf("%s",&femail);
						printf("%s",ffuser.email);
					//	takeinput(fusername);
						
						fp = fopen("Usersdata.txt","r");
							while(fread(&ffuser,sizeof(struct user),1,fp)){
//while(fread(&usr,sizeof(struct user))){
							if(!strcmp(femail,ffuser.email))
		                   {
							printf("Congrats ! Account found!\n");
							printf("Your password is %s",ffuser.password);
							printf("Your email is %s",ffuser.email);
						}
						else 
						{
							printf("Sorry, Your account is not found :( ");
						}
					}	fclose(fp);	
				     	break;
				     	goto re;
				     	
				     	
				     	
				     	
				     	
				     	
				     	
				     	case 2:
				     		printf("\n\nEnter Your Password : \t");
						scanf("%s",&fpassword);
					//	takeinput(fpassword);
						
						fp = fopen("Usersdata.txt","r");
							while(fread(&ffuser,sizeof(struct user),1,fp)){
//while(fread(&usr,sizeof(struct user))){
							if(!strcmp(fpassword,ffuser.password))
		                   {
							printf("Congrats ! Account found!\n");
							printf("Your username is %s",ffuser.username);
						}
						else 
						{
							printf("Sorry, Your account is not found :( ");
						}
					}	fclose(fp);	
				     	goto re;
				     	break;
				}
				
			}
		
	
			
				 
				 
				 
				 
				 
				
				 case 4:
				 printf("\n\n\t\t\tBye Bye :)  \t");
				 return 0;	
		
	}
	return 0;
}
