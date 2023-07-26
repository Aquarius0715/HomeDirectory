#include <stdio.h>

int MEM[100] = {0}, REG[16] = {0};
int ifid[14] = {0}, idex[4] = {0}, memwb[4] = {0};
unsigned int pc;

int if_stage(void);
void id_stage(void);
void ex_stage(void);
void wb_stage(void);

int main(void) {
  return 0;
}

int if_stage(void) {
  if (pc == 0) return 1;
  i++;
  return 0;
}

void id_stage(void) {
  if (MEM[pc] == 0) return 1;
  ifid = MEM[pc];
  return 0;
}

void ex_stage(void) {
  for (int i = 0; i < 4; i++) {
	 MEM[i] = ifid[i];
  }
}

void mem_stage(void) {

}

void wb_stage(void) {

}
