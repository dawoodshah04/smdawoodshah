#include <stdio.h>
#include <conio.h>

struct book
{
    int sr_no;
    char b_name[100];
    char author_name[100];
    int ISBN_no;
    int edition;
    int issue;
};

void add();
void display();
void update();
void search(int);
void del();

int main()
{
    char choice;
    int option;
    int i;
    do
    {
        printf("\n\n\t\t*****************Welcome to Library Management System*****************\n\n");
        printf("\t\t\t\t |-------------------------------|\n");
        printf("\t\t\t\t |Enter 'a' to Add book          |\n");
        printf("\t\t\t\t |Enter 'd' to Delete book       |\n");
        printf("\t\t\t\t |Enter 'r' to Display all books |\n");
        printf("\t\t\t\t |Enter 'u' to Update book       |\n");
        printf("\t\t\t\t |Enter 's' to Search books      |\n");
        printf("\t\t\t\t |Enter 'q' to Quit              |\n");
        printf("\t\t\t\t |-------------------------------|\n");

        printf("\nSelect any option above: ");
        fflush(stdin);
        choice=getche();
        printf("\n");

        switch(choice)
        {
        case 'a':
            printf("\n\nAdd a book \n");
            add();
            break;
        case 'u':
            printf("In Modify Function");
            update();
            break;
        case 'r':
            printf("Display all books \n\n");
            display();
            break;
        case 's':
            printf("\nSearch book by:\n1.ISBN\n2.Book Name\n3.Author Name\n");
            scanf("%d",&option);//option was being added
            search(option);
            break;
        case 'd':
            printf("\nDelete Book\n");
            del();
            break;

        case 'q':
            printf("Successfully Terminated the program!\n");
            break;

        }

    }
    while(choice != 'q');
}
void add()
{
    system("cls");
    struct book b[5];
    int i=0;
    int count=1;
    FILE *fp;

    fp=fopen("book.txt","w");

    if( fp == NULL )
    {
        printf("\nErorr! File not found\n");
        exit(1);
    }

    //input the books record in struct var
    for(i=0; i<5; i++)
    {
        printf("\nEnter serial ,Book name,Author Name, ISBN ,and Edition of book%d ",count);
        scanf("%d %s %s %d %d",&b[i].sr_no,b[i].b_name,b[i].author_name,&b[i].ISBN_no,&b[i].edition);
        count++;
    }

    fp=fopen("book.txt","w");

    if( fp == NULL )
    {
        printf("\nErorr! File not found\n");
        exit(1);
    }

    //printing the records on file
    for(i=0; i<5; i++)
    {
    	 fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",b[i].sr_no,b[i].b_name,b[i].author_name,b[i].ISBN_no,b[i].edition);//writes on the file which is stored
        //structure variable

	}

    fclose(fp);
    system("pause");
    system("cls");
}
void display()
{
    system("cls");
    struct book b[5];
    int i=0;
    FILE *fp;
    fp = fopen("book.txt","r");

    printf("Sr.No\tName\tAuthor Name\tISBN No\t Edition\n");
    while(fscanf(fp,"%d %s %s %d %d",&b[i].sr_no,b[i].b_name,b[i].author_name,&b[i].ISBN_no,&b[i].edition)!=EOF)
    {
        printf("%d\t%s\t%s\t\t%d\t %d\n",b[i].sr_no,b[i].b_name,b[i].author_name,b[i].ISBN_no,b[i].edition);
    }

    fclose(fp);
    system("pause");
    system("cls");
}

