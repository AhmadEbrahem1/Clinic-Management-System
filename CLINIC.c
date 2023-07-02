#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"STD_Types.h"
#pragma pack(2)
 char ASLYY[20]="Not Determined Yet";
 char busy1[20]="2pm to 2:30pm";
 char busy2[20]="2:30pm to 3pm";
 char busy3[20]="3pm to 3:30pm";
 char busy4[20]="4pm to 4:30pm";
 char busy5[20]="4:30pm to 5pm";
 typedef struct s1{
	
	 u8 name[50] ;
	 u8 appoint[20];
	 int age;
	 
	 
	 
	 u8 gender; // f m
	 u8 ID[6];
	 struct s1* next;
	
}record;

  typedef struct appointment{
	u8 taken ;
	u8 text[20];
	u8 num;
	 struct appointment* next;
}slot;


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


  u8 exist(record** head, u8 ID[6]){
	  
	 record * test = *head;
	 u8 found =0;
	 while(test!=NULL){
		if(!strcmp(ID,test->ID))
			found=1;
		test=test->next;
	 }
	  
	  return found;
	  
  }
 //void addnew(record ** head);

void Add_Name(record* newnode){
	
	printf(" \n Enter Name : ");
	clearInputBuffer();
	scanf("%s",newnode->name);
	
}


void Add_Age(record* newnode){
	 printf(" \n Enter Age: ");
	 clearInputBuffer();
	 scanf("%d",&(newnode->age));
}


u8 Add_ID(record** head,record* newnode){
	u8 done  =1; u8 temp_ID[6];
	 printf(" \n Enter ID: ");
	 clearInputBuffer();
    scanf("%s",temp_ID);
	if(exist(head,temp_ID)){
		printf("Patient already exists \n");
		done=0;
		free(newnode);
	      return  done;
	}
	for(int i=0;i<6;i++)
	newnode->ID[i]=temp_ID[i];
	 return  done;
}


void Add_gender(record* newnode){
	u8 g;
	RR:
	printf("\n Enter gender, [F] for female & [M] for male : ");
	clearInputBuffer();
	scanf("%c",&g);
	if(g=='F' || g=='M' )
		newnode->gender=g;
	else 
	{
		printf(" \n ERROR!! Enter a valid gender type ");
	goto RR;
	}
		
	
}


  void addnewpatient(record** head){
	/*create new node*/
	record* newnode=(record*)malloc(sizeof(record));
	
	record *last= *head;
	
		strcpy(newnode->appoint,ASLYY);

	Add_Name(newnode);
	Add_Age(newnode);
	
	Add_gender(newnode);
	 if(!Add_ID(head,newnode)) // لو متضافش
		 return;
	 
	 newnode->next=NULL;
	 
	 if(*head==NULL) // linke list is empty
	 {
		 *head =newnode;
		 printf("herrrrrr \n");
		 printf("\nNew patient record has been saved \n");
		 return;
	 }
	 
while(last->next!=NULL) //to reach last element
{
last=last->next;	
}
last->next=newnode;
printf("\nNew patient record has been saved \n");
printf("\n koko \n");
return;
	
}


