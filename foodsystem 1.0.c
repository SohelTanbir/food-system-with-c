#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct foodsystem{
    //To Keep Name Of Food
    char foodname[20];
     //To Keep Name Of Food
    char foodcat[20];
    //To Keep Price Of Food
    int foodprice;
    }foodsystem;
//Function To Make the file in correct Format.
    void   convert(){
// h is a variable here
            foodsystem h;
// fp and conv are two File Pointer here
            FILE *conv = fopen("conv.txt","r");
            FILE *fp = fopen("food.txt","a+");
//We took 2 int here read and records read ll match and record ll track the record for how many items we are accepting through converter.
  int read = 0;
  int records = 0;
// Main do while loops who ll collect deta from a file and it ll save into required file.
  do
  {

                  read = fscanf(conv,"%19[^','],%19[^','],%d\n",

                  h.foodname,
                  h.foodcat,
                  &h.foodprice);
                  fprintf(fp, "%-25s%-20s%-10d\n", h.foodname, h.foodcat, h.foodprice);

                  if (read == 3) records++;

        if (read != 3 && !feof(conv))
      {

      printf("\n%-20s%-1s"," ","File format incorrect Please Check Again.");
      return 1;
     }

    if (ferror(conv))
    {
      printf("Error reading file.\n");
      return 1;
    }

  } while (!feof(conv));

  fclose(conv);
fclose(fp);
if (records==1)
printf("\n\n%-27s%10s%d\n\n\n"," ","Total Of Food Imported From File Is : ", records);
if (records>1)
printf("\n\n%-27s%10s%d\n\n\n"," ","Total Of Food Imported From File Are : ", records);

}
//EXTRA OPTION TEST
void createfood(){
foodsystem h;
FILE *fp = fopen("food.txt","a+");
printf("\n%-20s%-1s"," ","What Is Your New Food Name : ");
scanf("%s",&h.foodname);
printf("\n%-20s%-1s"," ","What Is Your Food Catagory : ");
scanf("%s",&h.foodcat);
printf("\n%-20s%-1s"," ","What Is Your New Food Price : ");
scanf("%d",&h.foodprice);
fprintf(fp, "%-25s%-20s%-10d\n", h.foodname, h.foodcat, h.foodprice);
fclose(fp);
}
//Displaying Food
void showallfood(){
 foodsystem food;
FILE *fp = fopen("food.txt","r");
printf("\n--------------------------------------------------------\n");
printf("%-25s%-20s%-10s\n","FOOD NAME","FOOD CATAGORY","FOOD PRICE");
printf("\n--------------------------------------------------------\n");
while(fscanf(fp, "%49s%19s%d", food.foodname, food.foodcat, &food.foodprice) == 3) {
        printf("%-25s%-20s%-10d\n", food.foodname, food.foodcat, food.foodprice);
}

}
void searchFoodBySpecificPrice(){
    int founds;
    foodsystem ss;
    FILE *fp;
    int price;
    printf("\n%-20s%-1s"," ","Enter Food price to Search : ");
    scanf("%d",&price);

    fp = fopen("food.txt","r");
    printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n","FOOD NAME","FOOD CATAGORY","FOOD PRICE");
    printf("\n--------------------------------------------------------\n");
    while(fscanf(fp, "%49s%19s%d", ss.foodname, ss.foodcat, &ss.foodprice) == 3){
        if(ss.foodprice == price){
            founds = 1;
        printf("%-25s%-20s%-10d\n",ss.foodname,ss.foodcat,ss.foodprice);
        }
    }
    if(founds !=1){
        printf("\n%-10s%d\n"," No Food Found with your price --> ",price);
    }
    fclose(fp);
}
void searchFoodUnderPrice(){
    int founds;
    foodsystem s1;
    FILE *fp;
    int price;
    printf("\n%-20s%-1s"," ","Enter Food price to Search : ");
    scanf("%d",&price);

    fp = fopen("food.txt","r");
     printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n","FOOD NAME","FOOD CATAGORY","FOOD PRICE");
    printf("\n--------------------------------------------------------\n");
    while(fscanf(fp, "%49s%19s%d", s1.foodname, s1.foodcat, &s1.foodprice) == 3){
        if(s1.foodprice < price&& s1.foodprice>0){
        founds = 1;
        printf("%-25s%-20s%-10d\n",s1.foodname,s1.foodcat,s1.foodprice);

        }
    }
    if(founds !=1){
        printf("\n%-10s%d\n"," No Food Found under your price --> ",price);
    }

    fclose(fp);
}
void searchFoodName(){
    char namec[20];
    foodsystem sc;
    FILE *fp;
    int founds;
    printf("\n%-20s%-1s"," ","Enter Food Name to Search : ");
    scanf("%s",&namec);

    fp = fopen("food.txt","r");
        printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n","FOOD NAME","FOOD CATAGORY","FOOD PRICE");
    printf("\n--------------------------------------------------------\n");


    while(fscanf(fp, "%49s%19s%d", sc.foodname, sc.foodcat, &sc.foodprice) == 3){
        if(strcmp(namec , sc.foodname)==0 || (strstr(sc.foodname, namec) != NULL)){
            founds = 1;
            printf("%-25s%-20s%-10d\n",sc.foodname,sc.foodcat,sc.foodprice);
        }
    }
    if(founds !=1){
        printf("\n%-10s%s\n"," No Food Found with  name --> ",namec);
    }
    fclose(fp);
}
void searchFoodCategory(){
    char cat[20];
    foodsystem cc;
    FILE *fp;
    int founds;
    printf("\n%-20s%-1s"," ","Enter Category Name to Search : ");
    scanf("%s",&cat);

    fp = fopen("food.txt","r");
    printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n","FOOD NAME","FOOD CATAGORY","FOOD PRICE");
    printf("\n--------------------------------------------------------\n");


    while(fscanf(fp, "%49s%19s%d", cc.foodname, cc.foodcat, &cc.foodprice) == 3){
        if(strcmp(cat , cc.foodcat)==0 || (strstr(cc.foodcat, cat) != NULL)){
        founds = 1;
        printf("%-25s%-20s%-10d\n",cc.foodname,cc.foodcat,cc.foodprice);

        }
        }
      if(founds !=1){
       printf("\n%-40s%s\n"," No Food Category Found with Name...:",cat);
    }
    fclose(fp);
}
void swap(foodsystem *a,foodsystem *b) {
    foodsystem temp = *a;
    *a = *b;
    *b = temp;
}

