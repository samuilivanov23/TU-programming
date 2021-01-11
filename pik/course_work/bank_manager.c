#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _BankAccount {
    int id;
    double balance;
    char password[6];
};

struct _Customer {
    char isLogged; //0 -> not logged in, 1 -> logged in
    struct _BankAccount *account;
};

void ReadData(struct _BankAccount *accounts_archive, int *accounts_count, size_t *maxSize);
void LoginCustomer(struct _Customer *customer, struct _BankAccount *accounts_archive, int *accounts_count);
void LogoutCustomer(struct _Customer *customer);
void Draw(struct _Customer *customer);
void Put(struct _Customer *customer);
void Transfer(struct _Customer *customer, struct _BankAccount *accounts_archive, int *accounts_count);
void Info(struct _BankAccount *custommer_account);

int main(){
    size_t maxSize = 64;
    int accounts_count = 0;
    struct _BankAccount *accounts_archive = malloc(sizeof(*accounts_archive) * maxSize);
    
    if (accounts_archive == NULL){
        return EXIT_FAILURE;
    }

    struct _BankAccount customer_account;
    struct _Customer customer;
    customer.isLogged = 0;
    customer.account = NULL;
    char command[10];

    while(1){
        printf("enter command#> ");
        scanf("%s", command);

        if(strcmp("DATA", command) == 0){
            ReadData(accounts_archive, &accounts_count, &maxSize);
            printf("number of bank accounts: %d\n", accounts_count);
        }
        else if(strcmp("LOGIN", command) == 0){
            if(accounts_count > 0){
                LoginCustomer(&customer, accounts_archive, &accounts_count);

                if(customer.account != NULL){
                    printf("\nLOGGED customer account: \n");
                    printf("id: %d\n", customer.account->id);
                    printf("balance: %lf\n", customer.account->balance);
                }
                else{
                    printf("Incorrect login info\n");
                }
            }
            else{
                printf("Please enter at leat 1 bank account!\n");
            }
        }
        else if(strcmp("LOGOUT", command) == 0 && customer.isLogged){
            LogoutCustomer(&customer);
        }
        else if(strcmp("DRAW", command) == 0 && customer.isLogged){
            Draw(&customer);

            printf("\nLOGGED customer account: \n");
            printf("id: %d\n", customer.account->id);
            printf("balance: %lf\n", customer.account->balance);
        }
        else if(strcmp("PUT", command) == 0 && customer.isLogged){
            Put(&customer);

            printf("\nLOGGED customer account: \n");
            printf("id: %d\n", customer.account->id);
            printf("balance: %lf\n", customer.account->balance);
        }
        else if(strcmp("TRANSFER", command) == 0 && customer.isLogged){
            Transfer(&customer, accounts_archive, &accounts_count);

            printf("\nLOGGED customer account: \n");
            printf("id: %d\n", customer.account->id);
            printf("balance: %lf\n", customer.account->balance);
        }
        else if(strcmp("INFO", command) == 0 && customer.isLogged){
            Info(customer.account);
        }
        else if(strcmp("EXIT", command) == 0){
            break;
        }
        else{
            if(customer.isLogged){
                printf("Invalid command!\n");
            }
            else{
                printf("Please log in first!\n");
            }
        }
    }

    int i;
    for(i = 0; i < accounts_count; i++){
        printf("%d id: %d\n", i, accounts_archive[i].id);
        printf("%d balance: %lf\n", i, accounts_archive[i].balance);
        printf("%d password: %s\n", i, accounts_archive[i].password);
    }

    free(accounts_archive);
    return 0;
}

void ReadData(struct _BankAccount *accounts_archive, int *accounts_count, size_t *maxSize){
    if(*accounts_count == *maxSize){
        *maxSize *= 2;
        accounts_archive = realloc(accounts_count, sizeof(accounts_archive) * (*maxSize));
    }

    scanf("%d %lf %s", &accounts_archive[*accounts_count].id, &accounts_archive[*accounts_count].balance, accounts_archive[*accounts_count].password);    
    *accounts_count += 1;
}

void LoginCustomer(struct _Customer *customer, struct _BankAccount *accounts_archive, int *accounts_count){
    int input_ID;
    char input_password[6];
    
    printf("Enter ID and password\n");
    scanf("%d %s", &input_ID, input_password);

    int i;
    for(i = 0; i < *accounts_count; i++){
        if((input_ID == accounts_archive[i].id) && strcmp(input_password, accounts_archive[i].password) == 0 && customer->isLogged == 0){
            customer->isLogged = 1;
            customer->account = &accounts_archive[i];
            break;
        }
    }
}

void Draw(struct _Customer *customer){
    double amount;
    printf("Enter amount\n");

    while(1){
        scanf("%lf", &amount);

        if((amount < 0) || (customer->account->balance - amount < 0)){
            printf("Amount is too large or negative! Please enter correct value!\n");
        }
        else{
            customer->account->balance -= amount;
            break;
        }
    }
}

void Put(struct _Customer *customer){
    double amount;

    while (1){
        scanf("%lf", &amount);

        if(amount < 0){
            printf("Enter positive amount");
        }
        else{
            customer->account->balance += amount;
            break;
        }
    }
}

void Transfer(struct _Customer *customer, struct _BankAccount *accounts_archive, int *accounts_count){
    int id;
    printf("Please enter Bank Account ID to transfer money to\n");
    scanf("%d", &id);

    int i;
    for(i = 0; i < *accounts_count; i++){
        if(id == accounts_archive[i].id){
            printf("Bank account exist. Enter ammount to tranfer\n");
            double amount;

            while(1){
                scanf("%lf", &amount);

                if((amount < 0) || customer->account->balance - amount < 0){
                    printf("Amount too large or negative! Enter correct value\n");
                }
                else{
                    customer->account->balance -= amount;
                    accounts_archive[i].balance += amount;
                    break;
                }
            }
            break;
        }
    }
}

void Info(struct _BankAccount *customer_account){
    printf("balance: %lf\n", customer_account->balance);
}

void LogoutCustomer(struct _Customer *customer){
    customer->isLogged = 0;
    customer->account = NULL;
}