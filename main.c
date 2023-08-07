#include <stdio.h>
#include <string.h>
#define MAX_LEN_NAME 255
#define MAX_LEN_SURNAME 255
#define MAX_LEN_PHONE 255

#define LEN_PHONEBOOK_ELEMMENT (MAX_LEN_NAME + MAX_LEN_SURNAME + MAX_LEN_PHONE)
//number of entries in the phone book
//#define NUMBER_ENTIRES 10

struct phonebook_element{
    char array_name[MAX_LEN_NAME];
    char array_surname[MAX_LEN_SURNAME];
    char array_phone[MAX_LEN_PHONE];
};

//struct phonebook_element phonebook_array[NUMBER_ENTIRES];


char scan_input_command(void);
char scanf_input_number(long* number);

int main(void)
{
    long count_phonebook_element = 10;
    char* ptr;
    ptr = malloc(count_phonebook_element*LEN_PHONEBOOK_ELEMMENT);

    struct phonebook_element* temp_phonebook_element;

    long temp_number;
    char temp_name_array[MAX_LEN_NAME] = {"Ivan_0"};
    char temp_surname_array[MAX_LEN_SURNAME] = {"Ivanov_0"};
    char temp_phone_array[MAX_LEN_PHONE] = {"89238277580"};
    long i, j;

    for(i = 0; i < count_phonebook_element; ++i)
    {

        temp_name_array[5] = i + 0x30;
        temp_surname_array[7] = i + 0x30;
        temp_phone_array[10] = i + 0x30;

        temp_phonebook_element = (ptr + i*LEN_PHONEBOOK_ELEMMENT);

        for(j = 0; j < MAX_LEN_NAME; ++j)
        {
            temp_phonebook_element->array_name[j] = temp_name_array[j];
        }

        for(j = 0; j < MAX_LEN_SURNAME; ++j)
        {
            temp_phonebook_element->array_surname[j] = temp_surname_array[j];
        }

        for(j = 0; j < MAX_LEN_PHONE; ++j)
        {
            temp_phonebook_element->array_phone[j] = temp_phone_array[j];
        }

 //       printf("Name = %s\n", temp_phonebook_element->array_name);
 //       printf("Surname = %s\n", temp_phonebook_element->array_surname);
 //       printf("Phone = %s\n", temp_phonebook_element->array_phone);
    }

    printf("1 - add abonent\n");
    printf("2 - rename abonent\n");
    printf("3 - list PhoneBook abonent\n");
    printf("4 - search abonent to name\n");
    printf("5 - delete abonent to number\n");
    printf("6 - exit\n");



    int c;
    unsigned int nc = 0;
    char temp_array[255];
    char command_phonebook = 0;
    while(1)
    {
        command_phonebook = scan_input_command();

        if(1 == command_phonebook)
        {
            // 1 - add abonent
            printf("Enter name abonent\n");
            nc = 0;
            while ((c = getchar()) != '\n')
            {
                if(nc > (MAX_LEN_NAME - 1)){nc =(MAX_LEN_NAME - 1);}
                temp_name_array[nc] = c;
                ++nc;
            }
                    
            if(nc > MAX_LEN_NAME)
            {
                printf("Input Error name\n");
            }
            else
            {
                temp_name_array[nc] = 0;
                printf("Enter surname abonent\n");
                nc = 0;
                while ((c = getchar()) != '\n')
                {
                    if(nc > (MAX_LEN_SURNAME - 1)){nc =(MAX_LEN_SURNAME - 1);}
                    temp_surname_array[nc] = c;
                    ++nc;
                }
                if(nc > MAX_LEN_SURNAME)
                {
                    printf("Input Error surname\n");
                    temp_array[0] = '1';  nc = 1;
                }
                else
                {
                    temp_surname_array[nc] = 0;
                    printf("Enter phone number\n");
                    nc = 0;
                    while ((c = getchar()) != '\n')
                    {
                       if(nc > (MAX_LEN_PHONE - 1)){nc =(MAX_LEN_PHONE - 1);}
                       temp_phone_array[nc] = c;
                       ++nc;
                    }
                    
                    if(nc > MAX_LEN_PHONE)
                    {
                       printf("Input Error phone\n");
                       temp_array[0] = '1';  nc = 1;
                    }
                    else
                    {
                        temp_phone_array[nc] = 0;
                        ++count_phonebook_element;
                        ptr = realloc(ptr, count_phonebook_element*LEN_PHONEBOOK_ELEMMENT);
                        temp_phonebook_element = (ptr + (count_phonebook_element - 1)*LEN_PHONEBOOK_ELEMMENT);
                        for(j = 0; j < MAX_LEN_NAME; ++j)
                        {
                           temp_phonebook_element->array_name[j] = temp_name_array[j];
                        }
                        for(j = 0; j < MAX_LEN_SURNAME; ++j)
                        {
                           temp_phonebook_element->array_surname[j] = temp_surname_array[j];
                        }
                        for(j = 0; j < MAX_LEN_PHONE; ++j)
                        {
                            temp_phonebook_element->array_phone[j] = temp_phone_array[j];
                        }
                     }
                 }

              }

        }

        if(2 == command_phonebook)
        {
            // 1 - rename abonent
            printf("Enter number abonent\n");
            if(0 != scanf_input_number(&temp_number))
            {
                printf("Input Error number abonent\n");
            }
            else
            {
                if(count_phonebook_element <= temp_number)
                {
                    printf("Input Error number biger than max abonent number\n");
                }
                else
                {
                    printf("Enter name abonent\n");
                    nc = 0;
                    while ((c = getchar()) != '\n')
                    {
                        if(nc > (MAX_LEN_NAME - 1)){nc =(MAX_LEN_NAME - 1);}
                        temp_name_array[nc] = c;
                        ++nc;
                    }
                    
                    if(nc > MAX_LEN_NAME)
                    {
                        printf("Input Error name\n");
                      }
                    else
                    {
                        temp_name_array[nc] = 0;
                        printf("Enter surname abonent\n");
                        nc = 0;
                        while ((c = getchar()) != '\n')
                        {
                            if(nc > (MAX_LEN_SURNAME - 1)){nc =(MAX_LEN_SURNAME - 1);}
                            temp_surname_array[nc] = c;
                            ++nc;
                        }
                        if(nc > MAX_LEN_SURNAME)
                        {
                            printf("Input Error surname\n");
                            temp_array[0] = '1';  nc = 1;
                        }
                        else
                        {
                            temp_surname_array[nc] = 0;
                            printf("Enter phone number\n");
                            nc = 0;
                            while ((c = getchar()) != '\n')
                            {
                                if(nc > (MAX_LEN_PHONE - 1)){nc =(MAX_LEN_PHONE - 1);}
                                temp_phone_array[nc] = c;
                                ++nc;
                            }
                            
                            if(nc > MAX_LEN_PHONE)
                            {
                                printf("Input Error phone\n");
                                temp_array[0] = '1';  nc = 1;
                            }
                            else
                            {
                                temp_phone_array[nc] = 0;
                                temp_phonebook_element = (ptr + temp_number*LEN_PHONEBOOK_ELEMMENT);
                                for(j = 0; j < MAX_LEN_NAME; ++j)
                                {
                                    temp_phonebook_element->array_name[j] = temp_name_array[j];
                                }
                                for(j = 0; j < MAX_LEN_SURNAME; ++j)
                                {
                                    temp_phonebook_element->array_surname[j] = temp_surname_array[j];
                                }
                                for(j = 0; j < MAX_LEN_PHONE; ++j)
                                {
                                    temp_phonebook_element->array_phone[j] = temp_phone_array[j];
                                }
                            }
                        }

                    }

                }

            }


        }

        if(3 == command_phonebook)
        {
            // 3 - list PhoneBook abonen
            for(i = 0; i < count_phonebook_element; ++i)
            {
                temp_phonebook_element = (ptr + i*LEN_PHONEBOOK_ELEMMENT);
                printf("%17d Name = %s\n", i, temp_phonebook_element->array_name);
                printf("%17d Surname = %s\n", i, temp_phonebook_element->array_surname);
                printf("%17d Phone = %s\n", i, temp_phonebook_element->array_phone);
            }
        }
        

        if(4 == command_phonebook)
        {
            // 4 - search abonent to name
            printf("Enter name search abonent\n");
            nc = 0;
            while ((c = getchar()) != '\n')
            {
                temp_name_array[nc] = c;
                ++nc;
                if(nc > (MAX_LEN_NAME - 1))
                {
                   break;
                }
            }
            temp_name_array[nc] = 0;
            if(nc > MAX_LEN_NAME)
            {
                printf("Input Error name\n");
            }
            else
            {
                char temp = 1;
                for(j = 0; j < count_phonebook_element; ++j)
                {
                    temp_phonebook_element = (ptr + j*LEN_PHONEBOOK_ELEMMENT);
                    if(!strcmp (temp_phonebook_element->array_name, temp_name_array))
                    {
                        temp = 0;
                        temp_number = j;
                        break;
                    }
                }

                if(!temp)
                {
                    printf("Name = %s\n", temp_phonebook_element->array_name);
                    printf("Surname = %s\n", temp_phonebook_element->array_surname);
                    printf("Phone = %s\n", temp_phonebook_element->array_phone);
                }
                else
                {
                    printf("No name in list\n");
                }
                temp_array[0] = '3'; nc = 1;
            }
        }

        if(5 == command_phonebook)
        {
            // 5 - delete abonent to number
            printf("Enter number delete abonent\n");
//            scanf_input_number(&temp_number);

            if(0 != scanf_input_number(&temp_number))
            {
                printf("Input Error number abonent\n");
            }
            else
            {
                
                if(count_phonebook_element <= temp_number)
                {
                    printf("Input Error number biger than max abonent number\n");
                }
                else
                {
//                    temp_number = temp_array[0] - 0x30;

                    temp_phonebook_element = (ptr + temp_number*LEN_PHONEBOOK_ELEMMENT);
                    for(j = 0; j < MAX_LEN_NAME; ++j)
                    {
                        temp_phonebook_element->array_name[j] = 0;
                    }

                    for(j = 0; j < MAX_LEN_SURNAME; ++j)
                    {
                        temp_phonebook_element->array_surname[j] = 0;
                    }

                    for(j = 0; j < MAX_LEN_PHONE; ++j)
                    {
                        temp_phonebook_element->array_phone[j] = 0;
                    }
                }
            }

        }

        if(6 == command_phonebook)
        {
            // 6 - exit
            break;
        }




    }

    printf("The End\n");


    return 0;
}


char scan_input_command(void)
{
    int c;
    unsigned int nc = 0;
    char array[2];
    nc = 0;
    while ((c = getchar()) != '\n')
    {
        array[nc] = c;
        ++nc;
        
        if((0x31 > array[0]) || (0x36 < array[0]))
        {
             printf("Wrong input command number\n");
             nc = 0;
        }

        if(1 < nc)
        {
             printf("Wrong input command leng\n");
             nc = 0;
        }
    }
    
    return (array[0] - 0x30);
}

char scanf_input_number(long* number)
{
    int c;
    unsigned int nc = 0;
    char array[17];
    nc = 0;
    (*number) = 0;

    while ((c = getchar()) != '\n')
    {
        if((0x30 > c) || (0x39 < c))
        {
             printf("Wrong input number symbol\n");
             nc = 0;
             (*number) = 0;
             return 1;
        }

        if((17 - 1) < nc)
        {
             printf("Wrong input number leng\n");
             nc = 0;
             (*number) = 0;
             return 1;
        }

        array[nc] = c;
        ++nc;
        (*number) = 10*(*number) + (c - 0x30);
    }

    return 0;
}
            




