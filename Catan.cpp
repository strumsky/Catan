#include "Player.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>


//constructor
//something is wrong with it.
Player::Player(){
    this->name_ = "Jeff";

    this->victoryPoints_= 0;
    this->roadLength_   = 0;
    this->armySize_     = 0;
    this->yellow        = 0;
    this->lightGreen    = 0;
    this->darkGreen     = 0;
    this->blue          = 0;
    this->red           = 0;

    this->knight        = 0;
    this->victoryPointCard = 0;
    this->roadBuilder   = 0;
    this->monopoly      = 0;
    this->yearOfPlenty  = 0;
}

Player::~Player(){

}


int Player::roll(){
    return rand() %5 +1;
}

void Player::checkStats(){
    cout<<"Player Name: "<<this->name_<<endl;
    cout<<"Victory Points: "<<this->victoryPoints_<<endl;
    cout<<"Army Size: "<<this->armySize_<<endl;
    cout<<"Road Length: "<<this->roadLength_<<endl;
    cout<<"Num of Resources: " <<this->numberOfResources()<<endl;
    cout<<"Num of Development: "<<this->numberOfDevelopments()<<endl<<endl;
}

int Player::numberOfResources(){
    int total = this->yellow;
    total = total + this->lightGreen;
    total = total + this->darkGreen;
    total = total + this->blue;
    total = total + this->red;
    return total;
}

int Player::numberOfDevelopments(){
    int total = this->knight;
    total +=this->victoryPointCard;
    total +=this->roadBuilder;
    total +=this->monopoly;
    total +=this->yearOfPlenty;
    return total;
}


void Player::seeResources(){
    cout<<"Yellow: "<<this->yellow<<endl;
    cout<<"Light Green: "<<this->lightGreen<<endl;
    cout<<"Dark Green: "<<this->darkGreen<<endl;
    cout<<"Blue: "<<this->blue<<endl;
    cout<<"Red: "<<this->red<<endl<<endl;
}

void Player::seeDevelopments(){
    cout<<"Knights: "<<this->knight<<endl;
    cout<<"Victory Point Card(s): "<<this->victoryPointCard<<endl;
    cout<<"Road Builder: "<<this->roadBuilder<<endl;
    cout<<"Monoply: "<<this->monopoly<<endl;
    cout<<"Year Of Plenth: "<<this->yearOfPlenty<<endl<<endl;
}

void Player::buyItem(){
    cout<<"What would you like to buy: "<<endl;
    cout<<"1) Road        (1 Red, 1 Dark Green)"<<endl;
    cout<<"2) Settlement  (1 Red, 1 Dark Green, 1 Light Green, 1 Yellow)"<<endl;
    cout<<"3) City        (3 Blue, 2 Yellow)"<<endl;
    cout<<"4) Development Card (1 Blue, 1 Yellow, 1 Light Green)"<<endl;
    cout<<"0 to cancel"<<endl;
    int number;
    cin>>number;
    cout<<endl;
    if(number==1)
        this->buyRoad();
    else if (number ==2)
        this->buySettlement();
    else if (number==3)
        this->buyCity();
    else if (number==4)
        this->buyDevelopmentCard(); 

}

void Player::buyRoad(){
    if(this->red>0 && this->darkGreen>0){
        //do action to place road
        this->red--;
        this->darkGreen--;
    } else
        cout<<"You do not have the resources to purchase a road!"<<endl<<endl;

}

void Player::buySettlement(){
    if(this->red >0 && this->darkGreen>0 && this->lightGreen>0 && this->yellow>0){
        //do action to place settlement
        this->red--;
        this->darkGreen--;
        this->yellow--;
        this->lightGreen--;
        this->victoryPoints_++;
    }else
        cout<<"You do not have the resources to purchase a settlement!"<<endl<<endl;
}

void Player::buyCity(){
    if(this->blue>=3 && this->yellow>=2){
        //do action to place settlement, but also we have to make sure a settlement is already in that space.
        this->blue -= 3;
        this->yellow -= 2;
        this->victoryPoints_++;
    } else
        cout<<"You do not have the resources to purchase a city!"<<endl<<endl;

}

void Player::buyDevelopmentCard(){
    if(this->blue>0 && this->yellow>0 && this->lightGreen>0){
        //do action to fetch developmentCard
        this->blue--;
        this->yellow--;
        this->lightGreen--;
    } else
        cout<<"You do not have the resources to purchase a developmentCard!"<<endl<<endl;
}