u8 search_and_edit(u8 *to_be_edited_ID,int choise,record** head){
	
	u8 ok =0;
	record *target= *head;
	//list is empty
	//
	//
	
	while(target!=NULL){
		if(!strcmp(target->ID,to_be_edited_ID)) // لاقتها
		{
			switch(choise){
				case 1: //name
						Add_Name(target);
						break;
				
				case 2: //age
						Add_Age(target);
						break;
						
				case 3: //ID
						 if(!Add_ID(head,target)) // لو متضافش
							ok =0;
						break;
				
				case 4: //gender
						Add_gender(target);
						break;
						default: printf("Please enter a valid coise \n");
						return ok;
				}

							ok=1;
								return ok;
		}
		target=target->next;
		
	}
	// not found (won't happen ,we have already checked)
	return ok;
}
void Start_The_Day(slot**head){
	
	//بداية اليوم بتعمل 5 فترات 
	slot* slot1 =(slot*)malloc(sizeof(slot));
	strcpy(slot1->text,busy1);
	slot1->taken=0;
slot1->num=1;
	
	slot* slot2=(slot*)malloc(sizeof(slot));
	slot1->next=slot2;
	
	*head=slot1;

	strcpy(slot2->text,busy2);
	slot2->taken=0;
	slot2->num=2;
	slot* slot3=(slot*)malloc(sizeof(slot));
	slot2->next=slot3;
	strcpy(slot3->text,busy3);
    
	slot3->taken=0;
	slot3->num=3;
	slot* slot4=(slot*)malloc(sizeof(slot));
	slot3->next=slot4;
	strcpy(slot4->text,busy4);
	slot4->taken=0;
	slot4->num=4;
	slot* slot5=(slot*)malloc(sizeof(slot));
	slot4->next=slot5;
	strcpy(slot5->text,busy5);
	slot5->taken=0;
	slot5->num=5;
	slot5->next=NULL;
	
}
void View_Available_slots(slot**slot1){

	slot * slot_to_be_checked = *slot1;
	while(slot_to_be_checked!=NULL){
		if( !slot_to_be_checked->taken)
		printf(" preriod %d: %s \n",slot_to_be_checked->num,slot_to_be_checked->text);
		 slot_to_be_checked=slot_to_be_checked->next;
		
	}
	
	
	
	
}
			
			
void Let_Me_UNDO(u8* ID,record** head,slot** first){
				slot* temp_slot =* first;
				
				
				record *target= *head;
				while(target!=NULL)
				{
					if(!strcmp(target->ID,ID)) // لاقتها
					{
						while(temp_slot!=NULL)
						{
						if(!strcmp(target->appoint,temp_slot->text))
						{
							temp_slot->taken =0;
							strcmp(target->appoint,ASLYY);
							break;
						}
						
							else temp_slot=temp_slot->next;
						}
						break;
					}
					else
					target=target->next;
		
				}
			
				printf("patient already  has not reserved an appointment yet(no slot to be deleted !) \n");
				

}

void Let_Me_Choose(u8* ID,int Chosen_Slot,record** head,slot** first){
				slot* temp_slot =* first;
				
				
	record *target= *head;
	while(temp_slot!=NULL){
		if(temp_slot->num ==Chosen_Slot)
		{
			temp_slot->taken =1;
			
	     break;
		 }
		else
					temp_slot=temp_slot->next;
				}
				
				
				while(target!=NULL){
		if(!strcmp(target->ID,ID)) // لاقتها
		{
			strcpy(target->appoint,temp_slot->text);
		break;	
		}
		else
		target=target->next;
		
	}
	
	
	
			}

void View_patient_record(u8 *ID,record** head)
{
	record *target= *head;
	
	while(target!=NULL)
	{
		if(!strcmp(target->ID,ID)) // لاقتها
		{
			printf("patient name : %s \n\
gender: %c \n\
age: %d \n \
appoint: %s \n",target->name,target->gender,target->age,target->appoint);
			break;
		}
		else target=target->next;
	}
}


void view_today_reservation(record **head){
	
	record* patient =*head;
	printf("Today : \n");
	while(patient!=NULL){
		
		if(strcmp(patient->appoint,ASLYY)){
			printf("patient ID: %s has an appoint from %s \n",patient->ID,patient->appoint);
			
		}
		patient=patient->next;
		
	}
	
}











