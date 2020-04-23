
#ifndef THREATES_OBJECT_H_
#define THREATES_OBJECT_H_

#include "commonFunc.h"
#include "BaseObject.h"

#define WIDTH_THREAT 50
#define HEIGHT_THREAT 200


class ThreatObject : public BaseObject
{
public:
    ThreatObject();
    ~ThreatObject();

    void HandleMove(const int&x_bordr, const int& y_bordr);
    void HandleInputAction(SDL_Event events);
    void Show_1(SDL_Renderer*des);
    void set_x_val(const int&val){x_val_ = val;}
    void set_y_val(const int&val){y_val_ = val;}
    int get_x_val() const {return x_val_;}
    int get_y_val() const {return y_val_;}
    int randomY()
    {
        srand(time(0));
        int a = rand() % 1 -400 ;
        return a;
    }
private:
    int x_val_;
    int y_val_;

};

#endif // THREATES_OBJECT_H_
