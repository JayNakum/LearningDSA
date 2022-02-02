#include<stdio.h>
typedef struct emp{
	int empid;
	int age;
	char gender[10];
	char name[20];
}emp;

	void insert(){
		emp *s;
		FILE *fp;
		int n,i;
		printf("Enter the number of employees you want to insert = ");
		scanf("%d",&n);
		
		s = (emp*)calloc(n, sizeof(emp)); //Blocks of desired employees will be created in memory.
		fp = fopen("emp.txt","w");
		
		for(i=0;i<n;i++)
		{
			
			
			printf("Enter the id of employee = ");
			scanf("%d",&s[i].empid);
			
			printf("Enter the age of employee = ");
			scanf("%d",&s[i].age);
			fflush(stdin);
			
			printf("Enter the name of employee = ");
			gets(s[i].name);
			
			
			printf("Enter the gender of employee = ");
			gets(s[i].gender);
			
			fwrite(&s[i],sizeof(emp),1,fp);
			
		}
		fclose(fp);
	
	}
	
	
	void remov(){
		emp e1;
		int found; 
		FILE *fp,*fp1;
		fp=fopen("emp.txt","r");
		fp1=fopen("temp.txt","w");
		int eno;
		printf("Enter the employee number to be deleted = ");
		scanf("%d",&eno);
		while(fread(&e1,sizeof(emp),1,fp))
		if(e1.empid == eno)
		{
			found=1;	
		}
		else{
			fwrite(&e1,sizeof(emp),1,fp1);
		}
		fclose(fp);
		fclose(fp1);
		if(found)
		{
		fp=fopen("emp.txt","w");
		fp1=fopen("temp.txt","r");
		
			while(fread(&e1,sizeof(emp),1,fp1))
			{
				fwrite(&e1,sizeof(emp),1,fp);
			}
		}
	
	
	}
	
	void display(){
		emp e1;
		FILE *fp;
		fp = fopen("emp.txt","r");
		while(fread(&e1,sizeof(emp),1,fp))
		{
			printf("\n%-5d%-10s%-5d%-10s",e1.empid,e1.name,e1.age,e1.gender);
		}
		fclose(fp);
	}

int main()
{
	int ch;
	do{
		printf("\n1.INSERT");
		printf("\n2.REMOVE");
		printf("\n3.DISPLAY");
		printf("\nPress 0 for exit");
		
		printf("\n Enter your choice = ");
		scanf("%d",&ch );
				
		switch(ch){
			
			case 1:
				insert();
				break;
				
			case 2:
				remov();
				break;
				
			case 3:
				display();
				break;		
				
		}
				
	}while(ch!=0);
	
	
	return 0;
}
