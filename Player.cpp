//
//  Player.cpp
//  Lab 2 Pong Game
//
//  Created by Krrish Sharma, 20-09-2024
#include "Player.h"
#include "Screen.h"
#include "Globals.h"
Player::Player(){};
Player::Player(double X, double Y, int Height){
    this->x=X;
    this->y=Y;
    this->height=Height;
}
double Player::getX(){
    return x;
}

double Player::getY(){
    return y;
}

int Player::getHeight(){
    return height;
}

int Player::getWidth(){
    return width;
}

void Player::decreaseHeight(int delta_to_decrease_by){
    if( height - delta_to_decrease_by >= 3){
        height=height- delta_to_decrease_by ;
    }
    else{
        height=3;
    }
}
void Player::update(char c){
    if( c=='A' && (y+2+height)<=HEIGHT-1){
        y=y+2;
    }
    if( c=='B' && (y-2)>=0){
        y=y-2;
    }
}
void Player::draw(Screen& screen_to_draw_to){
    for(int i=0;i<height;i++){
        screen_to_draw_to.addPixel(x,y+i,'#');
    }
}