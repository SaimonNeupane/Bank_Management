#include <stdio.h>
struct details
{
    char name[60];
    int account_number;
    int PIN;
    int age;
    float balance;
    int sec_ques;
};
struct details account[10];
static int x = 0;

int createAccount()
{
    struct details new_account;
    printf("    Enter your full name:");
    scanf(" %[^\n]", new_account.name);
    printf("    Enter Your age:");

    do
    {
        scanf("%d", &new_account.age);

        if (new_account.age < 0)
        {
            printf("Enter valid age:");
        }

    } while (new_account.age <= 0);
    printf("    Enter  Your account number as you wish(4 digits recommended):");
    scanf("%d", &new_account.account_number);
    printf("    How much do you want to deposit initially?");
    scanf("%f", &new_account.balance);

    printf("    Set your PIN.(2 digits recommended):");
    scanf("%d", &new_account.PIN);
    printf("    Security Question is necessary to reset your PIN if you forgot your PIN.\n");
    printf("    What is your lucky number?");
    scanf("%d", &new_account.sec_ques);
    // for (int i = 0; i < 9; i++)
    // {
    //     char AccHolderName = account[0].name;
    //     int AccHolderAge = account[0].age;
    //     int AccHolderAccNo = account[0].account_number;
    //     if (account[i].account_number == AccHolderAccNo)
    //     {
    //         printf("This account number already exists.Please select another account number.\n");
    //     }
    //     else if (account[i].name == AccHolderName && account[i].age == AccHolderAge && account[i].account_number == AccHolderAccNo)
    //     {
    //         printf("You already have a account cannot create another ");
    //     }
    //     else
    //     {
    //         new_account.account_number = account[i].account_number;
    //     }
    // }
    printf("Account no. %d created succesfully in the name of %s\n", new_account.account_number, new_account.name);
    account[x] = new_account;
    x++;

    return 0;
}
int Forgot_PIN()
{
    int match_ac_no, pin_check, again_pin_check;
    printf("Enter Your Account Number:");
    scanf("%d", &match_ac_no);
    for (int i = 0; i < 9; i++)
    {
        if (account[i].account_number == match_ac_no)
        {
            printf("What is your lucky number?");
            scanf("%d", &pin_check);
            if (pin_check == account[i].sec_ques)
            {
                printf("what do you want to enter your PIN?");
                scanf("%d", &pin_check);
                printf("Enter it once again:");
                scanf("%d", &again_pin_check);
                if (again_pin_check == pin_check)
                {
                    account[i].PIN = again_pin_check;
                    printf("Now your PIN is reset to:%d", again_pin_check);
                    return -1;
                }
                else
                {
                    printf("The two pins doesnot match");
                    return -1;
                }
            }
            else
            {
                printf("The security question doesnot matches.Please try again or contact to our nearest branch.THANK YOU!!");
                return 0;
            }
        }
        else
        {
            printf("No accounts of no.%d was found", match_ac_no);
            return -1;
        }
    }
}

int Sign_in()
{
    int c = 0;
    int account_no_check, PIN, prev_pin, now_pin_1, now_pin_2;
    float money;
    float check_available_money;
    printf("Enter you account number:");
    scanf("%d", &account_no_check);

    for (int i = 0; i < 10; i++)
    {
        if (account_no_check == account[i].account_number)
        {
            c++;
            printf("Enter the PIN:");
            scanf("%d", &PIN);
            if (PIN == account[i].PIN)
            {
                int check_choice;
                printf("\n*_*-*_*-*_*-Sign-In successful-*_*-*_*-*_*\n");
                printf("\n\nHOW CAN WE HELP YOU TODAY?\n\n");

                do
                {
                    printf("6:Check Balance\t");
                    printf("7:Deposit Balance\t");
                    printf("8:Withdraw Balance\t");
                    printf("9:Reset PIN\t");
                    printf("10:Exit\n\n\n");
                    scanf("%d", &check_choice);
                    switch (check_choice)
                    {
                    case 6:
                        printf("Your current balance is %.2f\n\n", account[i].balance);
                        break;
                    case 7:
                        printf("How much do you want to deposit?\n\n");
                        scanf("%f", &money);
                        account[i].balance += money;
                        printf("Now your current balance is %.2f\n\n", account[i].balance);
                        break;
                    case 8:

                        printf("How much money do you want to withdraw?\n\n");
                        scanf("%f", &check_available_money);
                        if (check_available_money <= account[i].balance && check_available_money >= 0)
                        {
                            money = check_available_money;
                            account[i].balance -= money;
                            printf("Now your current balance is %.2f\n\n", account[i].balance);
                        }
                        else
                        {
                            printf("\t!!!!!Not enough Balance!!!!!\n");
                        }
                        break;
                    case 9:
                        printf("What was your previos pin?\n");
                        scanf("%d", &prev_pin);
                        if (prev_pin == account[i].PIN)
                        {
                            printf("what do you want to set your PIN?\n");
                            scanf("%d", &now_pin_1);
                            printf("Enter it once again:");
                            scanf("%d", &now_pin_2);
                            if (now_pin_1 == now_pin_2)
                            {
                                account[i].PIN = now_pin_1;
                                printf("Your pin is changed to %d", now_pin_1);
                                printf("%d", account[i].PIN);
                            }
                        }
                        else
                        {
                            printf("Wrong PIN");
                            return -1;
                        }
                        break;
                    case 10:
                        return 0;
                    }
                } while (check_choice != 10);
            }
            else
            {
                printf("Incorrect Pin");
                return -1;
            }
        }
    }
    if (c == 0)
    {
        printf("The account was not found.");
    }
}

int exit_oo()
{
    return 0;
}
void main()
{
    int choice;
    printf("Hi! Welcome to our banking management system\n");
    printf("How can we help you today?\n");
    // printf("1:Create Account\n");
    // printf("2:Sign in\n");
    // printf("3:Forgot PIN?\n");
    // printf("4:exit\n");

    do
    {
        printf("1:Create Account\n");
        printf("2:Sign in\n");
        printf("3:Forgot PIN?\n");
        printf("4:exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            Sign_in();
            break;

        case 3:
            Forgot_PIN();
            break;
        case 4:
            exit_oo();
            break;
        default:
            printf("Enter valid keys \n");
            break;
        }

    } while (choice != 4);
}
