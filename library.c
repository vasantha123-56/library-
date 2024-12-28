#include <stdio.h>
#include <string.h> 
#include <ctype.h> // For handling string trimming

struct library {
    char book_name[100];
    char author_name[100];
    int book_id;
    int return_period;
};

struct student_data {
    char student_name[100];
    char student_rollno[100];
    int year_of_study;
    char book[100];
};

// Function to trim leading and trailing spaces from a string
void trim_spaces(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    // Trim leading spaces
    while (isspace((unsigned char)str[start])) {
        start++;
    }

    // Trim trailing spaces
    while (end >= start && isspace((unsigned char)str[end])) {
        end--;
    }

    // Shift the string to the beginning of the buffer
    for (int i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }
    str[end - start + 1] = '\0'; // Null-terminate the string
}

int main() {
    char choice_book[100];
    struct library book1 = {"Atomic habits", "vvs laxman", 23, 15};
    struct library book2 = {"no way home", "tharun", 2, 12};
    struct library book3 = {"the influencer", "mahendra", 3, 55};
    struct library book4 = {"end emanna", "vijay kotlin", 4, 56};
    struct student_data student;

    printf("Enter your name: \n");
    scanf("%s", student.student_name);
    printf("Enter your roll number: \n");
    scanf("%s", student.student_rollno);
    printf("Enter the year of studying: \n");
    scanf("%d", &student.year_of_study);

    printf("--PICK ONE OF THE BELOW BOOKS, ONLY THESE BOOKS ARE AVAILABLE---\n");
    printf("1) %s \n2) %s \n3) %s \n4) %s \n", book1.book_name, book2.book_name, book3.book_name, book4.book_name);
    printf("Enter your choice: \n");
    scanf(" %[^\n]%*c", choice_book); // Reads input including spaces
    trim_spaces(choice_book); // Trim leading/trailing spaces

    if (strcmp(choice_book, "Atomic habits") == 0) {
        printf("You have chosen Atomic habits\nName: %s\nRoll No: %s\nYear of Study: %d\nBook Chosen: Atomic habits\nAuthor Name: %s\nReturn Period: %d days\nBook ID: %d\n",
               student.student_name, student.student_rollno, student.year_of_study, book1.author_name, book1.return_period, book1.book_id);
    } else if (strcmp(choice_book, "no way home") == 0) {
        printf("You have chosen No Way Home\nName: %s\nRoll No: %s\nYear of Study: %d\nBook Chosen: No Way Home\nAuthor Name: %s\nReturn Period: %d days\nBook ID: %d\n",
               student.student_name, student.student_rollno, student.year_of_study, book2.author_name, book2.return_period, book2.book_id);
    } else if (strcmp(choice_book, "the influencer") == 0) {
        printf("You have chosen The Influencer\nName: %s\nRoll No: %s\nYear of Study: %d\nBook Chosen: The Influencer\nAuthor Name: %s\nReturn Period: %d days\nBook ID: %d\n",
               student.student_name, student.student_rollno, student.year_of_study, book3.author_name, book3.return_period, book3.book_id);
    } else if (strcmp(choice_book, "end emanna") == 0) {
        printf("You have chosen End Emanna\nName: %s\nRoll No: %s\nYear of Study: %d\nBook Chosen: End Emanna\nAuthor Name: %s\nReturn Period: %d days\nBook ID: %d\n",
               student.student_name, student.student_rollno, student.year_of_study, book4.author_name, book4.return_period, book4.book_id);
    } else {
        printf("Invalid choice! Please choose a valid book from the list.\n");
    }

    return 0;
}
