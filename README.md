# Project FDF Wireframe Model

## Introduction

Welcome to the FDF Wireframe Model project! In this project, you will create a basic computer graphics project that involves creating a wireframe model representation of a 3D landscape. This project will introduce you to graphics programming and working with the MiniLibX, the school graphical library. Your task is to connect various points in 3D space with line segments to create a wireframe model of a landscape.

![alt text](https://github.com/nicolasb1607/42-fdf/blob/master/Screenshot%20from%202023-09-19%2015-03-21.png)

## Common Instructions

Before we dive into the project details, let's review some common instructions that apply to this project:

- **Language**: Your project must be written in C.

- **Norm Compliance**: Your project must adhere to the Norm. Norm errors, including those in bonus files/functions, will result in a score of 0.

- **Stability**: Your functions should not quit unexpectedly (e.g., segmentation fault, bus error, double free) except for undefined behaviors. Unexpected crashes will lead to a non-functional evaluation.

- **Memory Management**: Properly free all heap allocated memory space. No memory leaks will be tolerated.

- **Makefile**: If required by the subject, include a Makefile to compile your source files with the flags -Wall, -Wextra, and -Werror using cc. Ensure your Makefile does not relink and includes the rules $(NAME), all, clean, fclean, and re.

- **Bonuses**: If applicable, create a bonus rule in your Makefile to include headers, libraries, or functions forbidden in the main part of the project. Store bonus code in separate _bonus.{c/h} files.

- **Libft Integration**: If permitted, integrate your libft by copying its sources and associated Makefile into a libft folder with its own Makefile. Your project’s Makefile should compile the library via its Makefile and then compile the project.

- **Testing**: Develop test programs for your project, although they won't be submitted or graded. These tests will assist in verifying your work and evaluating your peers' work during the defense.

- **Submission**: Submit your work to your assigned git repository. Deepthought may grade your work after peer evaluations, and any errors during Deepthought’s grading will halt the evaluation.

## Project Instructions

### Mandatory Part

Your task is to create a simple wireframe model representation of a 3D landscape by connecting various points (x, y, z) using line segments (edges). Here are the main requirements:

- You must use the MiniLibX, either the version available on the school machines or by installing it using its sources.

- Create a Makefile that compiles your source files without relinking.

- Avoid using global variables in your project.
- 
### Makefile Rules

- `NAME`: The name of the executable.
- `all`: Compile the project.
- `clean`: Delete object files.
- `fclean`: Delete object files and the executable.
- `re`: Recompile the project.

### Arguments

Your program should accept a file in the format \*.fdf as an argument.