void foodSortByName() {
    foodsystem foods[10000];  // Assuming a maximum of 10000 foods
    int founds = 0;

    FILE *file = fopen("food.txt", "r");
    while (fscanf(file, "%49s%19s%d", foods[founds].foodname, foods[founds].foodcat, &foods[founds].foodprice) == 3) {
        founds++;
    }

    fclose(file);

    //sort by food name
    for (int i = 0; i < founds; i++) {
        for (int j = 0; j < founds - i - 1; j++) {
            if (strcmp(foods[j].foodname, foods[j + 1].foodname) > 0) {
                swap(&foods[j], &foods[j + 1]);
            }
        }
    }

    // Print the sorted data
    printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n", "FOOD NAME", "FOOD CATAGORY", "FOOD PRICE");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < founds; i++) {
        printf("%-25s%-20s%-10d\n", foods[i].foodname, foods[i].foodcat, foods[i].foodprice);
    }
}


void sortFoodByCategory(){
    foodsystem foods[10000];  // Assuming a maximum of 10000 foods
    int founds = 0;

    FILE *file = fopen("food.txt", "r");
    while (fscanf(file, "%49s%19s%d", foods[founds].foodname, foods[founds].foodcat, &foods[founds].foodprice) == 3) {
        founds++;
    }

    fclose(file);

    //sort by food name
    for (int i = 0; i < founds; i++) {
        for (int j = 0; j < founds - i - 1; j++) {
            if (strcmp(foods[j].foodcat, foods[j + 1].foodcat) > 0) {
                swap(&foods[j], &foods[j + 1]);
            }
        }
    }

    // Print the sorted data
    printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n", "FOOD NAME", "FOOD CATAGORY", "FOOD PRICE");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < founds; i++) {
        printf("%-25s%-20s%-10d\n", foods[i].foodname, foods[i].foodcat, foods[i].foodprice);
    }
}

