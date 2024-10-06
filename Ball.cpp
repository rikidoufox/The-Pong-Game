//
//  Ball.cpp
//  Lab 2 Pong Game
//
//  Created by Krrish Sharma, 20-09-2024
#include "Ball.h"
#include <cmath>
#include "Globals.h"
#include <iostream>

Ball::Ball(){};
Ball::Ball(double X, double Y, double Velocity_x, double Velocity_y, int Id){
    this->x=X;
    this->y=Y;
    this->velocity_x=Velocity_x;
    this->velocity_y=Velocity_y;
    this->id=Id;
    height=1;
    width=1;
};
double Ball::getX(){
    return x;
}

int Ball::getID(){
    return id;
}
void Ball::update(){
    velocity_y=velocity_y-0.02*timeStep;
    x= x + velocity_x * timeStep;
    y= y + velocity_y * timeStep;
};
int Ball::overlap(Ball& b){   //maybe a problem here 
    double x_overlap=fabs(x-b.x);
    double y_overlap=fabs(y-b.y);

    if(x_overlap<=1){
        x_overlap = 1-x_overlap;
    }
    if(y_overlap<=1){
        y_overlap=1-y_overlap;
    }

    if(x_overlap<=1 && y_overlap<=1){
        if(x_overlap>y_overlap){
            return HORIZONTAL_OVERLAP;
        } else if(x_overlap<y_overlap){
        return VERTICAL_OVERLAP;
        }
    }
    return NO_OVERLAP;

};
int Ball::overlap(Player& p){ //maybe a problem here 
    if (x<=fabs(p.getX()+1.2)) {
        if(y>=p.getY() && y<=p.getY()+p.getHeight()){
            return HORIZONTAL_OVERLAP;
        }                                                                        
    }
   
    return NO_OVERLAP;
    
 };
void Ball::bounce(Ball arr[], int ballCount, Player player){ //maybe here too
    if(y<=0 || y>=HEIGHT-1){
        velocity_y=-velocity_y;
    }
    if(x>=WIDTH-1){
        velocity_x= -velocity_x;
    }
    if(overlap(player)==HORIZONTAL_OVERLAP){
        velocity_x=-velocity_x;
    }
    for(int i=0;i<ballCount;i++){
        if(id!=arr[i].getID()){
            if(overlap(arr[i]) == HORIZONTAL_OVERLAP){
                velocity_x=-velocity_x;
            }
            if(overlap(arr[i]) == VERTICAL_OVERLAP){
                velocity_y=-velocity_y;
        }
        }
    }
};
void Ball::draw(Screen &screen_to_draw_to){
    screen_to_draw_to.addPixel(x,y,'o');
}


