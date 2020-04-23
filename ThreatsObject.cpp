#include "ThreatsObject.h"
#include<ctime>

int a[21]={-400,-380,-360,-340,-320,-300,-280,-260,-240,-220,-200,-180,-160,-140,-120,-100,-80,-60,-40,-20,0};


ThreatObject::ThreatObject()
{
    rect_.x = SCREEN_WIDTH;
    rect_.y = 0;
    rect_.w = WIDTH_THREAT;
    rect_.h = HEIGHT_THREAT;

    x_val_ = 0;
    y_val_ = 0;
}

ThreatObject::~ThreatObject()
{
    ;
}

void ThreatObject::HandleMove(const int&x_bordr, const int& y_bordr)
{
    rect_.x -= x_val_;
    if(rect_.x < -300)
    {
        rect_.x = SCREEN_WIDTH+100;

        srand(time(0));

        rect_.y = a[rand() % 20];
    }
}

void ThreatObject::Show_1(SDL_Renderer*des)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des,p_object_,NULL, &renderquad);
}

void ThreatObject::HandleInputAction(SDL_Event events)
{
 ;
}






