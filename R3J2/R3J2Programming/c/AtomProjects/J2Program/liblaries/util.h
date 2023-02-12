
int get_string_size(char string[]) {

  return sizeof string / sizeof string[0];

}

int get_integer_size(int num[]) {

  return sizeof num / sizeof num[0];

}

int is_contains_integer(int num[], int x) {

  for (int i = 0; i < get_integer_size(num); i++) {

    if (num[i] == x) {

      return 1;

    }

  }

  return 0;

}

int is_contains_char(char string[], char x) {

  for (int i = 0; i < get_string_size(string); i++) {

    if (string[i] == x) {

      return 1;

    }

  }

  return 0;

}

int is_exist_integer() {



}