void search(int choice)
{
    system("cls");
    struct book b[5];

    int isbn_srch;
    char name_srch[30];
    char author_srch[30];

    int i,a;
    int flag =0;
    FILE *fp;
    fp = fopen("book.txt","r");

    if(fp == NULL)
    {
        printf("\nError! File Not Found!\n");
        exit(1);
    }


    switch(choice)
    {
    case 1:
        printf("Enter the ISBN Number: ");
        scanf("%d",&isbn_srch);

        for(i=0; i<5; i++)
        {
            while(fscanf(fp,"%d %s %s %d %d",&b[i].sr_no,b[i].b_name,b[i].author_name,&b[i].ISBN_no,&b[i].edition)!=EOF)
            {
                if( b[i].ISBN_no == isbn_srch)
                {
                    flag =1;
                    printf("\n****Book Found!****\n\n");
                    printf("Sr.no\tBook Name\tAuthor Name\tISBN\tEdition");
                    printf("\n%d\t%s\t\t%s\t\t%d\t%d\n",b[i].sr_no,b[i].b_name,b[i].author_name,b[i].ISBN_no,b[i].edition);
                    break;
                }
            }
        }

        if(flag == 0)
        {
            printf("Book Not Found!");
        }

        break;

    case 2:
        printf("Enter the book Name: ");
        scanf("%s",name_srch);
        //searches the book name
        for(i=0; i<1; i++)
        {
            while(fscanf(fp,"%d %s %s %d %d",&b[i].sr_no,b[i].b_name,b[i].author_name,&b[i].ISBN_no,&b[i].edition) == 5)
            {
                a=strcmp(b[i].b_name,name_srch);

                if(a == 0)
                {
                    flag =1;
                    printf("\n****Book Found!****\n\n");
                    printf("Sr.no\tBook Name\tAuthor Name\tISBN\tEdition");
                    printf("\n%d\t%s\t\t%s\t\t%d\t%d\n",b[i].sr_no,b[i].b_name,b[i].author_name,b[i].ISBN_no,b[i].edition);
                    break;
                }
            }

        }


        if(flag == 0)
        {
            printf("Book Not Found!");
        }

        break;

    case 3:
        printf("Enter the Author Name: ");
        scanf("%s",author_srch);
        //searches the book name
        flag=0;
        for(i=0; i<5; i++)
        {
            while(fscanf(fp,"%d %s %s %d %d",&b[i].sr_no,b[i].b_name,b[i].author_name,&b[i].ISBN_no,&b[i].edition)!=EOF)
            {
                a=strcmp(b[i].author_name,author_srch);

                if(a == 0)
                {
                    flag =1;
                    printf("\n****Book Found!****\n\n");
                    printf("Sr.no\tBook Name\tAuthor Name\tISBN\tEdition");
                    printf("\n%d\t%s\t\t%s\t\t%d\t%d\n",b[i].sr_no,b[i].b_name,b[i].author_name,b[i].ISBN_no,b[i].edition);
                    break;
                }
            }

        }

        if(flag == 0)
        {
            printf("Book Not Found!");
        }

        break;

    default:
        printf("\nInvalid Option!\n");
    }
    fclose(fp);

    system("pause");
    system("cls");
}

void update()
{
    struct book b[5];
    char bsrch[30];
    char bnew[30];
    int i = 0; // Initialize i to 0
    FILE *fp;
    int a;

    fp = fopen("book.txt", "r");
    if (fp == NULL)
    {
        printf("Error! File not Found!");
        exit(1);
    }

    //storing values in structure variables
    while (fscanf(fp, "%d %s %s %d %d", &b[i].sr_no, b[i].b_name, b[i].author_name, &b[i].ISBN_no, &b[i].edition) != EOF)
    {
        i++;
    }

    printf("\nEnter book name to modify: ");
    scanf("%s", bsrch);
    printf("Enter New book name: ");
    scanf("%s", bnew);

    for (i = 0; i < 5; i++)
    {
        a = strcmp(bsrch, b[i].b_name);

        if (a == 0)
        {
            //updates the new copy name
            strcpy(b[i].b_name, bnew);
            printf("\nRecord Updated!\n");
            break;
        }
    }

    if(a != 0)
    {
        printf("Erorr! Record not Updated!");
    }

    fclose(fp);

    fp = fopen("book.txt", "w");
    if (fp == NULL)
    {
        printf("Error! File Not Found!");
        exit(1);
    }

    for (i = 0; i < 5; i++)
    {
        fprintf(fp, "%d\t%s\t%s\t%d\t%d\n", b[i].sr_no, b[i].b_name, b[i].author_name, b[i].ISBN_no, b[i].edition);
    }

    fclose(fp);
}
void del()
{
    struct book b[5];
    char b_del[30];
    int i,a;
    FILE *fp;

    fp = fopen("book.txt","r");

    if (fp == NULL)
    {
        printf("\nError! File not Found\n");
        exit(1);
    }

    //storing values in structure variables
  for (i=0; i<5&&fscanf(fp, "%d %s %s %d %d", &b[i].sr_no, b[i].b_name, b[i].author_name, &b[i].ISBN_no, &b[i].edition) != EOF; i++)
    {

    }

    fclose(fp);

    printf("\nEnter the book to be deleted: ");
    scanf("%s",b_del);

    fp = fopen("book.txt","w");

    if (fp == NULL)
    {
        printf("\nErorr! File not Found\n");
        exit(1);
    }
//if book found then continue and
//if not then print the content on file
    for(i=0; i<5; i++)
    {
         a = strcmp(b_del,b[i].b_name);
        if(a == 0)
        {
            printf("Record Deleted Sucessfully\n");
            continue;
        }
        else
            {
                fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",b[i].sr_no, b[i].b_name, b[i].author_name, b[i].ISBN_no, b[i].edition);
            }
    }

    fclose(fp);
}
