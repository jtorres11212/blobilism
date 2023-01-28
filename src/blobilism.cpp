#include <iostream>
#include <vector>
#include "tinygl-cpp.h"
using namespace tinygl;

struct clrs{
  float red;
  float green;
  float blue;
  float a;
};
struct c{
  float x;
  float y; 
  float size;
};

class MyWindow : public Window {
 public:
  MyWindow(int w, int h) : Window(w, h) {}

  void setup() override {
    std::cout << "Window size: " << width() << ", " << height() << std::endl;
  }

  virtual void mouseMotion(int x, int y, int dx, int dy) {
    if (mouseIsDown(GLFW_MOUSE_BUTTON_LEFT)) {
      circles.x=x;
      circles.y=y;
      circles.size=sze;
      current.a=alpha;
      pclr.push_back(current);
      pdata.push_back(circles);
    }
  }

  
  virtual void mouseDown(int button, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
      float dis;
      float mx=mouseX();  // current mouse pos x
      float my=mouseY();  // current mouse pos y
      dis=sqrt(pow(2,double(mx-80))+pow(2,double(my-35)));
      if(dis<30){
        current.red=.6;
        current.green=1;
        current.blue=.4; 
      }
      else {
        dis=sqrt(pow(2,double(mx-160))+pow(2,double(my-35)));
        if(dis<30){
          current.red=1;
          current.green=.31;
          current.blue=.31;
          printf("Green"); 
        }
        else{
          dis=sqrt(pow(2,double(mx-320))+pow(2,double(my-35)));
          if(dis<30){
            current.red=.4;
            current.green=.6;
            current.blue=1;
            printf("Red"); 
         }
         else{
           dis=sqrt(pow(2,double(mx-400))+pow(2,double(my-35)));
          if(dis<30){
            current.red=.8;
            current.green=.4;
            current.blue=1; 
            printf("Blue");          }
          else{
            dis=sqrt(pow(2,double(mx-480))+pow(2,double(my-35)));
            if(dis<30){
              current.red=1;
              current.green=1;
              current.blue=.4;
              printf("Purple "); 
            }
          } 
          }
         }
        }
      }
  }

  void keyDown(int key, int mods) {
    if (key == GLFW_KEY_UP) {
      sze=sze+1;
    } 
    else if (key == GLFW_KEY_DOWN) {
      if(sze<2){
        sze=sze;
      }
      else{
        sze=sze - 1;
        std::cout << "Window size: " << key << ", " << sze << std::endl;
      }
    }
    else if (key == GLFW_KEY_LEFT) {
      if(alpha <= 0.1){
        alpha=alpha;
      }
      else{
        alpha=alpha - 0.1;
      }
      std::cout << "Window size: " << key << ", " << alpha<< std::endl;
    }
    else if (key == GLFW_KEY_RIGHT) {
      alpha=alpha+0.1;
    }
    else if (key == GLFW_KEY_C) {
    pdata.clear();
    pclr.clear();
    }
    }
  void draw() override {
      background(0.95f, 0.95f, 0.95f); // parameters: r, g, b
      color(1.0f, 0.5f, 0.5f);
      circle(width() * 0.5f, height() * 0.5, sze);
      color(0.1f, 0.1f, 0.1f);
      square(width()/2.0f, 35, width(), 70);
      struct c cr={80, 35, 60};
      struct clrs pal={1, 0, 0};
      data.push_back(cr);
      pallete.push_back(pal);
      cr.x=80;
      pal.red=.6;
      pal.green=1;
      pal.blue=.4;
      data.push_back(cr);
      pallete.push_back(pal);
      cr.x=cr.x+80;
      pal.red=1;
      pal.green=.31;
      pal.blue=.31;
      data.push_back(cr);
      pallete.push_back(pal);
      cr.x=cr.x+80;
      pal.red=.4;
      pal.green=.6;
      pal.blue=1;
      data.push_back(cr);
      pallete.push_back(pal);
      cr.x=cr.x+80;
      pal.red=.8;
      pal.green=.4;
      pal.blue=1;
      data.push_back(cr);
      pallete.push_back(pal);
      for(int i=0; i<data.size(); i++){
        color(pallete[i].red, pallete[i].green, pallete[i].blue);
        circle(data[i].x, data[i].y, data[i].size);
      }   
      for(int i=0; i<pdata.size(); i++){
        color(pclr[i].red, pclr[i].green, pclr[i].blue,pclr[i].a);
        circle(pdata[i].x, pdata[i].y, pdata[i].size);
      }  
  }
 private:
  float sze=40;
  float alpha=1;
  struct clrs current={1,0,0}; 
  struct c circles;
  std::vector<clrs> pallete;
  std::vector<c> data;
  std::vector<c> pdata;
  std::vector<clrs> pclr;
};
int main() {
  MyWindow window(500, 500);
  window.run();
}
