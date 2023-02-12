#include <stdio.h>

float calcHypotenuse (float x, float y) {

  return x * x + y * y;
  
}

int isCongruence(float aLine[], float bLine[]) {

  int count = 0;
  
  for (int i = 0; i < 3; i++) {

    float a = aLine[i];

    for (int i = 0; i < 3; i++) {

      float b = bLine[i];

      if (a == b) {

	count++;
	
      }
      
    }
    
  }

  if (count == 3) {

    return 1;
    
  } else {

    return 0;
    
  }
  
}

int congruence(float a1[], float a2[], float a3[], float b1[], float b2[], float b3[]) {

  float aHigh = a1[1] - a2[1];
  float aPointX = a1[0];
  float aPointY = a1[1];
  float aBottom = a3[0] - a2[0];
  float aa = aBottom;
  float ab = calcHypotenuse(aBottom - (aPointX - a2[0]), aHigh);
  float ac = calcHypotenuse(aBottom - (a3[0] - aPointX), aHigh);
  float aLine[3] = {aa, ab, ac};

  float bHigh = b1[1] - a2[1];
  float bPointX = b1[0];
  float bPointY = b1[1];
  float bBottom = b3[0] - b2[0];
  float ba = bBottom;
  float bb = calcHypotenuse(bBottom - (bPointX - b2[0]), bHigh);
  float bc = calcHypotenuse(bBottom - (b3[0] - bPointX), bHigh);
  float bLine[3] = {ba, bb, bc};

  return isCongruence(aLine, bLine);
  
}

int main () {

  //float a[2] = {x, y};

  float a1[2] = {5.0, 5.0};
  float a2[2] = {0.0, 0.0};
  float a3[2] = {5.0, 0.0};

  float b1[2] = {10.0, 5.0};
  float b2[2] = {5.0, 0.0};
  float b3[3] = {10.0, 0.0};

  if (congruence(a1, a2, a3, b1, b2, b3)) {

    printf("Congruence\n");
    
  } else {

    printf("NotCongruence\n");
    
  }
  
  return 0;

}
