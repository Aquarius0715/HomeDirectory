int NAND(int a, int b) {
  if (a && b) {
    return 0;
  } else {
    return 1;
  }
}

int AND(int a, int b) {
  if (a == b) {
    return 1;
  } else {
    return 0;
  }
}

int NOT(int a) {
  return !a;
}

int XOR(int a, int b) {
  if (a == b) {
    return 0;
  } else {
    return 1;
  }
}

int OR(int a, int b) {
  if (a || b) {
    return 1;
  } else {
    return 0;
  }
}
