
# Students Labs Repository

This repository is intended for submitting individual lab solutions. Each student must follow the provided structure and guidelines.

## **Branch Naming Convention**

Each student should create their own branch. Use your **first name** and **last name** as per your **passport** in the following format:

```bash
git checkout -b "NameSurname"
```

### Example:

For a student named **Artur Lys**, the branch name would be:

```bash
git checkout -b "ArturLys"
```

## **Folder and File Structure**

### Folder Structure:
- The folder for each lab solution should be named `lab{number}` where `{number}` corresponds to the lab number provided in the task.
  
  **Example:**
  ```bash
  lab5/
  ```

### File Naming:
- For code files, the naming convention should follow the format: `lab{number}_{task_number}.extension`.

  **Example:**
  - For C code files:
    ```bash
    lab5_1.c
    ```
- For report files, submit in PDF format and name the file as `lab{number}.pdf`.

  **Example:**
  ```bash
  lab5.pdf
  ```

## **Example Repository Structure**

```
├── ArturLys/
│   ├── lab5/
│   │   ├── lab5_1.c
│   │   ├── lab5_2.c
│   │   ├── lab5.pdf
│   └── lab6/
│       ├── lab6.c
│       ├── lab6.pdf
├── JaneDoe/
│   ├── lab5/
│   │   ├── lab5_2.c
│   │   ├── lab5_3.c
│   │   ├── lab5.pdf
```

## **Submission Guidelines**

1. Each student must create their own branch using their name as described above.
2. Organize your solutions into separate folders for each lab.
3. Ensure all files are named according to the required format.
4. Submit a PDF report for each lab with a clear and concise explanation of your solution.
