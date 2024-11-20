#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* input(char* str) {
    char* inp = (char*)malloc(50*sizeof(char));
    printf("(%s)$ ", str);
    fgets(inp, 50, stdin);
    return inp;
}

typedef struct {
  char name[50];
  char surname[50];
  int age;
} Player;

typedef struct {
  int id;
  char name[50];
  char manufacturer[50];
  char cpu_type[50];
  char gpu_type[50];
} Notebook;

bool validate_player(Player player) {
  return (strlen(player.name) < 2 || strlen(player.surname) < 2);
}

Player new_player(int id) {
  Player new_p;
  printf("--- %d ---\n", id+1);
  strcpy(new_p.name, input("Введіть ім'я"));
  strcpy(new_p.surname, input("Введіть прізвище"));
  new_p.age = atoi(input("Введіть вік"));
  return new_p;
}

Player* gen_players(int ct) {
    Player* players = (Player*)malloc(ct * sizeof(Player));
    for (int i = 0; i < ct; i++) {
        while (true) {
            Player player = new_player(i);
            if (validate_player(player) || player.age <= 0) {
                printf("Новий користувач повинен відповідати наступним правилам:\n"
                       "\tІм'я та прізвище - більше 2 символів;\n"
                       "\tВік - більше 0;\n"
                       "\tПеревірте коректність полів та спробуйте ще раз.\n");
                continue;
            }
            players[i] = player;
            break;
        }
    }
    return players;
}

void sort_players(Player* players, int ct) {
  for( int i = 0; i < ct; i++ ) {
    for( int j = i+1; j < ct; j++ ) {
      if(players[i].age > players[j].age) {
        int tmp = players[i].age;
        players[i].age = players[j].age;
        players[j].age = tmp;
      }
    }
  }
}

void show_players(Player* players, int ct) {
  for( int i = 0; i < ct; i++ ) {
    printf("\nВік: %d, Ім'я: %s, Прізвище: %s\n", players[i].age, players[i].name, players[i].surname);
  }
}

void print_notebook(Notebook notebook) {
  printf("ID: %d\n", notebook.id);
  printf("Name: %s\n", notebook.name);
  printf("Manufacturer: %s\n", notebook.manufacturer);
  printf("CPU Type: %s\n", notebook.cpu_type);
  printf("GPU Type: %s\n", notebook.gpu_type);
}

int main() {
  /// ---   T A S K   O N E   ---
  int ct;
  printf("(Уведіть кількість користувачів)$ ");
  scanf("%d", &ct);
  getchar();
  Player* players = gen_players(ct);
  sort_players(players, ct);
  printf("--- Відсортований масив ---");
  show_players(players, ct);

  /// ---   T A S K   T W O   ---
  int inp;
  Notebook notebooks[] = {
    {1, "Dell XPS 13", "Dell", "Intel Core i7-1165G7", "Intel Iris Xe"},
    {2, "MacBook Pro 16", "Apple", "Apple M1 Pro", "Apple Integrated"},
    {3, "HP Spectre x360", "HP", "Intel Core i7-1165G7", "Intel Iris Xe"},
    {4, "Lenovo ThinkPad X1 Carbon", "Lenovo", "Intel Core i7-1185G7", "Intel Iris Xe"},
    {5, "Asus ROG Zephyrus G14", "Asus", "AMD Ryzen 9 5900HS", "NVIDIA GeForce RTX 3060"},
    {6, "Microsoft Surface Laptop 4", "Microsoft", "Intel Core i7-1185G7", "Intel Iris Xe"},
    {7, "Razer Blade 15", "Razer", "Intel Core i7-11800H", "NVIDIA GeForce RTX 3070"},
    {8, "Acer Predator Helios 300", "Acer", "Intel Core i7-11800H", "NVIDIA GeForce RTX 3060"},
    {9, "Samsung Galaxy Book Pro 360", "Samsung", "Intel Core i7-1165G7", "Intel Iris Xe"},
    {10, "Alienware m15 R6", "Alienware", "Intel Core i7-11800H", "NVIDIA GeForce RTX 3070"}
  };
  for(int i = 0; i < 10; i++) {
    print_notebook(notebooks[i]);
  }
  inp = atoi(input("Уведіть ідентифікатор моделі"));
  while(inp<=0||inp>10) {
    inp = atoi(input("Не коректний ідентифікатор! Уведіть ідентифікатор моделі"));
  }
  print_notebook(notebooks[inp+1]);
}