int main(){
	// UI
	 char* pass = "1234";
	 
	int m=0;
	record *head =NULL;
	//slots
	slot*first=NULL;
	Start_The_Day(&first);	
		start: 
	while(1){
	
	printf("CHOOSE MODE NUMBER:  \n \
1-Admin Mode \n \
2-User Mode     \n");

//clearInputBuffer();
	scanf("%d",&m); 
   
  
	
		if(m==1) // admin mode block
		{
	
		// entering password 
		u8 trial=3;
		
		while(trial!=0)
		{
			
		     printf("ENTER Password:");
			 
		    u8 * checkarray=malloc(20*sizeof(u8)); // know heap size we may do 1024*---
			clearInputBuffer();
			scanf("%s",checkarray);
			checkarray=realloc(checkarray,strlen(checkarray));  //HR technique
		     
			 
			 u8 wrongpass=0; 
			
		     if(strcmp(checkarray,pass))
			wrongpass=1;
		
		if(wrongpass){
			
			printf("Wrong Password! ,trials left : %d \n ",--trial);
			}
			else{
				free(checkarray);
				break;
			    }
			
			 
		}
		
		if (trial==0){ printf("trials is over , system is  shutting down ");return 0;}     // خلصت محاولاتك
		
			 // you are correct
			
          printf(" WELCOME ^_^ Choose feature Number: \n \
1. Add New Patient Record \n \
2. Edit patient record   \n \
3. Reserve a slot with the doctor \n \
4. Cancel reservation\n");
           
		int x =1 ; 
		clearInputBuffer();
		scanf("%d",&x);
	
		
			// Add New Patient Record
			if(x==1){
			addnewpatient(&head);
			continue;
			}
			
			
			
			//Edit patient record
			else if(x==2){
				u8 to_be_edited_ID[6];
				int choise =0;
				printf("Enter ID: ");
				repeat : 
				clearInputBuffer();
				scanf("%s",to_be_edited_ID);
				if(!exist(&head,to_be_edited_ID)){
		printf("incorrect ID, Please provide a valid ID :");     
	                     goto repeat;
						 }
						 //start editing
						 
	reenter:					
printf("choose what you want to modify for this patient \n ");
printf("1:Name \n  \
2:Age \n  \
3:ID \n  \
4: Gender \n  ");
clearInputBuffer();
scanf("%d",&choise);
 if(search_and_edit(to_be_edited_ID,choise,&head))
 { 	 
printf("Uptades Has been saved \n");
goto start;
 }
	else  goto reenter;
 


				}
			
			
			
			// Reserve a slot with the doctor
			else if(x==3){ 
			View_Available_slots(&first);
			u8 to_reserve_ID[6];
				int choise =0;
				
		
				printf("Enter ID: ");
				repeat_1 : 
				clearInputBuffer();
				scanf("%s",to_reserve_ID);
				printf("%s\n",to_reserve_ID);
			
			if(!exist(&head,to_reserve_ID)){
		printf("incorrect ID, amaken provide a valid ID :");     
	                     goto repeat_1;
						 }
			
		int var=0;
		printf("CHOOSE THE SLOT : ");
		
		clearInputBuffer();
		scanf("%d",&var);
			Let_Me_Choose(to_reserve_ID, var, &head,&first);
			printf("UPDATES HAVE BEEN SAVED \n");
			View_Available_slots(&first);
			
			
		
			}
			
			
			
			//Cancel reservation
			else if(x==4){ 
			
			u8 to_unreserve_ID[6];
				
				printf("Enter ID to cancel reseevation: ");
				repeat_2 : 
				clearInputBuffer();
				scanf("%s",to_unreserve_ID);	
			if(!exist(&head,to_unreserve_ID)){
		printf("incorrect ID, amaken provide a valid ID :");     
	                     goto repeat_2;
						 }
			
			Let_Me_UNDO(to_unreserve_ID,&head,&first);
			printf("DONE \n");
			
			}
		}
		//end of admin mode block
		
		else if(m==2) // user mode
		{
			usermode:
			printf("Hello! choose what you need : \n\
			1. View patient record       \n \
			2. View today’s reservations   \n ");
			int mode;
			clearInputBuffer();
			scanf("%d",&mode);
			switch(mode){
				case 1: //1. View patient record.
				printf("ENTER PATIENT ID :");
				char to_be_viewed[6];
				repeat_3: 
				clearInputBuffer();
				scanf("%s",to_be_viewed);	
			if(!exist(&head,to_be_viewed)){
		printf("ID does not exist,Try again :");     
	                     goto repeat_3;
						 }
					View_patient_record(to_be_viewed,&head);	 
				
				
				break;
				case 2: //2. View today’s reservations
				view_today_reservation(&head);
				break;
				
				default: printf("please enter a valid choice \n");
				goto usermode;
			}
		 //end of user mode block
		}
	
	else
printf("error ya 3ammm");		//invalid number
	
	
}



// main 
}
/*
اعتبارات:
الميمورى اوبتمايزيشن
freecorner cases
memory arrange بتاع الستركت
فلتعديل نغير مواعيد ولو هو دخل مواعيد مش متاحة نقوله انت غلط
لو حابب نحط مواعيد كمان يبقا واووووووو

*/