void sortFoodByPrice() {
     foodsystem foods[10000];
     foodsystem sortedFoods;
    int founds = 0;

    FILE *file = fopen("food.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    while (fscanf(file, "%49s%19s%d", foods[founds].foodname, foods[founds].foodcat, &foods[founds].foodprice) == 3) {
        founds++;
    }

    fclose(file);

    // Sort by food price (ascending order)
    for (int i = 0; i < founds; i++) {
        for (int j = 0; j < founds - i - 1; j++) {
            if (foods[j].foodprice > foods[j + 1].foodprice) {
                sortedFoods = foods[j];
                foods[j] = foods[j + 1];
                foods[j + 1] = sortedFoods;
            }
        }
    }

    // Print the sorted data
    printf("\n--------------------------------------------------------\n");
    printf("%-25s%-20s%-10s\n", "FOOD NAME", "FOOD CATAGORY", "FOOD PRICE");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < founds; i++) {
        printf("%-25s%-20s%-10d\n", foods[i].foodname, foods[i].foodcat, foods[i].foodprice);
    }
}


// food search controller
void searchFoodController(){
    printf("\n");
    printf("\n--------------------------------------------------------\n");
    printf("----------------- KHOJ THE SEARCH ---------------------");
    printf("\n--------------------------------------------------------\n");
   int selectedOption;

        printf("\n1.SEARCH BY SPECIFIC FOOD PRICE:");
        printf("\n2.SEARCH FOOD UNDER YOUR PRICE:");
        printf("\n3.SEARCH FOOD BY NAME:");
        printf("\n4.SEARCH BY CATEGORY:");

        printf("\n0.BACK TO MAIN MENU");
        printf("\nPLEASE SELECT A SEARCH TYPE :");
        scanf("%d",&selectedOption);
        switch(selectedOption){
        case 1:
                searchFoodBySpecificPrice();
        break;
         case 2:
                searchFoodUnderPrice();
        break;
         case 3:
                searchFoodName();
        break;
         case 4:
                searchFoodCategory();
        break;

        default:
             printf("INVALID INPUT");
        }

        printf("\n");

}


int main(){
int mainmenu;
    do{
        printf("\n%-43s%-1s\n"," ", "Welcome To CUB Food System");
        printf("%-28s%-1s"," ", "Version Beta 1.0 | Created By Team Web Development.\n" );
        printf("\n%-40s%-1s"," ","1.CREATE NEW FOOD MENU");
        printf("\n%-40s%-1s"," ","2.DISPLAY ALL FOOD");
        printf("\n%-40s%-1s"," ","3.SEARCH FOOD");
        printf("\n%-40s%-1s"," ","4.FILTER FOOD BY NAME");
        printf("\n%-40s%-1s"," ","5.FILTER FOOD BY CATEGORY");
        printf("\n%-40s%-1s"," ","6.FILTER FOOD BY Price");
        printf("\n%-40s%-1s"," ","7.Import Food from File");
        printf("\n%-40s%-1s"," ","0.EXIT");
        printf("\n\n    Please Select What You Want To Do : ");
        scanf("%d",&mainmenu);
        switch(mainmenu){
       case 1:
                createfood();
            break;
        case 2:
              showallfood();
           break;
        case 3:
                searchFoodController();
            break;

        case 4:
               foodSortByName();
            break;

        case 5:
               sortFoodByCategory();
            break;

        case 6:
               sortFoodByPrice();
            break;
        case 7:
               convert();
            break;
        case 0:
                printf("%-43s%-1s\n\n"," ","Thank You For Using CUB Food System.\n");
        }
        }while(mainmenu!=0);




return 0;
}
