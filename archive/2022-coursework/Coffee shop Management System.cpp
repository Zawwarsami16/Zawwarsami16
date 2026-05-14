
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void firstentry(int data, char foodname[25], int quantity, float price);
void secondentry(int pos, int data, char foodname[25], int quantity, float price);
void lastentry(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void foodlist();
void vieworder(int order, int quantity, int or_no);
void main_menu();
void deletefood(int serial);
int total_item();
void cls();
void loadingbar();
void echo(char print[]);
void color(int clr);
void br(int line);
void backuploader(void);
void pre(int tab);
void span(int space);
void wellcome();
void middle1(void);
void middtab1(void);

struct Cum{
	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Cum *next;
};
typedef struct Cum oral ;

oral *head, *list;

int main(){

	system("Coffee shop 69");
	system("mode con: cols=88 lines=30");

	loadingbar(); cls();
	wellcome();
	Sleep(150);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	head = NULL;
	firstentry(1,"penacolada  ",69,36.15);
	lastentry(2,"Latte       ",69,35.67);
	lastentry(3,"Cappuccino  ",8,36.83);
	lastentry(4,"Espresso    ",46,69.23);
	lastentry(5,"pub         ",46,69.23);
	lastentry(6,"Italian     ",34,36.23);
	lastentry(7,"gold leaf   ",7,25.29);
	lastentry(8,"bensen      ",121,0.13);
	lastentry(9,"kind edward ",73,37.13);
	mainmenu:
	br(1);
	main_menu();
	int main_menu_choice;
	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);
	if((main_menu_choice >=1 && main_menu_choice <=3)){
		if(main_menu_choice == 1){
			foodlist:
			cls();
			printf("=> 0. Main Menu ");
			foodlist();
		}  
		else if( main_menu_choice == 2){
			adminpanelchoice:
			int admin_panel_choice;
			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(120);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");
			fflush(stdin);  scanf("%d",&admin_panel_choice);
			if(admin_panel_choice==696969){
				oral *temp;
				temp = list;
				adminchoise:
				cls();  br(3); pre(4); echo(">> Admin Panel <<   \n\n");
				pre(4);
				printf(" 1. Total maal Today \n\n");Sleep(150);pre(4);
				printf(" 2. View Card details \n\n");Sleep(150);pre(4);
				printf(" 3. Add Coffee  \n\n");Sleep(150);pre(4);
				printf(" 4. Delete coffee \n\n");Sleep(150);pre(4);
				printf(" 5. Item List \n\n");Sleep(150);pre(4);
				printf(" 6. Item Counter \n\n");Sleep(150);pre(4);
				printf(" 7. Backup System\n\n");Sleep(150);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(150);pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your From 1-0: ");
				Sleep(350);
				int adminchoise;
				fflush(stdin);
				scanf("%d",&adminchoise);
				if(adminchoise==1){
					cls();  middle1(); pre(4);   printf("Todays maal Cash : %0.2f  \n",totalmoney);
					Sleep(5000);
					goto adminchoise;
				}
				else if(adminchoise==2){
					if(c!=0){
						cls();  br(3); pre(4);
						printf(" Card NO.      Money \n");pre(4);
						for(int z=1; z<=c;z++){
							printf("%d %0.2f \n",cardno[z],cardmoney[z]);pre(4);
							Sleep(150);
						}
						Sleep(1500);
					}
					if(c==0){
						cls();  middle1(); pre(4);
					printf("No Card History\n");}
					Sleep(150);
					goto adminchoise;
				}
				else if(adminchoise==3){
					foodadd:
					cls();
					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;
					br(3);pre(4);
					printf(" Enter Item Name :  ");
					fflush(stdin);    
					scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);
					br(2);pre(4);
					printf(" Enter Item Quantity :  ");
					scanf("%d",&fquantity);
					fflush(stdin);
                    foodserial:
					br(2);pre(4);  printf(" Enter Item Serial :  ");
                    scanf("%d",&fdata);
                    oral *exist;
                    exist = list;
                    while(exist->data!=fdata){
                    if(exist->next==NULL){
                    break;
                    }
                    exist=exist->next;
                    }
                    if(exist->data==fdata){
                    cls(); br(5);pre(3);  
					printf(" Item Serial Already Exist, Please Re-Enter  "); 
					Sleep(2000);
                    goto foodserial;
                    }
                    fprice:
                    fflush(stdin);
					br(2);pre(4); 
					printf(" Enter Item Price :  ");
					fflush(stdin);
					scanf("%f",&fprice);
					br(2);pre(4);  
					printf("Submiting your data");
					for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}
					lastentry(fdata,ffoodname,fquantity,fprice);
					br(2);pre(4);    
					printf("Adding Item  Successfull....\n");
					Sleep(2000);
					goto adminchoise;
				}
				else if(adminchoise==4){
					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Item To Delete : ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					oral *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2);
						 printf("Please Enter Correct Number :  "); 
						 Sleep(500);
						goto fdelete;
					}
					goto adminchoise;
				}
				else if(adminchoise==5){
					cls(); 
				    foodlist();
					Sleep(1000);
					br(2);
					pre(4);
					printf("1. <-- back  \n\n");
					pre(5);
					fflush(stdin);
				    scanf("%d",&any);
					goto adminchoise;
				}
				else if(adminchoise==6){
					citem = total_item();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						printf("Item Counting ");
						printf(" %d ",cs);
						Sleep(150);
						cls();
					}
					cls();
					middle1();pre(4);
					printf("Total Item Item is --> %d  \n",citem); Sleep(200);
					goto adminchoise;
				}
				else if(adminchoise==7){
					char date[35]=__DATE__;
					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); printf("Error!"); Sleep(500);
						goto adminchoise;
					}
					fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
					fprintf(fptr,"Card No ------- Money \n\n");
					for(int l=1; l<=c;l++){
						fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
					}
					br(2);pre(4); printf("Backup Successfull..."); Sleep(1500);
					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){
					cls();br(2);pre(2);
					color(26);
					printf("\n\t\t"); color(240);
					printf("\n\t\t");  color(240);
					printf("Order Number     Item Name     quantity   in stock "); color(26);
					printf("\n\t\t");  color(240);
					for(int o=1;o<=order;o++){
						vieworder(total_order[o],order_quantity[o],o);
					}
					br(2);pre(4);  printf("1.  back  \n\n");pre(5);
					fflush(stdin);   scanf("%d",&any);
					goto adminchoise;
				}
				else if(adminchoise==0){
					goto mainmenu;
				}
				else{
					br(2); pre(4); printf("Select From List :  "); Sleep(500);
					goto adminchoise;
				}
			}
			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Enter Correct Choice");
				goto adminpanelchoice;
			}
		}
		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Fuck You For Using Our System. \n\t\t\t Please fuck off \n\n\n\n\n\n\n");
			Sleep(1000);
			exit(1);

		}

	}
	else{
		br(2); pre(4); printf(" Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}
	int get_food_choice;
	br(2); pre(3);fflush(stdin);
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);
	if(get_food_choice==0){
		goto mainmenu;
	}
	oral *temp;
	temp = list ;
	while(temp->data != get_food_choice){
		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choice From List: "); br(2); Sleep(1000);
			goto foodlist;
		}
	}
	if(get_food_choice == temp->data){
		fcquantity:
		br(2); pre(4);
		printf("Enter Item Quantity : ");
		int fcquantity;
		fflush(stdin); scanf("%d",&fcquantity); cls();
		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);
			goto foodlist;
		}
		middle1();
		pre(4); 
		printf("Choice item %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Item List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");
		confirm:
		int confirm;
		fflush(stdin);
		scanf("%d",&confirm);
		if(confirm == 1 ){
			br(2);pre(4);
			printf(" 1. Cash ");
			br(2);pre(4);
            printf(" 2. Credit\n");
            printf("Select Method Of payment 1-2: ");
			payment:
			int payment;
			fflush(stdin);  scanf("%d",&payment);
			if(payment==1){
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);
				cls();middle1();pre(4);  printf("===>THANK YOU<===");
				br(2);pre(4);  printf("Item Ordered Successfully ...");
				br(2);pre(4);  printf("1. Wanna Buy Another Delicious ? ");
				br(2);pre(4);  printf("2. Main Menu \n");
				br(2);pre(4);   printf("Select: ");
				psmenu:
				int ps_menu;
				fflush(stdin);  scanf("%d",&ps_menu);
				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);printf("Please Choice from list : "); goto psmenu;}

			}
			else if(payment==2){
				int card_number[100];
				c++;
				cls();middle1();pre(4); printf("Enter Your Card No : ");
				fflush(stdin);   scanf("%d",&card_number[c]);
				cardno[c] = card_number[c];
				int pin;
				br(2);pre(2);  printf("Enter Your Card Pin [Dore mein]  : ");
				fflush(stdin);     scanf("%d",&pin);
				cardmoney[c] = temp->price*fcquantity;
				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);
				br(2);pre(4);  printf("Payment Success...");
				br(2);pre(4);    printf("1. Wanna Buy Another Delicious ? ");
				br(2);pre(4);    printf("2. Main Menu \n");
				br(2);pre(4);   printf("select: ");
				psmenu2:
				int ps_menu2;
				scanf("%d",&ps_menu2);
				if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);
				printf("Please Choice from list : "); goto psmenu2;}
			}
			else{
				br(2);
				pre(4);  
				printf("Enter Choice from List : ");
				goto payment;
			}
		}    
		else if(confirm == 2){
			goto foodlist;
		}
		else{
			br(2);
			pre(4);   
			printf("Enter Choise from List : ");
			goto confirm;
		}
	} 
	else{
		br(2);pre(4);  echo("Please Choice From List "); br(2); Sleep(300);
		goto foodlist;
	}
}
void cls(){
	system("cls");
}
void echo(char print[]){
	printf("%s",print);
}
void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}
}
void main_menu(){
	cls();
	br(5); pre(3); echo(">> 1. Coffee List"); Sleep(400);
	br(2); pre(3); echo(">> 2. Admin Panel"); Sleep(400);
	br(2); pre(3); echo(">> 3. Exit");  Sleep(400);
	br(1);
}
void lastentry(int data, char foodname[25], int quantity, float price){
	oral *temp;
	temp=(oral *)malloc(sizeof(oral));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	temp->next = NULL;
	if(head==NULL){
		head = temp;
		list = head;
	}
	else{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = temp;
	}
}
void firstentry(int data, char foodname[25], int quantity, float price){
	oral *temp;
	temp=(oral *)malloc(sizeof(oral));
	temp->data = data ;
	temp->price = price;
	strcpy(temp->foodname,foodname);
	temp-> quantity = quantity;
	temp->next = head;
	head = temp;
	list = head ;
}
void secondentry(int pos, int data, char foodname[25], int quantity, float price){
	oral *temp;
	temp=(oral *)malloc(sizeof(oral));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	while(head->next->data != pos ){
		head = head->next ;
	}
	temp->next = head->next;
	head->next = temp ;
    free(temp);
}
void deletefood(int serial){
	oral *temp;
	temp=(oral *)malloc(sizeof(oral));
	temp = list;
	if(temp->data != serial){
		while(temp->next->data != serial){
			temp = temp->next;
		}
		if(temp->next->data == serial){
			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}
			printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);
		}
		else{
			printf("\n\n\n\n\t\t\tCoffee Item Not Found\n"); Sleep(500);
		}
		head = temp ;
	}
	else{
		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}
		printf("\n\n\n\n\t\t\tDeleted Successfylly \n"); Sleep(500);
		head = temp ;
		list=head;
	}
}
void updatefood(int udata, int uquantity){
	oral *temp;
	temp = list;
	while(temp->data!=udata){
		temp = temp->next;
	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}
}
int total_item(){
	oral *temp;
	temp = list;
	int total_item=0;
	if(temp==NULL){
		total_item = 0;
	}
	else{
		total_item = 1;
		while(temp->next != NULL){
			total_item++;
			temp = temp->next;
		}
	}
	return total_item;
}
void foodlist(){
	color(0);
	printf("\n\t\t"); color(20);
	printf("\n\t\t"); color(240);
	printf("|  Item No.  |   Item Name      |  Price  |   In Stock   |");color(26);
	printf("\n\t\t"); color(240);
	oral *temp;
	temp = list;
	while(temp != NULL){
		color(26);
		printf("\n\t\t"); color(62);
		printf("| %d   |    %s  |    %0.2f   |    %d    |",temp->data,temp->foodname, temp->price, temp->quantity);
		color(26);
		printf("\n\t\t"); color(62);
		temp = temp->next ;
		Sleep(100);
	}
	color(26);
}
void vieworder(int order, int quantity, int or_no){
	color(26);
	oral *temp;
	temp = list;
	while(temp->data != order){
		temp = temp->next;
	}
	if(temp->data == order){
		color(26);
		printf("\n\t\t"); color(62);
		printf("|     %d      |    %s     |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
		color(26);
		printf("\n\t\t"); color(62);
		Sleep(100);
	}
	color(26);
}
void color(int clr){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);
}

void wellcome(){
	color(26);
	char welcome[500]="WELCOME";
	char welcome2[50]=" TO";
	char welcome3[50]=" SMOKING";
	char welcome4[50]=" COFFEE SHOP";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){
		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	color(26);
	printf("\n\n\t\t\t\t ");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	color(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){
			printf(" %c",welcome3[wlc3]);
		}
		else{
			printf(" %c",welcome3[wlc3]);
		}
		Sleep(100);
	}
	color(26);
	printf("\n\n\n\t\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
			printf(" %c",welcome4[wlc3]);
		}
		else{
			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
	color(26);
}
void loadingbar(void){
	for (int i=15;i<=100;i+=5){
		cls();
		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);
		printf("");
		for (int j=0; j<i;j+=2){
			color(160+j);
			printf(" ");
			color(26);
		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}
	}
}
void backuploader(void){
	for (int i=15;i<=100;i+=5){
		cls();
		color(26);
		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);
		printf("");
		for (int j=0; j<i;j+=2){
			color(120+j);
			printf(" ");
			color(26);
		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}
}
void middle1(void){
	printf("\n\n\n\n\n\n\n");
}
void middtab1(void){
	printf("\t\t\t\t\t");
}
