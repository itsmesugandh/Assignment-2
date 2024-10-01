
`
# IIIT-Delhi Library Management System

## Overview

This project models the administrative and academic structures of IIIT-Delhi, focusing on library management. It includes five administrative departments—IRD, Academics, Student Affairs, Store & Purchase, and Library—headed by deans (optionally assisted by associate deans), with the overall structure managed by a registrar. The library system manages books, journals, and publication rankings, providing functionalities for users to access and manage library items.

## File Structure

- `main.cpp`: Entry point of the program that manages user interactions.
- `Book.cpp` / `Book.h`: Implementation and definition of the Book class for managing book details.
- `User.cpp` / `User.h`: Implementation and definition of the User class, representing library users.
- `Journals.cpp` / `Journals.h`: Implementation and definition of the Journals class for managing journal entries.
- `PublicationRank.cpp` / `PublicationRank.h`: Implementation and definition of the PublicationRank class for ranking publications.
- `Library.cpp` / `Library.h`: Implementation and definition of the Library class, encapsulating library operations.
- `classFunctions.cpp`: Contains miscellaneous functions related to class operations.
- `functions.cpp`: Includes various helper functions used throughout the project.
- `LibraryItem.cpp`: Manages library items, including books and journals.

## Compilation and Execution

To compile the program, navigate to the project directory and use the following command:

```bash
make
```

To run the compiled program, execute:

```bash
make run
```

To clean up the build artifacts (object files and executable), use:

```bash
make clean
```

## Usage

Upon execution, the program prompts the user to input the name of a person to fetch room numbers, telephone numbers, and email addresses from the system. It also allows for managing library items and user interactions.

### Input Format

- The program accepts names of individuals (e.g., faculty, students) as input to retrieve their contact information.

## Dependencies

- This project requires a C++ compiler (g++) to compile and run the code.
- Standard C++ libraries are utilized for functionality.

## Implementation Details

- Classes are used to model the various components of the system, including libraries, books, users, and journals.
- A Makefile is included to facilitate easy compilation and execution of the project.

## Notes

- Ensure that all necessary header files and global variables are included in the respective source files.
- The logical structure of the program is maintained as per the requirements.

## Author

Your Name  
Your Email  
Your Contact Information
```

### Instructions for Finalizing
1. **Replace Placeholder Text**: Update the "Your Name," "Your Email," and "Your Contact Information" with your actual details.
2. **Test the Project**: Ensure that the provided commands work as expected.
3. **Format and Add Details**: You can add any additional sections or details as required, such as usage examples or screenshots.

Feel free to modify this README to fit your project’s specific needs and personal style!
