#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Patient{
    char name[30];
    bool urgent;

};
struct Specialization{
    struct Patient patients[5];
    int noOfPeopleInQueue;
    bool isEmpty;
};
struct Hospital{
    struct Specialization specializations[20];

};
int menu(){
    int choice;
    printf("Enter your choice:\n1) Add new patient\n2) Print all patients\n3) Get next patient\n4) Exit\n");
    scanf("%d", &choice);
    return choice;
}
void start()
{   
    int specNum=0;
    struct Hospital hos;
    char name[20];
    int urgent;
    
    for(int i = 0 ; i < 20; i++){
        hos.specializations[i].isEmpty = true;
        hos.specializations[i].noOfPeopleInQueue = 0;
    }
    char input;
    do{
        input = menu();
        switch(input){
            case 1:
                if(hos.specializations[specNum].noOfPeopleInQueue == 4){
                    printf("Sorry we can't add more patients for this specialization");
                    break;
                }
                printf("Enter specialization, name, status:  ");
                scanf("%d", &specNum);
                scanf("%s", &name);
                scanf("%d", &urgent);
                hos.specializations[specNum].isEmpty = 0;
                // hos.specializations[specNum].patients[hos.specializations[specNum].noOfPeopleInQueue].urgent = urgent;
                
            
                if(urgent == 0){
                    strcpy(hos.specializations[specNum].patients[hos.specializations[specNum].noOfPeopleInQueue].name, name);
                    hos.specializations[specNum].patients[hos.specializations[specNum].noOfPeopleInQueue].urgent = urgent;
                    hos.specializations[specNum].noOfPeopleInQueue ++;
                }
                else if(urgent == 1){
                    for(int i = 4; i > 0; i--){
                        strcpy(hos.specializations[specNum].patients[i].name, hos.specializations[specNum].patients[i-1].name);
                        hos.specializations[specNum].patients[i].urgent = hos.specializations[specNum].patients[i-1].urgent;
                    }
                    strcpy(hos.specializations[specNum].patients[0].name, name);
                    hos.specializations[specNum].noOfPeopleInQueue ++;
                    hos.specializations[specNum].patients[0].urgent = urgent;                
                }
                break;
                case 2:
                    printf("\n");
                    for(int j = 0; j < 20; j++){
                        if(hos.specializations[j].isEmpty == 0){
                            printf("There are %d patients in specialization %d\n", hos.specializations[j].noOfPeopleInQueue, j);
                            for(int k = 0; k < hos.specializations[j].noOfPeopleInQueue; k++){
                                if(hos.specializations[j].patients[k].urgent){
                                    printf("%s urgent\n", hos.specializations[j].patients[k].name);
                                }
                                else{
                                    printf("%s regular\n", hos.specializations[j].patients[k].name);
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    printf("Enter specialization ");
                    scanf("%d", &specNum);
                    if(hos.specializations[specNum].noOfPeopleInQueue == 0){
                        printf("No patients at the moment. Have a rest Dr");
                        break;
                    }

                    printf("\n%s please go with the Dr", hos.specializations[specNum].patients[0].name);
                    for(int z = 0; z < 4; z++){
                        strcpy(hos.specializations[specNum].patients[z].name, hos.specializations[specNum].patients[z+1].name);
                        hos.specializations[specNum].patients[z].urgent = hos.specializations[specNum].patients[z+1].urgent;
                    }
                    hos.specializations[specNum].noOfPeopleInQueue --;
                    break;
                case 4:
                    break;
                default:
                    printf("Enter one of the above options!!!\n ");
                    break;
        }
        
    }while(input != 4);
    // printf("%d", urgent);
}

int main(){
    start();
    return 0;
}