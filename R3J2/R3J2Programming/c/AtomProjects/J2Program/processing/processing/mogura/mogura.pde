//  もぐらたたき

final int NUM = 10;
int x[] = new int [NUM];
int y[] = new int[NUM];
int flag[] = new int[NUM];
PImage img;

void setup(){
  size(800,500);
  imageMode(CENTER);
  img = loadImage("mogura.png");
  img.resize( img.width/10, img.height/10);
  for (int i=0; i<NUM; i++) {
    flag[i] = 0;
  }
}

void draw() {
  background(128);
  int j = int(random(NUM));
  if(frameCount%40==0 && flag[j]==0) {
    x[j] = int(random(width));
    y[j] = int(random(height));
    println(x[j],y[j]);
    flag[j] = 1;
  }
  
  for (int i=0; i<NUM; i++) {
    if (flag[i]==1) {
        image(img, x[i], y[i]);
    }
  }
  
  if (mousePressed) {
     println(mouseX,mouseY);
    for (int i=0; i<NUM; i++) {
      if (dist(x[i],y[i],mouseX,mouseY)<50) {
        flag[i] = 0;
      }
    }
  }
}
