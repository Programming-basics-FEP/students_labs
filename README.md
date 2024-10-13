# Students Labs

[Copypaste](https://github.com/Programming-basics-FEP-11/students_labs?tab=readme-ov-file#copypaste)

## **Branch Naming**

Each student must create their own branch using their **first** and **last name** from your passport

### Example:

For **Artur Lys**, the branch is:

```bash
git checkout -b "ArturLys"
```
Submit all your labs directly to **your** branch

## **Folder and File Structure**

- Lab folders: `lab{number}`
  
  ```bash
  lab5/
  ```

- C files: `lab{number}_{task_number}.c` or `lab{number}.c` if there's only one

  ```bash
  lab5_1.c
  ```

- Reports: PDF format, `lab{number}.pdf`

  ```bash
  lab5.pdf
  ```

## **Example Structure**

```
├── ArturLys/
│   ├── lab5/
│   │   ├── lab5_1.c
│   │   ├── lab5_2.c
│   │   ├── lab5.pdf
│   └── lab6/
│       ├── lab6.c
│       ├── lab6.pdf
```

## **How to use .gitignore**

1. Create `.gitignore`
2. Add files to ignore

- Example .gitignore file
  
   ```
   README.md
   *.docx
   ```
  ignores all docx files and README.md

## **Submission Guidelines**

1. Create your branch
2. Organize solutions in `lab{number}` folders
3. Name files as specified
4. Submit reports in PDF format


## **Copypaste**


### If you have SSH
```bash
git clone git@github.com:Programming-basics-FEP-11/students_labs.git
```
### HTTPS (default)
```bash
git clone https://github.com/Programming-basics-FEP-11/students_labs.git
```

### Create your branch
```bash
git checkout -b "NameSurname"
```
### Add files
```bash
git add .
```
### Commit
```bash
git commit -m "message"
```
### Push commit in your branch
```bash
git push origin "NameSurname"
```
### If you get an error, this might fix it
```bash
git remote set-url origin git@github.com:Programming-basics-FEP-11/students_labs.git
```
